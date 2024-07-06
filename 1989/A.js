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
    let n = parseInt(readline());
    while(n-- > 0){
        let [xi, yi] = readline().split(' ').map((num) => parseInt(num));
        if(yi == 0 || yi >= xi){
            print('YES');
            continue;
        }
        print('NO');
    }
}
