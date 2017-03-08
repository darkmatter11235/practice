#include<iostream>
using namespace std;

void printArray(int arr[], int sz) {
    for(int i = 0; i < sz; i++) {
        cout << arr[i] << "-->";
    }
    cout << endl;
}
void swap(int arr[], int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
    return;
}

int partition2(int arr[], int left, int right) {
    int pivotIndex = left;
    int pivotValue = arr[pivotIndex];
    for(int j=left+1; j <= right; j++) {
        if ( arr[j] <= pivotValue) {
            pivotIndex++;
            swap(arr, pivotIndex, j);
        }
    }
    swap(arr, pivotIndex, left);
    return pivotIndex;
}

int partition(int arr[], int left, int right) {
    int pi = left;
    int i = left+1;
    int j = right;
    while( i <= j ) {
        while( i <= j && arr[i] <= arr[pi] ) i++;
        while( i <= j && arr[j] >= arr[pi] ) j--;
        if ( i < j ) {
            swap(arr, i , j);
            i++;
            j--;
        }
    }
    if ( pi < i ) {
        swap(arr, pi, i-1);
    }
    return i-1;
}

void qsort(int arr[], int left, int right) {

    //partition
    //pivot index
    //int pi = partition(arr, left, right);
    int pi = partition2(arr, left, right);
    printArray(arr,6);
    cout << "pivot " << pi << endl;
    //recurse
    if ( pi-1 > left ) {
        qsort(arr, left, pi-1);
    }
    if ( pi+1 < right ) {
        qsort(arr, pi+1, right);
    }

}


int main(char** argc, int argv) {
    int arr[6] = { 1, 42, 122, 23, 12, 11 };
    int sz = 6;
    cout << "BEFORE " << endl;
    printArray(arr, sz);
    cout << "AFTER " << endl;
    qsort(arr, 0, sz-1);
    printArray(arr, sz);
}
