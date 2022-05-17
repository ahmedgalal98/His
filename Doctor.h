#pragma once
#include <string>
#include<iostream>
using namespace std;
class Doctor
{
private:
	int SSN;
	string name;
	string major;
	string degree;
	string birthDate;
	string SEX;

	static int SSN_counter;

public:
	Doctor();
	Doctor(string name,string major,string degree,string birthDate,string SEX);

	//setters
	void setName(string name);
	void setMajor(string major);
	void setDegree(string degree);
	void setBirthdate(string birthDate);
	void setSEX(string sex);

	//getters
	int getSSN();
	string getName();
	string getMajor();
	string getDegree();
	string getBirthdate();
	string getSEX();

	//printing
	void displayDoctorInfo();

	~Doctor();
};

