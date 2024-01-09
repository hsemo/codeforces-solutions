#include <iostream>

using namespace std;

int main(){
    // It's solution is just a simple sorting of the big lines of cubes in last and small lines at start
    int n;
    cin >> n;
    int cols[n];
    for(int i=0; i<n; i++){
        cin >> cols[i];
    }

    int k;
    for(int i=n-1; i>0; i--){
        k = i-1;
        while(k >= 0){
            if(cols[i] < cols[k]){
                cols[i] += cols[k];
                cols[k] = cols[i]-cols[k];
                cols[i] -= cols[k];
            }
            k--;
        }
    }

    for(int i=0; i<n-1; i++){
        cout << cols[i] << " ";
    }
    cout << cols[n-1];

    return 0;
}
