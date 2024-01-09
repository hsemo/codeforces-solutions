#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    char dirs[n]; // directions array
    int sd = 0; // standing dominos from start (dots)
    int bsd = 0; // standing dominos from back
    int lsd = 0; // left standing dominos
    int start=0, end=n-1;
    
    for(int i=0; i<n; i++){
        cin >> dirs[i];
    }
    
    // find the first direction
    for(int i=0; i<n; i++){
        if(dirs[i] != '.'){
            sd = (dirs[i] == 'L')? 0 : sd;
            start = i;
            break;
        }
        sd++;
    }
    
    // find the last direction 
    for(int i=n-1; i>=0; i--){
        if(dirs[i] != '.'){
            bsd = (dirs[i] == 'R')? 0 : bsd;
            end = i;
            break;
        }
        bsd++;
    }

    lsd += bsd;
    
    // find all the left standing dominos between first and last direction
    for(int i=start; i<=end; i++){
        if(dirs[i] == 'L'){
            lsd += (sd % 2 == 0)? 0 : 1;
            sd = 0;
            continue;
        }else if(dirs[i] == 'R'){
            lsd += sd;
            sd = 0;
            continue;
        }
        sd++;
    }

    cout << lsd;
    
    return 0;
}
