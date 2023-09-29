#include <iostream>
#include "IntCell.h"

int main() {
    IntCell m;
    m=5;
    IntCell c=m;
    std::cout<<c.getValue()<<std::endl;
    std::cout<<m.getValue()<<std::endl;
    c= std::move(m);
    std::cout<<m.getValue()<<std::endl;
}
