#!/usr/bin/node
// Star wars api

const userInput = process.argv[2];
const requestFilm = require('request');
requestFilm('https://swapi-api.hbtn.io/api/films/' + userInput, async function (error, response, body) {
  if (error) {
    // pass
  }
  if (response.statusCode === 200) {
    const filmJson = JSON.parse(body);
    for (const character in filmJson.characters) {
      await new Promise(function (resolve, reject) {
        requestFilm(filmJson.characters[character], function (error, response, body) {
          if (error) {
            // pass
          }
          if (response.statusCode === 200) {
            console.log(JSON.parse(body).name);
            resolve();
          }
        });
      });
    }
  }
});
