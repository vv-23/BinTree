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
using namespace std;


int main() {
	/*cout << "CS260, A5-Binary Trees\nAuthor:Vi Vuong\n\n";

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
	s.print(cout);

	cout << endl << endl;


	cout << "Deleting Squirtle\n";
	s.remove("Squirtle");
	s.print(cout);
	cout << endl << endl;

	cout << "Deleting Meowth\n";
	s.remove("Meowth");
	s.print(cout);
	cout << endl << endl;

	cout << "Deleting Blastoise\n";
	s.remove("Blastoise");
	s.print(cout);
	cout << endl << endl;

	cout << "Deleting Jynx\n";
	s.remove("Jynx");
	s.print(cout);
	cout << endl << endl;*/

	StringBinTree s;
	s.insert("Q");
	s.insert("W");
	s.insert("E");
	s.insert("R");
	s.insert("T");
	s.insert("Y");
	s.insert("U");
	s.insert("I");
	s.insert("O");
	s.insert("P");
	s.insert("A");
	s.insert("S");
	s.insert("D");
	s.insert("F");
	s.insert("G");
	s.insert("H");
	s.insert("J");
	s.insert("K");
	s.insert("L");
	s.insert("Z");
	s.insert("X");
	s.insert("C");
	s.insert("V");
	s.insert("B");
	s.insert("N");
	s.insert("M");
    
	ofstream fo("Output.txt");
	s.print(fo);
	fo << endl << endl;
	StringBinTree s2 = s.copy();
	s2.print(fo);
	fo.close();
    return 0;
}