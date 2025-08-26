#ifndef ARRAY

#define ARRAY

class FixedArray {
    public:
        // Constructor basics
        FixedArray(int size);
        ~FixedArray();
        int size() const;

        // Element Access
        const int& operator[](int index) const;
        int& operator[](int index);

        int at(int index) const;

        int& front();
        const int& front() const;

        int& back();
        const int& back() const;

        int* data() const;


        // Iterators
        int *begin() const;
        int *end() const;

        // Modifiers
        void fill(int value);
        void swap(FixedArray &other);
    
    private:
        int *array;
        int array_size;
        void check_index(int index) const; 

};

class DynamicArray {
    private:
        int array_size;
        int *array;
        void check_index(int index) const;
        void checkArraySize() const;
        int capacity_size;
        void updateCapacity();

    public:
        // Constructor basics
        DynamicArray(int size);
        ~DynamicArray();

        void fillZero();
        void fillWith(int value);

        void assign(int begin, int end);
        
        int& at(int index);
        const int& at(int index) const;

        int& front();
        const int& front() const;
        
        int& back();
        const int& back() const;

        int* begin();
        const int* begin() const;

        int* end();
        const int* end() const;

        int capacity();
        void clear();
        int *data();
        bool empty();

        void earse();

        void insert(int index, int value);

        void pop_back();
        void push_back(int value);

        void reverse();
        void resize(int new_size, int value=0);
        int size();
        void swap(DynamicArray &other);

        // Operators
        int& operator[](int index) {check_index(index); return array[index];}
        const int& operator[](int index) const {check_index(index); return array[index];}
};

#endif