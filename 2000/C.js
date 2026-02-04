'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;
let print = console.log;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString
    .trim()
    .split('\n')
    .map(string => {
      return string.trim();
    });

  main();
});

function readline() {
  return inputString[currentLine++];
}

// ---------------------------------------------------------------------

function matchTemplate(arr, str) {
  if (arr.length !== str.length) {
    console.log('no');
    return;
  }

  const letters = {};
  const numbers = {};
  for (let i = 0; i < str.length; i++) {
    const c = str[i];
    const n = arr[i];
    const prevN = letters[c];

    const prevC = numbers[n];

    if (prevN === undefined) {
      letters[c] = n;
    } else if (prevN !== n) {
      console.log('no');
      return;
    }

    if (prevC === undefined) {
      numbers[n] = c;
    } else if (prevC !== c) {
      console.log('no');
      return;
    }
  }

  console.log('yes');
}

function parseTestCase() {
  const n = parseInt(readline());
  const a = readline()
    .split(' ')
    .map(s => parseInt(s));

  const m = parseInt(readline());
  for (let i = 0; i < m; i++) {
    const str = readline();
    matchTemplate(a, str);
  }
}

function main() {
  let t = parseInt(readline());
  while (t-- > 0) {
    parseTestCase();
  }
}
