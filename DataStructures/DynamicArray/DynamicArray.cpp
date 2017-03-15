#include "DynamicArray.h"

#include "time.h"

#include<iostream>
#include<cstdlib>

using namespace std;

dynamicArray::dynamicArray(const dynamicArray& other): _size(other.getSize()) {
	p_vals = new int[this->_size];
	for(int i = 0; i < _size; i++) {
		p_vals[i] = other.p_vals[i];
	}
}

void dynamicArray::printArray() {
	for(int i = 0; i < _size; i++) {
		cout << "A[" << i << "] ---> " << p_vals[i] << endl;
	}
}

int main(int argc, char** argv) {
	int size = 10;
	srand(time(NULL));
	try {
		dynamicArray A(size);
		for(int i = 0; i < size; i++) {
			A[i] = rand()%size;
		}
	} catch(arrayException &e) {
		cout <<  "Got Exception : " << e.enumber << " " << e.emsg << endl;
	}
}
