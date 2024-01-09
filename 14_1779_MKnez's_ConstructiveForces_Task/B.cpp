#include <iostream>

using namespace std;

void testCase(){
    int n;
    int a,b;
    cin >> n;
    if(n == 3){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if(n%2 == 0){
        a = 1;
        b = -1;
    } else {
        b = n-1;
        a = -( b-2 );
    }
    n = n/2;
    n--;
    while(n--){
        cout << a << " " << b << " ";
    }
    cout << a << " " << b;
    if(a < 0){ // to check that n was odd or not
        cout << " " << a << endl;
    } else{
        cout << endl;
    }

    return;
}

int main(){
    int t;
    cin >> t;
    while(t--)
        testCase();
    
    return 0;
}
