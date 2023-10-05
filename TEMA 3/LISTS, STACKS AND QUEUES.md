# RESUMEN LIBRO LISTS, STACKS AND QUEUES

## 3.1 Abstract data types (TIPOS DE DATOS ASTRACTOS "ADTs)

Los datos astractos como tal son un conjunto de objetos junto con un conjunto de operaciones.

Estos son datos abstractos matematicas, es decir que estos pueden verse los valores enteros, reales y boleanos. estos a su vez pueden tener operaciones como lo son (add) agregar, (remove) eliminar, (size) dimensionar y (contains) contener.

Estos datos caen en una misma categoria, la cual se le conoce como primitivos, al ser la forma mas basica en la que se pueden descomponer.
 
Agregar: Como su nombre lo dice nos permite introducir los datos a nuestra lista.
Eliminar: Como agregar, nuestros datos podria ser elinimados para el añadir una nueva serie de datos.
Dimensionar: Podemos decir que nos permite saber el tamaño de nuestros datos abstractos.
Contener: Con este metodo podemos almacenar en una forma de lista nuestros datos.

Los arreglos son una forma de organizar y agregar datos, aunque sin duda esta es una de las formas menos eficientes al tener este un tamaño fijo.

```cpp
int main 
{
    int num[5] = {1,2,3,4,5};
    // Esta es una forma de inicializar un arreglo.
    // Para utilizar un arreglo necesitamos darle el tamaño
    // Los tados tienen que ser añadidos de otra forma.
    for (int x = 0;1<=5; x++)
    {
        cout << num[x] << endl; // Imprime los datos
    }
}
```

Ejemplo de una estructura con datos abstractos personalizados

```cpp
#include <iostream>
using namespace std;

//ADT con datos personalizados
struct{
    string name;
    int day;
    int month;
    int year;
}

int main{
    cin >> date.name;
    cin >> date.day;
    cin >> date.month;
    cin >> date.year;
}
```

## 3.2 LA LISTA ADT

En este apartado tenemos como principal concepto la lista y algunas funciones o metodos para nuestra administacion de lista de los ADT

Usando una listsa del tipo **AN-1** para ejemplificar.
es decir una lista que sigue el metodo este metodo
A0, A1, A2...,AN-1 

**A=** *Datos de la secuencia desde 0 o cualquier valor, hasta su limite*

**N** *Tamaño de nuestra lista*

**A1** *Primer elemento de nuestra lista*

**AN-1** *Ultimo elemento de nuestra lista*

**Ai** *Se define como la posicion de nuestra lista*

**if (N=0)** *Entonces la lista esta vacia*

Una forma de organizar la imformacion seria.

$$ -A^{i-1} $$ 
precede a 
$$ A^1 $$

$$ A^i $$
le sigue a 
$$ A^{i-1} $$

Las listas de ADT cuenta con sus propias operaciones
como lo podrian ser **printList** y **makeEmpty**

```cpp
int main
{
    std::PrintList(&list);

    std::MakeEmpty(&list);
}
```
 
La funcion **find** nos devulve la primera aparicion de un elemento en la lista. 

```cpp
int main
{
    std::find(&lits);
}
```

Y como añadido podemos emplear la funcion de find_if para una busqueda con parametro.

```cpp

int main
{
    std::find_if(&list);
}
```

La funcion **insert** y **remove** como su nombre lo dice agrega y elimina elemntos de nuestra lista con la siguiente sintaxis

```cpp
int main
{
    // Para insertar la sintaxi que se puede usar son:

    //Esta sintaxis permite agregar un elemento al conjunto.
    set_name.insert(element);

    //Esta sintaxis se le asigna una posicion en la cual 
    //colocar el nuevo elemento.
    set_name.insert(hint_position, element);

    //Con esta sintaxis debemos añadir elementos de otros 
    //contenedores para que los elementos repetidos no se  
    //vuelvan a insertar. 
    set_name.insert(begin_iterator, end_iterador);

    //Una forma para eliminar datos de la lista
    set_name.remove(data);
}
```

### 3.2.1 Implementacion de matrices simples de listas

Se nos dice que en la mayoria de los casos los metodos, pueden ser empleados de forma sencilla si se usa una matriz, pero se sabe que las matrices tienen una capacidad fija, en el caso de una **clase vectorial** se puede usar para crear mas espacio para implementacion de datos.

En el caso de las funciones **findKth** (**Kth** *Minimo y Maximo elementos en un arreglo o matriz*) y **PrintList** pueden llevarse acabo con un tiempo lineal y constante.

Pero para las funciones **Insert** y **remove** se presentan una serie de casos particulares.

el caso que se quiera inserta un valor en la posicion 0 **Su costo sera mucho mayor**, puesto que en este caso se movera toda la lista hacia arriba para insertar el nuevo valor.

el caso donde insertamos 0(N) *N tamaño de la lista* usualmente se insertan en el centro de nuestra lista y se moveran en ambos casos. 

el caso donde insertamos 0(1) se añadira el nuevo valor en un extremo de la lista, donde no sera necesario mover ningun otro elemento ahorrando tiempo.

### 3.2.2 Listas enlazadas simples

La lista enlazada permite un costo menor que en una matris, al no seguir una direccion contigua, con la implentacion de nodos que hacen que la lista no sigua una cadena fija y no sea necesario mover todos los elementos de nuestra lista.

Permitiendo que al usar **printList()** o **find(x)** sea constante, aunque actua igual que en una matriz, esta operacion es de tiempo lineal.

Para el metodo **insert** necesitamos de crear un nuevo nodo en la lista mediante un nueva llamada, para dejarlo mas claro al insertar o eliminar un elemento, no se requieren hacer tantos cambios, y solo se realiza un cambio de constantes en los enlaces de nodos.

*Eliminar o agregar al frente* Este caso especial es mas sencillo al solo asignarle el lugar como una constante.

*Eliminar o agregar al final* Este caso se debe tomar en cuenta si nuestra lista mantiene un enlace con nuestro valor final, se puede asignar un nuevo valor al final, pero es mas complicado eliminar, puesto que tienes que encontrar el penultimo elemento, cambiar su siguente enlace a **nullptr** (es decir valor de puntero nulo) y luego actualizar el enlace que mantiene el ultimo elemento. 

## 3.3 Vector y lista en STL

**STL** corresponde a una de las bibliotecas de C++ o tambien conocida como Standard Template Library, es una de las bibliotecas de software la cual incluye entre su contenido los componentes, conocidos como algoritmos, contenedores, iteradores y funciones.

En este caso tenermos al **Vector** que da un crecimineto en la matriz, su utilizacion permite ser mas constante con el tiempo, pero en su contra se encuentra que el agragar y eliminar elementes son muy costosos, por su parte la **Lista** permite agregar y eliminar datos de forma mas barata, siempre que se conozca la posicion que se quiera modificar. 

Algo que tienen en comun que es ambos son malos para la realizacion de busquedas, pero por otro lado estos dos, cuenta con funciones en comun, las tres mencionadas son 

```cpp
int main
{
    int size() const; // Que nos devuelve el numero de elementos en nuestro contenedor
    void clear(); // Elimina los elementos o elemento del contenedor
    bool vacio() const; //Devuelve un verdadero si el contenedor no contiene ningun dato y falso de lo contrario.
}
```

los metodos para agregar y quitar elementos, tanto al final como al principio son:

```cpp
int main
{   
    // Con esta funcion podemos agragar un valor mas al
    // Final de nuestra lista 
    void push_back (const Object & x);
    // Con esta funcion eliminamos el ultimo valor de la
    // Fila
    void pop_back();
    // La funcion devuelve el objeto al final de la lista
    // A la par genera una nueva referencia
    const Object & back() const; 
    // Retorna el objeto al inicio de la lista, y genera 
    // Una nueva referencia
    const Object & Front() const; 
}
```

En los siguientes casos las funciones solo estan disponibles para las listas dobles enlazadas.

```cpp
int main
{
    // Añade un objeto mas al inicio de fila 
    void push_back( const Object & x);
    // remueve un objeto de la lista
    void pop_front();
}
```

Y a su vez los Vectores tambien cuentan con sus propios metodos para la lista, entre los metodos se encuentran 2 que permiten indexacion eficiente y los otros 2 metodos permiten al programador ver y cambiar la capacidad interna.

```cpp
int main
{
    Object & operator[] (int idx); // Devuelve el objeto en el idx, del vector sin necesidad de una verificacion de limites
    Object & at (int idx); // Devuelve el objeto en el indice idx con limites y se proporciona un descriptor de acceso
    int capacity() const; // devuelve la capacidad interna del vector
    void reserve (int newCapacity); // Establece una nueva capicadad y puede ayudar a evitar la sobre expacion del Vector 
}
```

### 3.3.1 Iteradores

Un iterador es un contador que se encarga de dar la ubicacion y decir en que posicion nos encontramos y darnos cuenta si estamos avanzando y recorrer la clase.

Para comenzar con el tema debemos saber que tanto las lista como de un vector, para esto hay que tener en cuenta 3 cuestiones como los son, como se consigue un vector, cuales son las operaciones o funciones de los iteradores y la lista de metodos ADT que requieren iteradores como parametros.

**OBTENER UN ITERADOR**

Las listas STL, pueden requerir de estos metodos:

```cpp
int main
{
    iterator begin(); // Este iterador devuelve el primer elemento del contenedor
    iterador end(); // ESte iterador devuelve el ultimo elemento del contenedor

    // En el siguiente codigo se explica mas a detalle el metodo Iterador end();

    for (int x = 0; x != v.size(); ++x)
    {
        cout << v[i] << endl;
    }

    // Reescribimos el codigo para introduccir los metodos mencionados 

    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr.???) // 1. se llama al iterador, despues decimos donde va a comenzar y luego se le coloca el limite, con v.end (dejara de repetir hasta que sean iguales), al final solo dice cuanto pasos va a dar el "for
    {
        cout << irt.??? << endl;
    }
}
```
Con este codigo, comprobamos si nuestro vector se pasa del limite.

**METODOS DE UN ITERADOR**

Ahora veremos algunos metodos que podemos emplear para nuestro Iteradores, como lo son los siguientes.

```cpp
int main
{
    itr++; y ++itr; // Nos pemirte avanzar en la siguiente ubicacion. ++ tiene como significado 
    *itr; // Nos permite devolver la ubicacion del iterador, en un referencia que puede ser modificable.
    itr1 == itr2; // Se encarga de comparar los itr, para saber si se refieren a la misma ubicacion y en caso contrario devuelve falso
    itr1 != itr2; // Se encarga de comparar los itr, para saber si tienen una ubicacion diferente y en caso contrario devuelve falso

    // Ahora utilizaremos estos metodos para crear un nuevo codigo.

    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << endl;
    }
}
```

**OPERACIONES DE CONTENEDORES QUE REQUIEREN ITERADORES**

Entre otra serie de iteradores podemos necesitar de aquellos que permitan agregar y/o eliminar valores de la lista, como lo son:

iterator insert(iterator pos, const Object & x): **Añade un elemento x en la posicion indicada, de tiempo constante para list pero no para Vector**

iterator erase(iterator pos): **Elimina el valor en la posicion dada, es de tiempo constante para list, pero no para Vector, devuelve el valor siguiente de nuestro valor borrado**

iterator erase(iterator start, end): **Se encarga de borrar toda la lista, aunque incluso puede solo eliminar el principio y el final**

### 3.3.2 EJEMPLO: USAR BORRADOR EN UNA LISTA

En el libro, se nos muestra un ejemplo, de como usar el sistema de borrado en una lista de 5 valores, siendo 6,5,1,4,2 al final solo tendremos los valores de 5 y 4, en una list, el metodo es de tiempo lineal, en un vector su tiempo escala a cuadratico, dejando en claro que los metodos se vuelven ineficientes usando tiempo **0(N)**, usaremos el siguente codigo como referencia, dado por el libro.

```cpp
int main
{
    template <typename Container>
    void removeEveryOtheritem( Container & lst)
    {
        auto itr = lst.begin(); // iter es un metodo del tipo Container::iterator
        while (itr != lst.end())
        {
            itr = lst.erase(itr );
            if(itr != lst.end())
                ++itr;
        }
    }
}
```
EL codigo permite eliminar los elementos de una lista o vector, claro con sus diferencias, efeciente para list pero no para Vector.

### 3.3.3 Itereadores constantes (const_iterators)

Sin duda los iteradores como lo hemos visto son de los metodos mas optimos para una buena forma de llevar acabo una lista o vector, donde necesitaremos claramente de modificar estos datos, el siguiente ejemplo proporcionado por el libro nos deja una forma facil y buena para escribir codigo generecio.

```cpp 
int main
{
    template <typename Container, typename Object>
    void change( Container & c, const Object & newValue )
    {
        typename Container::iterator itr = c.begin();
        while(itr != c.end())
        *itr++ = newValue;
    }
}
```

Mas adelante tenemos un ejemplo en caso de que nuestra propia lista.

```cpp
void print( const list<int> & lst, ostream & out = cout )
{
    typename Container::iterator itr = lst.begin();
    while(itr != lst.end())
    {
        out << *itr << endl;
        *itr = 0; // Esto no tiene sentido segun veo
        ++itr;
    }
}
```

Como podemos ver este codigo contiene un error fatal, pues estamos cambiando la direccion a 0, perdiendo la constancia de la lista.
Bien ahora si cual es la diferencia entre un iterador y un const_iterator, es que el operador* para const_iterator, devuelve una referencia constante, con lo que, podemos decir que *itr para const_iterator no puede encontrarse del lado izquierdo en un declaracion, sin contar que el const_iterator para recorrer otra constante.
Lo hace proporcionando dos versiones de inicio y dos versiones de fin, como se muestra a continuacion.

iterator begin();

const_iterator begin() const;

iterator end();

const_iterator end() const;

Posteriormente tenemos que saber que ambos metodos, pueden ser agrador a un mismo programa, con la idea de que si un iterador es empleado, se devolvera un iterador, mismo caso que con un const_iterator, nos devolvera un const_iterator, obvio si intentamos mezclarlos el resultado nos dara un error de compilacion.

En las clases como sabemos tenemos funciones que podemos usar para ambos tipos tanto vector, como list.
Que nos permite utilizarlo en caso de que nuestro contenedor no tiene funciones de miembro inicial y final.
Las opciones de inicio y fin estan definidas que permiten usar, begin(c); donde usar c.begin(); permite utilizar metodos en contenedores que tienen un begin/end como miembros, como aquellos que no tienen begin/end para luego poder amplearlas.

```cpp
template <typename Container>
void print( const Container & c, ostream & out = cout)
{
    if(c.empty())
    {
        out << "(empty)";
    }
    else 
    {
        auto itr = begin(c); // Este itr es del tipo Container::const_iterator

        out << " [ " << *itr++; // Esta linea imprime el primer elemento
        while( itr != end(c))
            out << ", " << *itr++;
        out << " ] " << endl;
    }
}
```
Para este codigo, se emplean metodos del tipo inicio y fin como funciones libres.

```cpp
int main
{
    template<typename Container> // El metodo template, sirve como una plantilla de funcion, que puede usarse mas adelante.
    auto begin( Container & c) -> decltype(c.begin())
    {
        return c.begin();
    }

    template<typename Container>
    auto begin( const Container & c) -> decltype(c.begin())
    {
        return c.begin();
    }
}
```

En este codigo señalamos el metodo begin(); dandonos un retorno de inicio.

## 3.4 IMPLEMENTACION DE VECTORES

Para comenzar debemos entender y comprender a grandes rasgos que es un vector, los vectores se puede decir que son una matriz, con una serie de datos ya sea del tipo primitivo como objetos, esto depende la situacion, con el objetivo de almacenar multiples valores en una sola variable.

```cpp
#include <iostream>
#include <vector>
int main
{
    // vector sin inicializar, del tipo entero
    vector<int> Numeros;
}
```

Los detalles mas notables del libro es que se nos enseña en gran medida una forma de implementar un vector en un codigo, a su vez que se nos enseña una serie de caracteristicas que estas pueden llevar y sircunstancias que pueden llegar a ocurrir.

Debemos entender que la matriz es una variable puntero de un bloque de memoria y este debe estar separado de nuestra memoria real, y este puede ser asignado mediante el metodo de new[] a la par que se puede usar el motodo de delate[] para liberar la memoria, este se puede entender mas adelante, en la esplicacion de codigo, utilizando una pantilla, templace vector. 
Los siguientes detalles seran de importancia para entender mejor a los vectores.

1. El vector tendra una matriz primitiva, atravez de una varibale de puntero al bloque de memoria, con la capacidad de la matriz y los elementos almacenados dentro de el vector.
2. En el codigo volveran los cinco grandes, los cuales nos permitiran tener una referencia y copia profunda, al igual que los constructores y operadores del = y añadir un destructor para recuperar la matriz primitiva.
3. El vector contara con la capacidad de cambiar el tamaño de nuestro vector, en un nuevo bloque donde se almacenara los datos, para recuperar el antiguo bloque.
4. Se puede implementar un operador como un accesor y mutador, para el vector.
5. El vector como sabemos necesita de espacio para evitar la sobre carga, con esto se implentara metodos de pop_back y push_back, para saber si es igual o a alcanzo el espacio maximo.
6. Se agragaran metodos para los tipos anidados iterador y const_iterador.

```cpp
1 #include <algorithm>
2
3 template <typename Object> //"template" termino utilizado para plantillas, que permite el uso de clases y funciones que trabajan con tipos genericos
4 class Vector //Nombre de nuestra clase
5 {
6 public:
7 explicit Vector( int initSize = 0 ) : theSize{ initSize },
8 theCapacity{ initSize + SPARE_CAPACITY }
9 { objects = new Object[ theCapacity ]; } // En este apartado podemos ver un constructor que permite asignar un tamaño a nuestro vector y almacenarlo en una variable
10 // Constructor que permite, comprobar el tamaño de nuestro vector
11 Vector( const Vector & rhs ) : theSize{ rhs.theSize },
12 theCapacity{ rhs.theCapacity }, objects{ nullptr } 
13 { // Esto representa un valor de un puntero nulo.
14 objects = new Object[ theCapacity ];
15 for( int k = 0; k < theSize; ++k )
16 objects[ k ] = rhs.objects[ k ];
17 }
18 
19 Vector & operator= ( const Vector & rhs ) // Operador para indicar que hacer con el =, esto se encargara de asignar el valor de lados derecho a la variable que se encuentre en el lado izquierdo
20 {
21 Vector copy = rhs;
22 std::swap( *this, copy );
23 return *this;
24 }
25
26 ~Vector( ) // Nuestro destructor
27 { delete [ ] objects; }
28 // constructor que permite la copia de nuestro vector en un valor L
29 Vector( Vector && rhs ) : theSize{ rhs.theSize },
30 theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
31 {
32 rhs.objects = nullptr;
33 rhs.theSize = 0;
34 rhs.theCapacity = 0;
35 }
36 // Operador igual para los valores del tipo L
37 Vector & operator= ( Vector && rhs )
38 {
39 std::swap( theSize, rhs.theSize );
40 std::swap( theCapacity, rhs.theCapacity );
41 std::swap( objects, rhs.objects );
42
43 return *this;
44 }
45 // Trate de documentar, relacionando con lo que tengo entendido.
void resize( int newSize ) // esta funcion permite cambiar el tamaño por uno nuevo, el cual se multiplica por 2 
47 {
48 if( newSize > theCapacity )
49 reserve( newSize * 2 );
50 theSize = newSize;
51 }
52 // La reserva nos permite guardar espacio en nuestro vector
53 void reserve( int newCapacity )
54 {
55 if( newCapacity < theSize )
56 return;
57 // newArray permite introducir una nueva capacidad de nuestro vector.
58 Object *newArray = new Object[ newCapacity ];
59 for( int k = 0; k < theSize; ++k )
60 newArray[ k ] = std::move( objects[ k ] );
61 // Aqui eliminamos los datos del vector viejo para moverlo a nuestro nuevo vector
62 theCapacity = newCapacity;
63 std::swap( objects, newArray );
64 delete [ ] newArray;
65 }
66 // Operadores de saber cual es el tipo de valor con el que trabajara
67 Object & operator[]( int index )
68 { return objects[ index ]; }
69 const Object & operator[]( int index ) const
70 { return objects[ index ]; }
71 // variables que funcionan como parametros de nuestros metodos
72 bool empty( ) const
73 { return size( ) == 0; }
74 int size( ) const
75 { return theSize; }
76 int capacity( ) const
77 { return theCapacity; }
78 // Nuestra funcion para agregar un valor mas a nuestro vector en la parte de atras.
79 void push_back( const Object & x )
80 {
81 if( theSize == theCapacity )
82 reserve( 2 * theCapacity + 1 );
83 objects[ theSize++ ] = x;
84 }
85 // Funcion para agrgar un valor extra en forma de copia.
86 void push_back( Object && x )
87 {
88 if( theSize == theCapacity )
89 reserve( 2 * theCapacity + 1 );
90 objects[ theSize++ ] = std::move( x );
91 }
92 // Funcion que elimina un valor de nuestro vector.
93 void pop_back( )
94 {
95 --theSize;
96 }
97 // Iteradores que permite recorrer el arreglo y obtener los datos dentro de cada punto.
98 const Object & back ( ) const
99 {
100 return objects[ theSize - 1 ];
101 }
102
103 typedef Object * iterator;
104 typedef const Object * const_iterator;
105 
106 iterator begin( )
107 { return &objects[ 0 ]; }
108 const_iterator begin( ) const
109 { return &objects[ 0 ]; }
```

En esta primera parte del codigo tenemos una implementacion de vector donde contiene su operador para comparar datos.

## 3.5 IMPLEMENTACION DE UNA "LIST"

Para comenzar que es una "list" como tal la lista es un clase de contenedor de secuencias de elementos lienales y nos da la posibilidad de añadir y eliminar de manera mas eficiente que un arreglo en cualquiera de las posiciones de nuestros elementos de la secuencia.

```cpp
template <clase Type, class Allocator = allocator<Type>>
class list
```

Una sintexis para indicar que lo que estamos creando es una list.

**Type** El tipo de datos que se almacenaran en la lista.

**Allocator** El tipo que representa el objeto asiganador almacenado.

Para este apartado buscaremos realizar una plantilla funcional para un list, de tipo entrelazada, Debemos tener en cuenta que el diseño, se implementaran 4 clases, siendo las siguientes:

1. La clase list, contendra los enlaces que unen los extremos de la lista de par a par, el tamaño de nuestra lista y el host (un conjunto de nombres de las variables), como almacen.
2. Nuestra clase nodo, un tipo de clase anidada, nodo (estos contiene la informacion de los datos) y punteros del anterior y siguien nodo, junto con los constructores.
3. la clase Iterador, este nos permite apuntar al nodo, en el que nos encontremos, junto con la implementacion de los operadores basicos, como lo son el =, equivalente ==, diferente de != y aumentar valor ++.
4. Y por ultimo un iterador, que nos dara una referencia del valor en el que se encuentra, la diferencia con el const_iterator es que no devuelve una referencia constante a el objeto.

Recordemos que al trabajar con un iterador constante, que nos ayuda con un puntero a almacenar la posicion inicial y la posicion final, una recomendacion es la crear un nodo extra a cada lado conocido como "sentinel nodes" *Los sentinel nodes, son nodos que no conienen ni hacen referencia ningun tipo de dato de la lista doblemente enlazada*, las ventajas que obtenemos del nodo sentinela son:
1. Al agregar los nodos centinela a la lista doblemente enlazada ahora para eliminarlos o insertarlos al principio, al final o entre los nodos iniciales y finales de la lista enlazada, no necesitamos escribir las diferentes condiciones para cada uno.
2. Todas estas operaciones se pueden realizar como eliminar o insertar entre el nodo inicial y final de una lista doblemente enlazada.

Ahora comenzaremos a darle forma a nuestra list.

```cpp
template <typename Object>
class List
{
private: // Se vuelve privado para que el usuario no pueda modificarlo
struct Node // Comenzamos primero con la aplicacion de nuestra plantila
    {  
        // Comenzamos asignado Nodes y sus respectivas asignaciones
        Object data;
        Node *prev;
        Node *next;

        Node( const Object & d = Object{}, Node * p = nullptr,
            Node * p = pullptr;)
            : data { d }, prev{ p }, next { n } {  }
        Node( Object && d , Node * p = nullptr, Node * n = nullptr)
            : data { std::move (d) }, prev{p}, next{n} {}
    };
public: 
class const_iterator // Creamos una nueva clase 
    { 
        public: // Asignamos los miembros de tipo publico
        const_iterator() : current { nullptr} 
        {}

        const Object & operator* () const //operador que nos permite adquierir la referencia de nuestro objeto
        { return retrieve();}

        // Operador para asignar la capacidad a nuestra lista para aumente el valor en 1.
        const_iterator & operator++ () 
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++ ( int )
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }
        // Operadores que se encargan de comparar y devolver un valor de acuerdo a cual sea la respuesta
        bool operator== (const const_iterator & rhs ) const
            { return current == rhs.current; }
        bool operator!= (const const_iterator & rhs ) const
            { return !(*this == rhs);} 
        
        protected: //Permite ser visible en cualquiera de sus clases donde se define.
        Node *current;

        Object & retrieve() const
            { return current->data;}
        
        const_iterator(Node *p) : current{p}
        {}
        friend class List<Object>; // Segenera una nueva subclase.
    };
class iterator : public const_iterator // Asignacion de la clase iterador, es decir el metodo que ayuda recorrer la list
    { 
        public:
        iterator()
        {}
        // Permite al iterador conseguir la memoria y la informacion dentro del espacio al que esta apuntando.
        Object & operator* ()
            { return const_iterator::retrieve(); }
        const Object & operator* () const
            { return const_iterator::operator*(); }

        // Operador que se encarga de darle la capacidad al iterador de sumar constantemente asi mismo.
        iterator & operator++ ()
        {
            this->current = this->current->next;
            return *this;
        }    

        iterator operator++ ()
        {
            iterator old = *this;
            ++(*this);
            return old;
        }
        protected:
        iterator(Node *p) : const_iterator{ p }
        {}
        friend class List<Object>;
    };
public:
List( )
    {  
        {init();}

        ~List() // Sistema que permite eliminar un elemento de la lista
        {
            clear();
            delete head;
            delete tail;
        }

        List(const List & rhs) // Constructor que permite asignar un nuevo elemento a la lista, en una posicion exacta
        {
            init();
            for(auto & x : rhs)
                push_back(x);
        }

        List & operator= ( const List & rhs) // Permite a la list asignar un valor a un nuevo elemento
        {
            List copy = rhs;
            std::swap(*this, copy);
            return *this;
        } 

        List(List && rhs) // Permite asignar tamano y metodos que ayudan a organizar los elementos en una poscion.
            : theSize{ rhs.theSize }, head{rhs.head}, tail{rhs.tail}
        {
            rhs.theSize = 0;
            rhs.head = nullptr;
            rhs.tail = nullptr;
        }

        List & operator= (Liat && rhs) // Intercambia los valores de los elementos.
        {
            std::swap( thsSize, rhs.theSize);
            std::swap( head, rhs.head );
            std::swap( tail, rhs.tail );

            return *this;
        }

        void init() // Asignar un espacio a estos elementos
        {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
        }
    }
List( const List & rhs )
{ {init();} }
~List( )
{ {init();} }
List & operator= ( const List & rhs )
{ {init();} }
List( List && rhs )
{ {init();} }
List & operator= ( List && rhs )
{ {init();} }

iterator begin( ) // Posicion de inicio del iterador
{ return { head->next }; }
const_iterator begin( ) const 
{ return { head->next }; }
iterator end( ) // Posicion del final del iterador
{ return { tail }; }
const_iterator end( ) const
{ return { tail }; }

int size( ) const 
{ return theSize; }
bool empty( ) const
{ return size( ) == 0; }

// Funciones y constructores para asignar y eliminar posiciones
void clear( )
{
while( !empty( ) )
pop_front( );
}
Object & front( )
{ return *begin( ); }
const Object & front( ) const
{ return *begin( ); }
Object & back( )
{ return *--end( ); }
const Object & back( ) const
{ return *--end( ); }
void push_front( const Object & x )
{ insert( begin( ), x ); }
void push_front( Object && x )
{ insert( begin( ), std::move( x ) ); }
void push_back( const Object & x )
{ insert( end( ), x ); }
void push_back( Object && x )
{ insert( end( ), std::move( x ) ); }
void pop_front( )
{ erase( begin( ) ); }
void pop_back( )
{ erase( --end( ) ); }

iterator insert( iterator itr, const Object & x ) // Constructor que permite y da la capasicadad de añadir un elemento a nuestra list, asiganado una posicion.
{   
    iterator insert(iterator itr, const Object & x)
    {
        Node *p = itr.current;
        theSize++;
        return { p->prev = p->prev->next = new Node{x,p->prev, p } }
    }
    iterator insert(iterator itr, Object && x)
    {
        Node *p = itr.current;
        theSize++;
        return { p->prev = p->prev->next
            = new Node{ std::move(x), p->prev, p }}
    }
}
iterator insert( iterator itr, Object && x )
{
    iterator insert(iterator itr, const Object & x)
    {
        Node *p = itr.current;
        theSize++;
        return { p->prev = p->prev->next = new Node{x,p->prev, p } }
    }
    iterator insert(iterator itr, Object && x)
    {
        Node *p = itr.current;
        theSize++;
        return { p->prev = p->prev->next
            = new Node{ std::move(x), p->prev, p }}
    }
}

iterator erase( iterator itr )
{ 
    Node *p = itr.current;
    iterator retVal{ p-> next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;

    return retVal;
}
iterator erase( iterator from, iterator to )
{ 
    for(iterator itr = from; itr != to; )
    itr = erase(itr);

    return to;
}

private:
int theSize;
Node *head;
Node *tail;

void init( ) 
{ {init();} }
};
```

## BIBLIOGRAFIA 

codigo Daniel037. 13 - ADT Abstract Data Types - C++ - Tipos De Datos Abstractos ADT. (5 de agosto de 2020). Accedido el 5 de octubre de 2023. [Video en línea]. Disponible: https://www.youtube.com/watch?v=Bj5w2bvCA2A

“¿Qué es ADT C++?” The Money © - N°1 Official Money & Networth Source. Accedido el 5 de octubre de 2023. [En línea]. Disponible: https://themoney.co/es/what-is-adt-c/

“List in C++ standard template library (STL) - geeksforgeeks”. GeeksforGeeks. Accedido el 5 de octubre de 2023. [En línea]. Disponible: https://www.geeksforgeeks.org/list-cpp-stl/

“CS 115: The list as an ADT”. University of Regina - Department of Computer Science. Accedido el 5 de octubre de 2023. [En línea]. Disponible: https://www2.cs.uregina.ca/~saxton/CS115/Notes/List/list.html

“Proyecto: Sistema de ayuda al C.” Accedido el 5 de octubre de 2023. [En línea]. Disponible: https://ccia.ugr.es/~jfv/ed1/c/cdrom/cap5/f_cap52.htm

Vida MRR - Programacion web. ¿Qué son y para qué sirven las listas enlazadas? Ejemplo de implementación. (18 de abril de 2019). Accedido el 5 de octubre de 2023. [Video en línea]. Disponible: https://www.youtube.com/watch?v=MThabgtlmDM

“Vector (clase)”. Microsoft Learn: Build skills that open doors in your career. Accedido el 5 de octubre de 2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/standard-library/vector-class?view=msvc-170

“List (clase)”. Microsoft Learn: Build skills that open doors in your career. Accedido el 5 de octubre de 2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/standard-library/list-class?view=msvc-170

“Iterators”. Microsoft Learn: Build skills that open doors in your career. Accedido el 5 de octubre de 2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/standard-library/iterators?view=msvc-170

## OPINIONES Y CRITICAS

La verdad el libro personalmente es confuso, al llevar un orden bastante extraño, ya que en su mayoria explica los detalles de cada caso, en este caso debo de decir que el tema de las listas entrelazas y listas doblemente entreladas me gusto, pero el resto, podria ser mas ordenado. En lo que me refiero es que podemos ver primero lo principal como es los Vectores y List, esta claro que esta hecho de esta forma para ver como esta conformado, pero me gustaria de primera ver en general un poco de lo que es la idea principal.


