#include <iostream>

int main(){

    // naming variables
    double num1;
    double num2;
    std::string operation;

    // ask user for two numbers
    std::cout << "Enter number one: ";
    std::cin >> num1;
    // checking to see if entered input is a number
    if (std::cin.fail()) {
        std::cout << "You did not enter a number";
        return 1;
    }
    
    std::cout << "Enter your desired operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter number two: ";
    std::cin >> num2;
    // checking to see if entered input is a number
    if (std::cin.fail()) {
        std::cout << "You did not enter a number";
        return 1;
    }

    // computes the math problem using the desired operation
    if (operation == "+") {
        std::cout << "Result: " << num1 + num2 << std::endl;

    } else if (operation == "-") {
        std::cout << "Result: " << num1 - num2 << std::endl;

    } else if (operation == "*") {
        std::cout << "Result: " << num1 * num2 << std::endl;

    } else if (operation == "/") {
        if (num2 == 0) {
            // checking for divide by 0 error
            std::cout << "Cannot divide by zero";
        } else {
        std::cout << "Result: " << num1 / num2 << std::endl;
        }

        //when user select a value outside of valid operations
    } else (std::cout << "You did not enter a valid operation");

    return 0;
}