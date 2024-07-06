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
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();
});

function readline() {
    return inputString[currentLine++];
}

//---------------------------------------------------------------------
function main(){
    let tests = parseInt(readline());
    while(tests-- > 0){
        handleTestCase();
    }
}

function handleTestCase(){
    let n = parseInt(readline());
    let a = readline().split(' ');

    // o = {number: cost}
    let o = {};

    a[0] = parseInt(a[0]);
    for(let i=1; i<n; i++){
        a[i] = parseInt(a[i]);
        if(a[i] < a[i-1]){
            o[a[i]] = a[i-1] - a[i];
        }
    }

}
