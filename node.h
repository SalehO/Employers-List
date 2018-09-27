#include<string>
#include "employee.h"
using namespace std ;
struct Node {
	employee data;
	Node *next;
};

struct HeadNode
{
	int count;
	Node *headPtr;
};
