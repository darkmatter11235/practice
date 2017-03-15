#ifndef DS_DYNAMIC_ARRAY
#define DS_DYNAMIC_ARRAY

class arrayException {
	public:
		arrayException(int no, const char* msg): enumber(no), emsg(msg) {}
		int enumber;
		const char* emsg;
};

class dynamicArray {
	private:
		int _size;
		int *p_vals;
	public:
		//default constructor
		dynamicArray() : _size(0), p_vals(nullptr) {}

		//constructor with default values
		dynamicArray(int size): _size(size) {
			if ( size <= 0 ) {
				throw arrayException(1, "got bad size in constructor!!");
			}
			p_vals = new int[size];
		}

		//copy constructor
		dynamicArray(const dynamicArray& other);

		//move constructor
		dynamicArray(dynamicArray&& other);

		//copy assignment operator
		dynamicArray& operator= (const dynamicArray& other);

		//move assignment operator
		dynamicArray& operator= (dynamicArray&& other);
	
		//const index operator
		const int& operator[] (int index) const {
			if ( index < 0 || index >= _size ) {
				throw arrayException(2, "index out of bounds");
			}
			return p_vals[index];
		}
		//index operator
		int& operator[] (int index) {
			if ( index < 0 || index >= _size ) {
				throw arrayException(2, "index out of bounds");
			}
			return p_vals[index];
		}

		//accessors
		int getSize() const { return _size; }

		//output
		void printArray();

		//destructor
		~dynamicArray() {
			delete [] p_vals;
		}
};
#endif
