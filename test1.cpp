#include <iostream>

int add(int num1, int num2);

int main() {
    int num1, num2;

    std::cout << "Enter Two Numbers\n";
    std::cin >> num1 >> num2;

    int result = add(num1, num2);

    std::cout << "The Sum is " << result << std::endl;
    return 0;
}

int add(int num1, int num2) {
    return num1 + num2;
}
