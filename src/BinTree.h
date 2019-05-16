/**--------------------------------------------------------

	@file BinTree.h
	@author Vi Vuong
	@version 13.37

	CS-260-01 - Assignment 5
	StringBinTree class

--------------------------------------------------------*/

#pragma once
#include "Node.h"
#include <string>
#include <ostream>
#include <iostream>

//Note: Since the class' destruction involves nested shared_ptr destruction, very large trees might cause stack overflow
//Since the class uses smart pointers to handle its nodes' memory allocation and deallocation, default destructor is good enough

//TODO: Convert this class to a template one.
//TODO: Find a way to use unique_ptr
class StringBinTree {
public:
	/**
	
		\brief Class constructor
	
	*/
    StringBinTree();

	/**

		\brief Class constructor that takes a pointer to root

	*/
	StringBinTree(NodePtr<std::string> rootPtr);

	/**
	
		\brief Insert a node into the tree. No duplicates allowed
		\param data Node data 
		\return Sucessful or not 
	*/
    bool insert(const std::string& data);
    
	/**
	
		\brief Print the tree (inorder)
		\param stream Destination ostream 
	*/
    void printInorder();

	/**
	
		\brief Print the tree (postorder)
		\param stream Destination ostream 
	*/
    void printPostorder();

	/**
	
		\brief Print the tree (Preorder)
		\param stream Destination ostream 
	*/
    void printPreorder();


	/**
	
		\brief Remove a node from the tree
		\param data Node data 
		\return Sucessful or not 	
	*/
	bool remove(const std::string& data);
	
	/**
	
		\brief Remove all nodes from the tree	
	*/
	void removeAll();

	StringBinTree copy() const;

	/**
	
		\brief Traverse the tree (inorder) and operate on the data
		\param func_ptr A pointer to a function that takes in a string reference and an integer (node level)
	*/
	void inOrder(void (*func_ptr)(std::string& s, int level));

	/**
	
		\brief Traverse the tree (postorder) and operate on the data
		\param func_ptr A pointer to a function that takes in a string reference and an integer (node level)
	*/
	void postOrder(void (*func_ptr)(std::string& s, int level));

	/**
	
		\brief Traverse the tree (preorder) and operate on the data
		\param func_ptr A pointer to a function that takes in a string reference and an integer (node level)
	*/
	void preOrder(void (*func_ptr)(std::string& s, int level));

private:
	void print(std::string& s, int level);

    bool insert(const NodePtr<std::string>& newNode, NodePtr<std::string>& current);
	void removeNode(NodePtr<std::string>& node);

	void inOrder(void (StringBinTree::*func_ptr)(std::string& s, int level));
	void postOrder(void (StringBinTree::*func_ptr)(std::string& s, int level));
	void preOrder(void (StringBinTree::*func_ptr)(std::string& s, int level));

	void inOrder(NodePtr<std::string> current, void (*func_ptr)(std::string& s, int level), int currentLevel);
	void postOrder(NodePtr<std::string> current, void (*func_ptr)(std::string& s, int level), int currentLevel);
	void preOrder(NodePtr<std::string> current, void (*func_ptr)(std::string& s, int level), int currentLevel);

	void inOrder(NodePtr<std::string> current, void (StringBinTree::*func_ptr)(std::string& s, int level), int currentLevel);
	void postOrder(NodePtr<std::string> current, void (StringBinTree::*func_ptr)(std::string& s, int level), int currentLevel);
	void preOrder(NodePtr<std::string> current, void (StringBinTree::*func_ptr)(std::string& s, int level), int currentLevel);

	NodePtr<std::string> copyNode(const Node<std::string>* node) const;
    NodePtr<std::string> root;
};