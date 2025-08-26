#ifndef NODES
#define NODES

template<typename T>
class Node {
    private:
        T data;
        Node<T> *next;

    public:
        Node() {}
        Node(T d) {
            data = d;
            next = nullptr;
        }

        T get_data() {
            return data;
        }

        Node<T>* get_next() {
            return next;
        }

        void set_next(Node<T> *n) {
            next = n;
        }
};

#endif


// 1 2 3 4 5

/*
    temp_node = 1
    while 1 -> 3
    while 2 -> 4
    while 3 -> 5
    while 4 -> 6

*/