
#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#include"stack_ptr.h"

#define unshareable 0

using namespace std;

template<typename T>
class TwoSideStack
{
private:
    StackPtr<T> *_stackPtr;

public:
    TwoSideStack(size_t = 20);

    TwoSideStack(TwoSideStack &&);
    TwoSideStack & operator=(TwoSideStack &&);

    TwoSideStack(const TwoSideStack &);
    TwoSideStack & operator=(const TwoSideStack &);

    friend std::ostream & operator<<(std::ostream & os, const TwoSideStack<T> & rhs)
    {
        os << *rhs._stackPtr;
        return os;
    }

    friend void swap(TwoSideStack<T> & f_s, TwoSideStack<T> & s_s) throw() {
        swap(f_s._stackPtr, s_s._stackPtr);
    }

    virtual ~TwoSideStack();

    //bool top(const T&);
    bool push_bottom(const T&);


    bool push_top(T&&);
    bool push_bottom(T&&);

    void pop_top();
    void pop_bottom();

    bool get_top(T & );
    bool get_bottom(T & );

    void printStack();

    void reallocation();

    void deep_copy();

    size_t capacity()const{
        return _stackPtr->_capacity;
    }

    size_t size(){
        return _stackPtr->_size;
    }


    class iterator{
    protected:
        StackPtr<T> *_stackPtr;
         int i;
    public:
        iterator(StackPtr<T> * stackPtr, int index){
            _stackPtr = stackPtr;
            i = index;
        }

        iterator& operator++(){
            if(i != _stackPtr->get_index_bottom() + 1)
                i = (i + 1) % _stackPtr->get_size();
            return *this;
        }

        iterator& operator--(){
            if(i  != _stackPtr->get_index_top())
                i = (i - 1 + _stackPtr->get_size()) % _stackPtr->get_size();
            return *this;
        }

        iterator operator++(int){
            if(i != _stackPtr->get_index_bottom() + 1)
                i = (i + 1) % _stackPtr->get_size();
            return *this;
        }

        iterator operator--(int){
            if(i  != _stackPtr->get_index_top())
                i = (i - 1 + _stackPtr->get_size()) % _stackPtr->get_size();
            return *this;
        }

        bool operator<(const iterator & it)const{
            int top = _stackPtr->get_index_top();

            int dif_this = i - top;
            int dif_other = it.i - top;

            if((dif_this > 0 && dif_other < 0) || (dif_this < 0 && dif_other > 0))
                return dif_this > dif_other;

            return dif_this < dif_other;

        }

        bool operator==(const iterator & it) const{
            return i == it.i;
        }

        bool operator>(const iterator & it)const{
            return !((*this < it) || (*this == it));
        }

        bool operator!=(const iterator & it)const{
            return !(*this == it);
        }

        T & operator*()const {
            return _stackPtr->_data[i];
        }
    };

    class const_iterator: public iterator{
    public:
        const T & operator*()const {
            return this->_stackPtr->_data[this->i];
        }

        const_iterator(StackPtr<T> *stackPtr, int index):
            iterator(stackPtr, index){}
    };

    iterator begin(){
        return iterator(_stackPtr, _stackPtr->get_index_top());
    }

    iterator end(){
        return iterator(_stackPtr, _stackPtr->get_index_bottom() + 1);
    }

    const_iterator begin_const(){
        return const_iterator(_stackPtr, _stackPtr->get_index_top());
    }

    const_iterator end_const(){
        return const_iterator(_stackPtr, _stackPtr->get_index_bottom() + 1);
    }
};


template <typename T>
bool TwoSideStack<T>::get_top(T & elem){
    return _stackPtr->get_top(elem);
}

template <typename T>
bool TwoSideStack<T>::get_bottom(T & elem){
    return _stackPtr->get_bottom(elem);
}
/*
template <typename T>
TwoSideStack<T> & TwoSideStack<T>::operator=(TwoSideStack<T> && other){
    this->_stackPtr = other._stackPtr;
}
*/
template <typename T>
TwoSideStack<T>::TwoSideStack(const TwoSideStack<T> & other){
    cout << "constructor copy" << endl;
    this->_stackPtr = other._stackPtr;
    _stackPtr->set_refs(_stackPtr->get_refs() + 1);
}

template <typename T>
TwoSideStack<T> & TwoSideStack<T>::operator=(const TwoSideStack<T> & other){
    _stackPtr->set_refs(_stackPtr->get_refs() + 1);
    this->_stackPtr = other._stackPtr;

    return *this;
}

template <typename T>
void TwoSideStack<T>::deep_copy(){
    if(_stackPtr->get_refs() > 1)
    {
        _stackPtr->set_refs(_stackPtr->get_refs() - 1);

        size_t sz = _stackPtr->get_size();
        int iTop = _stackPtr->get_index_top();
        int iBottom = _stackPtr->get_index_bottom();
        T * arr = (T*)calloc(sz, sizeof(arr));

        //std::copy(_stackPtr->_data, _stackPtr->_data + sz, arr);
        for(int i = 0; i < _stackPtr->_capacity; i++){
            new (arr + i) T (std::move(_stackPtr->_data[i]));
        }


        _stackPtr = new StackPtr<T>(arr, sz, iTop, iBottom);
    }
}

template <typename T>
TwoSideStack<T>::TwoSideStack(size_t s){
    _stackPtr = new StackPtr<T>(s);
}

template <typename T>
TwoSideStack<T>::~TwoSideStack(){
    if(_stackPtr->get_refs() == 1)
        _stackPtr->~StackPtr();
    else
        _stackPtr->set_refs(_stackPtr->get_refs() - 1);
}
/*
template <typename T>
bool TwoSideStack<T>::push_top(const T & value){
    deep_copy();
    return _stackPtr->push_top(value);
}
*/
template <typename T>
bool TwoSideStack<T>::push_top(T && value){
    deep_copy();
    return _stackPtr->push_top(std::move(value));
}

template <typename T>
bool TwoSideStack<T>::push_bottom(const T& value){
    deep_copy();
    return _stackPtr->push_bottom(value);
}

template <typename T>
bool TwoSideStack<T>::push_bottom(T && value){
    deep_copy();
    return _stackPtr->push_bottom(std::move(value));
}

template <typename T>
void TwoSideStack<T>::reallocation(){
    _stackPtr->reallocation();
}

template<typename T>
void TwoSideStack<T>::pop_top(){
    deep_copy();
    _stackPtr->pop_top();
}

template<typename T>
void TwoSideStack<T>::pop_bottom(){
    deep_copy();
    _stackPtr->pop_bottom();
}

template <typename T>
void TwoSideStack<T>::printStack(){
    _stackPtr->printStack(cout);
}

template<typename T>
void output(TwoSideStack<T> & container)
{
    cout << container << endl;
}

#endif // STACK_INCLUDED
