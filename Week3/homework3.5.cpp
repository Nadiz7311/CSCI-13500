#include <iostream>
#include <vector>

int main() {
    
// Task 1
    // Sets the matrix size
    int n = 3; 
    
    std::cout << "// Task 1: " << n << "x" << n << " array\n";

    std::vector<std::vector<int>> task1(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        std::cout << "[";
        for (int j = 0; j < n; ++j) {

            if (i + j < n) {
                task1[i][j] = 1;
            }
            std::cout << task1[i][j];
            if (j < n - 1) std::cout << "|";
        }
        std::cout << "]\n";
    }

// Task 2
    std::cout << "\n";

    std::vector<std::vector<int>> task2(n, std::vector<int>(n, 0));
    
        for (int i = 0; i < n; ++i) {
            std::cout << "[";
            for (int j = 0; j < n; ++j) {

            if (i == j || i + j == n - 1) {
                task2[i][j] = 1;
            }
            std::cout << task2[i][j];
            if (j < n - 1) std::cout << "|";
        }
        std::cout << "]\n"; 
    }

// Task 3
    std::cout << "\n";

    //Declare and initialize the vector
    std::vector<std::vector<int>> task3(n, std::vector<int>(n, 0));
    int counter = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            task3[i][j] = counter++;
        }
    }
    std::vector<std::vector<int>> sums(2, std::vector<int>(n, 0));

    //Calculation of row and column sums
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sums[0][i] += task3[i][j];
            sums[1][j] += task3[i][j];
    }

    for (int i = 0; i < 2; ++i) {
        std::cout << "[";
        for (int j = 0; j < n; ++j) {
            std::cout << sums[i][j];
            if (j < n - 1) std::cout << "|";
        }
        std::cout << "]\n";
        }
}

    return 0;
}