#ifndef TEMA_1_INTCELL_H
#define TEMA_1_INTCELL_H


class IntCell {
public:
    // Constructores para asignar tareas a nuestra clase
    explicit IntCell(int newValue = 0);
    IntCell(const IntCell &rhs);
    IntCell(IntCell &&rhs) noexcept;
    ~IntCell() = default;

    // Operador que permiten al programa utlizar el igual
    IntCell &operator=(const IntCell &rhs);
    IntCell &operator=(IntCell &&rhs) noexcept;

    // Overloaded assigment operator to accept primitive int
    // Operador sobre cargado para la asignación de variables int primitivas
    IntCell &operator=(int rhs);

    // Metodos que nos permiten ver y asignar valores
    int getValue() const;
    void setValue(int newValue);

private:
    int storedValue;
};

#endif //TEMA_1_INTCELL_H
