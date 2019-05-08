#include <iostream>
#include "Node.h"
#include "BinTree.h"
using namespace std;


int main() {
    StringBinTree s;
    s.insert("B");
    s.insert("A");
    s.insert("C");
    s.print(cout);
    return 0;
}