#ifndef TEMA_1_FLOAT_FLOATCELL_H
#define TEMA_1_FLOAT_FLOATCELL_H

class FloatCell {
public:
    explicit FloatCell(float newValue = 0);

    FloatCell(const FloatCell &rhs);

    FloatCell(FloatCell &&rhs) noexcept;

    ~FloatCell() = default;

    FloatCell &operator=(const FloatCell &rhs);

    FloatCell &operator=(FloatCell &&rhs) noexcept;

    FloatCell &operator=(float rhs);

    FloatCell &operator+(const FloatCell &rhs);

    float getValue() const;
    void setValue(float newValue);

protected:
    float storedValue;
};

#endif //TEMA_1_FLOAT_FLOATCELL_H
