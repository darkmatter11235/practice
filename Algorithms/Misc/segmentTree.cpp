#include<iostream>
#include<functional>
#include<vector>

using namespace std;


template<typename T>
class segmentTree {
  
  public:
  
    segmentTree(const vector<T> &data):m_data(data), m_size(data.size())  {}

    virtual T compute(const T& a, const T& b) = 0;

    void updateTree(const int index, const T& a) {
      if ( m_data.size() <= index ) { cout << "Unable to find element " << index <<  " in tree" << endl; return; }
    }

    void buildTree() {
      vector<T> data_array(2*m_size);
      int n = data_array.size();
      copy(m_data.begin(), m_data.end(), data_array.begin()+m_size);
      m_data = data_array;
      for(int i = m_size-1; i > 0; i--) {
        m_data[i] = compute(m_data[2*i], m_data[2*i+1]);
      }
      for(const auto val : m_data) { cout << val << endl; }
    }

    void insert(const T& a ) {
      m_data.push_back(a);
    }

  private:

  private:

    vector<T> m_data;
    int m_size;

};

template<typename T> 
class sumSegTree : public segmentTree<T> {

  public:

    sumSegTree(const vector<T> &data): segmentTree<T>(data) {
    }

    T compute(const T& a, const T& b) {
      return a+b;
    }


};

template<typename T> 
class maxSegTree : public segmentTree<T> {

  public:

    maxSegTree(const vector<T> &data): segmentTree<T>(data) {
    }

    T compute(const T& a, const T& b) {
      return a > b ? a : b;
    }


};



int main() {

  vector<int> data;
  for(int i = 0; i < 20; i++) {
    data.push_back(i);
  }
  sumSegTree<int> sTree(data);
  sTree.buildTree();
  maxSegTree<int> maxTree(data);
  maxTree.buildTree();
  return 0;
}
