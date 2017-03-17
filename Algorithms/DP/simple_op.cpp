#include <iostream>

using namespace std;

//F(n) = 1 + min ( F(n-1) + F(n/2) + F(n/3) )

int getNumOps(int N) {

	//default cases
	// too small
	if ( N <= 0 ) { return 0; } 
	
	int dp[N+1];

	dp[0] = 0;
	dp[1] = 0;
	for(int i = 2; i <= N; i++) {
		dp[i] = 1 + dp[i-1];
		if ( i%2 == 0 ) { dp[i] = min(dp[i], 1+dp[i/2]); }
		if ( i%3 == 0 ) { dp[i] = min(dp[i], 1+dp[i/3]); }
	}

	return dp[N];
}

int main(int argc, char** argv) {
	int input;

	input = 1;
	while(input) {
		cout << "Enter N " << endl;
		cin >> input;
		cout << "Num Ops " << getNumOps(input) << endl;
	}
}
