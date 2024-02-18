#include"adapter.h"
#include<iostream>
using namespace std;

//----------------------------------------------------------------------------------------//
template<class T>
Stack<T>::Stack()
{
    this->First=NULL;
    this->count=0;
}

template<class T>
void Stack<T>::Push(T value)
{
    struct StackNode<T> *newn= new struct StackNode<T>;
    newn->data=value;
    newn->next=NULL;

    if(this->First==NULL)
    {
        this->First=newn;
    }
    else
    {
        newn->next=this->First;
        this->First=newn;
    }
    this->count++;
}

template<class T>
void Stack<T>::show()
{
    struct StackNode<T> *temp=this->First;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
    
}

template<class T>
bool Stack<T>::isEmpty()
{
    if(this->First==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


template<class T>
T Stack<T>::Pop()
{
    struct StackNode<T> *out;
    T popped;
    if(!this->isEmpty())
    {
        out=this->First;
        popped=out->data;
        this->First=this->First->next;
        delete out;
        this->count--;
        return popped;
    }
    else
    {
        throw out_of_range("Stack is empty");
    }
}

template<class T>
T Stack<T>::Peek()
{
    StackNode<T> *top;
    if(!this->isEmpty())
    {
        top=this->First;
    }
    else
    {
        top=NULL;
    }
    return top->data;
}

template<class T>
int Stack<T>::size()
{
    return this->count;
}


template<class T>
Queue<T>::Queue()
{
    this->First=NULL;
    this->count=0;
}

template<class T>
void Queue<T>::Enqueue(T value)
{
    struct QueueNode<T> *newn=new struct QueueNode<T>;
    newn->data=value;
    newn->next=NULL;
    struct QueueNode<T> *temp=this->First;

    if(this->First==NULL)
    {
        this->First=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    this->count++;

}


template<class T>
bool Queue<T>::isEmpty()
{
    if(this->First==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
T Queue<T>::Dequeue()
{
    struct QueueNode<T> *out=NULL;
    T popped;
    if(!this->isEmpty())
    {
        out=this->First;
        popped=out->data;
        this->First=this->First->next;
        delete out;
        return popped;
        this->count--;
    }
    else
    {
        throw out_of_range("Queue is empty");
    }
}


template<class T>
void Queue<T>::show()
{
    struct QueueNode<T> *temp=this->First;

    if(this->isEmpty())
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<endl;
    }
}


template<class T>
int Queue<T>::size()
{
    return this->count;
}


