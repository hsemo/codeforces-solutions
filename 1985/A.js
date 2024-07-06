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
    let [a,b] = readline().split(' ');
    if(a !== b){
        let t = b[0] + a.slice(1);
        b = a[0] + b.slice(1);
        a = t;
    }
    print(a + ' ' + b);
}
