'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString.trim().split('\n').map(string => {
    return string.trim();
  });

  // so that main() function doesn't run before the program takes the input
  main();
});

function readline() {
  return inputString[currentLine++];
}

//---------------------------------------------------------------------
function main(){
  let tests = parseInt(readline());
  let i = tests;
  while(tests-- > 0){
    handleTestCase();
  }
}

function handleTestCase(){
  let [n,favIndex,k] = readline().split(' ').map((str) => parseInt(str));
  // normalizing them according to 0
  favIndex--;
  k--;
  let a = readline().split(' ').map((str) => parseInt(str));
  let favNum = a[favIndex];
  a.sort((a,b) => b - a);

  let firstFavIndex = a.indexOf(favNum);
  let lastFavIndex = a.lastIndexOf(favNum);

  if(firstFavIndex <= k && lastFavIndex > k){
    console.log('MAYBE');
    return;
  }

  if(lastFavIndex <= k){
    console.log('YES');
    return;
  }

  if(firstFavIndex > k){
    console.log('NO');
    return;
  }
}













