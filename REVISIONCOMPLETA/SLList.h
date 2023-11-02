#ifndef REVISIONCOMPLETA_SLLIST_H
#define REVISIONCOMPLETA_SLLIST_H

#include <iostream>
#include <utility>

template <typename Object>
class SLList {
private:
    //Estructura del nodo
    struct Node  {
        Object data;
        Node *next;//Anya

        //Constructor de copia
        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n} {}

        //Constructor de referncia
        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n} {}
    };

public:
    class iterator {
    public:
        //constructor implicito, se hace nulo el puntero
        iterator() : current{nullptr} {}

        //Operador * para darle forma a nuestro puntero
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        //Movimiento
        //Operador para poder moverse por la lista
        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        //Posicion
        //lee la posicion en la que va
        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        //Operadores para comparar
        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }
        //Operador para decir que es diferente
        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    private:
        //apunta al nodo al que estoy trabajando en ese momento
        Node *current;
        iterator(Node *p) : current{p} {}
        //la clase amigo de acceso a los atributos privados
        friend class SLList<Object>;
    };

public:
    //Dimencion de la lista
    //Se llama al nodo de la cabeza y la cola de la lista ya defina
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    //Destructor de la lista
    //Elimina el contenido comenzando con la cabeza, hasta la cola
    ~SLList() {
        clear();
        delete head;
        delete tail;
    }

    //Sirve para meter el iterador al principio o al final
    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    //El tamaño de nuestra lista para que el iterador pueda hacer el recorrido
    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    //Si la lista no esta vacía borra el objeto enfrente
    void clear() { while (!empty()) pop_front(); }

    //Si la lista esta vaciá da un error, si no vuelve al inicio
    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    //funcion de agregar por copia
    void push_front(const Object &x) { insert(begin(), x); }
    //funcion de agregar por referencia
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

    //elimina el valo de en frente
    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    //Reciben un iterador para leer la posicion y insertar el dato en la pocision
    //Funcion por copia
    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    //Funcion por referencia
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }

    //Toma el iterador para eliminar el dato en la posicion que le demos
    iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    //Funcion para imprimir toda la lista
    void printList() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    Node *head;
    Node *tail;
    int theSize;
    void init() {
        theSize = 0;
        head->next = tail;
    }
};

#endif //REVISIONCOMPLETA_SLLIST_H
