#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <iostream>
#include <stack>
#include "composite.h"

using namespace std;

class Base;

class Iterator {
protected:
	Base* self_ptr;
	Base* current_ptr;

public:
	Iterator(Base* ptr) { this->self_ptr = ptr; }
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool is_done() = 0;
	virtual Base* current() = 0;
};

class OperatorIterator : public Iterator {
public:
	OperatorIterator(Base* ptr) : Iterator(ptr) {
		//self_ptr = ptr;
		current_ptr = self_ptr;
	}
	void first();
	void next();
	bool is_done() {
		if (current_ptr == NULL) {
			return true;
		}
		return false;
	}
	Base* current() {
		return current_ptr;
	}
};


class UnaryIterator : public Iterator {
public:
	UnaryIterator(Base* ptr) : Iterator(ptr) {
		//self_ptr = ptr;
	}
	void first();
	void next() {
		current_ptr = NULL;
	}
	bool is_done() {
		if (current_ptr == NULL) {
			return true;
		}
		return false;
	}
	Base* current() {
		return current_ptr;
	}
};

class NullIterator : public Iterator {
public:
	NullIterator(Base* ptr) : Iterator(ptr) {
		//self_ptr = ptr;
		current_ptr = self_ptr;
	}
	void first() { return; }
	void next() { return; }
	bool is_done() {
		return true;
	}
	Base* current() {
		return NULL;
	}
};

class PreOrderIterator : public Iterator {
protected:
	stack<Iterator*> iterators; //keeps track of collection iterators that we need to traverse
public:
	PreOrderIterator(Base* ptr) : Iterator(ptr) {
		//self_ptr = ptr;
	}
	void first();
	void next();
	bool is_done() {
		if(iterators.empty()) {
			return true;
		}
		return false;
	}
	Base* current() {
		return iterators.top()->current();
	}
};

#endif
