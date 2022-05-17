#include "Doctor.h"


int Doctor::SSN_counter = 100;


Doctor::Doctor()
{
	this->SSN = 0;
}

Doctor::Doctor(string name, string major, string degree, string birthDate, string SEX)
{
	this->name = name;
	this->SSN = SSN_counter++;
	this-> setMajor(major);
	this->setDegree(degree);
	this->setBirthdate(birthDate);
	this->setSEX(SEX);
}



void Doctor::setName(string name)
{
	this->name = name;
}

void Doctor::setMajor(string major)
{
	this->major = major;
}

void Doctor::setDegree(string degree)
{
	this->degree = degree;
}

void Doctor::setBirthdate(string birthDate)
{
	this->birthDate = birthDate;
}

void Doctor::setSEX(string sex)
{
	this->SEX = sex;
}

int Doctor::getSSN()
{
	return this->SSN;
}

string Doctor::getName()
{
	return this->name;
}

string Doctor::getMajor()
{
	return this->major;
}

string Doctor::getDegree()
{
	return this->degree;
}

string Doctor::getBirthdate()
{
	return this->birthDate;
}

string Doctor::getSEX()
{
	return this->SEX;
}


void Doctor::displayDoctorInfo()
{
	cout << "Display Doctor with SSN: " << this->SSN << endl;
	cout << "Name  : " << this->name << endl;
	cout << "Birth date: " << this->birthDate << endl;
	cout << "Degree: " << this->degree << endl;
	cout << "Major: " << this->major << endl;
	cout << "SEX: " << this->SEX << endl;

}

Doctor::~Doctor()
{
	SSN_counter--;
}
