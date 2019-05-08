#pragma once
#include <memory>

template<typename Type> 
struct Node
{
    Type data;
    //No cyclic references -> shared_ptr seems to work better than unique_ptr
    std::shared_ptr<Node<Type> > leftChild = nullptr;
    std::shared_ptr<Node<Type> > rightChild = nullptr;
};

template<typename Type>
using NodePtr = std::shared_ptr<Node<Type> >;
