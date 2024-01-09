#include <iostream>

using namespace std;

void handleTestCase(void){
    int n{}, k{}, x{};
    int rem{-1}, solution{0}, length{0};
    int i;

    cin >> n >> k >> x;
    /* cout << "n: " << n << ", k: " << k << ", x: " << x << "\n"; */

    if(k == 1){
        cout << "NO" << "\n";
        return;
    }

    for(i=k; i >= 1; i--){
      if(i == x) continue;

      rem = n % i;
      /* cout << "rem: " << rem << ", i: " << i << "\n"; */
      if(rem != x){
        solution = 1;
        break;
      } else if(rem == x){
        // finding new remainder for the number if it exists
        rem += i;
        if(rem <= k){
          solution = 1;
          break;
        }
      }
    }

    if(solution != 1){
      cout << "NO" << "\n";
      return;
    }

    length = (n - rem) / i;

    cout << "YES" << "\n";

    if(rem > 0){
      length++;
      cout << length << "\n";
      cout << rem << ' ';
    } else{
      cout << length << "\n";
    }

    for(int j=0; j<((n - rem) / i); j++){
      cout << i << ' ';
    }

    cout << "\n";
}

int main(int argc, char **argv){
    int t{};
    cin >> t;
    for(int i=0; i<t; i++){
        handleTestCase();
    }

    return 0;
}
