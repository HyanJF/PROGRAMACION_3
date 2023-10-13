# DOCUMENTACION DE CODIGO "DLLIST".

## CODIGO DE LA DOBLE LISTA
```cpp
#ifndef TEMA_4_5_DLLIST_H
#define TEMA_4_5_DLLIST_H

// BIBLIOTECAS AÑADIDAS
#include <iostream>
#include <utility>

template <typename Object> //Plantilla que nos permite utilizar cualquier tipo de valor primitivo
class DLList {
private:
    struct Node {
        Object data;
        Node *next;
        Node *prev;

        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n}, prev{n} {}

        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n}, prev{n} {}
    };

public:
    class iterator {
    public:
        // Constructor implicito, con iterador nulo.
        iterator() : current{nullptr} {}

        Object &operator*() { // Iterador inicializado para marcar error en caso de falla logica
            if (current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() { // Iterador que permite que se mueva y le la información dentro del nodo
            if (current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) { // Iterador que permite llevar el conteo
            iterator old = *this;
            ++(*this);
            return old;
        }

        // Permite restar valor al iterador
        iterator &operator--() {
            if (current)
                current = current->prev;
            else
                throw std::logic_error("Trying to decrease past the end.");
            return *this;
        }

        iterator operator--(int) {
            iterator old = *this;
            --(*this);
            return old;
        }

        // Permite utilizar los operadores logicos
        bool operator==(const iterator &rhs) const { // Se asigna el operador que permite igualar la posicion
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const { // Se asigna el operador que permite comprobar la diferencia
            return !(*this == rhs);
        }

    private:
        // Nodo al que esta apuntando en este momento
        Node *current;

        iterator(Node *p) : current{p} {}

        friend class DLList<Object>; // Clase friend que permite entrar en el atributo
    };

public:
    // Este apartado nos indica y se asigna los nodos y sus posiciones en la lista enlazada
    DLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    // Nuestro bonito y hermoso destructor, borra el contenido y luego la cabeza y la cola
    ~DLList() {
        clear();
        delete head;
        delete tail;
    }

    // Nos indica quien es el principio y el final
    iterator begin() { return {head->next}; }

    iterator end() { return {tail}; }

    // Int para asignar el tamaño de nuestra lista
    int size() const { return theSize; }

    bool empty() const { return size() == 0; }

    // Mientras no este vacia la lista, borra el elemento que se encuentre al frente
    void clear() { while (!empty()) pop_front(); }

    // Si la lista esta vacia entonces nos devolvera el valor inicial o te dara un error.
    Object &front() {
        if (empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    // Funciones que permiten insertar un valor en el principio de la lista
    void push_front(const Object &x) { insert(begin(), x); }

    // push por copia
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

    //Funcion que permite insertar valores en el final de la fila
    void push_back(const Object &x) { insert(end(), x); }

    // push por copia
    void push_back(Object &&x) { insert(end(), std::move(x)); }

    void pop_front() {
        if (empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    // Iterador que permite agregar un valor en una posicion específica.
    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    // Iterador que asigna los valores en la posicion específica.
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }


    //Funcion para insertar datos
    void insert(int pos, const Object &x){
        insert(get_iterator(pos), x);
    }

    iterator get_iterator(int y){
        iterator Z = begin();
        for(int i = 0; i != y; i++ )
        {
            ++Z;
        }
        return Z;
    }

    // Iterador que borrar la información en la posicion en la que se le asigna.
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

    void erase(int pos)
    {
        erase(get_iterator(pos));
    }

    // Funcion que permite imprimir la información de la posicion en la que se encuentra el iterador
    // Nuestro getter
    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }
private:
    // Nodos y el tipo de datos que va a corresponder a cada constructor y operador
    Node *head;
    Node *tail;
    int theSize;
    // Constructor con las condiciones iniciales.
    void init() {
        theSize = 0;
        head->next = tail;
    }
};

#endif //TEMA_4_5_DLLIST_H
```

## INVESTIGACION RAPIDA

### ¿Ques la lista de dobleenlaze?

1. Es un tipo de lista enlazada que permite moverse hacia delante y hacia atras.
2. Cada nodo de una lista doblemente enlazada tiene dos enlaces, ademas de los campos de datos. Un enlace, el derecho, se utiliza para navegar la lista hacia delante. El otro enlace, el isquierdo, se utiliza para navegar la lista hacia atras.
3. Las Listas pueden navegarse hacia delante y hacia atras.
4. Las Listas pueden crear, actualizar y eliminar elementos.
5. En las Listas la posicion de los elementos es relevante.
6. Las Listas admiten elementos duplicados.
7. Las Listas tienen dos protocolos, uno secuencial y el otro directo.

## BLIOGRAFIA

Estructura de Datos : Lista Enlazada Doble. (s.f.). Sitio Oficial de la F C E I A. https://www.fceia.unr.edu.ar/estruc/2005/listendo.htm

LISTAS DOBLEMENTE-ENLAZADAS. (s.f.-a). https://ccia.ugr.es/~jfv/ed1/tedi/cdrom/docs/ldoble.html