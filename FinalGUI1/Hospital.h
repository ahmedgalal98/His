#pragma once
#include<iostream>
#include "Doctor.h"
#include "Patient.h"
#include "ICU.h"
#include "Prescription.h"
#include "priorityQueue.h"
using namespace std;
#define MAX_DOCTORS_LIST 200
#define MAX_ICU 50
#define MAX_PATIENTS 2000
#define MAX_PRES 4000
class Hospital
{
private:
	Doctor **doctors_ptr;
	ICU **ICU_ptr;
	Patient **patients_ptr; // already in hospital
	Prescription**prescription_ptr;
	priorityQueue <Patient* > Patients_Queue; //waiting 
	
	
	int counter_doctor;
	int counter_ICU;
	int patient_counter;
	int prespiction_counter = 0;
	int queue_counter;
	void addPatient(Patient*ptr);
public:
	Hospital();
	
	//getters
	ICU**getICU_LIST();
	Doctor **getDoctors_list();
	Patient**getPatients_list();
	priorityQueue <Patient* >getPatientsQueue();
	int getDoctorCounter();
	int getICUcounter();
	int getpatientCounter();
	int getQueueCounter();

	//printing
	void displayDoctorsList();
	void displayICUList();
	void displayPatientsList();

	//Helper functions
	void addDoctor(Doctor*ptr);
	void addICU(ICU*ptr);
	
	void EnqueuPatient(Patient*ptr);
	void DequeuPatient();
	Patient *getPeak();
	bool Max_capacity();
	void Make_Prescription(int p_id,Prescription*ptr);
	void Display_Prescribtion_of_Patient(int patient);
    string getPatientinfo(int i);

	


	~Hospital();
};

