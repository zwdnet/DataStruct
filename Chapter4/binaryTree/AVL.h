#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include <iostream>
#include "BinTree.h"

using namespace std;

template <typename T>
class AVLTree:public SearchTree<T>
{
    private:
        TreeNode<T> * tree;
        int size;
    private:
        TreeNode<T> * insert(T x, TreeNode<T> * Tree);
        TreeNode<T> * SingleRotateWithLeft(TreeNode<T> * K2);
        TreeNode<T> * DoubleRotateWithLeft(TreeNode<T> * K3);
        TreeNode<T> * SingleRotateWithRight(TreeNode<T> * K1);
        TreeNode<T> * DoubleRotateWithRight(TreeNode<T> * K1);
        TreeNode<T> * deleteNode(T x, TreeNode<T> * Tree);
        TreeNode<T> * find(T x, TreeNode<T> * Tree);
        int height(TreeNode<T> * Tree);
    public:
        AVLTree(void){tree = NULL; size = 0;}
        ~AVLTree(void){makeEmpty(tree);}
        //int Height(void){return height(this->tree);}
};

template <typename T>
int AVLTree<T>::height(TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        return -1;
    }
    else
    {
        return Tree->Height;
    }
}

template <typename T>
TreeNode<T> * AVLTree<T>::insert(T x, TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        Tree = new TreeNode<T>;
        if (Tree == NULL)
        {
            cout<<"ÄÚ´æ·ÖÅäÊ§°Ü!"<<endl;
        }
        else
        {
            Tree->Element = x;
            Tree->Height = 0;
            Tree->Left = Tree->Right = NULL;
            size++;
        }
    }
    else if (x < Tree->Element)
    {
        Tree->Left = insert(x, Tree->Left);
        if (height(Tree->Left) - height(Tree->Right) == 2)
        {
            if (x < Tree->Left->Element)
            {
                Tree = SingleRotateWithLeft(Tree);
            }
            else
            {
                Tree = DoubleRotateWithLeft(Tree);
            }
            size++;
        }
    }
    else if (x > Tree->Element)
    {
        Tree->Right = insert(x, Tree->Right);
        if (height(Tree->Right) - height(Tree->Left) == 2)
        {
            if (x > Tree->Right->Element)
            {
                Tree = SingleRotateWithRight(Tree);
            }
            else
            {
                Tree = DoubleRotateWithRight(Tree);
            }
            size++;
        }
    }

    Tree->Height = max(height(Tree->Left), height(Tree->Right)) + 1;
    cout<<"Height = "<<Tree->Height<<endl;
    return Tree;
}

template <typename T>
TreeNode<T> * AVLTree<T>::SingleRotateWithLeft(TreeNode<T> * K2)
{
    TreeNode<T> * K1;
    cout<<K2->Left->Element<<endl;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = max(height(K2->Left), height(K2->Right)) + 1;
    K1->Height = max(height(K1->Left), K2->Height) + 1;

    return K1;
}

template <typename T>
TreeNode<T> * AVLTree<T>::DoubleRotateWithLeft(TreeNode<T> * K3)
{
    cout<<K3->Left->Element<<endl;
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

template <typename T>
TreeNode<T> * AVLTree<T>::SingleRotateWithRight(TreeNode<T> * K1)
{
    TreeNode<T> * K2;
    cout<<K1->Right->Element<<endl;
    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = max(height(K1->Right), height(K1->Left)) + 1;
    K2->Height = max(height(K2->Right), K1->Height) + 1;

    return K2;
}

template <typename T>
TreeNode<T> * AVLTree<T>::DoubleRotateWithRight(TreeNode<T> * K1)
{
    cout<<K1->Right->Element<<endl;
    K1->Right = SingleRotateWithLeft(K1->Right);
    return SingleRotateWithRight(K1);
}

template <typename T>
TreeNode<T> * AVLTree<T>::deleteNode(T x, TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        return NULL;
    }
    TreeNode<T> * z = find(x, tree);
    if (z == NULL)
    {
        return NULL;
    }

    if (z->Element < Tree->Element)
    {
        Tree->Left = deleteNode(x, Tree->Left);
        if (height(Tree->Right) - height(Tree->Left) == 2)
        {
            TreeNode<T> * r = Tree->Right;
            if (height(r->Left) > height(r->Right))
            {
                Tree = DoubleRotateWithRight(Tree);
            }
            else
            {
                Tree = SingleRotateWithRight(Tree);
            }
        }
    }
    else if (z->Element > Tree->Element)
    {
        Tree->Right = deleteNode(x, Tree->Right);
        if (height(Tree->Left) - height(Tree->Right) == 2)
        {
            TreeNode<T> * l = Tree->Left;
            if (height(l->Right) > height(l->Left))
            {
                Tree = DoubleRotateWithLeft(Tree);
            }
            else
            {
                Tree = SingleRotateWithLeft(Tree);
            }
        }
    }
    else
    {
        if ((Tree->Left != NULL) && (Tree->Right != NULL))
        {
            if (height(Tree->Left) > height(Tree->Right))
            {
                TreeNode<T> * maxNode = findMax(Tree->Left);
                Tree->Element = maxNode->Element;
                Tree->Left = deleteNode(maxNode->Element, Tree->Left);
            }
            else
            {
                TreeNode<T> * minNode = findMin(Tree->Right);
                Tree->Element = minNode->Element;
                Tree->Right = deleteNode(minNode->Element, Tree->Right);
            }
        }
        else
        {
            TreeNode<T> * tmp = Tree;
            Tree = (Tree->Left != NULL) ? Tree->Left : Tree->Right;
            delete tmp;
            size--;
        }
    }
    return Tree;
}

template <typename T>
TreeNode<T> * AVLTree<T>::find(T x, TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        return NULL;
    }
    if (x < Tree->Element)
    {
        return find(x, Tree->Left);
    }
    else if (x > Tree->Element)
    {
        return find(x, Tree->Right);
    }
    else
    {
        return Tree;
    }
}
#endif // AVL_H_INCLUDED
