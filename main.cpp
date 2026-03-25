#include "person.hpp"
#include <iostream>


int main() {
    // Създава обект с конструктор по подразбиране
    Person p; 
    std::cout << "Default Person object: ";
    p.print();
    std::cout << std::endl;

    // Създава обект с конструктор за копиране
    Person p2 = p;
    std::cout << "Person object (copy constructor): ";
    p2.print();
    std::cout << std::endl;

    // Създава обект с конструктор с два параметъра
    Person p3("Ivan", 23);

    // Извършва присвояване между два създадени обекта чрез оператора за присвояване
    p2 = p3;
    std::cout << "Person object (operator=): ";
    p2.print();
    std::cout << std::endl;

    std::cout << "Person object (move constructor): ";
    Person pMove = std::move(Person("Obj move", 33));
    pMove.print();
    std::cout << std::endl;
    

    std::cout << "Person object (move operator =): ";
    Person pMove2;
    pMove2 = std::move(pMove);
    pMove2.print();
    std::cout << std::endl;

    return 0;
}
