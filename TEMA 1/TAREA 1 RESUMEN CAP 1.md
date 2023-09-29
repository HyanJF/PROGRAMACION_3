# CAPITULO 1 
## 1.1 ¿DE QUE TRATA ESTE LIBRO?

La primera parte de este libro es un repaso breve a lo que seria el problema de seleccion.

Se podria decir que es la breve introduccion a el contenido, haciendo un enfoque en que se buscara el como realizar un condigo optimizado en tiempo y evitar los cuellos de botella.

## 1.2 REVISION MATEMATICA 

*1.2.1* Exponentes

*1.2.2* Logaritmos

*1.2.3* Series

Esta seccion esta enfoca en revisar algunas de las formulas basicas de la derivada y los logaritmos de un numero, en una serie matematica, este capitulo esta mas enfocado a recordar ciertos criterios matematicos que pueden ser utilizados en la programacion.

*1.2.4* Aritmetica modular

*1.2.5* La palabra P

Entramos en el tema de los numeros primos con ejemplo en el cual contamos con casos, donde si se cumple cierta condicion, tenemos diferentes teoremas.
Para el segundo caso entramos en la induccion y la contradiccion. 

### Critica y Conclusion 1

En esta caso el repaso matematico lo veo bastante bien pues me permite recordar como funcionan varios sistemas y comprender algunos puntos que se me hayan olvidado, una buena forma para entender lo que se viene a continuacion.

## 1.3 RECUSIVIDAD

Comenzamos con el tema de la recursividad, comenzan con el analisis de un pequeño codigo, el que se mostrara a continuacion.

```
#include iostream

int main()
{
    int f(int x)
    {
        if(x == 0)
            return 0;
        else 
            return 2 * f(x - 1) + x * x;
    }
}
```

donde int f representa un numero entero el cual tiene un valor x dentro de nuestro ciclo, donde si nuestro x es igual a 0, retornara un 0 y en caso contrario este retornara un secuencia de 2 por f con el valor de x - 1 + la suma de x por x, lo que tenemos.

con sultando otras fuentes tenemos que...

¿Qué es la recursión?

La recursividad es una técnica de programación que busca resolver un problema sustituyéndolo por otros problemas de la misma categoría, pero más simples implementando un algoritmo recursivo.

En muchos lados encontrarás expresado lo anterior como:

Una función recursiva es una función que se llama a sí misma.

Se dice que un algoritmo es recursivo si dentro del cuerpo del algoritmo y de forma directa o indirecta se realiza una llamada a él mismo.

Las funciones recursivas tienen similitud con los bucles, pero no están basados en una declaración condicional. La función se llama siempre que se requiere el mismo código para ejecutarse de forma reiterada.

Para escribir una función recursiva, se deben satisfacer 3 condiciones:

Debe haber al menos un caso base de parada
Inducción: Paso recursivo que provoca una llamada recursiva Debe ser correcto para distintos parámetros de entrada**
**Convergencia: Cada paso recursivo debe acercar a un caso base. Se describe el problema en términos de problemas más sencillos. Es importante recordar que cualquier función recursiva debe tener un “caso base” (paso 1), el caso base es cualquier expresión donde le dice a la función cuándo dejar de llamarse a sí misma. Si no tiene un caso base, la recursión producirá un bucle infinito.

### Critica y Conclusion 2

En este tema del libro sin duda se puede entender perfectamente lo que nos da a entender, pero eso si tuve que consultar con otras fuentes para poder, complementar el tema que se vio aqui.

## 1.4 C++ CLASES

*1.4.1*

Para la sintaxis de la clases y sus bases, comenzamos con saber que las clases no son mas que una forma de almacenar estructuras, en forma de datos o funciones, que pueden ser llamadas a nuestro codigo, 
Las clases se pueden dividir en 4 tipos de metodos.

Siendo estos uno de lectura y el segundo escritura, los ultimos dos son conocidos como constructores.
lo primero que vemos, es las estiquetas de nuestra clase, las cuales determinan los datos y valores de estas misma.

```
1 /**
2 * A class for simulating an integer memory cell.
3 */
4 class IntCell
5 {
6   public:
7   /**
8   * Construct the IntCell.
9   * Initial value is 0.
10  */
11  IntCell( )
12 { storedValue = 0; }
13
14  /**
15  * Construct the IntCell.
16  * Initial value is initialValue.
17  */
18  IntCell( int initialValue )
19  { storedValue = initialValue; }
20
21  /**
22  * Return the stored value.
23  */
24  int read( )
25  { return storedValue; }
26
27  /**
28  * Change the stored value to x.
29  */
30  void write( int x )
31  { storedValue = x; }
32
33  private:
34  int storedValue;
35 };
```

En los valores publicos se puede accder desde cualquier metodo que el usuario este utilizando.

*1.4.2 Sintaxis y accesores*

Para el tema de los constructores me queda claro que la forma de crear estructuras es se puede dividir en varias ramas, siendo los constructores uno de ellos, los cualos no devuleven ningun valor, el cual puede ser de tipo publico y privado, en otros casos los constructores pueden llamar de forma mas eficaz he inicializar a los miembros de la clase.

*1.4.3* Separacion de interfaz e implementacion.

Como tal la interfaz es la principal fuente que se encarga de ennumerar las clases y sus miembros y la implementacion como su nombre lo dice se encarga de implementar, estos metodos en nuestros codigos.

*1.4.4* Vectores y strings

Para el tema de los vectores sin duda es el que mas conozco de tema, siendo que los vectores son la formas mas eficiente para almacenar mucha informacion, al igual que son los que uentan con varias funciones que permiten comparar la informacion dentro de ellos, 

En el caso de los strings son una version mejorar del tipo de variable char, el tipo string nos permite el añadir informacion del tipo texto, que puede ser utilizada para cadenas de caracteres, asi como la utilizacion de datos.

## 1.5 C++ DETALLES

*1.5.1* Punteros

Los punteros se pueden definir como una variable que tiene como objetivo, apuntar a una direccion de memoria, los principales objetivos de los punteros se pueden definir en tres tipos y utlidades, pueden ser utilizados para asignar nuevos objetos de informacion, para pasar funciones a otras funciones y para iterar elementos de una matriz entre otra estructura.

inicializar un puntero

```
int variable;
int * apuntador = &vriable;
*apuntador = 20;

delete [] apuntador;
puntero = NULL;
```

El uso de los punteros nos han permitido manipular informacion de estructuras dinamicas, para su posterior modificacion.

los punteros tambien pueden tener sus tipos como lo son los de tipo const y valatile.

```
const char *cpch;
volatile char *vpch;
```
Para declarar el valor del puntero (es decir, la dirección real almacenada en el puntero) como const o volatile, utilice una declaración con el formato:
```
char * const pchc;
char * volatile pchv;
```

*1.5.2 Valores L, Valores R y referencias*

En este punto lo mas importante que debemos saber es que los valores L, R son sencillos, 
Los valores R como su nombre lo dice son valores que solo pueden encontrarse en el lado derecho de la espresion y que no pueden encontrarse al lado izquierdo.

```
int x; 
i = x; 
&x = 3;
```
En el siguiente ejemplo podemos ver datos del tipo L

```
int x, y = 4;
x = y;
```
como un valor L tenemos el nombre de variables y referencias.

En resumen rapido y directo las referencias en C++ no son mas que los alias que resiven las variables existentes una referencia, la cual puede llegar a modificar la informacion dentro de una variable.

*1.5.3* Paso de parametros

Los parametros consisten en su mayoria en la capicidad de la informacion para se llamados en un funcion, se sabe que existen cuatro formas diferentes de pasar un parametro.

llamada por referencia.
llamada por valor referencia.
llamada por referencia a constante.
llamada por constante referencia.

Los parámetros permiten que una función pueda recibir diferentes valores cada vez que se llama.

*1.5.4* Retornar pasaje

el rotarnar pasaje se puede resumir en el simple ello de devolver un valor de un funcion y almacenarlo en una variable.

*1.5.5* std::swap y std::move

El principio de swap consiste en enviar informacion y a un funcion en el cual el objetivo principal es el de intercambiar la informacion.

```
template <class T> void swap ( T& a, T& b )
{
  T c(a); a=b; b=c;
}
```
Observe cómo esta función implica una construcción de copia y dos operaciones de asignación, que pueden no ser la forma más eficiente de intercambiar el contenido de las clases que almacenan grandes cantidades de datos, ya que cada una de estas operaciones generalmente opera en tiempo lineal en su tamaño.

El principio de move, directame se trata de un funcion es una especie de convertidor entre formas.

Lo que se encarga es de cambiar una expresion de ser un valor L a ser un valor x.

En otras palabras, cuando usas , estás permitiendo que el compilador canibalice . Por lo tanto, si tiene, digamos, su propio búfer en la memoria, después de que el compilador pueda tener otro objeto que lo posea en su lugar.

```
std::move(x)xxstd::move()
```

*1.5.6* Los 5 grandes

Estos tipos de clase son conocidas como.
Destruir.
Copiar constructor.
Mover constructor.
Copiar operador de asignacion. 
Mover operador de asignacion.

#### Destruir.

Se le considera destructor a cualquier objeto que sale del rango o se elimina, con la finalidad de borrar recursos.

#### Copiar constructor y mover constructor.

el objeto constructor es que que cuenta con un valor L y el constructor de movimiento aquel que tiene un valor R, en los siguientes casos se muestra un ejemplo.

```
IntCell B = C; // Copy construct if C is lvalue; Move construct if C is rvalue
IntCell B { C }; // Copy construct if C is lvalue; Move construct if C is rvalue
```
un objeto pasado usando llamada por valor (en lugar de por & o constante &), que, como se mencionó
antes, de todos modos rara vez debería hacerse.
un objeto devuelto por valor (en lugar de por & o constante &). Nuevamente, un constructor de copias es
se invoca si el objeto que se devuelve es un valor l, y se invoca un constructor de movimiento si
el objeto que se devuelve es un valor r.

#### Copiar operador de asignacion y Mover operador de asignacion

Se llama al operador de asignación cuando = se aplica a dos objetos que han sido
previamente construido. LHS=RHS está destinado a copiar el estado de RHS en LHS. Si rhs es un
lvalue, esto se hace utilizando el operador de asignación de copia; Si rhs es un valor r(es decir, un tem-
porary que está a punto de ser destruido de todos modos), esto se hace mediante el uso de la asignación de movimiento
operador. De forma predeterminada, el operador de asignación de copia se implementa aplicando la copia
operador de asignación a cada miembro de datos por turno.

*1.5.7* Matrices y cadenas estilo C++

Principalmente para declarar una matriz es tan facil como.
int arr1[10]

las matrices en terminos generales son una estructura de datos bastante similar a los vectores o arreglos, en otras palabras las matrices son una serie de vectores unidos uno detras de otro.

para crear una matriz es tan facil como 
```
int MatrizNumeros[10][5]
```
el 10 corresponde a las filas de la matriz y 5 corresponde a las columnas.

Strings, no son mas que una variable que cuentan con la facilidad de almacenar mas de un tipo de caracter del pito texto, se podria decir que se trata de un arreglo de char.

por ejemplo
```
// Include the string library
#include <string>

// Create a string variable
string greeting = "Hello";
```

## 1.6 Plantillas.

La idea simple es pasar el tipo de datos como un parámetro para que no necesitemos escribir el mismo código para diferentes tipos de datos. Por ejemplo, una compañía de software puede necesitar ordenar() para diferentes tipos de datos. En lugar de escribir y mantener múltiples códigos, podemos escribir un sort() y pasar el tipo de datos como parámetro.

*1.6.1* Funciones de Plantillas

Las plantillas se expanden en el momento del compilador. Esto es como macros. La diferencia es que el compilador realiza la comprobación de tipos antes de la expansión de la plantilla. La idea es simple, el código fuente contiene sólo función/clase, pero el código compilado puede contener múltiples copias de la misma función/clase.

```
1 /**
2 * Return the maximum item in array a.
3 * Assumes a.size( ) > 0.
4 * Comparable objects must provide operator< and operator=
5 */
6 template <typename Comparable>
7 const Comparable & findMax( const vector<Comparable> & a )
8 {
9 int maxIndex = 0;
10
11 for( int i = 1; i < a.size( ); ++i )
12 if( a[ maxIndex ] < a[i])
13 maxIndex = i;
14 return a[ maxIndex ];
15 }
```
*1.6.2* Clases de plantilla

Las clases de plantillas cuenta con la siguiente estructura.

```
1 /**
2 * A class for simulating a memory cell.
3 */
4 template <typename Object>
5 class MemoryCell
6 {
7 public:
8 explicit MemoryCell( const Object & initialValue = Object{ } )
9 : storedValue{ initialValue } { }
10 const Object & read( ) const
11 { return storedValue; }
12 void write( const Object & x )
13 { storedValue = x; }
14 private:
15 Object storedValue;
16 };
```

```
1 int main( )
2 {
3 MemoryCell<int> m1;
4 MemoryCell<string> m2{ "hello" };
5
6 m1.write( 37 );
7 m2.write( m2.read( ) + "world" );
8 cout << m1.read( ) << end1 << m2.read( ) << end1;
9
10 return 0;
11 }
```
En este codigo se nos da a entender que el valor de nuestro return es igual a 0, danos a entender que el valor puede ser invalido.
De hecho, muchas plantillas de clases se implementan de esta manera porque, actualmente, las clases separadas
La pila de plantillas no funciona bien en muchas plataformas. Por lo tanto, en muchos casos, en la clase completa, con su implementación, debe colocarse en un archivo .h. Implementaciones populares.

*1.6.3* Objeto, Comparable y Un ejemplo

Objeto.

Los objetos son tipos de datos abstractos (TDA) definidos por el programador. En realidad son unidades que contienen datos y funciones que operan sobre esos datos. A los objetos también se les conoce como instancias de clase. A los elementos de un objeto se les conoce como miembros (datos miembros y funciones miembro).

En este texto, utilizamos repetidamente Object y Comparable como tipos genéricos. Se supone que el objeto tener un constructor de parámetro cero, un operador = y un constructor de copia. Comparable, como sugerido en el ejemplo de findMax, tiene una funcionalidad adicional en forma de operador< que se puede utilizar para proporcionar un pedido total.

*1.6.4* Objetos de funcion

Un objeto de función, o functor, es cualquier tipo que implementa operator(). Este operador se conoce como el operador de llamada o a veces el operador de la aplicación. La biblioteca estándar de C++ usa objetos de función principalmente como criterios de ordenación para los contenedores y en algoritmos. Los objetos de función proporcionan dos ventajas principales en comparación con una llamada de función sencilla. La primera es que un objeto de función puede contener el estado. La segunda es que un objeto de función es un tipo y, por tanto, puede usarse como un parámetro de plantilla. 
Para la creacion de objeto de funcion tomaremos como ejemplo.

```
class Functor
{
public:
    int operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    Functor f;
    int a = 5;
    int b = 7;
    int ans = f(a, b);
}
```

*1.6.5* Compilacion separada de plantillas de clase.

Como se vio en el tema anterior estas plantillas se pueden implementar en su declaracion, para implementar plantillas de clases.
El Apéndice A describe los mecanismos involucrados en la compilación separada de plantillas.
La declaración de la interfaz para una plantilla es exactamente lo que se esperaría: el
Las funciones miembro terminan con un solo punto y coma, en lugar de proporcionar una implementación.
Pero como se muestra en el Apéndice A, la implementación de las funciones miembro puede introducir
sintaxis de aspecto complicado, especialmente para funciones complicadas como operador=.

Es fácilmente presentable, pero las implementaciones se muestran como en el código en línea. En una plataforma-
De manera específica, uno puede transformar mecánicamente nuestras implementaciones de archivos de encabezado único.En implementaciones de compilación separadas si lo desea. Consulte el Apéndice A para conocer algunas de las
diferentes escenarios que podrían aplicarse.

## 1.7 Usando Matrices. 

Las matrices como sabemos son un conjunto de informacion organizada una dentro de otra.

*1.7.1* Los miembros de datos, el constructor y el basico Accesorios.

La matriz se representa con un miembro de datos de tipo vector,Objeto.
Despues de esto se ingresa el cuerpo de nuestro constructor y el propio tamaño de nuesta fila y columnas.
ejemplo 
```
#ifndef MATRIX_H
2 #define MATRIX_H
3
4 #include <vector>
5 using namespace std;
6
7 template <typename Object>
8 class matrix
9 {
10 public:
11 matrix( int rows, int cols ) : array( rows )
12 {
13 for( auto & thisRow : array )
14 thisRow.resize( cols );
15 }
16
17 matrix( vector<vector<Object>> v ) : array{ v }
18 { }
19 matrix( vector<vector<Object>> &&v): array{ std::move( v ) }
20 { }
21
22 const vector<Object> & operator[]( int row ) const
23 { return array[ row ]; }
24 vector<Object> & operator[]( int row )
25 { return array[ row ]; }
26
27 int numrows( ) const
28 { return array.size( ); }
29 int numcols( ) const
30 { return numrows( ) ? array[ 0 ].size( ) : 0; }
31 private:
32 vector<vector<Object>> array;
33 };
34 #endif
```

*1.7.2* Operador

La idea del operador[] es que si tenemos una matriz m, entonces m[i] debería devolver un vector
correspondiente a la fila i de la matriz m. Si se hace esto, entonces m[i][j] dará la entrada en
posición j para el vector m[i], utilizando el operador de indexación de vectores normal. Así, la matriz
operador[] devuelve un vector<Objeto> en lugar de un Objeto.
Ahora sabemos que el operador[] debería devolver una entidad de tipo vector<Objeto>. Debería
¿Usamos retorno por valor, retorno por referencia o retorno por referencia constante? Inmediatamente
eliminamos el retorno por valor, porque la entidad devuelta es grande pero se garantiza que existe
después de la llamada. Por lo tanto, nos encontramos ante un retorno por referencia o un retorno por referencia constante.

*1.7.3* Los cinco grandes.

Todo esto se soluciona automáticamente, porque el vector se ha encargado de ello. Por lo tanto,
Este es todo el código necesario para una clase de matriz en pleno funcionamiento.

## Bliografia

General programming style is discussed in several books. Some of the classics are [4],
[7], and [8].
1. M. O. Albertson and J. P. Hutchinson, Discrete Mathematics with Algorithms, John Wiley &
Sons, New York, 1988.
2. Z. Bavel, Math Companion for Computer Science, Reston Publishing Co., Reston, Va., 1982.
3. R. A. Brualdi, Introductory Combinatorics, 5th ed., Pearson, Boston, Mass, 2009.
4. E. W. Dijkstra, A Discipline of Programming, Prentice Hall, Englewood Cliffs, N.J., 1976.
5. B. Eckel, Thinking in C++, 2d ed., Prentice Hall, Englewood Cliffs, N.J., 2002.
6. R. L. Graham, D. E. Knuth, and O. Patashnik, Concrete Mathematics, Addison-Wesley,
Reading, Mass., 1989.
7. D. Gries, The Science of Programming, Springer-Verlag, New York, 1981.

8. B. W. Kernighan and P. J. Plauger, The Elements of Programming Style, 2d ed., McGraw-Hill,
New York, 1978.
9. D. E. Knuth, The Art of Computer Programming, Vol. 1: Fundamental Algorithms, 3d ed.,
Addison-Wesley, Reading, Mass., 1997.
10. S. B. Lippman, J. Lajoie, and B. E. Moo, C++ Primer, 5th ed., Pearson, Boston, Mass., 2013.
11. S. Meyers, 50 Specific Ways to Improve Your Programs and Designs, 3d ed., Addison-Wesley,
Boston, Mass., 2005.

12. S. Meyers, More Effective C++: 35 New Ways to Improve Your Programs and Designs, Addison-
Wesley, Reading, Mass., 1996.

13. D. R. Musser, G. J. Durge, and A. Saini, STL Tutorial and Reference Guide: C++ Programming
with the Standard Template Library, 2d ed., Addison-Wesley, Reading, Mass., 2001.
14. F. S. Roberts and B. Tesman, Applied Combinatorics, 2d ed., Prentice Hall, Englewood Cliffs,
N.J., 2003.
15. B. Stroustrop, The C++ Programming Language, 4th ed., Pearson, Boston, Mass., 2013.
16. A. Tucker, Applied Combinatorics, 6th ed., John Wiley & Sons, New York, 2012.

17. M. A. Weiss, Algorithms, Data Structures, and Problem Solving with C++, 2nd ed., Addison-
Wesley, Reading, Mass., 2000.

## Opiniones y criticas.

Para comenzar debo decir que en lo personal la forma de ver este tipo informacion debe de realizarse mediante practica y enseyo y error, no tanto con teoria aunque la teoria nos permitiria anlizar y revisar la informacion antes de llevarla acabo personalmente prefiero programarlo para despues analizarlo el como funcionan y el como podrian ayudarme.
