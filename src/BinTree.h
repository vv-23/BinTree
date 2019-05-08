#pragma once
#include "Node.h"
#include <string>
#include <ostream>



class StringBinTree {
public:
    StringBinTree();

    bool insert(std::string data);
    
    void print(std::ostream& stream);

    //bool isEmpty();
private:
    bool insert(const NodePtr<std::string>& newNode, NodePtr<std::string>& current);
    void print(std::ostream& stream, NodePtr<std::string> current);
    NodePtr<std::string> root;
};


StringBinTree::StringBinTree() {
    root = nullptr;
};


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

bool StringBinTree::insert(std::string data) {
    NodePtr<std::string> newNode = std::make_shared<Node<std::string>>();
    newNode->data = data;
    insert(newNode, root);
}


void StringBinTree::print(std::ostream& stream) {
    print(stream, root);
};

void StringBinTree::print(std::ostream& stream, NodePtr<std::string> current) {
    if (current==nullptr) return;
    else {
        print(stream, current->leftChild);
        stream << current->data << " ";
        print(stream, current->rightChild);
    }
};