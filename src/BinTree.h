#pragma once
#include "Node.h"
#include <string>
#include <ostream>



class StringBinTree {
public:
    StringBinTree();

    bool insert(const std::string& data);
    
    void print(std::ostream& stream);

    //bool isEmpty();

	bool remove(const std::string& data);
private:
    bool insert(const NodePtr<std::string>& newNode, NodePtr<std::string>& current);
    void print(std::ostream& stream, NodePtr<std::string> current, int level);
	void removeNode(NodePtr<std::string>& node);
    NodePtr<std::string> root;
};


StringBinTree::StringBinTree() {
    root = nullptr;
};


bool StringBinTree::remove(const std::string & data) {
	NodePtr<std::string> current = root;
	NodePtr<std::string> parent = nullptr;
	bool found = false;
	
	while (current != nullptr && !found) {
		if (data == current->data) {
			found = true;
		}
		else {
			parent = current;
			if (data < current->data) current = current->leftChild;
			else current = current->rightChild;
		}
	}
	if (found) {
		if (current == root) removeNode(root);
		else if (data < parent->data) removeNode(parent->leftChild);
		else removeNode(parent->rightChild);
		return true;
	}
	return false;
}

void StringBinTree::removeNode(NodePtr<std::string>& node) {
	if ((node->leftChild == nullptr) && (node->rightChild == nullptr)) {
		//Decrease the reference counter by 1. When the counter reaches 0 (typically when "current" from remove method goes out of scope), the object will automatically be destroyed
		node = nullptr;
	}

	else if (node->rightChild == nullptr) { // Node has left child
		/*node now points to the left child of the Node object that it handles. When no more pointers own that object, the object is destroyed
		(*node->leftChild) now has 2 pointers pointing to it: node and node->leftChild. When the object that node previously owned is destroyed
		(typically when "current" from remove method goes out of scope), its leftChild destructor will be called, decreasing the refcount to its leftChild object by 1
		But now node is pointing at that object, it won't be removed.
		*/
		node = node->leftChild;
	}

	else if (node->leftChild == nullptr) { // Node has right child
		//Same as left child
		node = node->rightChild;
	}

	else { //Has 2 children
		NodePtr<std::string> current = node->leftChild;
		NodePtr<std::string> parent = nullptr;

		//find suitable replacement node by going left once and go right as deep as possible
		while (current->rightChild != nullptr) {
			parent = current;
			current = current->rightChild;
		}
		node->data = current->data;

		/*if replacement data is from node's left child: node->leftChild now points to current->leftChild, decreasing (*node->leftChild) ref count by 1
		When current goes out of scope, no more pointers will be pointing at the object mentioned above and it will be destroyed
		When that object is destroyed, its leftChild destructor is called, decreasing the ref count by 1
		But that leftChild still have node->leftChild pointing to it, so it will not be destroyed*/
		if (parent == nullptr) node->leftChild = current->leftChild;

		//replacement node comes from further down
		else parent->rightChild = current->leftChild;
	}
}

bool StringBinTree::insert(const NodePtr<std::string>& newNode, NodePtr<std::string>& current) {
    if (current==nullptr) {
        current = newNode;
    }
    else {
        if (newNode->data < current->data) insert(newNode, current->leftChild);
        else if (newNode->data > current->data) insert(newNode, current->rightChild);
        else return false;
    }
    return true;
};

bool StringBinTree::insert(const std::string& data) {
    NodePtr<std::string> newNode = std::make_shared<Node<std::string>>();
    newNode->data = data;
    return insert(newNode, root);
}


void StringBinTree::print(std::ostream& stream) {
    print(stream, root,0);
};

void StringBinTree::print(std::ostream& stream, NodePtr<std::string> current, int level) {
    if (current==nullptr) return;
    else {
        print(stream, current->leftChild, level+1);
        stream << current->data << "(" << level << ") ";
        print(stream, current->rightChild, level+1);
    }
};