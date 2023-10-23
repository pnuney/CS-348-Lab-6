#include <iostream>
#include <fstream>
#include <iomanip>

//max size for matrix
const int MAX_SIZE = 100;

void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int& N, const std::string& fileName);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N, const std::string& matrixName);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);

int main() {
    std::cout << "Priyatam\nLab #6: Matrix manipulation\n\n";

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int N;

    //read matrix from the file
    readMatrixFromFile(matrixA, N, "matrix_input.txt");
    readMatrixFromFile(matrixB, N, "matrix_input.txt");

    //return matrices
    printMatrix(matrixA, N, "Matrix A");
    printMatrix(matrixB, N, "Matrix B");

    //operations on matrices
    addMatrices(matrixA, matrixB, result, N);
    printMatrix(result, N, "Matrix Sum (A + B)");

    multiplyMatrices(matrixA, matrixB, result, N);
    printMatrix(result, N, "Matrix Product (A * B)");

    subtractMatrices(matrixA, matrixB, result, N);
    printMatrix(result, N, "Matrix Difference (A - B)");

    return 0;
}

//create a function to read matrix from a file
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int& N, const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: cannot open file " << fileName << std::endl;
        exit(1);
    }

    inputFile >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();
}

//create a function to return the matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N, const std::string& matrixName) {
    std::cout << matrixName << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//create a function to add two matrices together and have the result be returned as a new third matrix
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

//create a fucntion to multiple two matrices together and have the result be stored as a new third matrix
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

//create a function to subtract two matrices and have the result be stored as a new third matrixc
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
