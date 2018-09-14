#include<iostream>
#include<vector>

using namespace std;


vector<int> findChange(const vector<int> &coins, int value, vector<int> &DP) {

}

int main() {
  int N, V;
  cout << "Enter number of coins: " << endl;
  cin >> N;
  vector<int> C;
  cout << "Enter coin values: " << endl;
  for(auto i : N) {
    cin >> V;
    C.push_back(V);
  }
  cout << "Enter Value: " << endl;
  cin >> V;
  vector<int> DP(V, 0);
  for(auto i : C) {
    DP[i] = 1;
  }
  findChange(C, V, DP);
}
