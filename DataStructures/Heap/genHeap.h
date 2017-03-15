#ifndef DS_GEN_HEAP_H
#define DS_GEN_HEAP_H

#include<iostream>
#include<stdexcept>
#include<vector>
#include<cstdlib>


using namespace std;

template<typename T> class genHeap {
    public:
        genHeap();
        genHeap(T elements[], int arraySize);
        void add(T val);
        T remove() throw(runtime_error);
        int getSize();
    private:
        vector<T> v;
};
#endif //DS_GEN_HEAP_H
