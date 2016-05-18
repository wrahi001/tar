#include "iterator.h"
#include "composite.h"
#include <iostream>
#include <stack>

void OperatorIterator::first() {
	this->current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
	if(current_ptr == self_ptr->get_right()) { //if it's currently pointing to the right
		current_ptr = NULL;
	}
	else {
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
	iterators.push(itr);
	iterators.top()->first();
}

void PreOrderIterator::next() {
	Iterator* itr = iterators.top()->current()->create_iterator(); //new Iterator(iterators.top())
	//cout << "Creates iterator" << endl;
	iterators.push(itr);
	//cout << "Pushes iterator to stack" << endl;
	
	iterators.top()->first();
	while(iterators.top()->is_done()) {
		iterators.pop();
		if(iterators.size() > 0)
		{
			iterators.top()->next();
		}
		if(iterators.size() == 0) {
			return;
		}
	}
	

}