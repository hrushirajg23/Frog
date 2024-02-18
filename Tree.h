#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct TreeNode
{
    int data;
    struct TreeNode<T> *left;
    struct TreeNode<T> *right;
};

class BinaryTree 
{
    private:
        struct TreeNode *root;
        int nodes;
        struct TreeNode * minValue(struct TreeNode *);
        struct TreeNode *removeRecursive(struct TreeNode *,int);
    public:
        BinaryTree();
        ~BinaryTree();
        void Insert(int);
        bool search(int);
        void preorder(struct TreeNode *);
        void preorder();
        void nonrecursivepreorder();
        void inorder(struct TreeNode *);
        void inorder();
        void nonrecursiveinorder();
        void postorder(struct TreeNode *);
        void postorder();
        void nonrecursivepostorder();
        void LevelOrder();
        void remove(int);
        void destroy();
};


#endif