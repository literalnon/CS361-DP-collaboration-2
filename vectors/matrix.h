#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

using namespace std;

template<typename T>
class Matrix {
private:
    T * _matrix;
    size_t _m;
    size_t _n;

public:

    Matrix(size_t t_m = 2,size_t t_n = 2): _m(t_m), _n(t_n){
        _matrix = new T[t_m * t_n];
    }

    template<typename... Args>
    Matrix(size_t t_m,size_t t_n, Args... args): _m(t_m), _n(t_n){
            _matrix = new T[t_m * t_n]{args...};
    }

    Matrix(size_t t_m,size_t t_n, T * t_arr): _m(t_m), _n(t_n), _matrix(t_arr){}

    void printMatrix() const {
        for(size_t i = 0; i < _m; ++i){
            for(size_t j = 0; j < _n; ++j)
                cout << _matrix[j + i * _n] << " | ";
            cout << endl;
        }
        cout << endl;
    }

    T& operator()(int i, int j){
        return _matrix[i * _m + j];
    }

    Matrix<T>(Matrix<T> && other){
        cout << " move constructor " << endl;

    }

    ~Matrix<T>(){
        cout << "destructor " << _m << " " << _n << endl;
        delete [] _matrix;
    }

    Matrix<T> operator+(const Matrix<T> & r_value) const {
        Matrix<T> t_m(_m, _n);

        if(r_value._m == _m && r_value._n == _n)
            for(size_t i = 0; i < _m * _n; ++i)
                t_m._matrix[i] = _matrix[i] + r_value._matrix[i];

        return t_m;
    }

    Matrix<T> operator-(const Matrix<T> & r_value) const {
        Matrix<T> t_m(_m, _n);

        if(r_value._m == _m && r_value._n == _n)
            for(size_t i = 0; i < _m * _n; ++i)
                t_m._matrix[i] = _matrix[i] - r_value._matrix[i];

        return t_m;
    }

    Matrix<T> operator*(const Matrix<T> & r_value) const {
        Matrix<T> t_m(_m, r_value._n);

        if(_n != r_value._m)
            cout << "Error: dimensions must match! " << endl;
        else
            for(size_t i = 0; i < _m; ++i)
                for(size_t j = 0; j < r_value._n; ++j)
                    for(size_t k = 0; k < _n; ++k)
                        t_m._matrix[i * r_value._n + j] +=
                            _matrix[k + i * _n] *
                                r_value._matrix[k * r_value._n + j];

        return t_m;
    }

    Matrix<T> operator* (const T & c) const {
        Matrix<T> t_m(_m, _n);

        for(size_t i = 0; i < _m * _n; ++i)
            t_m._matrix[i] = _matrix[i] * c;

        return t_m;
    }

};

#endif // MATRIX_H_INCLUDED
