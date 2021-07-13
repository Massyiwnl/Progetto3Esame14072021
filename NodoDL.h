#ifndef NODODL_H_INCLUDED
#define NODODL_H_INCLUDED

#include <iostream>
#include <sstream>

using namespace std;

template<class T>
class NodeDL {
    T value;
    NodeDL<T> * prev;
    NodeDL<T> * next;

public:

	NodeDL(T value, NodeDL<T> *prev, NodeDL<T> *next):
		value(value), prev(prev), next(next) {}
	NodeDL(T value) : NodeDL(value, NULL, NULL) {}

	void setValue(T value) { this->value = value; }
	void setPrev(NodeDL<T> *prev) { this->prev = prev; }
	void setNext(NodeDL<T> *next) { this->next = next; }

	T getValue() const { return value; }
	NodeDL<T> * getPrev() const { return prev; }
	NodeDL<T> * getNext() const { return next; }

	string toString() const {
		stringstream stream;
		stream << "NodeDL value = " << value << ", prev = " << prev << ", next = " << next;
		return stream.str();
	}

	friend ostream& operator<<(ostream& out, const NodeDL<T>& n) {
		out << n.toString();
		return out;
	}
};

#endif // NODODL_H_INCLUDED
