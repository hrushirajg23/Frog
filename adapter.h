#ifndef ADAPTER_H
#define ADAPTER_H

template<class T>
struct StackNode
{
    T data;
    struct StackNode<T> *next;
};

template<class T>
struct QueueNode
{
    T data;
    struct QueueNode<T> *next;
};



//Stack: InsertFirst and DeleteFirst
template<class T>
class Stack
{
    private:
        struct StackNode<T> *First;
        int count;
    public:
        Stack();
        Stack(int length);
        T Peek();
        void Push(T value);
        T Pop();
        bool isEmpty();
        int size();
        void show();
};


//Queue: InsertLast and deletefirst
template<class T>
class Queue
{
    private:
        struct QueueNode<T> *First;
        int count;
    public:
        Queue();
        Queue(int size);
        void Enqueue(T value);
        T Dequeue();
        bool isEmpty();
        int size();
        void show();  
};
#endif