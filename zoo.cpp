#include<iostream>
//#include"LinkedList.h"
#include"Tree.h"
#include"Adapters.cpp"

using namespace std;

int main()
{
   BinaryTree b;

   b.Insert(5);
   b.Insert(3);
   b.Insert(4);
   b.Insert(2);
   b.Insert(7); 
   b.Insert(6);
   b.Insert(8);

   b.preorder();

   b.remove(7);

   b.preorder();

    return 0;
}

/*command:-
g++ zoo.cpp Binarytree.cpp -o myexe


*/