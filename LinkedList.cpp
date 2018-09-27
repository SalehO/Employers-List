#include<iostream>
#include <string>
#include "employee.h"
#ifndef H_LinkedList
#define H_LinkedList

#include"LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	head.count = 0;
	head.headPtr = NULL;
}

LinkedList::~LinkedList()
{
	deleteAllNodes();
}

void LinkedList::addToHead( employee newData )
{
	Node *pNew = new Node;
	if (pNew == NULL){
		cout << " Creation invalid" << endl;
		return;
	}

	pNew -> data = newData;
	pNew -> next = head.headPtr;
	head.headPtr = pNew;
	head.count++;
}

bool LinkedList::removeFromHead()
{
	bool exit;
	Node *temp;

	if ( head.headPtr )
	{
		temp = head.headPtr;
		head.headPtr = head.headPtr -> next;
		delete temp;
		head.count--;
		exit = true; // returns true if successful
	}
	else
		exit = false; // returns false if unsuccessful

	return exit;
}

/*
bool LinkedList::addToTail( int )
{

}
bool LinkedList::removeFromTail()
{

}
*/

//void LinkedList::addNode( employee newData )
//{
//	Node *pNew = new Node,
//	     *pPre = NULL,
//	     *pCur = head.headPtr;
//	pNew -> data = newData;
//	pNew->next = NULL;
//
//	while ( pCur && dataCmp( pNew -> data, pCur -> data ) >= 0 )
//	{
//		pPre = pCur;
//		pCur = pCur -> next;
//	}
//
//	if ( pPre )
//	{
//		pNew -> next = pPre -> next;
//		pPre -> next = pNew;
//		head.count++;
//	}
//	else
//	{
//		pNew -> next = head.headPtr;
//		head.headPtr = pNew;
//		head.count++;
//	}
//	
//}

//bool LinkedList::deleteNode( employee data )
//{
//	bool exit;
//	Node *pPre = NULL,
//	     *pCur = head.headPtr;
//
//	while ( pCur && dataCmp( pCur -> data, data ) != 0 )
//	{
//		pPre = pCur;
//		pCur = pCur -> next;
//	}
//
//	if ( pCur && dataCmp( pCur -> data, data ) == 0 )
//	{
//		if ( pPre )
//		{
//			pPre -> next = pCur -> next;
//			delete pCur;
//			head.count--;
//			exit = true; // return true if successful
//		}
//		else
//		{
//			head.headPtr = pCur -> next;
//			delete pCur;
//			head.count--;
//			exit = true; // return true if successful
//		}
//	}
//	else
//		exit = false; // return false if unsuccessful
//
//	return exit;
//}

void LinkedList::deleteAllNodes()
{
	Node *temp;

	while ( head.headPtr )
	{
		temp = head.headPtr;
		head.headPtr = head.headPtr -> next;
		delete temp;
		head.count--;
	}


}

bool LinkedList::isEmpty()
{
	return head.count == 0;
}


int LinkedList::getNoOfNodes()
{
	return head.count;
}

void LinkedList::displayAllNodes()
{
	Node *pCur = head.headPtr;
	int nodeCount = 1;

	while ( pCur )
	{
		cout << "Node " << nodeCount << ": ";
		displayNode( pCur );
		cout << endl;

		nodeCount++;
		pCur = pCur -> next;
	}

	return;
}


/*int LinkedList::dataCmp( employee value0, employee value1 )
{
	int exit = 0;

	if ( value0 < value1 )
		exit = -1;
	else if ( value0 > value1 )
		exit = 1;

	return exit;
}
*/
void LinkedList::displayNode( Node *node )
{
	node -> data.print_mon_emp();
	return;
}
#endif