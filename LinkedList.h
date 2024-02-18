#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Single 
{
    int data;
    struct Single *next;
};

struct Double{
    int data;
    struct Double *prev;
    struct Double *next;
};

class LinkedList
{
    private:
        struct Single *First;
        int count;
    public:
        LinkedList();
        virtual void InsertFirst(int ino);
        virtual void InsertLast(int ino);
        virtual void DeleteFirst();
        virtual void DeleteLast();
        virtual void InsertAtPosition(int ino,int iPos);
        virtual void DeleteAtPosition(int iPos);
        virtual void Display();
        virtual int Count(){
            return this->count;
        };
};

class SinglyCL:public LinkedList
{
    private:
        struct Single *First;
        struct Single *Last;
        int count;
    public:
        SinglyCL();
        void InsertFirst(int ino);
        void InsertLast(int ino);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(int ino,int iPos);
        void DeleteAtPosition(int iPos);
        void Display();
        int Count(){
            return this->count;
        };
};

class DoublyLL:public LinkedList
{
    private:
        struct Double *First;
        int count;
    public:
        DoublyLL();
        void InsertFirst(int ino);
        void InsertLast(int ino);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(int ino,int iPos);
        void DeleteAtPosition(int iPos);
        void Display();
        int Count(){
            return this->count;
        };
};

class DoublyCL:public LinkedList
{
    private:
        struct Double *First;
        struct Double *Last;
        int count;
    public:
        DoublyCL();
        void InsertFirst(int ino);
        void InsertLast(int ino);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(int ino,int iPos);
        void DeleteAtPosition(int iPos);
        void Display();
        int Count(){
            return this->count;
        };
};

#endif