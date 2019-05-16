/**--------------------------------------------------------

	@file main.cpp
	@author Vi Vuong
	@version 13.37

	CS-260-01 - Assignment 5
	Program entry point. Tests StringBinTree class

--------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "Node.h"
#include "BinTree.h"
#include <chrono>
using namespace std;


void printCout (string& s, int level) {
	cout << s << " (" << level << ") ";
}


int main() {
	cout << "CS260, A5-Binary Trees\nAuthor:Vi Vuong\n\n";

    StringBinTree s;
	
	s.insert("Jynx");
	s.insert("Charmander");
	s.insert("Snorlax");
	s.insert("Diglett");
	s.insert("Kakuna");
	s.insert("Meowth");
	s.insert("Pikachu");
	s.insert("Blastoise");
	s.insert("Squirtle");
	s.insert("Ivysaur");
	s.insert("Bulbasaur");
	s.insert("Abra");
	s.printInorder();
	cout << endl << endl;


	StringBinTree s2 = s.copy();


	cout << "Deleting Squirtle\n";
	s.remove("Squirtle");
	s.printInorder();
	cout << endl << endl;

	cout << "Deleting Meowth\n";
	s.remove("Meowth");
	s.printInorder();
	cout << endl << endl;

	cout << "Deleting Blastoise\n";
	s.remove("Blastoise");
	s.printInorder();
	cout << endl << endl;

	cout << "Deleting Jynx\n";
	s.remove("Jynx");
	s.printInorder();
	cout << endl << endl;

	cout << "Copied tree\n";

	cout << "Inorder:\n";
	s2.printInorder();
	cout << endl << endl;

	cout << "Preorder:\n";
	s2.printPreorder();
	cout << endl << endl;

	cout << "Postorder:\n";
	s2.printPostorder();
	cout << endl << endl;

	s2.removeAll();
	s2.printInorder();

    return 0;
}