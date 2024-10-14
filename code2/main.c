/*Author: Jett Viduya
  KUID: 3115988
  Date: 10/11/24
  Lab: 5
  Purpose: The Matrix Manipulation program asks you to read input for two matrices and develop functions for the following matrix manipulations:

Add Two Matrices: This function should take two matrices as input and return their sum.

Multiply Two Matrices: This function should take two matrices as input and return their product.

Transpose a Matrix: This function should take a matrix as input and return its transpose.

Print a Matrix: This function should take a matrix as input and print it in a user-friendly format.*/
#include <stdio.h>

#define SIZE 5 // Define the size of the matrices

// Function prototypes
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main() {
    //Define two matrices from instructions
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int sum[SIZE][SIZE];        //Matrix to hold the sum of m1 and m2
    int product[SIZE][SIZE];    //Matrix to hold the product of m1 and m2
    int transpose[SIZE][SIZE];  //Matrix to hold the transpose of m1

    //Perform matrix addition
    addMatrices(m1, m2, sum);
    printf("Sum of matrices:\n");
    printMatrix(sum);

    //Perform matrix multiplication
    multiplyMatrices(m1, m2, product);
    printf("\nProduct of matrices:\n");
    printMatrix(product);

    //Perform matrix transpose
    transposeMatrix(m1, transpose);
    printf("\nTranspose of the first matrix:\n");
    printMatrix(transpose);

    return 0;
}

//Function to add two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //Loop through each element and add the corresponding elements
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

//Function to multiply two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //Initialize the result matrix with zeros
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; //Ensure result matrix is cleared before use
        }
    }

    //Multiply the matrices
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

//Function to transpose a matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    //Loop through each element and swap the indices
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

//Function to print a matrix in a user-friendly format
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", matrix[i][j]); //Print each element with padding
        }
        printf("\n"); //Newline after each row
    }
}
