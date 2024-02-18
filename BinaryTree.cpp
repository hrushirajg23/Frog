#include<iostream>
#include"Tree.h"
#include"Adapters.cpp"
using namespace std;

BinaryTree::BinaryTree()
{
    this->root=NULL;
}
// BinaryTree::~BinaryTree()
// {
//     cout<<"Before deleting address of root is:- "<<root<<endl;
//     delete root;
// }

void BinaryTree::Insert(int no)
{
    struct TreeNode *newn=new struct TreeNode;
    newn->data=no;
    newn->left=NULL;
    newn->right=NULL;
    struct TreeNode *temp=this->root;

    if(this->root==NULL)
    {
        this->root=newn;
    } 
    else
    {
        while(1)
        {

            if(no==temp->data)
            {
                printf("Data already present\n");
                break;
            }

            if(no < temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=newn;
                    break;
                }
                temp=temp->left;
            }
            else if(no > temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right=newn;
                    break;
                }
                temp=temp->right;
            }
        }
    }
}

void BinaryTree::preorder(struct TreeNode *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        this->preorder(temp->left);
        this->preorder(temp->right);
    }
    
}

void BinaryTree::preorder()
{
    preorder(this->root);
    cout<<endl;
}

void BinaryTree::postorder(struct TreeNode *temp)
{
    if(temp!=NULL)
    {
        
        this->postorder(temp->left);
        this->postorder(temp->right);
        cout<<temp->data<<"\t";
    }
}

void BinaryTree::postorder()
{
    postorder(this->root);
    cout<<endl;
}

void BinaryTree::inorder(struct TreeNode *temp)
{
    if(temp!=NULL)
    {
        this->inorder(temp->left);
        cout<<temp->data<<"\t";
        this->inorder(temp->right);
    }
}

void BinaryTree::inorder()
{
    inorder(this->root);
    cout<<endl;
}

void BinaryTree::LevelOrder()
{
    if(this->root==NULL)
    {
        return;
    }
    Queue<TreeNode *> obj;
    struct TreeNode *temp=NULL;
    obj.Enqueue(root);

    while(!obj.isEmpty())
    {
        temp=obj.Dequeue();
        cout<<temp->data<<"\t";
        if(temp->left!=NULL)
        {
            obj.Enqueue(temp->left);
        }
        if(temp->right!=NULL)
        {
            obj.Enqueue(temp->right);
        }
    }
    cout<<endl;
    
}

void BinaryTree::nonrecursivepreorder()
{
    Stack<TreeNode *> sobj;

    bool bFlag=false;
    TreeNode *temp=this->root;
    while(bFlag==false)
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            sobj.Push(temp);
            temp=temp->left;
        }
        if(!sobj.isEmpty())
        {
            temp=sobj.Pop();
            temp=temp->right;
        }
        else
        {
            bFlag=true;
        }
    }
    cout<<endl;
}

void BinaryTree::nonrecursiveinorder()
{
    bool bFlag=false;
    Stack<TreeNode*> sobj;
    struct TreeNode *temp=this->root;
    while(bFlag==false)
    {
        while(temp!=NULL)
        {
            sobj.Push(temp);
            temp=temp->left;
        }
        if(!sobj.isEmpty())
        {
            temp=sobj.Pop();
            cout<<temp->data<<"\t";
            temp=temp->right;
        }
        else
        {
            bFlag=true;
        }
        
    }
    cout<<endl;
}

void BinaryTree::nonrecursivepostorder()
{
    Stack<TreeNode *> sobj;

    TreeNode *temp=this->root;
    bool bFlag=false;
    TreeNode * visited=NULL;

    while(bFlag==false)
    {
        while(temp!=NULL)
        {
            sobj.Push(temp);
            temp=temp->left;
        }
        if(!sobj.isEmpty())
        {
            temp=sobj.Peek();
            if(temp->right==NULL || temp->right==visited)
            {
                temp=sobj.Pop();
                visited=temp;
                cout<<temp->data<<"\t";
                temp=NULL;
            }
            else
            {
                temp=temp->right;
            }
        }
        else
        {
            bFlag=true;
        }
       
    }
     cout<<endl;

}

struct TreeNode * BinaryTree::minValue(struct TreeNode *helper)
{
    struct TreeNode *current=helper;

    while(current!=NULL && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}

void BinaryTree::remove(int data)
{
    if(this->root==NULL)
    {
        return;
    }
    this->root=this->removeRecursive(this->root,data);    
}

struct TreeNode * BinaryTree::removeRecursive(struct TreeNode *root,int data)
{
    cout<<"Address of root is :- "<<root<<endl;
    if(root==NULL)
    {
        return root;
    }

    if(data < root->data)
    {
        root->left=this->removeRecursive(root->left,data);
    }
    else if(data > root->data)
    {
        root->right=this->removeRecursive(root->right,data);
    }
    else
    {
        struct TreeNode *temp=NULL; 

        if(root->left==NULL)
        {
            temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL)
        {
            temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            temp=this->minValue(root->right);
            root->data=temp->data;
            root->right=this->removeRecursive(root->right,temp->data);
            cout<<"After completing Address of root is :- "<<root<<endl;
            return root;
        }

    }
}

/*

use command :-  D:\GokhaleSir\cat>g++ BinaryTree.cpp Adapters.cpp -o myexe

D:\GokhaleSir\cat>myexe

*/