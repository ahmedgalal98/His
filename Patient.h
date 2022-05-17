#pragma once
#include <string>
#include<iostream>
using namespace std;
#define MAX_DOCTORS 10
class Patient
{
	
private:
	int id;
	string name;
	string address;
	string phone;
	string birthDate;
	string SEX ;
	
	//Doctor_id
	int SSN[MAX_DOCTORS];

	static int Patient_counter;

	// medicalStatus
	string medicalHistory;
    string  allergies;
	string bloodPressure;
	int heartRate;
	float temperature;

	//Criteria for inserting in pirority Queue
	int severity;
public:

    Patient(string name,string address, string phone, string birthDate,string sex,string medicalHistory,string allergies, string bloodPressure, int heartRate, float temperature,int severity);
	
	//setters
	void setName(string name);
	void setAddress(string address);
	void setPhone(string phone);
	void setBirthdate(string birthDate);
	void setSEX(string sex);
	void setMedicalHistory(string medical);
    void setAllergies(string allergies);
	void setBloodPressure(string blood);
	void setHeartRate(int heartrate);
	void setTepmprature(float temp);
	void setSeverity(int severity);
	

	//getters
	int getID();
	string getName();
	string getAddress();
	string getPhone();
	string getBirthdate();
	string getSEX();
	string getMedicalHistory();
    string getAllergies();
	string getBloodPressure();
	int getHeartRate();
	float getTepmprature();
	int getSeverity();
    string getPersonalName();
	//printing 
	void displayPatientINFO();
	void displayPersonalINFO();
	void displayMedicalINFO();

	//oparetor overloading
	bool operator >(Patient &p)const;
	bool operator <(Patient &p)const;
	bool operator==(Patient &p)const;

	//helper functions
	void setDoctor(int ssn);
	int *getDoctors();
	~Patient();
};

