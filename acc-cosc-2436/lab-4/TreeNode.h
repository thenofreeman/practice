#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <string>
#include <memory>

template <typename T>
class TreeNode
{
    private:
        T data;
        std::shared_ptr<TreeNode<T>> left;
        std::shared_ptr<TreeNode<T>> right;

    public:
        TreeNode(const T data);
        TreeNode(const T data, std::shared_ptr<TreeNode<T>> left, std::shared_ptr<TreeNode<T>> right);

        T getData() const;
        std::shared_ptr<TreeNode<T>> getLeftNode() const;
        std::shared_ptr<TreeNode<T>> getRightNode() const;
        void setLeftNode(std::shared_ptr<TreeNode<T>> newNode);
        void setRightNode(std::shared_ptr<TreeNode<T>> newNode);
        std::string toString();

}; // class TreeNode

#include "TreeNode.cpp"

#endif // TREE_NODE_H_
