#ifndef TEMA_1_INTCELL_H
#define TEMA_1_INTCELL_H


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

#endif //TEMA_1_INTCELL_H
