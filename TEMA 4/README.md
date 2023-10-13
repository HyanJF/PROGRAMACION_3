# DOCUMENTACION DE CODIGO "LIST".

## INVESTIGACION DEL TEMA "List".

### ¿Que es una "List"

Son secuencias de elementos almacenados en una lista encadenada. Comparadas con los vectores, estas permiten una mayor rapidez de inserción y borrado, pero una menor velocidad de acceso aleatorio.

### CREACION DE UNA LITS

```cpp 
template <class Type, class Allocator= allocator<Type>>
class list
```

### GLOSARIO

<font color='red'>*Type*</font>
El tipo de datos de elementos que se almacenará en la lista.

<font color='red'>*Allocator*</font>
El tipo que representa el objeto asignador almacenado que encapsula los detalles sobre la asignación y la desasignación de memoria de la lista. Este argumento es opcional y el valor predeterminado es allocator<Type>.

<font color='red'>*const_iterator*</font>
Tipo que proporciona un iterador bidireccional que puede leer un elemento const de una lista.

<font color='red'>*iterator*</font>	
Tipo que proporciona un iterador bidireccional que puede leer o modificar cualquier elemento de una lista.

<font color='red'>*erase*</font>
Quita un elemento o un intervalo de elementos de una lista de las posiciones especificadas.

<font color='red'>*front*</font>
Devuelve una referencia al primer elemento de una lista.

### CODIGO DOCUMENTADO

```cpp
#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream> //Bibliotecas añadidas al proyecto
#include <utility>

template <typename Object> //La plantilla de nuestra clase, con el nombre de nuestros tipos
class SLList { // Nombre de la clase
private: //Tipo de funciones
    //Cada Cuadrado
    struct Node  {
        Object data; // Data es un tipo de funcion como metodo para contener y en algoritmos
        Node *next; // Anya

        // Esto nos permite ubicar el siguiente Nodo
        // De la lista
        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {}

        Node(Object &&d, Node *n = nullptr)
            : data{std::move(d)}, next{n} {}
    };

public: //Esta clase puede ser utilizada por cualquier llamada fuera de la clase
    class iterator { // Nuestra clase para inicializando el iterator
    public:
        iterator() : current{nullptr} {}

        Object &operator*() { // Iterador inicializado para marcar error en caso de falla logica
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() { // Iterador que permite sumar y aumentar la posicion del iterador
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) { // Iterador que permite y asigna un valor para cambiar la posicion
            iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const iterator &rhs) const { // Se asigna el operador que permite igualar la posicion
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const { // Se asigna el operador que permite comprobar la diferencia
            return !(*this == rhs);
        }

    private:
        Node *current;
        iterator(Node *p) : current{p} {}
        friend class SLList<Object>; // Clase friend que permite señalar el objeto
    };

public:
    // Este apartado nos indica y se asigna los nodos y sus posiciones en la lista entrelazada
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }
    // Nuestro bonito y hermoso destructor
    ~SLList() {
        clear();
        delete head;
        delete tail;
    }
    // Constructores que permiten reorganizar y limpiar la lista una vez eliminado un valor
    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void clear() { while (!empty()) pop_front(); }

    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }
    // Funciones que permiten insertar un valor en el principio de la lista
    void push_front(const Object &x) { insert(begin(), x); }
    void push_front(Object &&x) { insert(begin(), std::move(x)); }
    // Funcion que permite eliminar el primer elemento de la lista sin alterar el orden
    void pop_front() {
        if(empty())
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
    // Iterador que asigna los valores L en la posicion específica.
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
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
    // Funcion que permite imprimir la información de la posicion en la que se encuentra el iterador
    void printList() {
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
    void init() {
        theSize = 0;
        head->next = tail;
    }
};
#endif
```