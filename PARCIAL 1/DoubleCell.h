#ifndef PARCIAL_1_DOUBLECELL_H
#define PARCIAL_1_DOUBLECELL_H

class DoubleCell {
public:
    // Default constructor
    // Nuestro constructor principal
    DoubleCell();
    // Constructor with value
    // El constructor con un valor ingresado
    explicit DoubleCell(double value);
    // Copy constructor
    // Constructor de copia de una clase doble
    DoubleCell(const DoubleCell& other);
    // Reference constructor
    // Constructor de referencia para mover valores
    DoubleCell(DoubleCell &&rhs) noexcept;
    // Destructor
    // Destructor para eliminar DoubleCell
    ~DoubleCell() = default;
    // Assignment operator by copy
    // Operadores que dan la funcion del igual
    DoubleCell &operator=(const DoubleCell &rhs);
    // Assignment operator by reference
    DoubleCell &operator=(DoubleCell&& other) noexcept;
    // Assignment operator for double
    DoubleCell& operator=(double value);

    // Arithmetic operators
    // Operadores que nuestro DoubleCell puede hacer en matematicas
    DoubleCell operator +(const DoubleCell& other) const;
    DoubleCell operator +(const double other) const;
    DoubleCell operator -(const DoubleCell& other) const;
    DoubleCell operator -(const double other) const;
    DoubleCell operator *(const DoubleCell& other) const;
    DoubleCell operator *(const double other) const;
    DoubleCell operator /(const DoubleCell& other) const;
    DoubleCell operator /(const double other) const;

    // Vemos el valor y asignamos el valor de esa variable
    // Setters
    void SetValue(double newValue);
    // Getters
    [[nodiscard]]double GetValue() const;

private:
    // Nuestro valor para igualar
    double Storedvalue;
};

#endif