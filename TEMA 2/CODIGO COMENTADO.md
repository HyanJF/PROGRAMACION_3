# COMENTANDO CODIGO.
## CODIGO

Para comenzar en este codigo, se nos enseña como crear y la funcionalidad de esta misma.
El codigo que se estara comentando es el siguiente.

*.h* del codigo que se comentara.

```
#ifndef TEMA_1_FLOATCELL_H
#define TEMA_1_FLOATCELL_H


class IntCell {
public:
    explicit IntCell(int newValue = 0);
    IntCell(const IntCell &rhs);
    IntCell(IntCell &&rhs) noexcept;
    ~IntCell() = default;

    IntCell &operator=(const IntCell &rhs);
    IntCell &operator=(IntCell &&rhs) noexcept;
    IntCell &operator=(int rhs);

    int getValue() const;
    void setValue(int newValue);

private:
    int storedValue;
};

#endif
```

En este codigo podemos ver una clase que nos permite asignale a una varible un numero entero, de tal modo que posteriormente pediremos que lo imprima.

```
#ifndef TEMA_1_FLOATCELL_H
#define TEMA_1_FLOATCELL_H

class IntCell {
public:
    
private:
   
};

#endif
```

Primero definiremos nuestra clase con las varibles y metodos publicos y privados.

```
#ifndef TEMA_1_FLOATCELL_H
#define TEMA_1_FLOATCELL_H


class IntCell {
public:
    // En este constructor se indica que no queremos una conversion.
    explicit IntCell(int newValue = 0);
    // Damos a entender que nuestra variable tendra el mismo valor del otro lado.
    IntCell(const IntCell &rhs);
    // Indicamos que el dato sera un tipo de funcion de datos sin formato.
    IntCell(IntCell &&rhs) noexcept;
    // En este IntCell se crea un caso default para un caso no reconocido
    ~IntCell() = default;

    // En nuestra constante almacenaremos los datos del lado de nuestra variable
    IntCell &operator=(const IntCell &rhs);
    // Operador que tomara un dato anterior en nuestra variable.
    IntCell &operator=(IntCell &&rhs) noexcept;

    // Le damos la opcion a nuestro operador para que acepte los valores de nuestra variable.
    IntCell &operator=(int rhs);

    int getValue() const;
    void setValue(int newValue);

#endif
```

Cada uno de estos constructores no permite enviar la informacion de un lado a otro la informacion de nuestro valor al que queramos darle la informacion.

```
#ifndef TEMA_1_FLOATCELL_H
#define TEMA_1_FLOATCELL_H


class IntCell {
private:
    //El metodo de nuestra funcion, siendo de tipo entero.
    int storedValue;
};

#endif
```

*En este apartado tenemos nuestra variable del tipo entero la cual solo podra ser llamada y modificada por medio de metodos. Con esto tenemos documentado nuestra clase ahora sigue la llamada de los metodos.
el codigo del .cpp de nuestra clase.*

```
#include "FloatCell.h"

IntCell::IntCell(int newValue) : storedValue(newValue) {}
IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}
IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {
    // rhs.storedValue = 0;
}
IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}
```

En este codigo se estaran llamando a los constructores de nuestra clase cada uno para poder transfomar la variable en un valor entero.

```
#include "FloatCell.h"

// Tenemos un constructor, con un metodo que nos asigna un valor.
IntCell::IntCell(int newValue) : storedValue(newValue) {}

// Para este parametro copiamos nuestro valor del parametro una constante.
IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}

// Move constructor a una variable de nombre storedValue, con la datos del otro lado.
IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {
    // rhs.storedValue = 0;
}
// Copiamos la datos a nuestro constructor
IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

// Removemos nuestros datos, y los asignamos a nuestra variable
IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// eliminamos los datos, para poder asiganarle un nuevo valor a nuestro operador.

// operador diseñado solo para aceptar los datos correspondientes a la variable
IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}
```

##  MI OPINION.

Sinceramente me cuesta mucho entender varios sistemas, como algunos significados, y el libro no me ayuda mucho que digamos, principalmente por la diferencia de idiomas, por lo cual solo pido paciencia y toleracia para poder entender mejor la construcion de sus logica de programacion.

