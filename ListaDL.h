#ifndef LISTADL_H_INCLUDED
#define LISTADL_H_INCLUDED

#include <iostream>
#include <sstream>
#include "NodoDL.h"

template<class T>
class ListDL{
    NodeDL<T> *head, *tail;
    int length;
    bool ascend;

    void insertAscending(T value){
        NodeDL<T> * temp = new NodeDL<T>(value);
        if(head == NULL && tail == NULL){
            this->insertHead(value);
            return;
        }
        if(head->getValue() > value){
            this->insertHead(value);
            return;
        }
        if(tail->getValue() <= value){
            this->insertTail(value);
            return;
        }
        NodeDL<T> * current = head;
        while(current->getValue() < value){
            current = current->getNext();
        }

        temp->setPrev(current->getPrev());
        temp->setNext(current);
        current->getPrev()->setNext(temp);
        current->setPrev(temp);
        length++;
    }

public:

    ListDL() : ListDL(true) {}
    ListDL(bool ascend) : head(NULL), tail(NULL), length(0), ascend(ascend) {}

    NodeDL<T> * getHead() const{return this->head;}
    NodeDL<T> * getTail() const{return this->tail;}
    bool isAscending() const{return this->ascend;}
    int getLength() const{return this->length;}

    void insertHead(T value){
        NodeDL<T> * temp = new NodeDL<T>(value);
        if(head == NULL && tail == NULL){
            head = temp;
            tail = temp;
        }
        else{
            temp->setNext(head);
            head->setPrev(temp);
            head = temp;
        }
        length++;
    }

    void insertTail(T value){
        NodeDL<T> * temp = new NodeDL<T>(value);
        if(head == NULL && tail == NULL){
            head = temp;
            tail = temp;
        }
        else{
            temp->setPrev(tail);
            tail->setNext(temp);
            tail = temp;
        }
        length++;
    }

    void insertInOrder(T value){
        if(this->isAscending())
            this->insertAscending(value);
        else
            cout << "to be implemented" << endl;
        return;
    }

    void insert(T x){
        NodeDL<T>* n = new NodeDL<T>(x);
        n->setPrev(nullptr);
        n->setNext(this->head);
        this->head = n;
        length++;

    }

    friend ostream& operator<<(ostream& out, const ListDL<T> list){
        out << "Lista di lunghezza " << list.length << ", head = " << list.head << ", tail = " << list.tail << endl;
        NodeDL<T> * cur = list.head;
        while(cur != NULL){
            out << "\t" << *cur << endl;
            cur = cur->getNext();
        }
        return out;
    }
};


#endif // LISTADL_H_INCLUDED

