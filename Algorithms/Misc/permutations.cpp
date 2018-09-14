#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N = 10;

void search(vector<bool> chosen, vector<int> permutation) {

  if ( permutation.size() == N ) {
    for(auto i: permutation) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    for(int i = 0; i < N; i++) {
      if ( chosen[i] ) { continue; }
      chosen[i] = true;
      permutation.push_back(i);
      search(chosen, permutation);
      chosen[i] = false;
      permutation.pop_back();
    }
  }
  return;
}

void print_perm(vector<int> permutation) {
  for(const auto& i: permutation) {
    cout << i << " ";
  }
  cout << endl;
}
void next() {
  vector<int> permutation;
  for(int i = 0; i < N; i++) {
    permutation.push_back(i);
  }
  do {
    print_perm(permutation);
  } while(next_permutation(permutation.begin(), permutation.end()));
}
int main() {
  cout << "Enter the number for permutations " << endl;
  cin >> N;
  vector<bool> c(N,false);
  vector<int> p;
  //search(c, p);
  next();
  return 0;
}
