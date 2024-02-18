#include"LinkedList.h"
#include<iostream>
using namespace std;

LinkedList::LinkedList()
{
    this->count=0;
    this->First=NULL;
}

void LinkedList::InsertFirst(int no)
{
    struct Single *newn= new struct Single;
    newn->data=no;
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

void LinkedList::InsertLast(int no)
{
    struct Single *newn= new struct Single;
    struct Single *temp=this->First;
    newn->data=no;
    newn->next=NULL;

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

void LinkedList::InsertAtPosition(int ino,int iPos)
{
    int size=this->Count();

    if(iPos< 1 || iPos>size+1)
    {
        cout<<"Enter a valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->InsertFirst(ino);
    }
    else if(iPos==size+1)
    {
        this->InsertLast(ino);
    }
    else
    {
        struct Single *newn= new struct Single;
        newn->data=ino;
        newn->next=NULL;
        struct Single *temp=this->First;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    this->count++;
}

void LinkedList::DeleteFirst()
{
    if(this->First==NULL)
    {
        return;
    }
    else if(this->First->next==NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        struct Single *temp=this->First;
        First=First->next;
        delete temp;
    }
    this->count--;
}

void LinkedList::DeleteLast()
{
    if(this->First==NULL)
    {
        return;
    }
    else if(this->First->next==NULL)
    {
        delete this->First;
        this->First=NULL;
    }
    else
    {
        struct Single *temp=this->First;
        struct Single *hold=NULL;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        hold=temp->next;
        temp->next=NULL;
        delete hold;
    }
    this->count--; 
}

void LinkedList::DeleteAtPosition(int iPos)
{
    int size=this->Count();

    if(iPos< 1 || iPos>size)
    {
        cout<<"Enter a valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->DeleteFirst();
    }
    else if(iPos==size)
    {
        this->DeleteLast();
    }
    else
    {
        struct Single *temp=this->First;
        struct Single *hold=NULL;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        hold=temp->next;
        temp->next=hold->next;
        delete hold;
    }
    this->count--;
}

void LinkedList::Display()
{
    struct Single *temp=this->First;
    while(temp!=NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    cout<<endl<<this->count<<"-- elements present"<<endl;
}



//------------------------------------------------------------------------------------------------------//


SinglyCL::SinglyCL()
{
    this->First=NULL;
    this->Last=NULL;
    this->count=0;
}

void SinglyCL::InsertFirst(int no)
{
    struct Single *newn= new struct Single;
    newn->data=no;
    newn->next=NULL;

    if(this->First==NULL && this->Last==NULL)
    {
        this->First=newn;
        this->Last=newn;
    }
    else
    {
        newn->next=this->First;
        this->First=newn;
    }
    this->Last->next=this->First;
    this->count++;
}

void SinglyCL::InsertLast(int no)
{
    struct Single *newn= new struct Single;
    newn->data=no;
    newn->next=NULL;

    if(this->First==NULL && this->Last==NULL)
    {
        this->First=newn;
        this->Last=newn;
    }
    else
    {
        this->Last->next=newn;
        this->Last=newn;
    }
    this->Last->next=this->First;
    this->count++;
}

void SinglyCL::InsertAtPosition(int ino,int iPos)
{
    int size=this->Count();

    if(iPos< 1 || iPos>size+1)
    {
        cout<<"Enter a valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->InsertFirst(ino);
    }
    else if(iPos==size+1)
    {
        this->InsertLast(ino);
    }
    else
    {
        struct Single *newn= new struct Single;
        newn->data=ino;
        newn->next=NULL;
        struct Single *temp=this->First;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    this->count++;
}

void SinglyCL::DeleteFirst()
{
    if(this->First==NULL && this->Last==NULL)
    {
        return;
    }
    else if(this->First==this->Last)
    {
        delete this->First;
        this->First=NULL;
        this->Last=NULL;
    }
    else
    {
        this->First=this->First->next;
        delete this->Last->next;
        this->Last->next=this->First;
    }
}

void SinglyCL::DeleteLast()
{
    if(this->First==NULL && this->Last==NULL)
    {
        return;
    }
    else if(this->First==this->Last)
    {
        delete this->Last;
        this->First=NULL;
        this->Last=NULL;
    }
    else
    {
        struct Single *temp=this->First;
        while(temp->next!=this->Last)
        {
            temp=temp->next;
        }
        delete temp->next;
        this->Last=temp;
        this->Last->next=this->First;
    }
}

void SinglyCL::DeleteAtPosition(int iPos)
{
    int size=this->Count();

    if(iPos< 1 || iPos>size)
    {
        cout<<"Enter a valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->DeleteFirst();
    }
    else if(iPos==size)
    {
        this->DeleteLast();
    }
    else
    {
        struct Single *temp=this->First;
        struct Single *hold=NULL;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        hold=temp->next;
        temp->next=hold->next;
        delete hold;
    }
    this->count--;
}

void SinglyCL::Display()
{
    struct Single *temp=this->First;
    do{
        cout<<"| "<<temp->data<<" |-> ";
        temp=temp->next;
    }while(temp!=this->First);

    cout<<"Address of 1st element"<<endl;

    cout<<endl<<this->count<<"-- elements present"<<endl;
}


//------------------------------------------------------------------------------------------------------//

DoublyLL::DoublyLL()
{
    this->First=NULL;
    this->count=0;
}

void DoublyLL::InsertFirst(int no)
{
    struct Double *newn= new struct Double;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

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

void DoublyLL::InsertLast(int no)
{
    struct Double *newn= new struct Double;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    struct Double *temp= this->First;

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
        newn->prev=temp;
    }
    this->count++;
}

void DoublyLL::InsertAtPosition(int no,int iPos)
{
    int size=this->count;

    if(iPos<1 || iPos>size+1)
    {
        cout<<"Insert valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->InsertFirst(no);
    }
    else if(iPos==size+1)
    {
        this->InsertLast(no);
    }
    else
    {
        struct Double *newn= new struct Double;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
        struct Double *temp=this->First;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        this->count++;
    }
    
}

void DoublyLL::DeleteAtPosition(int iPos)
{
    int size=this->count;

    if(iPos<1 || iPos>size)
    {
        cout<<"Insert valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->DeleteFirst();
    }
    else if(iPos==size)
    {
        this->DeleteLast();
    }
    else
    {
        
        struct Double *temp=this->First;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }

        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        this->count--;
    }
}

void DoublyLL::DeleteFirst()
{
    if(this->First==NULL)
    {
        return;
    }
    else if(this->First->next==NULL)
    {
        delete this->First;
        this->First=NULL;
    }
    else
    {
        struct Double *temp=this->First;
        this->First=this->First->next;
        delete temp;
    }
    this->count--;
}

void DoublyLL::DeleteLast()
{
    if(this->First==NULL)
    {
        return;
    }
    else if(this->First->next==NULL)
    {
        delete this->First;
        this->First=NULL;
    }
    else
    {
        struct Double *temp=this->First;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    this->count--;
}

void DoublyLL::Display()
{
    struct Double *temp=this->First;
    cout<<"NULL";
    while(temp!=NULL)
    {
        cout<<" <=> "<<temp->data<<" <=> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    cout<<this->count<<" -- elements present"<<endl;

}

//------------------------------------------------------------------------------------------------------//

DoublyCL::DoublyCL()
{
    this->First=NULL;
    this->Last=NULL;
    this->count=0;  
}

void DoublyCL::InsertFirst(int no)
{
    struct Double *newn=new struct Double;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(this->First==NULL && this->Last==NULL)
    {
        this->First=newn;
        this->Last=newn;
    }
    else
    {
        newn->next=this->First;
        this->First->prev=newn;
        this->First=newn;
    }
    this->First->prev=this->Last;
    this->Last->next=this->First;
    this->count++;
}

void DoublyCL::InsertLast(int no)
{
    struct Double *newn=new struct Double;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(this->First==NULL && this->Last==NULL)
    {
        this->First=newn;
        this->Last=newn;
    }
    else
    {
        this->Last->next=newn;
        newn->prev=this->Last;
        this->Last=newn;
    }
    this->First->prev=this->Last;
    this->Last->next=this->First;
    this->count++;
}

void DoublyCL::InsertAtPosition(int no,int iPos)
{
    int size=this->count;

    if(iPos<1 || iPos>size+1)
    {
        cout<<"Insert valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->InsertFirst(no);
    }
    else if(iPos==size+1)
    {
        this->InsertLast(no);
    }
    else
    {
        struct Double *newn= new struct Double;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
        struct Double *temp=this->First;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        this->count++;
    }
}

void DoublyCL::DeleteFirst()
{
    if(this->First==NULL && this->Last==NULL)
    {
        return;
    }
    else if(this->First==this->Last)
    {
        delete this->First;
        this->First=NULL;
        this->Last=NULL;
    }
    else
    {
        this->First=this->First->next;
        delete this->First->prev;

        this->First->prev=this->Last;
        this->Last->next=this->First;
    }
    this->count--;
}

void DoublyCL::DeleteLast()
{
     if(this->First==NULL && this->Last==NULL)
    {
        return;
    }
    else if(this->First==this->Last)
    {
        delete this->Last;
        this->First=NULL;
        this->Last=NULL;
    }
    else
    {
        this->Last=this->Last->prev;
        delete this->Last->next;
        this->First->prev=this->Last;
        this->Last->next=this->First;
    }
    this->count--;
}

void DoublyCL::DeleteAtPosition(int iPos)
{
    int size=this->count;

    if(iPos<1 || iPos>size)
    {
        cout<<"Insert valid position"<<endl;
        return;
    }

    if(iPos==1)
    {
        this->DeleteFirst();
    }
    else if(iPos==size)
    {
        this->DeleteLast();
    }
    else
    {
        struct Double *temp=this->First;
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        this->count--;
    }
}

void DoublyCL::Display()
{
    struct Double *temp=this->First;

    cout<<"Address of Last Node";
    do{
        cout<<" <=>"<<temp->data<<" <=>";
        temp=temp->next;
    }while(temp!=this->First);
    cout<<"Address of First Node"<<endl;

    cout<<this->count<<" -- elements present"<<endl;
}

