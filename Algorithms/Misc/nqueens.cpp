#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n = 0;

bool is_valid(int r, int c, const vector<pair<int, int> > &queens) {

  for(const auto & coord: queens) {
    int qr = coord.first;
    int qc = coord.second;
    if ( qr == r || qc == c ) { return false; }
    if ( abs(qr-r) == abs(qc-c) ) { return false; }
  }
  return true;
}

void print_queens(const vector<pair<int, int> > &queens) {

  for(int r = 0; r < n; r++) {
    for(int c = 0; c < n; c++) {
      if ( find(queens.begin(), queens.end(), make_pair(r,c)) == queens.end() ) {
        cout << "| * |";
      } else {
        cout << "| Q |";
      }
    }
    cout << endl;
  }
  cout << endl;
  return;
}

void nqueens( vector<pair<int, int> > &queens) {
  if ( queens.size() == n ) { 
    print_queens(queens);
    return;
  } else {
    for(int r = 0; r < n; r++) {
      for(int c = 0; c < n; c++) {
        if ( is_valid(r, c, queens) ) {
          queens.push_back(make_pair(r, c) );
          nqueens(queens);
          queens.pop_back();
        }
      }
    }
  }
}

int main() {
  cin >> n;
  vector<pair<int, int> > Qs;
  nqueens(Qs);
  return 0;
}
