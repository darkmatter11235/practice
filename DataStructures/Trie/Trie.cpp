#ifndef __TRIE_H
#define __TRIE_H

#include<iostream>
#include<map>
#include<vector>

using namespace std;

class TrieNode;
class Trie;

class TrieNode {
 
  public:

    TrieNode(bool isa_leaf, TrieNode* parent):_isa_leaf(isa_leaf), _parent(parent) {}

    int getNumChildren() { return _children.size(); }

    void setIsaLeaf(bool isaLeaf) { _isa_leaf = isaLeaf; }
    
    bool isaLeaf() { return _isa_leaf; }

    TrieNode* getChild(char a) {
      if ( _children.find(a) != _children.end() ) {
        return _children[a];
      }
      return NULL;
    }

    TrieNode* insert(char a) {

      if ( _children.find(a) != _children.end() ) {
        return _children[a];
      } else {
        TrieNode* n = new TrieNode(false, this);
        _children.insert(make_pair(a, n));
        return n;
      }

    }

    void removeEntry(char c) {

      if ( _children.find(c) != _children.end() ) {
        _children.erase(_children.find(c));
      }

    }

    void print(int indent) {
      std::map<char, TrieNode*>::iterator it;
      for(it = _children.begin(); it != _children.end(); it++ ) {
        for(int i = 0; i < indent; i++ ) { cout << " "; }
        cout << " | " << it->first << " " << (it->second)->isaLeaf() << endl;
        (it->second)->print(indent+2);
      }
    }
  private:

    std::map<char,TrieNode*> _children;

    TrieNode* _parent;

    bool _isa_leaf;
};

class Trie {

  public:

  Trie():_root(NULL) {}

  void insert(string word) {
    if ( !_root ) {
      _root = new TrieNode(false, NULL);
    }
    TrieNode* cur = _root;
    for(int i = 0; i < word.length(); i++ ) {
      cur = cur->insert(word[i]);
    }
    cur->setIsaLeaf(true);
  }

  void deleteWord(string word) {
    deleteWord(_root, word, 0);
  }

  bool deleteWord(TrieNode* current, string word, int index) {

    if ( !current ) { return false; }

    if ( index >= word.length() ) {
      return (current->getNumChildren() == 0);
    }

    char c = word[index];

    TrieNode* child = current->getChild(c);
    
    if ( child ) {

      bool deleteThisEntry = deleteWord(child, word, index+1);

      if ( deleteThisEntry ) {
        current->removeEntry(c);
      }

      if ( child->getNumChildren() == 0 ) {
        delete child;
        return true;
      } else {

        if ( index == word.length()-1) {
          child->setIsaLeaf(true);
        }
        return false;
      }

    } else {

      return false;

    }

  }

  void print() {

      _root->print(0);
  }

  private:

  TrieNode* _root;
};

int main() {
  vector<string> inputs;
  inputs.push_back("abc");
  inputs.push_back("abgl");
  inputs.push_back("lmn");
  vector<string>::iterator it;
  Trie* trie = new Trie();

  for(it = inputs.begin(); it != inputs.end(); it++) {
    trie->insert(*it);
  }

  trie->print();

  trie->deleteWord("lmn");
  cout << "After deleting " << endl;

  trie->print();
}
#endif //__TRIE_H
