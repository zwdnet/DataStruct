#ifndef BINTREE_H_INCLUDED
#define BINTREE_H_INCLUDED
//二叉搜索树实现
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct TreeNode
{
    T Element;
    TreeNode<T> * Left;
    TreeNode<T> * Right;
};

template <typename T>
class SearchTree
{
    private:
        TreeNode<T> * tree;
        int size;

    private:
        void makeEmpty(TreeNode<T> * Tree);
        void printTreeInOrder(TreeNode<T> * Tree);
        void printTreePreOrder(TreeNode<T> * Tree);
        void printTreePostOrder(TreeNode<T> * Tree);
        int height(TreeNode<T> * Tree);
        TreeNode<T> * insert(T x, TreeNode<T> * Tree);

    public:
        SearchTree(void){tree = NULL; size = 0;}
        int Size(void){return size;}
        void MakeEmpty(void){makeEmpty(tree);}
        TreeNode<T> * Find(T x);
        TreeNode<T> * FindMin(void);
        TreeNode<T> * FindMax(void);
        void Insert(T x){tree = insert(x, tree);};
        void Delete(T x);
        void PrintTreeInOrder(void){printTreeInOrder(tree);cout<<endl;};
        void PrintTreePreOrder(void){printTreePreOrder(tree);cout<<endl;};
        void PrintTreePostOrder(void){printTreePostOrder(tree);cout<<endl;};
        int Height(void){return height(tree);};
};

template <typename T>
void SearchTree<T>::makeEmpty(TreeNode<T> * Tree)
{
    if (Tree != NULL)
    {
        makeEmpty(Tree->Left);
        makeEmpty(Tree->Right);
        delete Tree;
    }
}

template <typename T>
void SearchTree<T>::printTreeInOrder(TreeNode<T> * Tree)
{
    if (Tree != NULL)
    {
        printTreeInOrder(Tree->Left);
        cout<<Tree->Element<<" ";
        printTreeInOrder(Tree->Right);
    }
}

template <typename T>
void SearchTree<T>::printTreePreOrder(TreeNode<T> * Tree)
{
    if (Tree != NULL)
    {
        cout<<Tree->Element<<" ";
        printTreePreOrder(Tree->Left);
        printTreePreOrder(Tree->Right);
    }
}

template <typename T>
void SearchTree<T>::printTreePostOrder(TreeNode<T> * Tree)
{
    if (Tree != NULL)
    {
        printTreePostOrder(Tree->Left);
        printTreePostOrder(Tree->Right);
        cout<<Tree->Element<<" ";
    }
}

template <typename T>
int SearchTree<T>::height(TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        return -1;
    }
    else
    {
        return 1+max(height(Tree->Left), height(Tree->Right));
    }
}

template <typename T>
TreeNode<T> * SearchTree<T>::insert(T x, TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        Tree = new TreeNode<T>;
        if (Tree == NULL)
        {
            cout<<"内存分配出错"<<endl;
            return NULL;
        }
        else
        {
            size++;
            Tree->Element = x;
            Tree->Left = Tree->Right = NULL;
        }
    }
    else
    {
        if (x < Tree->Element)
        {
            Tree->Left = insert(x, Tree->Left);
        }
        else if (x > Tree->Element)
        {
            Tree->Right = insert(x, Tree->Right);
        }
    }
    return Tree;
}
#endif // BINTREE_H_INCLUDED
