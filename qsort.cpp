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

//not truly iterative
//simulating the program stack with in memory stack representation
void qsortIterativeWithStack(int arr[], int left, int right) {
  
  int st[right-left+1];
  int top = -1;
  st[top++] = left;
  st[top]= right;
  int pivotIndex;
  while( top >= 0 ) {
    
    int r = st[top--];
    int l = st[top];

    pivotIndex = partition(arr, l, r);
    if ( pivotIndex > l ) {
      st[top++] = l;
      st[top] = pivotIndex-1;
    }

    if ( r > pivotIndex ) {
      st[top++] = pivotIndex+1;
      st[top] = r;
    }

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
  cout << "QSORT RECURSIVE" << endl;
  printArray(a, sz);
  //qsort(a, 0, sz-1);
  //cout << "AFTER QSORT RECURSIVE" << endl;
  //printArray(a, sz);
  qsortIterativeWithStack(a, 0, sz-1);
  cout << "QSORT ITERATIVE WITH STACK" << endl;
  printArray(a, sz);
}
