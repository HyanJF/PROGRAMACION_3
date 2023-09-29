#include <iostream>
#include "FloatCell.h"

int main() {
    FloatCell x;
    x=5.43;
    FloatCell y = x;
    std::cout<<x.getValue()<<std::endl;
    std::cout<<y.getValue()<<std::endl;
    y = std::move(x);
    std::cout<<y.getValue()<<std::endl;
    FloatCell z;
    z=6.21;
    z + y;
    std::cout<<z.getValue()<<std::endl;

}
