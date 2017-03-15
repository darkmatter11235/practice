#include "DynamicArray.h"

#include "time.h"

#include<iostream>
#include<cstdlib>

using namespace std;

//regular copy
dynamicArray::dynamicArray(const dynamicArray& other): _size(other.getSize()) {
	p_vals = new int[this->_size];
	for(int i = 0; i < _size; i++) {
		p_vals[i] = other.p_vals[i];
	}
	cout << "Inside copy constructor " << endl;
}

//rvalue move constructor
dynamicArray::dynamicArray(dynamicArray&& other): _size(other._size), p_vals(other.p_vals) {
	other.p_vals = nullptr;
	other._size = 0;
	cout << "Inside rvalue referenced move constructor " << endl;
}

//copy assignment
dynamicArray& dynamicArray::operator= (const dynamicArray& other) {
	_size = other._size;
	if ( _size <= 0 ) { throw arrayException(1, "got bad size in copy constructor");
	}
	p_vals = new int[_size];
	for(int i = 0; i < _size; i++) {
		p_vals[i] = other.p_vals[i];
	}
	cout << "Inside copy assignment" << endl;

	return *this;
}

//move assignment
dynamicArray& dynamicArray::operator= (dynamicArray&& other) {
	delete [] p_vals;
	p_vals = nullptr;
	_size = 0;

	//pilfer from other
	_size = other._size;
	p_vals = other.p_vals;

	//make other destructor safe
	other._size = 0;
	other.p_vals = nullptr;

	cout << "Inside move assignment operator " << endl;

	return *this;
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
		A.printArray();
		dynamicArray BC(A);
		dynamicArray BM(std::move(A));
		dynamicArray DAC;
	       	DAC = BC;
		dynamicArray DAM;
	        DAM = (std::move(BC));
		//int x = A[size];
	} catch(arrayException &e) {
		cout <<  "Got Exception : " << e.enumber << " " << e.emsg << endl;
	}
}
