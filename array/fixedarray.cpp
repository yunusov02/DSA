#include <iostream>
#include "array.h"

using namespace std;


FixedArray::FixedArray(int size) {

    if (size < 0) {
        throw invalid_argument("Size must be greather than zero");
    }
    array_size = size;
    array = new int[size];
}

FixedArray::~FixedArray() {
    delete[] array;
}

void FixedArray::check_index(int index) const{
    if (index < 0 || index >= array_size)
        throw invalid_argument("Invalid index of array");
}

void FixedArray::fill(int value) {
    for (int i = 0; i < array_size; i++) {
        array[i] = value;
    }
}

int FixedArray::size() const {
    return array_size;
}

const int& FixedArray::operator[](int index) const {
    return array[index]; // no check
}

int& FixedArray::operator[](int index) {
    return array[index];
}

int FixedArray::at(int index) const {
    check_index(index);
    return array[index];
}

int& FixedArray::front() { return array[0]; }
const int& FixedArray::front() const { return array[0]; }

int& FixedArray::back() { return array[array_size - 1]; }
const int& FixedArray::back() const { return array[array_size - 1]; }


int *FixedArray::begin() const{
    return array;
}

int *FixedArray::end() const {
    return array + array_size;
}

void FixedArray::swap(FixedArray &other) {
    delete[] array;

    array_size = other.size();

    array = new int[array_size];

    for (int i = 0; i < array_size; i++) {
        array[i] = other[i];
    }
}

