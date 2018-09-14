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
      copy(m_data.begin(), m_data.end(), data_array.begin()+m_size);
      m_data = data_array;
      for(const auto val : m_data) { cout << val << endl; }
    }

    void insert(const T& a ) {
      m_data.push_back(a);
    }

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


int main() {

  vector<int> data;
  for(int i = 0; i < 20; i++) {
    data.push_back(i);
  }
  sumSegTree<int> sTree(data);
  sTree.buildTree();
  return 0;
}
