#include <iostream>
class Test {
    public:
        Test(int = 0);
        void print();
    private:
        int x;
};

Test::Test(int value):x(value) {} //constructor 

void Test::print() {
std::cout << " x = " << x;
std::cout << "\n this->x = " << this->x;
std::cout << "\n(*this).x = " << (*this).x << std::endl;
}

int main() {
Test testObject(12);
testObject.print();
return 0;
}