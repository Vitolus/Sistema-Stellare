#ifndef DEEP_PTR_H
#define DEEP_PTR_H
#include <utility>
template <class T>
class Deep_ptr{
    typedef std::size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::ptrdiff_t difference_type;

    pointer ptr;
public:
    Deep_ptr(pointer =nullptr);
    Deep_ptr(const Deep_ptr&);
    ~Deep_ptr();
    Deep_ptr& operator=(const Deep_ptr&);
    T* operator->() const;
    bool operator==(const Deep_ptr&) const;
    bool operator!=(const Deep_ptr&) const;
    bool operator>(const Deep_ptr&) const;
    bool operator<(const Deep_ptr&) const;
    operator T*() const;
};

template <class T>
Deep_ptr<T>::Deep_ptr(pointer p): ptr(p){}

template <class T>
Deep_ptr<T>::Deep_ptr(const Deep_ptr& deep){
    if(!deep) ptr=nullptr;
    else ptr= deep.ptr->clone();
}

template <class T>
Deep_ptr<T>::~Deep_ptr(){
    if(ptr) delete ptr;
}

template <class T>
Deep_ptr<T>& Deep_ptr<T>::operator=(const Deep_ptr& deep){
    assert(this != &deep);
    if(ptr) delete ptr;
    ptr = deep.ptr->clone();
    return *this;
}

template <class T>
T* Deep_ptr<T>::operator->() const{
       return ptr;
}

template <class T>
bool Deep_ptr<T>::operator==(const Deep_ptr& dptr) const{
    return *ptr==*(dptr.ptr);
}

template <class T>
bool Deep_ptr<T>::operator!=(const Deep_ptr& dptr) const{
    return *ptr!=*(dptr.ptr);
}

template<class T>
bool Deep_ptr<T>::operator<(const Deep_ptr& dptr) const{
    return *ptr<*(dptr.ptr);
}

template<class T>
bool Deep_ptr<T>::operator>(const Deep_ptr& dptr) const{
    return *ptr>*(dptr.ptr);
}

template<class T>
Deep_ptr<T>::operator T *() const
{
    return ptr;
}


#endif // DEEP_PTR_H
