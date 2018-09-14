#include<iostream>
#include<string>
#include<cmath>

using namespace std;



bool isa_ps(string text, int index, char c) {
    if( text[index] == c ) { return true; }
    return false;
}

int kmp(string text, string pattern) {

  int text_length = text.size();
  int pattern_length = pattern.size();
  //base cases
  if(pattern_length > text_length ) { return -1; }
  if(text_length == 0) { return 0; }
  //first create the proper-suffix array
  //this is based on dynamic programming
  //F[i] = F[i-1]+t[i] if F[i-1]+t[i] is a proper suffix
  //else F[i] = F[F[i-1]]+t[i] and so on
  int F[pattern_length];
  for(int i = 0; i < pattern_length; i++) {
    F[i] = 0;
  }
  int j;
  j = 0;
  for(int i = 1; i < pattern_length; i++) {
    while( j >= 0) {
      if ( isa_ps(pattern, F[j], pattern[i]) ) {
        F[i] = F[j]+1;
        break;
      }
      if ( j == 0 ) { break; }
      j = F[j];
    }
  }
  
  for(int i = 0; i < pattern_length; i++) {
    cout << "F[" << i << "] " << F[i] << endl;
  }

  //now we have the ps array start matching the pattern
  //everytime it fails fall-back on the F array and see if you can continue the match from there.
  int i = 0;
  j = 0;
  bool found = false;
  while(!found) {
    if ( j == text_length ) { return -1; }
    if ( text[j] == pattern[i] ) {
      i++;
      j++;
      if ( i == pattern_length ) { return j-pattern_length; }
    } else if(i > 0) { 
      i = F[i]; 
    } else {
      j++;
    }
    
  }

  return -1;
}

int main() {
  string text, pattern;
  cout << "Enter text " << endl;
  cin >> text;
  cout << "Enter pattern" << endl;
  cin >> pattern;

  int foundSub = kmp(text, pattern);

  if ( foundSub > -1 ) {
    cout << "Found substring at index " << foundSub << endl;
  } else {
    cout << "Unable to find substring " << endl;
  }
}
