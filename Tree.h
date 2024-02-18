#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct TreeNode
{
    T data;
    struct TreeNode<T> *left;
    struct TreeNode<T> *right;
};

template<class T>
class BinaryTree 
{
    private:
        struct TreeNode<T> *root;
        int nodes;
        struct TreeNode<T> * minValue(struct TreeNode<T> *);
        struct TreeNode<T> *removeRecursive(struct TreeNode<T> *,int);
    public:
        BinaryTree();
        ~BinaryTree();
        void Insert(T);
        bool search(T);
        void preorder(struct TreeNode<T> *);
        void preorder();
        void nonrecursivepreorder();
        void inorder(struct TreeNode<T> *);
        void inorder();
        void nonrecursiveinorder();
        void postorder(struct TreeNode<T> *);
        void postorder();
        void nonrecursivepostorder();
        void LevelOrder();
        void remove(T);
        void destroy();
};


#endif