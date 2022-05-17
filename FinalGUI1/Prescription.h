#pragma once
#include <string>
#include<iostream>

using namespace std;
class Prescription
{
	string drug;
	string start;   //format MM/DD
	string end;     //format MM/DD
	int code=0;
	int noftimes=0;
	int dose=0;
	int patient_id = 0;

public:
	Prescription(string drug,int code,int noftimes,int dose, string start, string end);
	
	void setPatientID(int id);

	//getters
	string getDrug();
	int getCode();
	int getnoftimes();
	int getDose();
	int getPatientID();

	//printing
	void displayPrescription();

	~Prescription();
};

