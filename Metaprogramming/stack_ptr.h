#ifndef STACK_PTR_H_INCLUDED
#define STACK_PTR_H_INCLUDED

using namespace std;

template<typename T>
class StackPtr{

public:
    unsigned long _cRefs;
    size_t _size;
    int _indexTop;
    int _indexBottom;
    int _capacity;

    T * _data;

    StackPtr(size_t = 11);
    StackPtr(T *, size_t, int indexTop, int indexBottom);

    StackPtr(StackPtr &&);
    StackPtr & operator=(StackPtr &&);

    StackPtr(const StackPtr &);
    StackPtr & operator=(const StackPtr &);

    virtual ~StackPtr();

    size_t get_size() const;

    unsigned long  get_refs() const{return _cRefs;}
    void set_refs(unsigned long  rfs){_cRefs = rfs;}

    int get_index_top() const {return _indexTop;}
    int get_index_bottom() const {return _indexBottom;}

    T & operator[](const size_t);

    void reallocation();

    bool push_top(const T&);
    bool push_top(T&&);

    bool push_bottom(const T&);
    bool push_bottom(T&&);

    void pop_top();
    void pop_bottom();

    bool get_top(T &);
    bool get_bottom(T &);

    void printStack(std::ostream & cout)const;

    friend void swap(StackPtr<T> & f_s, StackPtr<T> & s_s) throw(){
        swap(f_s._cRefs, s_s._cRefs);
        swap(f_s._size, s_s._size);
        swap(f_s._indexTop, s_s._indexTop);
        swap(f_s._indexBottom, s_s._indexBottom);
        swap(f_s._capacity, s_s._capacity);
    }

    friend std::ostream & operator<<(std::ostream & cout, const StackPtr<T> & rhs){
        rhs.printStack(cout);
        return cout;
    }

};


template <typename T>
bool StackPtr<T>::get_top(T & elem){
    if(_indexTop < 0)
        return false;

    elem = _data[_indexTop];
    return true;
}

template <typename T>
bool StackPtr<T>::get_bottom(T & elem){
    if(_indexBottom >= _size)
        return false;
    elem = _data[_indexBottom];
    return true;
}

template<typename T>
StackPtr<T>::StackPtr(const StackPtr & other):
    _size(other._size),
    _cRefs(other._cRefs),
    _indexTop(other._indexTop),
    _indexBottom(other._indexBottom),
    _capacity(other._capacity){
    _data = other._data;
}

template<typename T>
StackPtr<T> & StackPtr<T>::operator=(const StackPtr<T> & other){
    if (this != &other){
        _size = other._size;
        _cRefs = other._cRefs;
        _indexTop = other._indexTop;
        _indexBottom = other._indexBottom;
        _capacity = other._capacity;

        _data = other._data;
    }
    return *this;
}

template<typename T>
StackPtr<T> & StackPtr<T>::operator=(StackPtr<T> && other){
    if(_data)
        delete[] _data;

    _data = other._data;

    other._data = nullptr;

    _cRefs = 1;
    _size = other._size;
    _indexTop = other._indexTop;
    _indexBottom = other._indexBottom;
    _capacity = other._capacity;

    return *this;
}

template<typename T>
StackPtr<T>::StackPtr(StackPtr<T>&& other){
    if(_data)
        delete[] _data;

    _data = other._data;

    other._data = nullptr;

    _cRefs = 1;
    _size = other._size;
    _indexTop = other._indexTop;
    _indexBottom = other._indexBottom;
    _capacity = other._capacity;
}
/*
template <typename T>
bool StackPtr<T>::push_top(const T & value){
    if(_capacity < _size){
        _indexTop = (--_indexTop + _size)%_size;
        _data[_indexTop] = value;
        ++_capacity;
        return true;
    }else{
        try{
            reallocation();
            _data[(--_indexTop + _size)%_size] = value;
            ++_capacity;
            return true;
        }
        catch(exception& e){
            cout<<"Error in push_top "<< e.what() << endl;
            return false;
        }
    }
}
*/
template <typename T>
bool StackPtr<T>::push_top(T && value){
    if(_capacity < _size){
        _indexTop = (--_indexTop + _size)%_size;
        (_data +_indexTop) = t;
        ++_capacity;
        return true;
    }else{
        try{
            reallocation();
            _indexTop = (--_indexTop + _size)%_size;
            _data[_indexTop](value);
            ++_capacity;
            return true;
        }
        catch(exception& e){
            cout<<"Error in push_top "<< e.what() << endl;
            return false;
        }
    }
}

//!
template <typename T>
bool StackPtr<T>::push_bottom(const T & value){
    if(_capacity < _size){
        _indexBottom = (++_indexBottom + _size)%_size;
        _data[_indexBottom] = value;
        ++_capacity;
        return true;
    }else{
        try{
            reallocation();
            _data[(++_indexBottom + _size)%_size] = value;
            ++_capacity;
            return true;
        }
        catch(exception& e){
            cout<<"Error in push_top "<< e.what() << endl;
            return false;
        }
    }
}

template<typename T>
void StackPtr<T>::pop_top(){
    if(_capacity > 0){
        _indexTop = (++_indexTop + _size)%_size;
        --_capacity;
    }
}

template <typename T>
void StackPtr<T>::printStack(std::ostream & cout) const {
    if(_capacity > 0)
        for(int i = 0, j = _indexTop; i < _capacity;
        ++i, ++j%=_size)
            cout << j << " : " << _data[j] << endl;
    else
        cout << "null" << endl;

    cout<< "cRefs" << _cRefs << endl;
    cout<<endl;

}

template<typename T>
void StackPtr<T>::reallocation(){
    int badSize = _size;
    _size *= 2;

    try{
        T * newStackPtr =  new T[_size];

        int badIndBtm = _indexTop;

        for(int j = _indexTop; badIndBtm < _capacity + _indexTop; ++badIndBtm, ++j)
            newStackPtr[badIndBtm] = _data[j % badSize];

        delete[] _data;

        _data = newStackPtr;
        _indexBottom = badIndBtm - 1;

    }catch(exception & e){
        cout << e.what() << endl;
    }
}

template<typename T>
StackPtr<T>::StackPtr(size_t sz){
    cout << "constructor Stackptr " << sz << endl;
    if(_data)
        delete[] _data;

    _data = new T[sz];
    _cRefs = 1;
    _indexTop = sz;
    _indexBottom = -1;
    _size = sz;
    _capacity = 0;
}

template<typename T>
StackPtr<T>::~StackPtr(){
    cout << "destructor StackPtr "<< _size << endl;
    delete[] _data;
}

template<typename T>
T & StackPtr<T>::operator[](size_t ind){
    try{
        return _data[ind];
    }catch(exception& e){
        cout << "Error in operator[] " << e.what() << endl;
    }
}

template<typename T>
StackPtr<T>::StackPtr(T * arr, size_t sz, int iTop, int iBottom){
    _data = arr;

    _cRefs = 1;
    _indexTop = iTop;
    _indexBottom = iBottom;
    _size = sz;
    int cap = _indexBottom - _indexTop;
    if(cap < 0)
        cap = sz + cap;
    _capacity = cap + 1;
}

template<typename T>
size_t StackPtr<T>::get_size() const{
    return _size;
}

template<typename T>
void StackPtr<T>::pop_bottom(){
    if(_capacity > 0){
        _indexBottom = (--_indexBottom + _size) % _size;
    }
}
#endif // STACK_PTR_H_INCLUDED
