#include<iostream>
#include<bitset>

using namespace std;

void print_subsets(int n) 
{
  constexpr int num = 8*sizeof(int);
  for(int i = 0; i < (1 << n); i++) {
    bitset<num> bs = i;
    cout << bs << endl;
  }
}

int main() 
{
  int N;
  cout << "Enter number between 1 & 32 " << endl;
  cin >> N;
  print_subsets(N);
  return 0;
}
