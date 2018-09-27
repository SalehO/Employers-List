#ifndef employee_H
#define employee_H
#include "node.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
/*
|-------------------------------------------------------|
|					employee     						|
|-------------------------------------------------------|
| - first_name, last_name : string		                |
| -	status : char		    							|
| - netsalary , grosssalary , taxes : float				|
|-------------------------------------------------------|
| + employee(void)                                      |
| + employee(string, string,char, float, float, float)  |
| +	set_first(string f):void							|
| +	set_last(string):void				    			|
| +	set_status(char):void								|
| +	set_net(float):void									|
| +	set_gross(float)									|
| +	get_first():string									|
| +	get_last(): string									|
| +	get_status():char									|
| +	get_net():float										|
| +	get_gross():float									|
| +	get_taxes(): float									|
| +	Read_struct(ifstream & fin): void					|
| +	Read_info():void									|
| +	joint_taxes():void									|
| +	single_taxes():void									|
| +	print_mon_emp():void								|
| +	print_file_emp(ofstream&fout): void					|
| +	set_taxes(float t): void							|
|_______________________________________________________|
*/
class employee{
private :

	string     first_name , last_name ;
	char  		status ;
	float		netsalary , grosssalary , taxes;


public:
	employee(void);
	employee(string f, string l, char s, float n, float g, float t);
		void set_first(string f);
		void set_last(string l);
		void set_status(char s);
		void set_net(float n);
		void set_gross(float g);
		string get_first();
		string get_last();
		char get_status();
		float get_net();
		float get_gross();
		float get_taxes();
		void Read_struct(ifstream & fin);
		void Read_info();
		void joint_taxes();
		void single_taxes();
		void print_mon_emp();
		void print_file_emp(ofstream&fout);
		void set_taxes(float t);
};







#endif