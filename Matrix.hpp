#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

#include <iostream>
#include <istream>
#include <vector>

using std::size_t;
/**
 * @class Matrix
 * @brief A class for matrix opertaions
 */
template <typename T> class Matrix {
private:
  size_t m_;
  size_t n_;
  std::vector<T> data_;

public:
  Matrix(size_t m, size_t n) : m_(m), n_(n), data_(m_ * n_) {}
  Matrix() : m_(0), n_(0), data_(0) {}
  ~Matrix() = default;

  size_t getRow() const { return m_; }
  size_t getCol() const { return n_; }
  void setRow(size_t m) { m_ = m; }
  void setCol(size_t n) { n_ = n; }

  void resizeMatrix(size_t m, size_t n) {m_ = m; n_ = n; data_.resize(m * n);}
  T getT(size_t x, size_t y) const {return data_[y * n_ + x];}
  void setT(size_t x, size_t y , T t) {data_[y * n_ + x] = t;}

  /**
   * @brief assign a matrix using another one
   * @param a matrix's quote
   */
  Matrix &operator=(const Matrix &others) {
    this->m_ = others.m_;
    this->n_ = others.n_;
    this->data_ = others.data_;
    return *this;
  }

  /**
   * @brief add another matrix to this one
   * @param a matrix you want to add
   * @return the result matrix
   */
  Matrix<T> operator+(const Matrix &others) const {
    size_t m = this->m_;
    size_t n = this->n_;
    Matrix<T> result(m, n);
    if (m == others.m_ && n == others.n_) {

      for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
          result.setT(i, j, this->getT(i,j) + others.getT(i, j));
        }
      }
    }
    return result;
  }
  /**
   * @brief add another matrix to this one
   * @param a matrix you want to subscribe
   * @return the result matrix
   */
  Matrix<T> operator-(const Matrix& others) const {
    size_t m = this->m_;
    size_t n = this->n_;
    Matrix<T> result(m, n);
    if (m == others.m_ && n == others.n_) {

      for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
          result.setT(i, j, this->getT(i,j) - others.getT(i, j));
          
       }
      }
    }
    return result;
  }
  /**
   * @brief Multiplicate a double number to this matrix
   * @param a double number
   * @return the result matrix
   */
  Matrix<T> &operator*(const double k)  {
    for (auto &it : this->data_) {
      it *= k;
    }
    return *this;
  }
  /**
   * @brief Matrix mulplication
   * @param another matrix you want to mulplicate(ensure this's col == another's row)
   * @return a matrix with the result(quote)
   */
  Matrix<T> operator*(const Matrix &others) {
    Matrix result(this->m_, others.n_);
    if (this->n_ != others.m_) {
      std::cerr << "Invalid argument,invalid operation";
      return *this;
    } else {

      for (size_t i = 0; i < this->m_; ++i) {
        for (size_t j = 0; j < others.n_; ++j) {
          T sum = 0;
          for (size_t k = 0; k < this->n_; ++k) {
            sum += this->getT(i, k) * others.getT(k, j);
            result.setT(j, i, sum);
          }
        }
      }
    }
    return result;
  }
  /**
    * @brief cout the matrix
    * @param a ostream os and matrix
    * @return a quote of os
  */
  friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
    for (size_t i = 0; i < matrix.m_; ++i) {
      for (size_t j = 0; j < matrix.n_; ++j) {
        os << matrix.data_[i * matrix.n_ + j] << " ";
      }
      os << std::endl;
    }
    return os;
  }
  /**
    * @brief cin the matrix
    * @param a istream is and matrix
    * @return a quote of is
  */
  friend std::istream &operator>>(std::istream &is, Matrix<T> &matrix) {
    std::size_t rows;
    std::size_t cols;
    std::cout << "Please enter the rows : " << std::endl;
    is >> rows;
    std::cout << "Please enter the cols : " << std::endl;
    is >> cols;
    matrix.resizeMatrix(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < cols; ++j) {
        std::cout<<"Element["<<i<<"]"<<"["<<j<<"] : "<<std::endl;
        is >> matrix.data_[i * cols + j];
      }
    }
    return is;
  }
};
void menu(char ch);
#endif