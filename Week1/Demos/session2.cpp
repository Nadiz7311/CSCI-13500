#include <iostream>

int main(){
 
    //Enter age
    int age = 0;
    std::cout << "Enter age: ";

    //Valitdate input
    while(std::cin >> age){
        if (std::cin.fail()){
            std::cout << "Invalid input!" << std::endl;
        }

        if (age < 0){
            std::cout << "Cannot input negative numbers" << std::endl;
            break;
        }

        //Print out what they are legally allowed to do at that tate

        if (age >= 18){
            std::cout << "You can vote!" << std::endl;
        }

        if (age >= 21){
            std::cout << "You can drink!" << std::endl;
        }

        if (age < 18 && age >= 0){
            std::cout << "You are a minor!" << std::endl;
        }
    }

}
