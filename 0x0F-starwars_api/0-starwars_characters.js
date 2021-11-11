#!/usr/bin/node
// Star wars api

const userInput = process.argv[2];
const requestFilm = require('request');
requestFilm('https://swapi-api.hbtn.io/api/films/' + userInput, function (error, response, body) {
  console.error(error);
  if (response.statusCode === 200) {
    const filmJson = JSON.parse(body);
    filmJson.characters.forEach(character => {
      const requestCharacter = require('request');
      requestCharacter(character, function (error, response, body) {
        console.error(error);
        if (response.statusCode === 200) {
          const characterJson = JSON.parse(body);
          console.log(characterJson.name);
        }
      });
    });
  }
});
