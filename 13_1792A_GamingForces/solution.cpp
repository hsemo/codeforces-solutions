#include <iostream>

using namespace std;

void testCase(){
    int n;
    int ones=0;
    int totalSpells=0;
    int tm;

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> tm;
        if(tm==1)
            ones++;
    }
    ones = (ones % 2 == 0)? ones : ones-1;
    totalSpells = (ones/2) + (n-ones);

    cout << totalSpells << endl;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        testCase();
    }
    
    return 0;
}
