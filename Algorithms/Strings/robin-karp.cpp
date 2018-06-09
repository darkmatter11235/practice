#include<iostream>
#include<string>
#include<cmath>

using namespace std;

#define B 1000
#define M 1000000007
//this returns the modulo even for negative input a, and modulus over b
int intmod(int a, int b) {
  return (a % b + b)%b;
}

bool validate_substring(string text, int index, string pattern) {

    for(int i = 0; i < pattern.size(); i++) {
      if(text[index+i] != pattern[i]) { return false; }
    }
    return true;
}

int rk(string text, string pattern) {

  int text_length = text.size();
  int pattern_length = pattern.size();

  int pattern_hash = 0;

  if(text_length < pattern_hash) { return -1; }

  for(int i = 0; i < pattern_length; i++) {
      pattern_hash = intmod( pattern_hash*B + pattern[i], M);
  }

  int text_hash = 0;
  //calculate the hash of the first text
  for(int i = 0; i < pattern_length; i++) {
    text_hash = intmod( text_hash*B + text[i], M);
  }

  if ( text_hash == pattern_hash ) {
    if ( validate_substring(text, 0, pattern) ) { return 0; }
  }

  //calculate the rolling hash
  int E = intmod(pow(B, pattern_length-1), M);
  for(int i = pattern_length ; i < text_length; i++) {
    text_hash = intmod(text_hash - intmod(text[i-pattern_length]*E, M ), M);
    text_hash = intmod(text_hash*B, M);
    text_hash = text_hash + text[i];

    if ( text_hash == pattern_hash ) {
      if( validate_substring(text, i-pattern_length+1, pattern) ) { return i-pattern_length; }
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

  int foundSub = rk(text, pattern);

  if ( foundSub > -1 ) {
    cout << "Found substring at index " << foundSub << endl;
  } else {
    cout << "Unable to find substring " << endl;
  }
}
