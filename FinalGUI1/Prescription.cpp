#include "Prescription.h"


Prescription::Prescription(string drug, int code, int noftimes, int dose,string start,string end)
{
	if (end < start)
		cout << "end date must be after start date"<<endl;
	else
	{
		this->drug = drug;
		this->code = code;
		this->noftimes = noftimes;
		this->dose = dose;
		this->start = start;
		this->end = end;
	}

}

void Prescription::setPatientID(int id)
{
	this->patient_id = id;
}

string Prescription::getDrug()
{
	return this->drug;
}
int Prescription::getCode()
{
	return this->code;
}

int Prescription::getnoftimes()
{
	return this->noftimes;
}

int Prescription::getDose()
{
	return this->dose;
}

int Prescription::getPatientID()
{
	return this->patient_id;
}

void Prescription::displayPrescription()
{
	cout << "Patient id is: " <<this->patient_id<< endl;
	cout << "Prescription of code " << this->code << endl;
	cout << "Drug is: " << this->drug << endl;
	cout << "Number of times is " << this->noftimes << endl;
	cout << "Dose :" << this->dose << endl;
	cout << "Start date: " << this->start << endl;
	cout << "End date: " << this->end << endl;;
}

Prescription::~Prescription()
{
}
