import * as cheerio from 'cheerio';
import fetch from 'node-fetch';


// 0. Install packages
// In terminal, run:
// npm install node-fetch cheerio


// 1. Get data

// 1.1 Get pages to parse for all heroes
// https://www.dotabuff.com/heroes

// https://github.com/node-fetch/node-fetch#plain-text-or-html

// 1.2 For each hero, fetch common positions and counter stats
// Lane position
// https://www.dotabuff.com/heroes/abaddon
// Counter stats
// https://www.dotabuff.com/heroes/abaddon/counters

const getHeroPaths = async () => {
    const response = await fetch('https://www.dotabuff.com/heroes');

    const body = await response.text();

    // Saved as a cheerio-specific instance, rather than any other constant
    const $heroes = cheerio.load(body);

    // Request cheerio to look for data under the div 'hero-grid'   
    const heroGrid = $heroes('div.hero-grid')[0]
    const paths = heroGrid.children
        .filter(child => child.name === 'a')
        .map(child => child.attribs['href'])

    return paths
}

// Func:   Fetch hero details
// Input:  url to hero.
// Output: a constant with a name, tags and matchups.
const getHeroDetails = async (path) => {
    const detailsUrl = `https://www.dotabuff.com${path}`
    const detailResponse = await fetch(detailsUrl);
    const detailBody = await detailResponse.text();

    // Get counters and their data.
    const countersUrl = `https://www.dotabuff.com${path}/counters`
    const counterResponse = await fetch(countersUrl);
    const counterBody = await counterResponse.text();
    
    const $detail = cheerio.load(detailBody);
    const $counters = cheerio.load(counterBody);
    
    // Name and tags
    const heroh1 = $detail('h1')
    const tags = $detail('h1 small').text().split(",")
    $detail('h1 small').remove()
    const name = heroh1.text()
    
    // Counters
    const tableSelector = "body > div.container-outer.seemsgood > div.skin-container > div.container-inner.container-inner-content > div.content-inner > section:nth-child(4) > article > table > tbody"
    const rows = $counters(tableSelector)[0].children

    const counters = rows.map((row) => ({
        hero: row.children[1].children[0].children[0].data,
        disadvantage: parseFloat(row.children[2].attribs['data-value'])
    }))

    const hero = {
        name,
        tags,
        counters,
    }
    return hero
}


const paths = await getHeroPaths()
const heroes = await Promise.all(paths.map(getHeroDetails))
    
// 2. TODO:


// Func:   getCounters()
// Input:  Heroes, SomeHeroA (string)
// Output: All heroes w/index >0 vs SomeHeroA[], Index (score)
// Desc:

const getCounters = (heroes, name) => {
    const someHeroA = heroes.find((h) => h.name === name)
    return someHeroA.counters
}

// Func:   getDisadvantageScore
// Input:  SomeHero, All heroes w/ index >0 vs SomeHero[] 
// Output: Index (Score)
// Index is positive -> Bad Choice
// Index is negative -> Good Choice 

const getDisadvantageScore = (hero, counters) => {
    const heroCounters = hero.counters
    const filteredCounters = heroCounters.filter(hero => counters.find(c => c.name === hero.name))
    const sumOfDisadvantages = filteredCounters.reduce((acc, counter) => acc + counter.disadvantage , 0)
    return sumOfDisadvantages
}

const someHeroACounters = getCounters(heroes, 'Spectre')
const scores = heroes.map(hero => {
    const score = getDisadvantageScore(hero, someHeroACounters)
    return [hero.name, score]
})

console.log(scores.sort((a, b) => a[1] > b[1] ? -1 : 1).slice(0,5))