#include <iostream>

// Reminder: Information about functions is on the specification PDF

// Prints a 2D array in the format:
// [1|2|3]
// [4|5|6]
void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total) {
    std::cout << "Function Called:\nPrint2DArray\n\n";

    // Time complexity: O(rows * 3) because we only visit each element one
    for (int r = 0; r < matrix_local_rows_total; ++r) {
        std::cout << "[";
        for (int c = 0; c < 3; ++c) {
            std::cout << matrix_local[r][c];
            if (c < 2) {
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }

    std::cout << "\nEnd of function:\nPrint2DArray\n\n";
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total) {
    std::cout << "Function Called:\nMatrixAddition\n\n";

    int result[3][3] = {0};

    // Time complexity: O(rows * 3)
    for (int r = 0; r < matrix_one_rows_total; ++r) {
        for (int c = 0; c < 3; ++c) {
            result[r][c] = matrix_one[r][c] + matrix_two[r][c];
        }
    }

    std::cout << "Result of matrix addition:\n";
    Print2DArray(result, matrix_one_rows_total);

    std::cout << "End of function:\nMatrixAddition\n\n";
}

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total) {
    std::cout << "Function Called:\nTransposeMatrix\n\n";

    int transposed[3][3] = {0};

    // Time complexity: O(rows * 3) because we copy each element once
    for (int r = 0; r < matrix_local_rows_total; ++r) {
        for (int c = 0; c < 3; ++c) {
            transposed[c][r] = matrix_local[r][c];
        }
    }

    std::cout << "Transposed matrix:\n";
    // We print 3 rows because the transposed matrix has 3 rows
    Print2DArray(transposed, 3);

    std::cout << "End of function:\nTransposeMatrix\n\n";
}

void Determinant(const int matrix_local[][3], const int size) {
    std::cout << "Function Called:\nDeterminant\n\n";

    // 2x2 determinant: |a b; c d| = a*d - b*c
    // 3x3 determinant using expansion:
    // a(ei - fh) - b(di - fg) + c(dh - eg)

    if (size == 2) {
        int a = matrix_local[0][0];
        int b = matrix_local[0][1];
        int c = matrix_local[1][0];
        int d = matrix_local[1][1];

        // Time complexity: O(1) because there is a fixed number of operations
        int det = a * d - b * c;
        std::cout << "Determinant (2x2) = " << det << "\n";
    } else if (size == 3) {
        int a = matrix_local[0][0];
        int b = matrix_local[0][1];
        int c = matrix_local[0][2];
        int d = matrix_local[1][0];
        int e = matrix_local[1][1];
        int f = matrix_local[1][2];
        int g = matrix_local[2][0];
        int h = matrix_local[2][1];
        int i = matrix_local[2][2];

        // Time complexity: O(1) because there is a fixed number of operations
        int det = a * (e * i - f * h)
                - b * (d * i - f * g)
                + c * (d * h - e * g);

        std::cout << "Determinant (3x3) = " << det << "\n";
    } else {
        std::cout << "Determinant is only implemented for 2x2 and 3x3 matrices.\n";
    }

    std::cout << "\nEnd of function:\nDeterminant\n\n";
}

void SearchValue(const int matrix_local[][3], const int rows, const int target) {
    std::cout << "Function Called:\nSearchValue\n\n";

    bool found = false;

    // Time complexity: O(rows * 3) becuase we check each element once
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (matrix_local[r][c] == target) {
                found = true;
                std::cout << "Found " << target << " at ["
                          << r << "][" << c << "]\n";
            }
        }
    }

    if (!found) {
        std::cout << target << " was not found in the matrix\n";
    }

    std::cout << "\nEnd of function:\nSearchValue\n\n";
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3],
                          const int rows_a, const int cols_a,
                          const int rows_b, const int cols_b) {
    std::cout << "Function Called:\nMatrixMultiplication\n\n";

    //Number of columns of A must equal number of rows of B
    if (cols_a != rows_b) {
        std::cout << "Matrices cannot be multiplied: cols_a != rows_b.\n";
        std::cout << "\nEnd of function:\nMatrixMultiplication\n\n";
        return;
    }

    int result[3][3] = {0};

    // Time complexity: O(rows_a * cols_b * cols_a)
    for (int i = 0; i < rows_a; ++i) {
        for (int j = 0; j < cols_b; ++j) {
            int sum = 0;
            for (int k = 0; k < cols_a; ++k) {
                sum += matrix_a[i][k] * matrix_b[k][j];
            }
            result[i][j] = sum;
        }
    }

    std::cout << "Result of matrix multiplication:\n";
    Print2DArray(result, rows_a);

    std::cout << "End of function:\nMatrixMultiplication\n\n";
}

int main() {
    // Use these two matrices for basic testing

    int testing_matrix_one[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int testing_matrix_two[3][3] = {
        {12, 65, 82},
        {83, 2, 8},
        {10, 96, 67}
    };

    int size_row_one = sizeof(testing_matrix_one) / sizeof(testing_matrix_one[0]);
    int size_col_one = sizeof(testing_matrix_one[0]) / sizeof(testing_matrix_one[0][0]);

    std::cout << "row: " << size_row_one << " col: " << size_col_one << std::endl << std::endl;

    Print2DArray(testing_matrix_one, size_row_one);
    MatrixAddition(testing_matrix_one, size_row_one,
                   testing_matrix_two, size_row_one);
    TransposeMatrix(testing_matrix_one, size_row_one);
    Determinant(testing_matrix_one, 3);
    SearchValue(testing_matrix_two, size_row_one, 96);
    MatrixMultiplication(testing_matrix_one, testing_matrix_two,
                         size_row_one, size_col_one,
                         size_row_one, size_col_one);

    return 0;
}