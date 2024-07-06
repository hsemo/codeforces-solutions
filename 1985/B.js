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
    let optimalX = 0;
    let optimalSum = 0;
    let sum = 0;
    for(let x = 2; x <= n; x++){
        for(let k = 1; k<=n; k++){
            let t = k*x;
            if(k*x > n){
                break;
            }
            sum += t;
        }
        if(sum > optimalSum){
            optimalSum = sum;
            optimalX = x;
        }
        sum = 0;
    }

    print(optimalX);
}
