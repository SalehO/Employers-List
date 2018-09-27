#include <iostream>
#include<string>
#include "node.h"
#include "employee.h"
using namespace std ;
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();

		void addToHead( employee );
		bool removeFromHead();

//		bool addToTail( string );
//		bool removeFromTail();

		//void addNode( employee );
	//	bool deleteNode( employee);
		void deleteAllNodes();

		bool isEmpty();
		int getNoOfNodes();

		void displayAllNodes();

	private:
		//int dataCmp( employee, employee );
		void displayNode( Node* );

		HeadNode head;

};