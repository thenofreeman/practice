#include "TreeNode.h"

#include <memory>

template <typename T>
TreeNode<T>::TreeNode(const T data)
    : data(data), left(nullptr), right(nullptr)
{ }

template <typename T>
TreeNode<T>::TreeNode(const T data, std::shared_ptr<TreeNode<T>> left, std::shared_ptr<TreeNode<T>> right)
    : data(data), left(left), right(left)
{ }

template <typename T>
T TreeNode<T>::getData() const
{
    return this->data;
} // end getData

template <typename T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::getLeftNode() const
{
    return this->left;
} // end getLeftNode

template <typename T>
std::shared_ptr<TreeNode<T>> TreeNode<T>::getRightNode() const
{
    return this->right;
} // end getRightNode


template <typename T>
void TreeNode<T>::setLeftNode(std::shared_ptr<TreeNode<T>> newNode)
{
    this->left = newNode;
} // end setLeftNode

template <typename T>
void TreeNode<T>::setRightNode(std::shared_ptr<TreeNode<T>> newNode)
{
    this->right = newNode;
} // end setRightNode

// returns a string representation of the data stored in its node.
template <typename T>
std::string TreeNode<T>::toString()
{
    return this->data.toString();
} // end toString
