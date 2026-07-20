#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFileName;
    std::string searchWord;
    std::string replacementWord;
    std::string word;
    int count = 0;

    std::cout << "Enter the input file name: ";
    std::cin >> inputFileName;

    std::cout << "Enter the word to search for: ";
    std::cin >> searchWord;

    std::cout << "Enter the replacement word: ";
    std::cin >> replacementWord;

    std::ifstream inputFile(inputFileName);

    if (!inputFile) {
        std::cout << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::ofstream outputFile("output.txt");

    while (inputFile >> word) {
        if (word == searchWord) {
            outputFile << replacementWord << " ";
            count++;
        }
        else {
            outputFile << word << " ";
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "The word \"" << searchWord << "\" was found "
              << count << " times." << std::endl;

    std::cout << "The modified text has been saved to output.txt."
              << std::endl;

    return 0;
}