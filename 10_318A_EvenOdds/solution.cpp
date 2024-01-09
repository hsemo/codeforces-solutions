#include <iostream>

using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    
    long long odds, evens;
    odds = n / 2;
    evens = odds;
    odds = (n % 2 != 0)? odds+1 : odds;

    long long ans;
    if(k <= odds){
        ans = (k * 2) - 1;
    }else{
        ans = (k-odds) * 2;
    }

    cout << ans;
    
    return 0;
}
