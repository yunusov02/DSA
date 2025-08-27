#ifndef STACK_NODE
#define STACK_NODE


template<typename T>
class StackNode {
    private:
        T data;
        StackNode *next;

    public:
        StackNode() {}
        StackNode(T value) {
            data = value;
            next = nullptr;
        }
};


#endif