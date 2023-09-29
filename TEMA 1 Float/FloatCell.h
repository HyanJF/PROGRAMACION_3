#ifndef TEMA_1_FLOAT_FLOATCELL_H
#define TEMA_1_FLOAT_FLOATCELL_H

class FloatCell {
public:
    // Constructor implícito de nuestra clase
    explicit FloatCell(float newValue = 0);
    // Constructor explicito de copia
    FloatCell(const FloatCell &rhs);
    // Constructor explícito por referencia
    FloatCell(FloatCell &&rhs) noexcept;
    // Destructor de la clase, por default
    ~FloatCell() = default;

    // operador por copia, R-valor
    // Indica a la clase que hacer con los operadores de igual
    FloatCell &operator=(const FloatCell &rhs);
    FloatCell &operator=(FloatCell &&rhs) noexcept;

    // Operador que indica el tipo de valor con el que trabajara
    FloatCell &operator=(float rhs);
    // Operador aritmetico para las sumas
    FloatCell &operator+(const FloatCell &rhs);

    // Funciones para asignación y ver los datos de las variables
    // Función para ver el valor de la variable
    float getValue() const;
    // Función void "No devuelve nada"
    // Funcion para asignar los datos de la variable
    void setValue(float newValue);

protected:
    // StoredValue, variable que almacena datos float
    float storedValue;
};

#endif //TEMA_1_FLOAT_FLOATCELL_H
