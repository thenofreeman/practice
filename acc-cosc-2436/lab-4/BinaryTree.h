#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <memory>
#include <string>

#include "TreeNode.h"
#include "EmployeeInfo.h"

template <typename T>
class BinaryTree
{
    private:
        std::shared_ptr<TreeNode<T>> root;

        std::shared_ptr<TreeNode<T>> addHelper(std::shared_ptr<TreeNode<T>> newNode, std::shared_ptr<TreeNode<T>> curr, bool& status);
        bool existsHelper(std::shared_ptr<TreeNode<T>> curr, const int& id);
        std::string displayTreeHelper(std::string branches, std::string treeAsText, std::shared_ptr<TreeNode<T>> curr);

    public:
        BinaryTree();

        bool add(const T& data);
        bool exists(const int& id);
        std::string displayTree();
};

#include "BinaryTree.cpp"

#endif // BINARY_TREE_H_
