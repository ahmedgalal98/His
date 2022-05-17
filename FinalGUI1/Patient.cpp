#include "Patient.h"

int Patient::Patient_counter = 0;

Patient::Patient(string name, string address, string phone, string birthDate, string sex, string medicalHistory,string  allergies, string bloodPressure, int heartRate, float temperature,int severity)
{
	
	this->id = ++Patient_counter;
	this->setName(name);
	this->setAddress(address);
	this->setPhone(phone);
	this->setBirthdate(birthDate);
	this->setSEX(sex);
	this->setMedicalHistory(medicalHistory);
	this->setAllergies(allergies);
	this->setBloodPressure(bloodPressure);
	this->setHeartRate(heartRate);
	this->setTepmprature(temperature);
	this->setSeverity(severity);

	//initail doctor
	for (int i = 0; i < MAX_DOCTORS; i++)
	{
		SSN[i] = 0; //if 0 means that this patient has no doctor
	}
	
	cout << "You have entered a new patient to our seystem with id= " << id << endl;
	
	
}

void Patient::setName(string name)
{
	this->name = name;
}

void Patient::setAddress(string address)
{
	this->address = address;

}

void Patient::setPhone(string phone)
{
	this->phone = phone;

}

void Patient::setBirthdate(string birthDate)
{
	this->birthDate = birthDate;
}

void Patient::setSEX(string sex)
{
	this->SEX = sex;
}

void Patient::setMedicalHistory(string medicalHistory)
{
	this->medicalHistory = medicalHistory;
}

void Patient::setAllergies(string allergies)
{
	this->allergies = allergies;
}

void Patient::setBloodPressure(string bloodPressure)
{
	this->bloodPressure = bloodPressure;
}

void Patient::setHeartRate(int heartRate)
{
	this->heartRate = heartRate;
}

void Patient::setTepmprature(float temp)
{
	this->temperature = temp;
}

void Patient::setSeverity(int severity)
{
	this->severity = severity;
}

void Patient::setDoctor(int ssn)
{
	bool found = false;
	bool exist = false;
	for (int i = 0; i < MAX_DOCTORS; i++)
	{
		if (SSN[i] == ssn) //same doctor has added before
		{
			exist = true;
			break;
		}

		if (SSN[i] == 0)//check if patient has Max_enough_doctors
		{
			SSN[i] = ssn;
			found = true;
			break;
		}
	}
	if (exist)
	{
		cout << "doctor of SSN: " << ssn << " is already existed" << endl;
		return;
	}
	if (found)
		cout << "ASSIGN doctor sucessfully" << endl;
	else
		cout << "Patient has max number of doctors OR "<<endl;

}

int Patient::getID()
{
	return this->id;
}

string Patient::getName()
{
	return this->name;
}

string Patient::getAddress()
{
	return this->address;
}

string Patient::getPhone()
{
	return this->phone;
}

string Patient::getBirthdate()
{
	return this->birthDate;
}

string Patient::getSEX()
{
	return this->SEX;
}

string Patient::getMedicalHistory()
{
	return this->medicalHistory;
}

string Patient::getAllergies()
{
	return this->allergies;
}

string Patient::getBloodPressure()
{
	return this->bloodPressure;
}

int Patient::getHeartRate()
{
	return this->heartRate;
}

float Patient::getTepmprature()
{
	return this->temperature;
}

int Patient::getSeverity()
{
	return this->severity;
}

int* Patient::getDoctors()
{
	return SSN;
}

void Patient::displayPatientINFO()
{
	cout << "Personal INFO: " << endl;
	this->displayPersonalINFO();
	cout << "Medical Info: " << endl;
	this->displayMedicalINFO();
}

void Patient::displayPersonalINFO()
{
	cout << "Patient of ID: " << this->id << endl;
	cout << "Name: " << this->name << endl;
	cout << "Address: " <<this-> address << endl;
	cout << "Phone: " << this->phone << endl;
	cout << "Birthdate: " << this->birthDate << endl;
    cout << "Sex: " << this->SEX << endl;

}

string Patient::getPersonalName()
{
   return this->name;
}

void Patient::displayMedicalINFO()
{
	cout << "Patient of ID: " << this->id << endl;
	cout << "medicalHistory: " << this->medicalHistory << endl;;
	cout << "allergies: " << this->allergies << endl;
	cout << "bloodPressure: " << this->bloodPressure << endl;
	cout << "heartRate: " << this->heartRate << endl;
	cout << "temperature: " << this->temperature << endl;
	cout << "severity: " << this->severity << endl;
	
}
bool Patient::operator >(Patient & p)const
{
	if ( this->severity > p.getSeverity())
		return true;
	else
		return false;

}

bool Patient::operator<(Patient & p)const
{
	if (this->severity < p.getSeverity())
		return true;
	else
		return false;
}

bool Patient::operator==(Patient & p)const
{
	if (this->severity == p.getSeverity())
		return true;
	else
		return false;
}



Patient::~Patient()
{
	--Patient_counter;
}
