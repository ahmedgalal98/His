#pragma once
#include <string>
#include <set>
#include<iostream>
using namespace std;
class ICU
{
private:
	string name; //must be unique
	string manager;
	int code;   //must be unique
	int capacity;
	int freeBeds;
	std::set<int> patients;

public:
	ICU(string name,string manager,int code,int capacity);
	ICU();
	//setters
	void setName(string name);
	void setManager(string manager);
	
	//getters
	string getName();
	string getManager();
	int getCode();
	int getCapacity();
	int getFreeBeds();

	//printing
	void dispaly_ICU_Info();

	//helper functions
	void AssignPatient(int patientId);
	void DischargePatient(int patientId);
};

