#include "ICU.h"

ICU::ICU(string name, string manager, int code, int capacity)
{
	this->setName(name);
	this->setManager(manager);
	this->code = code;
	this->capacity = capacity;
	this->freeBeds = capacity;
}

ICU::ICU()
{
	this->code = 0;
	this->capacity = 0;
	this->freeBeds = 0;
}

void ICU::setName(string name)
{
	this->name = name;
}

void ICU::setManager(string manager)
{
	this->manager = manager;
}

string ICU::getName()
{
	return this->name;
}

string ICU::getManager()
{
	return this->manager;
}

int ICU::getCode()
{
	return this->code;
}

int ICU::getCapacity()
{
	return this->capacity;
}

int ICU::getFreeBeds()
{
	return this->freeBeds;
}


void ICU::dispaly_ICU_Info()
{
	cout << "the ICU of code : " <<this->code << " and name : " << this->name << endl;
	cout << "manager is :" << this->manager << endl;
	cout << "capacity is: " << this->capacity << endl;
	cout << "num of free beds is :" << this->freeBeds << endl;

}

void ICU::AssignPatient(int patientId)
{
	if (patients.find(patientId) != patients.end()) // the patient already in the ICU
	{
		cout << "The patient with ID : " << patientId << " is already in the ICU" << endl;
		return;
	}

	if (freeBeds > 0) {
		--freeBeds;
		patients.insert(patientId);
	}
	else
		cout << "there is no free beds in the " << this->name << endl;
}

void ICU::DischargePatient(int patientId)
{
	if (patients.find(patientId) == patients.end()) // the patient is not in the ICU
	{
		cout << "The patient with ID : " << patientId << " is not in the ICU" << endl;
		return;
	}

	if (freeBeds < capacity)
	{
		++freeBeds;
		patients.erase(patientId);
		cout << "another bed now is free and now freeBeds is: " << this->freeBeds << endl;
	}
}

