#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int gcda(int a[], int n){
    int g = a[0];
    for(int i=1; i<n; i++){
        g = gcd(max(g, a[i]), min(g, a[i]));
    }
    return g;
}
int findLowestCost(int nums[], int gcds[], int n){
    int mc1 = 0; // min cost for changing only one element
    int mc2 = 0; // min cost for two elements
    if(gcda(nums, n) == 1) return 0;
    if(n == 1) return 1;
    int flag = 0; // for breaking out of all the nested loops, ridiculous fiture of c++
    int ga = gcda(nums, n);
    for(int i=n-1; (i>=0) && (!flag); i--){
        if(gcd(ga, gcds[i]) == 1){
            mc1 = n - (i+1) + 1;
            flag = 1;
            break;
        }
    }
    flag = 0;
    for(int i=n-1; (i>=0) && (!flag); i--){
        for(int j=i-1; j>=0; j--){
            int c = (n - (i+1) + 1) + (n - (j+1) + 1);
            /* cout << "cost: " << c << endl; */
            if(c >= mc1){ mc2 = c; flag = 1; break;}
            if(gcd(gcds[i], gcds[j]) == 1){ mc2 = c; flag = 1; break;}
        }
    }
    return min(mc1, mc2);
}

int main(){
    int t, n;
    int sol;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int nums[n];
        int gcds[n];
        for(int j=0; j<n; j++){
            cin >> nums[j];
            gcds[j] = gcd(max(j+1, nums[j]), min(j+1, nums[j]));
        }
        cout << findLowestCost(nums, gcds, n) << endl;
    }
	return 0;
}

