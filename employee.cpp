#include <string>
#include <fstream>
#include "node.h"
#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "employee.h"
using namespace std;

employee::employee(void)
{
	string     first_name = "fdefault", last_name="ldefault";
	char  		status='J';
	float		netsalary=0000, grosssalary=0000, taxes=00000;

}

employee :: employee (string f, string l, char s, float n, float g, float t)
{
	first_name = f;
	last_name = l;
	status = s;
	netsalary = n;
	grosssalary = g;
	taxes = t;

}

void employee::set_first(string f){
	first_name = f;
}

void employee::set_last(string l ){
	last_name = l;
}

void employee::set_taxes(float t){
	taxes = t;
}
void employee::set_status(char s){
	status = s;
}

void employee::set_net(float n)
{
	netsalary = n;
} 

void employee::set_gross(float g){
	grosssalary = g;
}

string employee::get_first(){
	return first_name;
}

string employee::get_last(){
	return last_name;
}
char employee::get_status(){
	return status;
}
float employee::get_net(){
	return netsalary;
}
float employee::get_gross(){
	return grosssalary;
}

float employee::get_taxes(){
	return taxes;
}
void employee :: Read_struct(ifstream & fin)
{
	fin >> first_name;
	fin >> last_name;
	fin >> status;
	status = toupper(status);
	fin >> grosssalary;
}

void employee::Read_info()
{
	cout << "\n\nPlease enter the data for new employee(First, Last, Status, Income):\n";
	cin >> first_name;
	cin >> last_name;
	cin >> status;
	status = toupper(status);
	cin >> grosssalary;
}

void employee::joint_taxes()
{

	if ((grosssalary >= 0) && (grosssalary < 3420))
		taxes = 0;
	else if (grosssalary < 47120)
		taxes = 330.00 + ((4.0 / 100.0)*(grosssalary - 3420));
	else if (grosssalary < 57580)
		taxes = 1905.40 + ((9.0 / 100.0)*(grosssalary - 47120));
	else
		taxes = 2899.20 + ((11.0 / 100.0)*(grosssalary - 57580));
	netsalary = grosssalary - taxes;
}


void employee:: single_taxes()
{
	if ((grosssalary >= 0) && (grosssalary <1710))
		taxes = 0;
	else if (grosssalary < 20930)
		taxes = 87.00 + ((3.0 / 100.0)*(grosssalary - 1710));
	else if (grosssalary  < 28790)
		taxes = 742.40 + ((8.0 / 100.0)*(grosssalary - 20930));
	else
		taxes = 1449.60 + ((11.0 / 100.0)*(grosssalary - 28790));
	netsalary = grosssalary - taxes;
}

void employee:: print_mon_emp()
{
	cout << showpoint << setprecision(2) << left << fixed;

	cout << setw(20) << last_name + ", " + first_name;
	if (status == 'J' || status == 'j')
	{
		cout << setw(13) << "Joint";

		if (grosssalary < 0)
		{

			cout << left << setw(9) << "ERROR" << " <<<< Negative salary is invalid >>>>" << endl << endl;

		}
		else
		{
			cout << "$" << setw(13) << grosssalary;
			cout << "$" << setw(13) << taxes << "$" << setw(13) <<netsalary << endl << endl;

		}
	}
	else if (status == 'S' || status == 's')
	{
		cout << setw(13) << "Single";

		if (grosssalary < 0)
		{

			cout << setw(9) << "ERROR" << " <<<< Negative salary is invalid >>>>" << endl << endl;

		}
		else
		{
			cout << "$" << setw(13) << grosssalary;
			cout << "$" << setw(13) << taxes << "$" << setw(13) << netsalary << endl << endl;
		}
	}
	else
	{
		cout << "ERROR " << status << " is invalid input. " << endl << endl;

	}
}




void employee:: print_file_emp(ofstream&fout)           
{

	fout << showpoint << setprecision(2) << left << fixed;

	fout << setw(20) << first_name + " " + last_name;

	if (status == 'J' || status == 'j')
	{
		fout << left << setw(13) << "Joint";
		if (grosssalary < 0)
		{

			fout << "ERROR" << " <<<< Negative salary is invalid >>>>" << endl << endl;
		}
		else
		{
			fout << "$" << setw(13) << grosssalary;
			fout << "$" << setw(13) << taxes << "$" << setw(13) << netsalary << endl << endl;
		}
	}
	else if (status == 'S'|| status== 's')
	{
		fout << left << setw(13) << "Single";
		if (grosssalary < 0)
		{

			fout << "ERROR" << " <<<< Negative salary is invalid >>>>" << endl << endl;

		}
		else
		{
			fout << "$" << setw(13) << grosssalary;
			fout << "$" << setw(13) << taxes << "$" << setw(13) << netsalary << endl << endl;
		}
	}
	else
	{
		fout << "ERROR " << status << " is invalid input. " << endl << endl;
	}
}