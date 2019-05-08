#include <iostream>
#include "Node.h"
#include "BinTree.h"
using namespace std;


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
	cout << endl << endl;
    
    return 0;
}