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

function parseTestCase() {
  const n = parseInt(readline());

  const s = readline();
  const subS = new Set();

  for (let i = 0; i < s.length - 1; i++) {
    const ss = s.slice(0, i) + s.slice(i + 2);
    subS.add(ss);
  }

  console.log(subS.size);
}

function main() {
  let t = parseInt(readline());
  while (t-- > 0) {
    parseTestCase();
  }
}
