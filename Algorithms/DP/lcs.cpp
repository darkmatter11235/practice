#include <iostream>
#include "malloc.h"

using namespace std;

//F(n) = Max { ai, .., aj } s.t i < j

int lcs(int* a, int* b, int N) {

	//default cases
	// too small
	if ( N <= 0 ) { return 0; } 
	//recursion
	//dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j-1]+1, dp[i-1][j]+1)
	
	int dp[N+1][N+1];

	return result;

}

int main(int argc, char** argv) {
	int input;
	int *a, *b;
	input = 1;
	while(input) {
		cout << "Enter N " << endl;
		cin >> input;
		cout << "Enter Array A " << endl;
		a = (int*) malloc(input*sizeof(int));
		for(int i = 0; i < input; i++) {
			cin >> a[i];
		}
		b = (int*) malloc(input*sizeof(int));
		cout << "Enter Array B " << endl;
		for(int i = 0; i < input; i++) {
			cin >> b[i];
		}
		cout << "LCS: length " << lis(a, b, input) << endl;
		free(a);
		free(b);
	}
}
