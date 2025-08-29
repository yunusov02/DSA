#ifndef STACK_NODE
#define STACK_NODE


template<typename T>
class StackNode {
    private:
        T data;
        StackNode *next;

    public:
        StackNode() {
            next = nullptr;
        }
        StackNode(T value) {
            data = value;
            next = nullptr;
        }

        void set_next(StackNode<T> *obj) {
            next = obj;
        }

        StackNode<T> *get_next() {
            return next;
        }

        T get_data() const {
            return data;
        }
};


#endif