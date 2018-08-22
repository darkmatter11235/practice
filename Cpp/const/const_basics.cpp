#include<iostream>

// benefits of const
// prevent unintented writes
// self documenting the code's expected behavior
// enables further compiler optimization
// values can be stored in ROM where applicable i.e in embedded systems

using namespace std;

int main() {

  //if const is to the left of * then data is const
  //if const is to the right of * then pointer is const

  const int i = 7;
  //i = 6;

  //pointer j is pointing to the i's address
  const int *j = &i;

  j++;

  cout << i << " " << &i << " " << &j << endl;

  const int *p = &i;

  //int* const p1 = static_cast<int* const> &i;


}
