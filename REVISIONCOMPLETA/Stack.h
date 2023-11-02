#ifndef REVISIONCOMPLETA_STACK_H
#define REVISIONCOMPLETA_STACK_H

#include "DLList.h"
template <typename Iterator>
class Stack : private DLList<Iterator> {
public:
    Stack() {
    }

    ~Stack(){
        clear();
        delete DLList<Iterator>::head;
        delete DLList<Iterator>::tail;
    }

    void push(Iterator &data){
        DLList<Iterator>::push_front(data);
    }
    void push(Iterator &&data){
        DLList<Iterator>::push_front(data);
    }

    void pop(){
        DLList<Iterator>::pop_front();
    }

    void clear(){
        DLList<Iterator>::clear();
    }

    void print(){
        DLList<Iterator>::print();
    }

    Iterator top(){
        return DLList<Iterator>::head->next->data;
    }
};

#endif //REVISIONCOMPLETA_STACK_H
