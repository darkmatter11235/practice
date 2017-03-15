#include <iostream>
#include <cmath>

//class to represent a van embde boas tree structure
//non STL implementation i.e no vector/lists/etc.
using namespace std;
public class vebNode {
    public:
        //summary node that tracks the empty/non-empty cluster indices
        vebNode* summary;
        vebNode** clusters;
        int min;
        int max;
        int size;
        int csize;
        
        //constructor
        vebNode(int sz) {
            min = max = -1;
            size = sz;
            csize = ceil(sqrt(sz));
        };

        //destructor
        ~vebNode() {
            
        }

        //insert
        void insertValue(int key);
        //delete
        void deleteValue(int key);
        //findNext
        int findNext(int key);
        //findPrev
        int findPrev(int key);
        //hasElement
        bool hasElement(int key);
        
};

void vebNode::insertValue(int key) {
        //case1: first value inserting
        if ( min == -1 && max == -1 ) {
            min = max = key;
            summary = new vebNode(csize);
            return;
        }
        //case2: has non-empty elements
}

void vebNode::deleteValue(int key) {

}

int vebNode::findNext(int key) {

}

int vebNode::findPrev(int key) {

}

bool vebNode::hasElement(int key) {

}
