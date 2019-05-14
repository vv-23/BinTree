/**--------------------------------------------------------

    @file Node.h
    @author Vi Vuong
    @version 13.37

    CS-260-01 - Assignment 5
    Binary tree node template

--------------------------------------------------------*/

#pragma once
#include <memory>

template<typename Type> 
struct Node
{
    Type data;
    //No cyclic references -> shared_ptr seems to work better than unique_ptr
	//TODO: Find a way to changed this to unique_ptr, since the node objects' ownership shouldn't be shared
    std::shared_ptr<Node<Type> > leftChild = nullptr;
    std::shared_ptr<Node<Type> > rightChild = nullptr;
};

template<typename Type>
using NodePtr = std::shared_ptr<Node<Type> >;
