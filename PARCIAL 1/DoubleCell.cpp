#include "DoubleCell.h"
#include <stdexcept>

// Default constructor
// Nuestro constructor base
DoubleCell::DoubleCell()
        :Storedvalue(0.0){}

// Constructor with value
// Constructor con el valor asignado
DoubleCell::DoubleCell(double value)
        : Storedvalue(value){}

// Copy constructor
// Constructor que se encarga de copia
DoubleCell::DoubleCell(const DoubleCell& other)
        : Storedvalue(other.Storedvalue){}

// Reference  constructor
// Constructor que se encarga por referencia
DoubleCell::DoubleCell(DoubleCell &&rhs) noexcept
        : Storedvalue(rhs.Storedvalue){
    rhs.Storedvalue = 0;}

// Destructor
// Nose si el destructor es necesario inicializarlo

// Operadores que se encargan del igual y como ejecutarlo
// Assignment operator by copy
DoubleCell& DoubleCell::operator=(const DoubleCell& other){
    if (this != &other){
        Storedvalue = other.Storedvalue;
    }
    return *this;
}

// Assignment operator by reference
DoubleCell &DoubleCell::operator=(DoubleCell&& other) noexcept{
    if (this != &other)
    {
        Storedvalue = other.Storedvalue;
        other.Storedvalue = 0;
    }
    return *this;
}

// Assignment operator for double
DoubleCell& DoubleCell::operator=(double value){
    Storedvalue = value;
    return *this;
}

// Inicializacion de las operaciones basicas
// Matematicas
// Arithmetic operators
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{
    return DoubleCell(Storedvalue + other.Storedvalue);
}
//primitive double adding
DoubleCell DoubleCell::operator+(const double other) const {
    return DoubleCell(Storedvalue + other);
}
//DoubleCell substracting
DoubleCell DoubleCell::operator-(const DoubleCell &other) const {
    return DoubleCell(Storedvalue - other.Storedvalue);
}
//primitive double substracting
DoubleCell DoubleCell::operator -(double value) const{
    return DoubleCell(Storedvalue - value);
}

//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{
    return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator*(double value) const {
    return DoubleCell(Storedvalue * value);
}

//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{
    if(other.Storedvalue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive double division
DoubleCell DoubleCell::operator /(double value) const{
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / value);
}

// Metodos para asignar y ver los valores asignados.
// Setters
void DoubleCell::SetValue(double newValue){
    Storedvalue = newValue;
}
// Getters
double DoubleCell::GetValue() const{
    return Storedvalue;
}