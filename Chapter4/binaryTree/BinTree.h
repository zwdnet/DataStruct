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
    int Height;
};

template <typename T>
class SearchTree
{
    private:
        TreeNode<T> * tree;
        int size;

    protected:
        void makeEmpty(TreeNode<T> * Tree);
        void printTreeInOrder(TreeNode<T> * Tree);
        void printTreePreOrder(TreeNode<T> * Tree);
        void printTreePostOrder(TreeNode<T> * Tree);
        int height(TreeNode<T> * Tree);
        TreeNode<T> * insert(T x, TreeNode<T> * Tree);
        TreeNode<T> * find(T x, TreeNode<T> * Tree);
        TreeNode<T> * findMin(TreeNode<T> * Tree);
        TreeNode<T> * findMax(TreeNode<T> * Tree);
        TreeNode<T> * deleteNode(T x, TreeNode<T> * Tree);

    public:
        SearchTree(void){tree = NULL; size = 0;}
        int Size(void){return size;}
        void MakeEmpty(void){makeEmpty(tree);}
        void Insert(T x){tree = insert(x, tree);};
        void Delete(T x){deleteNode(x, tree);}
        void PrintTreeInOrder(void){printTreeInOrder(tree);cout<<endl;};
        void PrintTreePreOrder(void){printTreePreOrder(tree);cout<<endl;};
        void PrintTreePostOrder(void){printTreePostOrder(tree);cout<<endl;};
        int Height(void){return height(tree);};
        bool Find(T x);
        T FindMin(void){return findMin(tree)->Element;}
        T FindMax(void){return findMax(tree)->Element;}
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

template <typename T>
bool SearchTree<T>::Find(T x)
{
    if (find(x, tree) != NULL)
    {
        return true;
    }
    return false;
}

template <typename T>
TreeNode<T> * SearchTree<T>::find(T x, TreeNode<T> * Tree)
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

template <typename T>
TreeNode<T> * SearchTree<T>::findMin(TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        return NULL;
    }
    else if (Tree->Left == NULL)
    {
        return Tree;
    }
    else
    {
        return findMin(Tree->Left);
    }
}

template <typename T>
TreeNode<T> * SearchTree<T>::findMax(TreeNode<T> * Tree)
{
    if (Tree == NULL)
    {
        return NULL;
    }
    else if (Tree->Right == NULL)
    {
        return Tree;
    }
    else
    {
        return findMax(Tree->Right);
    }
}

template <typename T>
TreeNode<T> * SearchTree<T>::deleteNode(T x, TreeNode<T> * Tree)
{
    TreeNode<T> * TmpCell;

    if (Tree == NULL)
    {
        return NULL;
    }
    else if (x < Tree->Element)
    {
        Tree->Left = deleteNode(x, Tree->Left);
    }
    else if (x > Tree->Element)
    {
        Tree->Right = deleteNode(x, Tree->Right);
    }
    else if (Tree->Left && Tree->Right)  //找到要删除的结点，有两个子结点
    {
        TmpCell = findMin(Tree->Right);
        Tree->Element = TmpCell->Element;
        Tree->Right = deleteNode(Tree->Element, Tree->Right);
    }
    else //只有一个或没有子孩子
    {
        TmpCell = Tree;
        if (Tree->Left == NULL)
        {
            Tree = Tree->Right;
        }
        else if (Tree->Right == NULL)
        {
            Tree = Tree->Left;
        }
        delete TmpCell;
    }
    return Tree;
}
#endif // BINTREE_H_INCLUDED
