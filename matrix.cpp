#include "Matrix.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>
using namespace std;
void menu(char ch);
int main() {
  Matrix<int> A;
  Matrix<int> B;
  Matrix<int> C;
  // show operator>>
  cout<<"Please enter two square matrix."<<endl;
  cout << "Please cin matrix A" << endl;
  cin >> A;
  cout << "Please cin matrix B" << endl;
  cin >> B;

  // show operator+ and <<
  C = A + B;
  cout<<"The result of A + B is "<<endl;
  cout << C;

  // show operator - and <<
  C = A - B;
  cout << "The result of A - B is :" << endl;
  cout << C;
    // show operator* and<<
    C = A * B;
    cout<<"The result of A * B is :"<<endl;
    cout<<C;
    cout<<"The result of A * 3 is "<<endl;
    cout<<C * 3;
    cout<<"When A's m == B's n : "<<endl;
    cout<<"Now I set and show : "<<endl;
    int example = 0;
    A.resizeMatrix(3, 2);
    for (size_t i = 0; i < 3; ++i) {
      for(size_t j = 0; j < 2; ++j) {
        example++;
        A.setT(i, j, example);
      }
    }
    cout<<A<<endl;
    B.resizeMatrix(2, 3);
    for (size_t i = 0; i < 3; ++i) {
      for(size_t j = 0; j < 2; ++j) {
        example++;
        B.setT(i, j, example);
      }
    }
    cout<<B;
    C = A * B;
    cout<<"The result of A * B is :"<<endl;
    cout<<C;
  return 0;
}
