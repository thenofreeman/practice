#include "BinaryTree.h"

#include "TreeNode.h"
#include "EmployeeInfo.h"

#include <iostream>

// Default constructor
// does nothing but set root to nullptr
template <typename T>
BinaryTree<T>::BinaryTree()
    : root(nullptr)
{ }

// Add
// Client called method for adding a new node to the tree.
// prepares the needed elements and calls its helper function with said elements.
// returns true if node was successfully added.
template <typename T>
bool BinaryTree<T>::add(const T& data)
{
    std::shared_ptr<TreeNode<T>> newNode = std::shared_ptr<TreeNode<T>>(new TreeNode<T>(data));
    std::shared_ptr<TreeNode<T>> curr = root;
    bool status {true};

    root = addHelper(newNode, curr, status);

    return status;
} // end add

// AddHelper
// This method does all the work for adding a new user.
// It recursively traverses the tree until it finds the appropriate place to insert.
// if it doesn't find a place to insert, it will set the status flag to false.
template <typename T>
std::shared_ptr<TreeNode<T>> BinaryTree<T>::addHelper(std::shared_ptr<TreeNode<T>> newNode, std::shared_ptr<TreeNode<T>> curr, bool& status)
{
    if (curr == nullptr)
        curr = newNode;
    else if (newNode->getData().getID() == curr->getData().getID())
        status = false; // value already exists
    else if (newNode->getData().getID() < curr->getData().getID())
        curr->setLeftNode(addHelper(newNode, curr->getLeftNode(), status));
    else // if (newNode->getData().getID() > curr->getData().getId())
        curr->setRightNode(addHelper(newNode, curr->getRightNode(), status));

    return curr;
} // end AddHelper

// Exists
// Client called method for verifying whether a node exists in the tree.
// prepares the needed elements and calls its helper function with said elements.
// returns true if node exists
template <typename T>
bool BinaryTree<T>::exists(const int& id)
{
    std::shared_ptr<TreeNode<T>> curr = root;
    return existsHelper(curr, id);
} // end exists

// ExistsHelper
// recursively go through tree checking if input id exists in the tree
// returns true if node exists
template <typename T>
bool BinaryTree<T>::existsHelper(std::shared_ptr<TreeNode<T>> curr, const int& id)
{
    if (curr == nullptr)
    {
        return false;
    }
    else if (curr->getData().getID() == id)
    {
        return true;
    }
    else if (curr->getData().getID() > id)
    {
        return existsHelper(curr->getLeftNode(), id);
    }
    else // if (curr->getData().getID() < id)
    {
        return existsHelper(curr->getRightNode(), id);
    }

    return false;
} // end existsHelper

// DisplayTree
// calls its helper function to facilitate printing the tree
// returns a string representation of the tree
template <typename T>
std::string BinaryTree<T>::displayTree()
{
    std::string treeAsText {""}; // value that gets printed
    std::shared_ptr<TreeNode<T>> curr = root; // used to traverse the tree

    // if root isn't null, display the tree
    return ((root == nullptr) ? "Tree is Empty." : displayTreeHelper("", treeAsText, curr));
} // end DisplayTree

// DisplayTreeHelper
// recusevely prints the elements of the tree to a variable.
// returns a string representation of the tree.
template <typename T>
std::string BinaryTree<T>::displayTreeHelper(std::string branches, std::string treeAsText, std::shared_ptr<TreeNode<T>> curr)
{
    if (curr != nullptr)
    {
        // add the current node to output string
        treeAsText += (branches + curr->toString() + '\n');

        // traverse right side
        treeAsText = displayTreeHelper(branches+"    ", treeAsText, curr->getRightNode());

        // traverse left side
        treeAsText = displayTreeHelper(branches+"    ", treeAsText, curr->getLeftNode());
    }

    return treeAsText;
} // end DisplayTreeHelper
