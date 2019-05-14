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

//Note: Since the class' destruction involves nested shared_ptr destruction, very large trees might cause stack overflow
//Since the class uses smart pointers to handle its nodes' memory allocation and deallocation, default destructor is good enough

//TODO: Convert this class to a template one.
class StringBinTree {
public:
	/**
	
		\brief Class constructor
	
	*/
    StringBinTree();

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
    void print(std::ostream& stream);

	/**
	
		\brief Remove a node from the tree
		\param data Node data 
		\return Sucessful or not 	
	*/
	bool remove(const std::string& data);

	std::shared_ptr<StringBinTree> copy() const;
private:
    bool insert(const NodePtr<std::string>& newNode, NodePtr<std::string>& current);
    void print(std::ostream& stream, NodePtr<std::string> current, int level);
	void removeNode(NodePtr<std::string>& node);
	NodePtr<std::string> copyNode(const Node<std::string>* node);
    NodePtr<std::string> root;
};