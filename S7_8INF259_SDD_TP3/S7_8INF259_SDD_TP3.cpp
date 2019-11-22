#include <iostream>
#include "bst.h"
#include <vector>
using namespace std;

int main()
{
	BST arbre = BST(10);
	std::vector<int> vect { 5,12,3,9,16,13,11,6,8 };
	arbre.Insert(vect);


	std::cout << "Fin programme" << endl;
}