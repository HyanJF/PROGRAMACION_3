# DOCUMENTACION DE UN ARBOL

## INVESTIGACION DEL UN "Arbol"

### ¿Que es un "Arbol"?

El Arbol en terminos generales es una estructura de datos no lineales, es decir que estos no siguen una secuencia directa. como lo haria una lista, en las lista secuenciales se puede tener una flexibilidad sobre las representaciones contiguas. 

A diferencia de las estructuras de datos no lineales cada elemento puede tener diferentes secuencias, una desendiente de otra.

### Las definiciones a tener en cuenta son:

**Raíz** del árbol. Todos los árboles que no están vacíos tienen un único nodo raíz. Todos los demás elementos o nodos se derivan o descienden de él. El nodo raíz no tiene padre – es decir, no es el hijo de ningún elemento.

**Nodo** son los vértices o elementos del árbol.

**Nodo terminal u hoja** (leaf node) es aquel nodo que no contiene ningún subárbol.
A cada nodo que no es hoja se asocia uno o varios subárboles llamados 

**Descendientes** (offspring) o hijos. De igual forma tiene asociado un antecesor o ascendiente llamado padre.

Los nodos de un mismo padre se llaman **hermanos**.

Los nodos con uno o dos subárboles – no son hojas ni raíz – se llaman **nodos interiores o internos**.

Una colección de dos o más árboles se llama bosque **forest**.

*Todos los nodos tienen un solo padre – excepto la raíz – que no tiene padre.*

Se denomina **camino** el enlace entre dos nodos consecutivos, y rama es un camino que termina en una hoja.

*Cada nodo tiene asociado un número de nivel que se determina por la longitud del camino desde la raíz al nodo específico.*

*La altura o profundidad de un árbol es el número máximo de nodos de una rama. Equivale al nivel más alto de los nodos más uno. El peso de un árbol es el número de nodos terminales.*

### ARBOLES BINARIOS
 
Para explicar un arbol, necesitamos conocer ademas de su composicion, tambien como se puede representar, los arboles requieren de punteros que nos permitan ubicar las posiciones de cada nodo, en cada rama

### ÁRBOL BINARIO AUTO-BALANCEABLES

En ciencias de la computación, un árbol binario de búsqueda auto-balanceable o equilibrado es un árbol binario de búsqueda que intenta mantener su altura, o el número de niveles de nodos bajo la raíz, tan pequeños como sea posible en todo momento, automáticamente. Esto es importante, ya que muchas operaciones en un árbol de búsqueda binaria tardan un tiempo proporcional a la altura del árbol, y los árboles binarios de búsqueda ordinarios pueden tomar alturas muy grandes en situaciones normales, como cuando las claves son insertadas en orden. Mantener baja la altura se consigue habitualmente realizando transformaciones en el árbol, como la rotación de árboles, en momentos clave.

Tiempos para varias operaciones en términos del número de nodos en el árbol n:

*Operación*	Tiempo en cota superior asintótica

*Búsqueda*	O(log n)

*Inserción*	O(log n)

*Eliminación*	O(log n)

*Iteración en orden*	O(n)

Para algunas implementaciones estos tiempos son el peor caso, mientras que para otras están amortizados.

### GENERALIDADES

Un árbol binario es un conjunto finito de cero o más nodos tales que:
Existe un nodo denominado raíz del árbol.
Cada nodo puede tener 0, 1 ó 2 subárboles, conocidos como subárbol izquierdo y subárbol derecho.

### RECORRIDO DE UN ARBOL

Se denomina recorrido de un árbol al proceso que permite acceder de una sola vez a cada uno de los nodos del árbol. Cuando un árbol se recorre, el conjunto completo de nodos se examina.

Existen muchos modos para recorrer un árbol binario. Por ejemplo existen seis diferentes recorridos generales en un árbol binario, simétrico dos a dos.

Los algoritmos de recorrido de un árbol binario presentan tres tipos de actividades comunes:

Visitar el nodo raíz.
Recorrer el subárbol izquierdo.
Recorrer el subárbol derecho.
Estas tres acciones repartidas en diferentes órdenes proporcionan los diferentes recorridos del árbol. Los más frecuentes tienen siempre en común recorrer primero el subárbol izquierdo y luego el subárbol derecho. Los algoritmos anteriores se llaman pre-orden, post-orden, in-orden, y su nombre refleja el momento en que se visita el nodo raíz. En el in-orden el raíz está en el medio del recorrido, en el pre-orden el raíz está primero y en el post-orden el raíz está el último.

Recorrido pre-orden:

Visitar el raíz.
Recorrer el subárbol izquierdo en pre-orden.
Recorrer el subárbol derecho en pre-orden.
Recorrido en-orden:

Recorrer el subárbol izquierdo en in-orden.
Visitar el raíz.
Recorrer el subárbol derecho en in-orden.
Recorrido post-orden:

Recorrer el subárbol izquierdo en post-orden.
Recorrer el subárbol derecho en post-orden.
Visitar el raíz.
Obsérvese que todas estas definiciones tienen naturaleza recursiva. (Recursiva: Función o Procedimiento que se llama a sí mismo)

## DOCUMENTACION DEL CODIGO

```cpp 
#ifndef AVL_TREE_H
#define AVL_TREE_H
// BIBLIOTECAS 
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<memory>

// Usando template para indicar que puede aceptar cualquier tipo de dato
template <typename T>
// Clase nodo para diseñar la lista
class Node {
public:
    T data; // T el tipo de dato
    // Variable para indicar el tamaño
    int height;
    // Nodos izquierda y derecha de la clase
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
    // Creacion de un nodo de arbol
    Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
};
// La clase Arbol
template <typename T>
class AVLTree {
public:
    // root nos permite manejar la inforacion de nuestro nodo
    std::shared_ptr<Node<T>> root;

    // funcion cuando un ptr es nulo
    AVLTree(): root(nullptr) {}

    // funciones que nos permite agregar, eliminar y inprimir el arbol
    void add(T data) {
        root = insert(root, data);
    }

    void remove(T data)  {
        root = deleteNode(root, data);
    }

    void print() {
        if (root != nullptr) {
            print(root, 0);
        } else {
            std::cout << "The tree is empty." << std::endl;
        }
    }

// Metodos privados
private:
    // Funcion imprimir donde necesitamos el el ptr del nodo, el nodo y un entero que indique el valor
    void print(std::shared_ptr<Node<T>> node, int indent) {
        if(node) {
            if(node->right) {
                print(node->right, indent + 8);
            }
            // setw utilizado para insertar el ancho del siguiente elemento del flujo 
            if (indent) {
                std::cout << std::setw(indent) << ' '; 
            }
            if (node->right) {
                std::cout << " / (Right of " << node->data << ")\n" << std::setw(indent) << ' ';
            }
            std::cout << node->data << "\n" ;
            if (node->left) {
                std::cout << std::setw(indent) << ' ' << " \\ (Left of " << node->data << ")\n";
                print(node->left, indent + 8);
            }
        }
    }

    // Metodo que nos permite agregar un nuevo nodo con el tipo de dato
    std::shared_ptr<Node<T>> newNode(T data) {
        return std::make_shared<Node<T>>(data);
    }
    //Metodo que realiza la busqueda de un puntuero del nodo para analizar y dar valores de lado izquierdo o derecho del nodo
    std::shared_ptr<Node<T>> rightRotate(std::shared_ptr<Node<T>> y) {
        std::shared_ptr<Node<T>> x = y->left;
        std::shared_ptr<Node<T>> T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;

        return x;
    }
    // Mismo caso de busqueda de nodo que permite asignar y dar un valor del nodo, en el que se encuentra ubicado
    std::shared_ptr<Node<T>> leftRotate(std::shared_ptr<Node<T>> x) {
        std::shared_ptr<Node<T>> y = x->right;
        std::shared_ptr<Node<T>> T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;

        return y;
    }
    // Funcion que permite retorno en forma de entero el puntero izquierdo menos el tamaño del puntero derecho.
    int getBalance(std::shared_ptr<Node<T>> N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }
    // Parte la estructura que nos permite acceder a la "data" del puntero de nuestro nodo
    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> node, T data) {
        if (node == nullptr)
            return (newNode(data));

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
    // Recorrido del nodo entre las ramas de nuestro arbol
        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    // Funcion que permite evaluar el valor nuestro nodo
    std::shared_ptr<Node<T>> minValueNode(std::shared_ptr<Node<T>> node) {
        std::shared_ptr<Node<T>> current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }
    // Funcion que permite eliminar el nodo de la estructura arbol
    std::shared_ptr<Node<T>> deleteNode(std::shared_ptr<Node<T>> root, T data) {
        if (!root)
            return root;

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if(data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if(!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }
            else {
                std::shared_ptr<Node<T>> temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
                temp.reset();
            }
        }
        // Eliminar el valor del puntero haciendo lo nulo dependiendo de en que nodo se encuentre
        if(!root)
            return root;
        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
    // El ancho de nuestro arbol y sus nodos
    int height(std::shared_ptr<Node<T>> N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }
    // Funcion de tipo entero que permite saber el valor maximo de nuestro arbol
    int max(int a, int b) {
        return (a > b)? a : b;
    }
};
#endif /* AVL_TREE_H */

```

## BIBLIOGRAFIA

M. Cruz. “Árboles Binarios de Búsqueda en C++ | Recorrido por niveles (Amplitud)”. Martin Cruz. Accedido el 30 de octubre de 2023. [En línea]. Disponible: https://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html

M. Cruz. “Árboles Binarios de Búsqueda en C++ | Recorrido por niveles (Amplitud)”. Martin Cruz. Accedido el 30 de octubre de 2023. [En línea]. Disponible: https://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html
