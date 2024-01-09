#include <iostream>

using namespace std;

int main(){
    int n, maxlen, tl;
    int prev,cur;
    cin >> n;
    cin >> prev;
    tl = 1;
    maxlen = 0;
    for(int i=1; i<n; i++){
        cin >> cur;
        if(cur < prev){
            maxlen = (maxlen > tl)? maxlen : tl;
            tl = 0;
        }
        tl++;
        prev = cur;
    }
    maxlen = max(maxlen, tl);
    cout << maxlen;
    
    return 0;
}
