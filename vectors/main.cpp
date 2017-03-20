#include<iostream>
#include"matrix.h"

using namespace std;

int main(){

    Matrix<int> m(3, 3, 2, 3, 4, 1, 5, 6, 7, 1, 8);
    //Matrix<string> s(2, 3, "roses", "are", "red", "violets", "are", "blue");
    //s.printMatrix();
    Matrix<int> m1(3, 2, 5, 2, 3, 4, 1, 6);
    Matrix<int> m2(m);
   // m2.printMatrix();
    //Matrix<int> v(3, 1, 5, 3, 1);
    //cout << " m * v " << m(1, 2) << endl;
    //(m * m1).printMatrix();
    /*cout << " m - m1 " << endl;
    (m - m1).printMatrix();
    cout << " m * m1 " << endl;
    (m * m1).printMatrix();
    cout << " matrix m * 10 " << endl;
    (m * 10).printMatrix();
    cout << " matrix " << endl;
    m1.printMatrix();
    m.printMatrix();
    Matrix<string> ms(1,1);
    ms(0, 0) = "Hello";*/
    return 0;
}
