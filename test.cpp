#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "matrix.h"
#include <iostream>
using namespace std;

TEST_CASE("Matrix initialization and display", "[initialization][display]") {
    Matrix mat(3);

    REQUIRE(mat.getElement(0, 0) == 0);
    REQUIRE(mat.getElement(0, 1) == 0);
    REQUIRE(mat.getElement(0, 2) == 0);
    REQUIRE(mat.getElement(1, 0) == 0);
    REQUIRE(mat.getElement(1, 1) == 0);
    REQUIRE(mat.getElement(1, 2) == 0);
    REQUIRE(mat.getElement(2, 0) == 0);
    REQUIRE(mat.getElement(2, 1) == 0);
    REQUIRE(mat.getElement(2, 2) == 0);
}

TEST_CASE("Matrix set and get elements", "[set][get]") {
    Matrix mat(3);

    mat.setElement(0, 0, 5);
    mat.setElement(1, 1, -3);
    mat.setElement(2, 2, 7);

    REQUIRE(mat.getElement(0, 0) == 5);
    REQUIRE(mat.getElement(1, 1) == -3);
    REQUIRE(mat.getElement(2, 2) == 7);
}

TEST_CASE("Matrix determinant calculation", "[determinant]") {
    Matrix mat(3);

    mat.setElement(0, 0, 1);
    mat.setElement(0, 1, 2);
    mat.setElement(0, 2, 3);
    mat.setElement(1, 0, 0);
    mat.setElement(1, 1, 1);
    mat.setElement(1, 2, 4);
    mat.setElement(2, 0, 5);
    mat.setElement(2, 1, 6);
    mat.setElement(2, 2, 0);

    REQUIRE(mat.getDeterminant() == 1);
}

TEST_CASE("Matrix inverse calculation", "[inverse]") {
    Matrix mat(3);

    mat.setElement(0, 0, 4);
    mat.setElement(0, 1, 7);
    mat.setElement(0, 2, 2);
    mat.setElement(1, 0, 3);
    mat.setElement(1, 1, 5);
    mat.setElement(1, 2, 1);
    mat.setElement(2, 0, 2);
    mat.setElement(2, 1, 3);
    mat.setElement(2, 2, 1);

    Matrix *ptr = mat.getInverse();
    REQUIRE(ptr->getElement(0, 0) == -2);
    REQUIRE(ptr->getElement(0, 1) == 1);
    REQUIRE(ptr->getElement(0, 2) == 3);
    REQUIRE(ptr->getElement(1, 0) == 1);
    REQUIRE(ptr->getElement(1, 1) == 0);
    REQUIRE(ptr->getElement(1, 2) == -2);
    REQUIRE(ptr->getElement(2, 0) == 1);
    REQUIRE(ptr->getElement(2, 1) == -2);
    REQUIRE(ptr->getElement(2, 2) == 1);
}


TEST_CASE("Matrix transpose operation", "[transpose]") {
    Matrix mat(3);

    mat.setElement(0, 0, 1);
    mat.setElement(0, 1, 2);
    mat.setElement(0, 2, 3);
    mat.setElement(1, 0, 4);
    mat.setElement(1, 1, 5);
    mat.setElement(1, 2, 6);
    mat.setElement(2, 0, 7);
    mat.setElement(2, 1, 8);
    mat.setElement(2, 2, 9);

    Matrix *ptr = mat.getTranspose();
    REQUIRE(ptr->getElement(0, 0) == 1);
    REQUIRE(ptr->getElement(0, 1) == 4);
    REQUIRE(ptr->getElement(0, 2) == 7);
    REQUIRE(ptr->getElement(1, 0) == 2);
    REQUIRE(ptr->getElement(1, 1) == 5);
    REQUIRE(ptr->getElement(1, 2) == 8);
    REQUIRE(ptr->getElement(2, 0) == 3);
    REQUIRE(ptr->getElement(2, 1) == 6);
    REQUIRE(ptr->getElement(2, 2) == 9);
}



TEST_CASE("Matrix multiplication operation", "[multiplication]") {
    Matrix mat1(3);
    Matrix mat2(3);

    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(0, 2, 3);
    mat1.setElement(1, 0, 4);
    mat1.setElement(1, 1, 5);
    mat1.setElement(1, 2, 6);
    mat1.setElement(2, 0, 7);
    mat1.setElement(2, 1, 8);
    mat1.setElement(2, 2, 9);

    mat2.setElement(0, 0, 1);
    mat2.setElement(0, 1, 2);
    mat2.setElement(0, 2, 3);
    mat2.setElement(1, 0, 4);
    mat2.setElement(1, 1, 5);
    mat2.setElement(1, 2, 6);
    mat2.setElement(2, 0, 7);
    mat2.setElement(2, 1, 8);
    mat2.setElement(2, 2, 9);

    Matrix *ptr = mat1.multiply(mat2);
    REQUIRE(ptr->getElement(0, 0) == 30);
    REQUIRE(ptr->getElement(0, 1) == 36);
    REQUIRE(ptr->getElement(0, 2) == 42);
    REQUIRE(ptr->getElement(1, 0) == 66);
    REQUIRE(ptr->getElement(1, 1) == 81);
    REQUIRE(ptr->getElement(1, 2) == 96);
    REQUIRE(ptr->getElement(2, 0) == 102);
    REQUIRE(ptr->getElement(2, 1) == 126);
    REQUIRE(ptr->getElement(2, 2) == 150);
}
TEST_CASE("Matrix trace calculation", "[trace]") {
    Matrix mat(3, 3);

    // Set elements on the diagonal
    mat.setElement(0, 0, 1.0);
    mat.setElement(1, 1, 2.0);
    mat.setElement(2, 2, 3.0);

    // Calculate and check the trace
    REQUIRE(mat.getTrace() == 6.0); // 1.0 + 2.0 + 3.0
}
TEST_CASE("Matrix inversion (invertible matrix)", "[inverse]") {
    Matrix mat(2, 2);

    // Set elements in the matrix
    mat.setElement(0, 0, 4);
    mat.setElement(0, 1, 7);
    mat.setElement(1, 0, 2);
    mat.setElement(1, 1, 6);

    // Calculate the inverse
    Matrix inv = mat.getInverse();

    // Check the inverse matrix elements
    REQUIRE(inv.getElement(0, 0) == Approx(0.6));
    REQUIRE(inv.getElement(0, 1) == Approx(-0.7));
    REQUIRE(inv.getElement(1, 0) == Approx(-0.2));
    REQUIRE(inv.getElement(1, 1) == Approx(0.4));
}
TEST_CASE("Matrix inversion (non-invertible matrix)", "[inverse]") {
    Matrix mat(2, 2);

    // Set elements in the matrix that result in a determinant of 0
    mat.setElement(0, 0, 1);
    mat.setElement(0, 1, 2);
    mat.setElement(1, 0, 2);
    mat.setElement(1, 1, 4);

    // Try to calculate the inverse
    Matrix inv = mat.getInverse();

    // Since the matrix is non-invertible, inv should be an empty or unchanged matrix
    REQUIRE(inv.getElement(0, 0) == 0);
    REQUIRE(inv.getElement(0, 1) == 0);
    REQUIRE(inv.getElement(1, 0) == 0);
    REQUIRE(inv.getElement(1, 1) == 0);
}
TEST_CASE("Matrix initialization error (non-square matrix)", "[initialization]") {
    Matrix mat(2, 3);

    // Check that the matrix should not allow non-square matrices for this problem
    REQUIRE(mat.getRows() == 0);
    REQUIRE(mat.getCols() == 0);
}
