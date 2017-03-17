#ifndef PROJECT_BST_H
#define PROJECT_BST_H


template<typename T> class bsTree {
	private:
		class bsNode {
			public:
				bsNode() *val(new T), leftChild(nullptr), rightChild(nullptr) {}
				bsNode(T inVal) val(inVal), leftChild(nullptr), rightChild(nullptr) {}

				T getValue() { return val; }
				bsNode<T> *getLeft() { return leftChild; }
				bsNode<T> *getRight() { return leftChild; }

			private:
				T val;
				bsNode<T> *leftChild;
				bsNode<T> *rightChild;
		};
		bsNode *root;
	public:
		//constructor
		bsTree() root(NULL) {}

		//destructor
		~bsTree();

		//display
		void printTree();

		//basic operations
		void insert(T val);
		bool remove(T val);
		remove find(T val);

		//traversals
		void inOrder();
		void preOrder();
		void postOrder();

};

#endif
