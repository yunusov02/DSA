#include <iostream>

#include "array.h"

using namespace std;


DynamicArray::DynamicArray(int size) {
    if (size < 0)
        throw invalid_argument("Size must be greater than zero");
    
    array_size = size;
    array = new int[size];
    capacity_size = size;
    
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

int DynamicArray::size() {
    return array_size;
}

void DynamicArray::fillZero() {
    for (int i = 0; i < array_size; i++) {
        array[i] = 0;
    }
}

void DynamicArray::fillWith(int value) {
    for (int i = 0; i < array_size; i++) {
        array[i] = value;
    }
}

void DynamicArray::check_index(int index) const {
    if (index < 0 || index >= array_size) {
        throw range_error("Index out of range");
    }
}

void DynamicArray::checkArraySize() const{
    if (array_size == 0)
        throw invalid_argument("Array size is zero");
}

int& DynamicArray::at(int index) {
    check_index(index);    
    return array[index];
}

const int& DynamicArray::at(int index) const {
    check_index(index);    
    return array[index];
}

int& DynamicArray::front() {
    checkArraySize();
    return array[0];
}

const int& DynamicArray::front() const {
    checkArraySize();
    return array[0];
}

int& DynamicArray::back() {
    checkArraySize();
    return array[array_size - 1];
}

const int& DynamicArray::back() const {
    checkArraySize();
    return array[array_size - 1];
}

int* DynamicArray::begin() {
    return array;
}

const int* DynamicArray::begin() const {
    return array;
}

int* DynamicArray::end() {
    return array + array_size;
}

const int* DynamicArray::end() const {
    return array + array_size;
}

int DynamicArray::capacity() {
    return capacity_size;
}

void DynamicArray::clear() {
    for (size_t i = 0; i < array_size; ++i) {
        array[i] = 0;
    }
    array_size = 0; // reset size
}


int* DynamicArray::data() {
    return array;
}

bool DynamicArray::empty() {
    return array_size == 0;
}

void DynamicArray::insert(int index, int value) {
    int *new_array = new int[array_size + 1];

    int counter = 0;
    for (int i = 0; i < array_size + 1; i++) {
        if (i == index) {
            new_array[i] = value; 
            continue;
        } 

        new_array[i] = array[counter];
        counter += 1;
    }

    delete[] array;

    array = new_array;
    array_size += 1;

    updateCapacity();
}

void DynamicArray::push_back(int value) {
    int *new_array = new int[array_size + 1];

    for (int i = 0; i < array_size; i++) {        
        new_array[i] = array[i];
    }    

    new_array[array_size] = value;

    delete[] array;

    array = new_array;
    array_size += 1;

    updateCapacity();
}

void DynamicArray::pop_back() {
    if (array_size == 0) {
        throw std::out_of_range("Cannot pop_back from empty array");
    }

    int* new_array = new int[array_size - 1];
    for (int i = 0; i < array_size - 1; i++) {
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
    array_size -= 1;
    capacity_size = array_size; // shrink capacity too
}

void DynamicArray::reverse() {
    for (int i = 0; i < array_size / 2; i++) {
        std::swap(array[i], array[array_size - i - 1]);
    }
}

void DynamicArray::resize(int new_size, int value) {
    int *new_array = new int[new_size];

    for (int i = 0; i < new_size; i++) {
        if (i >= array_size) {
            new_array[i] = value;
        } else {
            new_array[i] = array[i];
        }
    }

    delete[] array;

    array = new_array;
    array_size = new_size;

    updateCapacity();
}


void DynamicArray::swap(DynamicArray &other) {
    std::swap(array, other.array);
    std::swap(array_size, other.array_size);
    std::swap(capacity_size, other.capacity_size);
}

void DynamicArray::updateCapacity() {
    if (array_size >= capacity_size) {
        capacity_size *= 2;
    }
}