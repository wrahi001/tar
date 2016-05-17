#include "iterator.h"
#include "composite.h"
#include <iostream>
#include <stack>

void OperatorIterator::first() {
	this->current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
	if(current_ptr == self_ptr->get_right()) { //if it's currently pointing to the right
		cout << "current ptr set to null" << endl;
		current_ptr = NULL;
	}
	else {
		cout << "get right" << endl;
		current_ptr = self_ptr->get_right();
	}
	
}

void UnaryIterator::first() {
	current_ptr = self_ptr->get_left();
}

void PreOrderIterator::first() {
	while(!iterators.empty()) {
		iterators.pop(); //empty the stack just in case we had something leftover
	}
	Iterator* itr = self_ptr->create_iterator();
	cout << "Created iterator" << endl;
	iterators.push(itr);
	cout << "Pushes to stack" << endl;
}

void PreOrderIterator::next() {
	Iterator* itr = iterators.top()->current()->create_iterator(); //new Iterator(iterators.top())
	//cout << "Creates iterator" << endl;
	iterators.push(itr);
	//cout << "Pushes iterator to stack" << endl;
	iterators.top()->first();

	if(iterators.top()->is_done()) {
		cout << "top Iterator finished" << endl;
		iterators.pop();
		cout << "Pops iterator off stack" << endl;
		iterators.top()->next();
		cout << "Calls next" << endl;
	}
}