#include <initializer_list>
#include <iostream>
template <class T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

    void resize(int newSize);

public:
    Array(int initialCapacity = 10, int grow = 5);
    Array(std::initializer_list<T> list);
    ~Array();
    T& operator[](int index);
    void Add(const T& item);
    int GetSize() const;
    void SetSize(int newSize, int newGrow = 1);
};

template <class T>
Array<T>::Array(int initialCapacity, int grow) : size(0), capacity(initialCapacity), grow(grow) {
    data = new T[capacity];
}

template <class T>
Array<T>::Array(std::initializer_list<T> list) : size(list.size()), capacity(list.size()), grow(5) {
    data = new T[capacity];
    int i = 0;
    for (const T& item : list) {
        data[i++] = item;
    }
}

template <class T>
Array<T>::~Array() {
    delete[] data;
}

template <class T>
T& Array<T>::operator[](int index) {
    return data[index];
}

template <class T>
void Array<T>::Add(const T& item) {
    if (size >= capacity) {
        resize(capacity + grow);
    }
    data[size++] = item;
}

template <class T>
int Array<T>::GetSize() const {
    return size;
}

template <class T>
void Array<T>::SetSize(int newSize, int newGrow) {
    if (newSize > capacity) {
        resize(newSize);
    }
    grow = newGrow;
}

template <class T>
void Array<T>::resize(int newSize) {
    T* newData = new T[newSize];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newSize;
}
