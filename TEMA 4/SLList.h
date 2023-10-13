#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream> //Bibliotecas añadidas al proyecto
#include <utility>
// Debugin es el metodo que detiene el codigo y no se ejecuta.
template <typename Object> //La plantilla de nuestra clase, con el nombre de nuestros tipos
class SLList { // Nombre de la clase
private: //Tipo de funciones
    //Cada Cuadrado
    struct Node  {
        Object data; // Data es un tipo de funcion como metodo para contener y en algoritmos
        Node *next; // Anya UwU

        // Esto nos permite ubicar el siguiente Nodo
        // De la lista
        // Constructores de copia y referencia
        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {}

        Node(Object &&d, Node *n = nullptr)
            : data{std::move(d)}, next{n} {}
    };

public: //Esta clase puede ser utilizada por cualquier llamada fuera de la clase
    class iterator { // Nuestra clase para inicializando el iterator
    public:
        // Constructor implicito, con iterador nulo.
        iterator() : current{nullptr} {}

        Object &operator*() { // Iterador inicializado para marcar error en caso de falla logica
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() { // Iterador que permite que se mueva y le la información dentro del nodo
            if(current)
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
        friend class SLList<Object>; // Clase friend que permite entrar en el atributo
    };

public:
    // Este apartado nos indica y se asigna los nodos y sus posiciones en la lista enlazada
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }
    // Nuestro bonito y hermoso destructor, borra el contenido y luego la cabeza y la cola
    ~SLList() {
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
    // Iterador que asigna los valores en la posicion específica.
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
    // Nuestro getter
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
    // Constructor con las condiciones iniciales.
    void init() {
        theSize = 0;
        head->next = tail;
    }
};
#endif
