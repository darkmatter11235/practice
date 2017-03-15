#include "genHeap.h"

#include "time.h"

template<typename T> T genHeap<T>::remove()  throw(runtime_error)
{   
    if ( v.size() == 0 ) {
        throw runtime_error("Heap Size is zero!!");
    }

    T rval = v[0];
    v[0] = v[v.size()-1];
    v.pop_back();

    int currentIndex = 0;
    int leftIndex, rightIndex;
    while ( currentIndex  < v.size()) {

        leftIndex = 2*currentIndex + 1;
        rightIndex = 2*currentIndex + 2;

        if ( leftIndex >= v.size() ) break;

        int maxIndex = leftIndex;
        if ( v[rightIndex] > v[maxIndex] ) maxIndex = rightIndex;

        if ( v[currentIndex] < v[maxIndex] ) {
            T temp = v[currentIndex];
            v[currentIndex] = v[maxIndex];
            v[maxIndex] = temp;
        } else {
            break;
        }

        currentIndex = maxIndex;
    }
    
    return rval;
}

template<typename T> genHeap<T>::genHeap(T elements[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        add(elements[i]);
    }
}

template<typename T> void genHeap<T>::add(T val) 
{
    v.push_back(val);

    int currentIndex = v.size()-1;

    int parentIndex;

    while(currentIndex > 0) {

        parentIndex = (currentIndex-1)/2;

        if ( v[parentIndex] < v[currentIndex] ) {
            T temp = v[currentIndex];
            v[currentIndex] = v[parentIndex];
            v[parentIndex] = temp;
        } else {
            break;
        }
        currentIndex = parentIndex;
    }
}

template<typename T> int genHeap<T>::getSize() {
    return v.size();
}

int main(int argc, char** argv) {
    int arr[10];
    int size = 10;
    srand(time(NULL));
    for(int i = 0; i < size; i++ ) {
        arr[i] = rand()%size;
        cout << "inserting " << arr[i] << endl;
    }
    genHeap<int> maxHeap(arr, size);
    while(maxHeap.getSize() > 0 ) {
        int topVal = maxHeap.remove();
        cout << topVal << " --> ";
    }
    cout << endl;

}
