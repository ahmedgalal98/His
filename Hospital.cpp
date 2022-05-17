#include "Hospital.h"



Hospital::Hospital()
{
	this->queue_counter = 0;
	this->counter_ICU = 0;
	this->counter_doctor = 0;
	this->patient_counter = 0;

	doctors_ptr = new Doctor*[MAX_DOCTORS_LIST];
	ICU_ptr = new ICU*[MAX_ICU];
	patients_ptr = new Patient*[MAX_PATIENTS];
	prescription_ptr = new Prescription*[MAX_PRES];

}

ICU ** Hospital::getICU_LIST()
{
	return ICU_ptr;
}

Doctor ** Hospital::getDoctors_list()
{
	return doctors_ptr;
}

Patient ** Hospital::getPatients_list()
{
return patients_ptr;
}


priorityQueue<Patient*> Hospital::getPatientsQueue()
{
	return Patients_Queue;
}

int Hospital::getDoctorCounter()
{
	return this->counter_doctor;
}

int Hospital::getICUcounter()
{
	return this->counter_ICU;
}

int Hospital::getpatientCounter()
{
	return this->patient_counter;
}

int Hospital::getQueueCounter()
{
	return this->queue_counter;
}

void Hospital::displayDoctorsList()
{
	for (int i = 0; i < counter_doctor; i++)
	{
		if (doctors_ptr[i] != NULL)
			doctors_ptr[i]->displayDoctorInfo();
	}
}

void Hospital::displayICUList()
{
	for (int i = 0; i < counter_ICU; i++)
	{
		if (ICU_ptr[i] != NULL)
			ICU_ptr[i]->dispaly_ICU_Info();
	}
}

void Hospital::displayPatientsList()
{
for (int i = 0; i < patient_counter; i++)
{
if (patients_ptr[i] != NULL)
patients_ptr[i]->displayPatientINFO();
}
}

string Hospital::getPatientinfo(int i)
{

if (patients_ptr[i] != NULL)

return patients_ptr[i]->getPersonalName();
}


void Hospital::addDoctor(Doctor * ptr)
{
	if (counter_doctor < MAX_DOCTORS_LIST)
		doctors_ptr[counter_doctor++] = ptr;
	else
		cout << "You have maximum number of doctors " << MAX_DOCTORS_LIST << endl;
	
}

void Hospital::addICU(ICU * ptr)
{
	if (counter_ICU < MAX_ICU)
		ICU_ptr[counter_ICU++] = ptr;
	else
		cout << "You have maximum number of ICUs " << MAX_ICU << endl;
}

void Hospital::EnqueuPatient(Patient * ptr)
{
	Patients_Queue.insertNode(ptr);
	queue_counter++;
}
void Hospital::DequeuPatient()
{
	if (patient_counter < MAX_PATIENTS)
	{
		Patient*ptr = Patients_Queue.peek();
		this->addPatient(ptr);
		Patients_Queue.deque();
		queue_counter--;
	}
	else {
		cout << "Patient should be in the Queue as there is no  vacancy place in hopital" << endl;
	}
	
}
Patient * Hospital::getPeak()
{
	return Patients_Queue.peek();
}

bool Hospital::Max_capacity()
{
	if (this->patient_counter == MAX_PATIENTS)
		return true;
	else
		return false;
}

void Hospital::Make_Prescription(int patient_id,Prescription*ptr)
{
	if (prespiction_counter > MAX_PRES)
	{
		cout << "You have reached to the MAX of Prescriptions" << endl;
		return;
	}
	bool found = false;
	for (int i = 0; i < patient_counter; i++)
	{
		if (patients_ptr[i]->getID() == patient_id)
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		prescription_ptr[prespiction_counter] = ptr;;
		prescription_ptr[prespiction_counter++]->setPatientID(patient_id);
	}
	else
		cout << "There is no patient with this id" << endl;
}

void Hospital::Display_Prescribtion_of_Patient(int patient_id)
{
	if (prespiction_counter < 1)
	{
		cout << "there is no Prescribtion already written" << endl;
		return;
	}

	bool found = false;
	for (int i = 0; i < patient_counter; i++)
	{
		if (patients_ptr[i]->getID() == patient_id)
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		int counter = 0;
		for (int i = 0; i < prespiction_counter; i++)
		{
			if (prescription_ptr[i]->getPatientID() == patient_id)
			{
				prescription_ptr[i]->displayPrescription();
				counter++;
			}
		}
		if (counter == 0)
			cout << "this patient has no Prespiction" << endl;
		else
			cout << "total Prespiction is : " << counter << endl;
	}
	else
		cout << "There is no patient with this id" << endl;
}

void Hospital::addPatient(Patient * ptr)
{
if (patient_counter < MAX_PATIENTS)
patients_ptr[patient_counter++] = ptr;
else
cout << "You have maximum number of Patients " << MAX_PATIENTS << endl;

}


Hospital::~Hospital()
{
}
