#include <iostream>
#include <vector>
#include "composite.h"

using namespace std;

int main() {

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4);
	Sqr* sqr = new Sqr(op2);
	Sub* sub = new Sub(add, sqr);
	Root* root = new Root(sub);

	cout << "--- PreOrder Iteration ---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->print();
		cout << endl;
	}
	cout << endl;

	Op* op5 = new Op(5);
	Add* add2 = new Add(op5,op2);
	Add* add3 = new Add(op3,op2);
	Mult* mult = new Mult(add2, add3);
	Root* root2 = new Root(mult);

	cout << "--- PreOrder Iteration ---" << endl;

	PreOrderIterator* itr = new PreOrderIterator(root2);
	for(itr->first(); !itr->is_done(); itr->next()) {
		itr->current()->print();
		cout << endl;
	}
}
