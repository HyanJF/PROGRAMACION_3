# TAREA 2 CREACION DE UNA CLASE (FLOAT)

Para la realizacion de este codigo se uso el codigo anterior que estaba enfocado a una clase que permita trabajar con valores del tipo entero *int*.

Para esto necesitamos reaccinar y cambiar nuestro metodos al tipo FloatCell, asi como inicializarlos de la misma forma.

```
#ifndef TEMA1_FLOAT_FLOATCELL_H
#define TEMA1_FLOAT_FLOATCELL_H

class FloatCell {
public:
    //Constructor que permite mantener un dato igual asignado
    explicit FloatCell(float newValue = 0);
    
    //Constructor de referencia
    FloatCell(const FloatCell &rhs);
    
    //Constructor de Referencia y para entrar en la memoria
    FloatCell(FloatCell &&rhs) noexcept;
    
    //Nuestro Destructor, como metodo default
    ~FloatCell() = default;

    //Asignacion por copia, para los valores R
    FloatCell &operator = (const FloatCell &rhs);
    FloatCell &operator = (FloatCell &&rhs) noexcept;

    //Añadimos "float rhs" que indica el tipo de valor con el trabajara
    FloatCell &operator=(float rhs);

    //Funcion que nos permite saber el valor asignado
    float getValue() const;

    //Funcion para asignar un valor
    //Del tipo float en este caso
    void setValue(float newValue);

private:
    //Con esta variable podemos asignar nuestros valores del tipo float
    float storedValue;
};

#endif //TEMA1_FLOAT_FLOATCELL_H

```

Como se muestra en esta caja de codigo, nuestros constructores nos ayudaran a tomar la informacion apartir de una copia por referencia de nuestro valor agragado por el usuario.

y usando nuestra variable privada, para decirle a nuestra clase que tipo de valores, aceptara.

En nuestro .cpp del mismo nombre tendremos inicializados nuestros constructores, para recibir el valor de tipo float
```
#include "FloatCell.h"

//Nuestro Constructor implicito
FloatCell::FloatCell(float newValue) : storedValue(newValue){}

//Constructor copia
FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue) {}

FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue){
    //rhs.storedValue = 0;
}

FloatCell &FloatCell::operator=(const FloatCell &rhs) {
    if (this != &rhs){
        storedValue = rhs.storedValue;
    }
    return * this;
}

//En esta funcion indicamos como hacer que un Rvalor asigne, cuando se iguala a una valor Float
FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if(this != &rhs){
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

FloatCell &FloatCell::operator=(float rhs) {
    storedValue = rhs;
    return *this;
}

//Metodo para asignar el valor float
void FloatCell::setValue(float newValue)
{
    storedValue = newValue;
}

//Metodo para tomar el valor float
float FloatCell::getValue() const {
    return storedValue;
}
```
 ya inicializados nuestros constructores y metodos, lo siguiente sera asignar mientre el main nuestro valor del tipo FloatCell, para que asi el programa al ejecutar pueda imprimirlo.

 ```
 #include <iostream>
#include "FloatCell.h"

int main() {
    FloatCell y;
    y = 5.55;
    FloatCell x=y;
    std::cout<<x.getValue()<<std::endl;
    x= std::move(y);
    std::cout<<y.getValue()<<std::endl;
}
 ```

 En este int main, nuestro valor de tipo FloatCell y, ahora tiene un valor de 5.55, en este menu, al correr el digo nuestro resultado sera que nuestra variable y cambiara su valor con la varible x, dandonos a entender que nuestra clase ahora reconoce y trabaja con los valores float.

## Suma de FloatCell
Para que nuestros valores float creados puedan saber como sumar necesitaremos de nuestro nuevo constructor.

```
FloatCell &operator + (const FloatCell &rhs);
```

Con esto tenemos un constructor que permite sumar los valores de la variable asignada.
En el cpp inicializaremos este metodo para que pueda ser utilizado.

```
FloatCell &FloatCell::operator+(const FloatCell &rhs) {
    storedValue = storedValue + rhs.storedValue;
    return *this;
}
```

Con esta linea de codigo podremos indicarle al operador que al recibir dos varibles del mismo tipo puedo unirlos y almacenarlos en la variable del primer valor.

Y en el main se escribiria asi
```
int main() {
    FloatCell y;
    y = 5.55;
    std::cout<<y.getValue()<<std::endl;
    FloatCell x=y;
    std::cout<<x.getValue()<<std::endl;
    x= std::move(y);
    std::cout<<y.getValue()<<std::endl;
    FloatCell z;
    z = 4.55;
    z + x;
    std::cout<<z.getValue()<<std::endl;
}
```

Esto al ser ejecutado dara como resultado la union de estas dos variables, x seguira teniendo su mismo valor, al contrario que z


 ### Conclusiones.
 Luego de la clase que tuvimos, pude entender una buena parte del codigo y el como funcionan los constructores maso menos, igual maestro, si encuentra algo o siente que hay algun detalle que aun tiene un error en alguno de los constructores, no dude en dejarlo en un comentario.