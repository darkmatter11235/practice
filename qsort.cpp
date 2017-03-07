#include<iostream>
using namespace std;

void swap(int arr[], int a, int b ) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

//partitions the source array into two halfs 
//lefthalf <= pivot element
//righthalf > pivot element
//returns the pivot point
int partition(int arr[], int left, int right) {
  int pivotElement = left+(right-left)/2;
  int pivotValue = arr[pivotElement];
  int i, j;
  i = left;
  j = right;
  while(i <= j) {
    while(i <= j && arr[i] <= pivotValue) i++;
    while(i <= j && arr[j] >= pivotValue) j--;
    if ( i <= j ) {
      swap(arr, i , j);
    } else {
      break;
    }
  }

  if ( pivotElement > i ) {
    swap(arr, i , pivotElement);
  } else if ( pivotElement < i ) {
    swap(arr, i-1, pivotElement);
    i--;
  }
  return i;
}

void qsort(int arr[], int left, int right) {
  int pivotIndex = partition(arr, left, right);
  if ( pivotIndex > left ) {
    qsort(arr, left, pivotIndex-1);
  }
  if ( pivotIndex < right ) {
    qsort(arr, pivotIndex+1, right);
  }
}

void printArray(int arr[], int sz) {
  for(int i = 0; i < sz; i++) {
    cout << arr[i] << "-->";
  }
  cout << endl;
}


int main(char** argc, int argv) {
  int a[5] = { 1, 4, 56, 6 ,2};
  int sz = 5;
  cout << "BEFORE SORT" << endl;
  printArray(a, sz);
  qsort(a, 0, sz-1);
  cout << "AFTER SORT" << endl;
  printArray(a, sz);
}
