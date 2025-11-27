#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        data.resize(rows, vector<T>(cols, 0));
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void input() {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
        for (auto rowIt = data.begin(); rowIt != data.end(); ++rowIt) {
            for (auto colIt = rowIt->begin(); colIt != rowIt->end(); ++colIt) {
                cin >> *colIt;
            }
        }
    }

    void print() const {
        cout << "Matrix:\n";
        for (auto rowIt = data.begin(); rowIt != data.end(); ++rowIt) {
            for (auto colIt = rowIt->begin(); colIt != rowIt->end(); ++colIt) {
                cout << *colIt << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix sizes do not match for addition");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw invalid_argument("Cannot multiply matrices: incompatible sizes");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
        return result;
    }

    // Multiply by vector
    vector<T> operator*(const vector<T>& vec) const {
        if (cols != vec.size())
            throw invalid_argument("Vector size does not match matrix columns");
        vector<T> result(rows, 0);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[i] += data[i][j] * vec[j];
        return result;
    }
};
