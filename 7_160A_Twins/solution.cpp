#include <iostream>

using namespace std;

int main(){
	int n;
	int sum = 0;
	int temp;

	cin >> n;
	int narr[n];
	for(int i=0; i<n; i++){
		cin >> narr[i];
		sum += narr[i];
	}

	// sorting the array
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(narr[i] < narr[j]){
				temp = narr[i];
				narr[i] = narr[j];
				narr[j] = temp;
			}
		}
	}

	int tsum = 0;
	int i;
	for(i=0; i<n; i++){
		tsum += narr[i];
		if(tsum > (sum - tsum)){
			i++;
			break;
		}
	}

	cout << i;
}