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
    let strA = readline();
    let a = Array(n);
    let numStr = '';
    let k = 0;
    for(const c of strA){
        if(c !== ' '){
            numStr += c;
            continue;
        }
        let num = parseInt(numStr);
        a[k] = num;
        k++;
        numStr = '';
    }
    // temporary code block
    {
        let num = parseInt(numStr);
        a[k] = num;
        numStr = '';
    }

    let sum = 0;
    let max = 0;
    let goodPrefixes = 0;
    for(let i=0; i<n; i++){
        sum += a[i];
        if(a[i] > max) max = a[i];
        if(sum - max == max){
            goodPrefixes++;
        }
    }

    print(goodPrefixes);
}
