

/*
=======>> ID Block

						     	   <<  ---------------------------  >>
							   <<     *	Name: Omar Saleh        *      >>
					        <<        *	ID# 1395477             *         >>  
                          <<          *	Computer Science 2      *           >>
					   <<             ***************************             >>
			    	     <<           *	Friday                  *            >>
                           <<         *	Prof. Massoud Ghyam     *          >>
                              <<      *	Assignment 2            *       >>
                                <<    *	Due 09/25/2015          *     >>
								   << ---------------------------  >>






*/
#include "LinkedList.h"
#include "node.h"
#include "employee.h"
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#define capacity 20

using namespace std;


//========>> Functions Prototypes

void capital (string & lastname);
int counter(employee list[], int size);
void Bubble_sort_last(employee list[], int size);
void Bubble_sort_grosssalary (employee list[], int size);
bool open_ifile(ifstream &fin);
void Read_struct(ifstream & fin, employee & temp);
void open_ofile();
bool check_all(employee list[], int index);
bool check_grosssalary(employee list[], int index);
void Process(employee list[], int size);
void Totals( employee list[], float & tgSalary, float & tnSalary, float & tTaxes, int size);
bool Equal( employee e1, employee e2);
void Avg (employee list[], float & AgSalary, float & AnSalary, float & ATaxes, int size);
void header (ofstream & fout);
int Search_last( employee list[], int size, string Lname);
void Find_employee(employee list[], int size);
void remove (employee list[], int &size);
int read_all ( employee list[], int capacity_size);
void header_monitor ();
void OUTPUT_monitor(employee list[], int size);
void OUTPUT(employee list[], int size);
void add(employee list[], int &index, int cap);
char Letter();
void fun_switch(employee list[], int&size, int cap, char&choice);
void goodbye();
void empty_errormsg();
void ID ();

//                                           ===============>>>>>> MAIN FUNCTION <<<<<<<====================

int main()
{
ID ();
employee list[capacity];
int size;
char let;
size=read_all (list, capacity);
Process(list,size);
if(size>0)
 {
	let=Letter();
	while(let!='J')
	{
		fun_switch(list, size, capacity, let);
		let=Letter();
	}
 }
goodbye();
return 0;
}


void capital (string & lastname) 
{   int length=0;
	length=lastname.length(); 

	lastname[0] = toupper(lastname[0]);
	for(int i=1; i<length; i++)
		lastname[i] = tolower(lastname[i]);
}

// print error msg if file is empty
void empty_errormsg()
{
	cout<<"ERROR! Empty File!!"<<endl;
}


//opens input file, prombts user for name and check if it opens or not
bool open_ifile(ifstream &fin)
{    
	string	ifile_name;
	cout <<"- Pease Enter Input File Name: ";
	cin >> ifile_name ;
	fin.open(ifile_name.c_str());
	if (fin.fail())
	{
		cout<<"File does Not exist!"<<endl;		
		return false ;
	}
	else
		{
		return true ;	 
		}
	}

// reads all information from list by using the read function above, and checks if the file opens, if it didnt open prints error msg, and returns size of file
int read_all ( employee list[], int capacity_size)
{
		
		int i=0;
		ifstream fin;
		if(open_ifile(fin))
			{
	 		list[i].Read_struct( fin);
	 		while(!fin.eof())
	 		{
	 		i++;
	 		if (i<capacity_size)
	 		list[i].Read_struct( fin);
	 		else
	 			{
	 		cout<<"Array is Full, Please increase array capacity!"<<endl;
	 		break;
	 			}
						}
			if (i==0)
				empty_errormsg();
			
		}
		return i;
}
		
// opens output file by prombting user for output name
void open_ofile(ofstream& fout)

{
string ofile_name;
	cout <<"-Please Enter Output File Name: ";
	cin >> ofile_name ;
	fout.open(ofile_name.c_str());

}	


bool check_grosssalary(employee list[], int index)
				{
					if (list[index].get_gross() < 0)
				return false;
				else 
				return true;
				}
// checks for all info and returns true or false 
bool check_all(employee list[], int index)
			{
				if ((list[index].get_status() == 'J' || list[index].get_status() == 'S' || list[index].get_status() == 'j' || list[index].get_status() == 's') && (check_grosssalary(list, index)))
			return true;	
			else
			return false;	
			 }
// increases the count and returns it
int counter(employee list[], int size)
	{
	int count=0;

	for (int i =0; i<size; i++)
					{
			if(check_all(list, i))
			count++;
					}
			return count;
		}

// claculates everything by using for loob, after checking all info it calculates taxes then net salary
void Process(employee list[], int size)
				{
				
for (int i =0; i<size; i++)
		{
	if(check_all(list, i))
					{
							
						if (list[i].get_status() == 'J' || list[i].get_status() == 'j')
						{
							list[i].joint_taxes();
						}
						else if (list[i].get_status() == 'S' || list[i].get_status() == 's')
									list[i].single_taxes();
									
					}
	else
			{
				list[i].set_net(0) ;
				list[i].set_taxes(0) ;
				}
						} 
								
				}



// calculates average by dividing totals over counter
void Avg (employee list[], float & AgSalary, float & AnSalary, float & ATaxes, int size)
{

float tgsalary=0,tnsalary=0, ttaxes=0;
Totals(  list,  tgsalary,  tnsalary,  ttaxes, size);
AgSalary=tgsalary/counter( list, size);
AnSalary=tnsalary/counter( list, size);
ATaxes=ttaxes/counter( list, size);
}

//prints header to file
void header (ofstream & fout)
{
	
	fout <<endl <<left<<setw (18)<< "Name"<< setw (13) << "  Status" << setw (13) << "  Gross Salary" << setw(13) << "  Taxes" << setw (13) << "   Net Salary"<<endl;
	fout <<"=============================================================================="<<endl;
}
//prints my ID 			
void ID ()
{
	cout << "			++++++++++++++++++++++++++++++"<<endl;
	cout << "			+                            +"<<endl;
	cout << "	 		+    Assignment:    5        +"<<endl;
	cout << " 			+    Programer: Omar Saleh   +"<<endl;
	cout << "			+    CS 2. Friday            +"<<endl;
	cout << "			+    Instructor: M. Ghyam    +"<<endl;
	cout << "			+                            +"<<endl;
	cout << "			++++++++++++++++++++++++++++++"<<endl << endl << endl;
	
}

// prints prints everything to the monitor and prints average
void OUTPUT(employee list[], int size)
{
ofstream fout;


open_ofile(fout);


header(fout);
float Agsalary, Ansalary, Ataxes;
Avg ( list,  Agsalary, Ansalary,  Ataxes, size);
for(int i=0 ; i < size ; i++)
		{
list[i].print_file_emp(fout);
		}

		fout<<"			------*************-------"<<endl<<endl;
		fout<<setw(33)<<"Average="<<setw(13)<<Agsalary<<setw(13)<<Ataxes<<setw(13)<<Ansalary<<endl<<endl;
		fout.close();
}



// calculate the totals by using for loob
void Totals( employee list[], float & tgSalary, float & tnSalary, float & tTaxes, int size)
{
for(int i=0 ; i < size ; i++)
		{
			if(check_all(list,i))
			{
				tTaxes += list[i].get_taxes();
				tnSalary += list[i].get_net();
				tgSalary += list[i].get_gross();
			}
		}
}

// print joint information to file and prints error msg if negative
void printJoint(employee list[], ofstream&fout, int index)    
{

			//cout<< setw(14) << "Joint";
			fout<< left<<setw(13) << "Joint";
			if (list[index].get_gross() < 0)
			{
               
		     //   cout<<"ERROR" << " <<<< Negative salary is invalid >>>>"<<endl<<endl;
				fout<<"ERROR" << " <<<< Negative salary is invalid >>>>"<<endl<<endl;
			}
        	else 
		    {
				fout << "$" << setw(13) << list[index].get_gross();
				fout << "$" << setw(13) << list[index].get_taxes() << "$" << setw(13) << list[index].get_net() << endl << endl;
			}
	}

//print single , taxes and net salary to fileand prints error msg if negative
void printSingle (employee list[], ofstream&fout, int index)            
	{
			fout <<left<< setw(13) << "Single";
			if (list[index].get_gross() < 0)
				{
					
		        fout<<"ERROR" << " <<<< Negative salary is invalid >>>>"<<endl<<endl;
				
			}
        	else 
		    {								
				fout << "$" << setw(13) << list[index].get_gross();
				fout << "$" << setw(13) << list[index].get_taxes() << "$" << setw(13) << list[index].get_net() << endl << endl;
			}
	}

// function search for last name and return index if found or -1 if cant be found	
int Search_last( employee list[], int size, string Lname)
{
	for (int i = 0 ; i < size ; i++)
		if (list[i].get_last() == Lname)
			return i ;
	return -1 ;
}

// prombts user for name of an employee to remove from list from list by switching it with the last one and decrease size by 1
void remove (employee list[], int &size)
{
    string	target ;
	int		index ;
	cout << "Please enter employee's last name you want to delete: " ;
	cin >> target ;
	capital(target);
	index = Search_last(list, size, target);
	if (index == -1)
		cout << target << " does not exist!"<<endl<<endl;
	else
	{
		list[index]=list[size-1];
		size--;
	}
}

// prombs user for last name to look for and print an error msg if cant find it and print report
void Find_employee(employee list[], int size)
{
	string	target ;
	int		index ;
	cout << "Please enter employee's last name to search for: " ;
	cin >> target ;
	capital(target);
	index = Search_last(list, size, target);
	if (index == -1)
		cout << target << " does not exist!"<<endl<<endl;
	else
	{
		header_monitor();
		list[index].print_mon_emp();
	}
}
		

// sorts last names
void Bubble_sort_last(employee list[], int size)
{
	bool 	flag ;
	employee	Temp ;

do
	{
		size--;
		flag = false ;
		for(int i = 0 ; i < size ; i++)
			if (list[i].get_last() > list[i + 1].get_last())
			{
				Temp = list[i];
				list[i] = list[i+1];
				list[i+1] = Temp ;
				flag = true ;
			}
	}
while(flag);
}

// sorts gross salary
void Bubble_sort_grosssalary (employee list[], int size)
{
	bool 	flag ;
	employee	Temp ;

do
	{
		size--;
		flag = false ;
for(int i = 0 ; i < size ; i++)
	if (list[i].get_gross() < list[i + 1].get_gross())
			{
				Temp = list[i];
				list[i] = list[i+1];
				list[i+1] = Temp ;
				flag = true ;
			}
	}
while(flag);
}
	
	

// prints header to the monitor
void header_monitor ()
{
	cout <<endl <<left<<setw (18)<< "Name"<< setw (13) << "  Status" << setw (13) << "  Gross Salary" << setw(13) << "  Taxes" << setw (13) << "   Net Salary"<<endl;
	cout <<"=============================================================================="<<endl;
}



// prombts user for employee's data to add to list and check if it already exist and prints error msg
void add(employee list[], int &index , int cap)
{
	employee temp;
	int check=0;
	if(index < cap)
	{
	
		temp.Read_info();                     
		for(int i=0; i<index; i++)
		{
		if (Equal( temp, list[i]))
		 {
		cout<<"ERROR!! Employee already exists!!"<<endl;
		check= -1;
		break;
		 }
		}
		if(check==0)
			{
		list[index]= temp;
		
		if (list[index].get_status() == 'J' || list[index].get_status() == 'j')
		list[index].joint_taxes();   
		else if (list[index].get_status() == 'S' || list[index].get_status() == 's')
		list[index].single_taxes();
		index++ ;

			}
	}
	else
		cout <<"Array is full, can't add any more employees.\n\n";

}




/// prints everything to monitor output print function above
void OUTPUT_monitor(employee list[], int size)
{
float Agsalary, Ansalary, Ataxes;

header_monitor();
Avg ( list,  Agsalary, Ansalary,  Ataxes, size);
for(int i=0 ; i < size ; i++)
		{
list[i].print_mon_emp();      
				}
	}


//checks if last name in 2 structurs are equal
bool Equal( employee e1, employee e2) // EXTRA CREDIT(CHECK FIRST NAME, STATUS, AND INCOME)
{
	if ( 
		e1.get_last() == e2.get_last()
		
		  )
		return true ; 
	else
		 return false ;
}


		
//promits user for a letter of an operation or the switch function
char Letter()
	{
	char letter;
	cout<<endl<<"--Please enter the letter of the operation you want to do:"<<endl<<endl
	<<"-A To read Income data from a file to update the list"<<endl
	<<"-B To print employee list content to a file"<<endl
	//<<"-C To Sort the list of employees alphabetical (Based on last name)"<<endl
	//<<"-D To sort the list of employees in descending order (based on Income)"<<endl
	<<"-E To Print list of employees in a tabular form to the monitor only"<<endl
	<<"-F To Search the list of employees and print report"<<endl
	<<"-G To add new employee to the list"<<endl
	<<"-H To delete an employee from the list"<<endl
	<<"-J To terminate the program"<<endl<<endl; 
	cin>>letter;
	letter=toupper(letter);
	return letter;
	}

// switch functin to operate one operatiom
void fun_switch(employee list[], int&size, int cap, char&letter)
{
 	
 	switch (letter)
	{
	case 'A':
		{
		size=read_all ( list, cap);
		Process(list,size);
		break;
		}
		
		case 'B':
		{
			 OUTPUT(list, size);
		break;
		}
		
		/*case 'C':
			{		
		Bubble_sort_last( list,  size);
		break;
		}
		
		case 'D':
		{
		Bubble_sort_grosssalary (list, size);	
		break;
		}
		*/
		case 'E':
		{
		OUTPUT_monitor(list, size);	
		break;
		}
		
		case 'F':
		{
		Find_employee(list, size);	
		break;
		}
		
		case 'G':
		{
		add(list, size, cap);
		break;
		}
		
		case 'H':
		{
		remove (list, size);
		break;
		}
		
		default :
	cout<<"ERROR!! The letter you entered is not acceptable"<<endl;
	}
}

// prints goodbye msg
void goodbye()
{
	cout<<"		    *********** Program Terminated! GoodBye:) **********"<<endl;

}