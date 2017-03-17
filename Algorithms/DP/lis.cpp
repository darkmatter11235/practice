#include <iostream>
#include "malloc.h"

using namespace std;

//F(n) = Max { ai, .., aj } s.t i < j

int lis(int* arr, int N) {

	//default cases
	// too small
	if ( N <= 0 ) { return 0; } 
	//recursion
	//dp[n] = dp[n-1]
	
	int dp[N+1];


	int result = 0;
	for(int i = 0; i < N; i++) {
		dp[i] = 1;
		for(int j=0; j < i; j++) {
			if ( arr[j] < arr[i] ) {
				dp[i] = max(dp[i], 1+dp[j]);
				result = max(result, dp[i]);
			}
		}
	}

	return result;

}

int main(int argc, char** argv) {
	int input;
	int *arr;
	input = 1;
	while(input) {
		cout << "Enter N " << endl;
		cin >> input;
		arr = (int*) malloc(input*sizeof(int));
		for(int i = 0; i < input; i++) {
			cin >> arr[i];
		}
		cout << "LIS: length " << lis(arr, input) << endl;
		free(arr);
	}
}
