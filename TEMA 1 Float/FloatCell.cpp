#include "FloatCell.h"

// Inicializacion de constructor implicito
FloatCell::FloatCell(float newValue) : storedValue(newValue){}

// Inicializacion de constructor por copia
FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue){}

// Inicializacion de constructor de movimiento
FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue){
    rhs.storedValue = 0;
}

// Operador de asignacion de un R-valor cuando este se iguala a otro valor
FloatCell &FloatCell::operator=(const FloatCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

// Operador de asignacion de un R-valor cuando se iguala a un valor
FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if (this != &rhs){
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }

    return *this;
}

// Asignacion de con que tipo de valores trabajara la clase
FloatCell &FloatCell::operator=(float rhs) {
    storedValue = rhs;
    return *this;
}

// Inicializacion del operador de suma, para nuestra clase
FloatCell &FloatCell::operator+(const FloatCell &rhs){
    storedValue = storedValue + rhs.storedValue;
    return *this;
}

// Inicializacion de la Funcion para ver el valor de la variable
void FloatCell::setValue(float newValue) {
    storedValue = newValue;
}

// Inicializacion de la funcion para asignar los datos de la variable
float FloatCell::getValue() const {
    return storedValue;
}