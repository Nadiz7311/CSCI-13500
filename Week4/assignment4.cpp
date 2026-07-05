#include <iostream>
#include <vector>
#include <string>

void removeCopies(std::vector<int>& data) {
    // Stop if vector is empty
    if (data.empty()) {
        return;
    }

    int write = 1;

    // Checking each value
    for (int read = 1; read < data.size(); read++) {
        // If current value is different, keep it
        if (data[read] != data[write - 1]) {
            data[write] = data[read];
            write++;
        }
    }

    // Cut off leftover duplicate values
    data.resize(write);
}

void isAnagram(std::string officer_name, std::string spy_name) {
    // If lengths are different. It is not a anagram
    if (officer_name.size() != spy_name.size()) {
        std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
        return;
    }

    // Store character counts
    std::vector<int> freq(256, 0);

    // Count letters in officer name
    for (char ch : officer_name) {
        freq[(unsigned char)ch]++;
    }

    // Subtract letters in spy name
    for (char ch : spy_name) {
        freq[(unsigned char)ch]--;
    }

    for (int count : freq) {
        if (count != 0) {
            std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
            return;
        }
    }

    std::cout << "No imposter detected!" << std::endl;
}

int main() {

    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    for (int data : server) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    // Remove duplicates
    removeCopies(server);

    // Print cleaned vector
    for (int data : server) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    // Test anagram cases
    isAnagram("syeda", "aysed");
    isAnagram("angelo", "annabeth");

    return 0;
}