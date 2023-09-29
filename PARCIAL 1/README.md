# Examen 1 programación 3

# Examen de Programación 3

## Parte 1

Para la realización de este examen tendrán que Subir en `Classroom` un archivo `README.md` con las respuestas a las indicaciones, preguntas y calculos que se tengan que hacer en el siguiente examen. Para la entrega del código corregido tendrán que subirlo a su **Repositorio de GitHub** en una carpeta que tenga el nombre: <span style="color: #ff7600; ">Examen</span> Tendrán un lapso de 12 horas a partir de la publicación del espacio correspondiente en classroom.

### Creación de Clases

En este repositorio de [GitHub](https://github.com/BiomedicLJZ/Examen/tree/master/Examen_Programacion_3) cuentan con los archivos `.h` y `.cpp` de una clase, estos archivos están incompletos ya que les hace falta una serie de lineas críticas para su funcionamiento, su trabajo en este examen será hacer funcionar el archivo `main.cpp` utilizando la documentación disponible, **apuntes y conocimientos previos** para ello deberán:

1. Reparar el archivo de Interfaz `.h`
2. Reparar el archivo de implementación `.cpp`
3. Hacer funcionar el archivo `main.cpp`

## Parte 1.1

4. Responde a las siguientes preguntas:
   1. ¿Qué es un Rvalor y un Lvalor?
   **Los valores R son aquellos que se encuentran solo del lado derecho del igual y los valores L son aquellos que se encuntran del lado izquierdo de la igualdad, es cuenta con la caracteristica de que pueden ser tanto Rvalor y Lvalor**
   2. ¿Porqué es necesario que una clase tenga constructores y operadores por **copia** y por **referencia**?
   **R= Para el constructor de "copia" es necesario para que los objetos copie los mismos valores de un objeto igual, para el de "Referencia" es utilizado para que dato tenga un punto de referencia, de su valor o direccion de memoria**
   3. ¿Qué función desarrollan los `::` en la implementación de la clase?
   **R= el de ser un operador de resolucion de ambito, este operador se encarga de hacer una distincion entre variables del mismo nombre por ejemplo Human::Run siendo "Human" la clase y "Run" El metodo que se llama**
   4. ¿Cómo se le denomina a cuando una clase posee un operador puede tener múltiples implementaciones dependiendo de los argumentos que este reciba?
   **R= Overload** 
   5. ¿Cúal es la funcion del archivo `.h`?
   **R= Como tal su funcion principal en c++ es la de permitirnos crear clases o funciones, fuera de un main, para este como ser llamadas solomanete con el tipo que se indique, en el caso de las clases, es para poder ejecutar los metodos o valores dentro de la clase, y permitan un codigo mas optimo y limpio**

## Parte 2

### Complejidad Temporal

Calcular la complejidad temporal en **Big(O) Notation** del siguiente algoritmo:

```cpp
#include <iostream>

int algoritmo1(int n) {
    int resultado = 0;

    for (int i = 0; i < n; i++) { // O(n)
        resultado += i; // Operación simple O(1)
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { // O(n^2)
            resultado += i * j; // Operación simple O(1)
        }
    }

    return resultado;
}

int main() {
    int n;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    int resultado = algoritmo1(n);
    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}

```