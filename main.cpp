#include "mainwindow.h"

#include <QApplication>

#include "Patient.h"
#include "Doctor.h"
#include "ICU.h"
#include "Prescription.h"
#include "Hospital.h"


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

//        Hospital* h1 = new Hospital();
//        // doctor
//        string name;
//        string major;
//        string degree;
//        string birthDate;
//        string SEX;
//        // patient
//        string pname;
//        string paddress;
//        string pphone;
//        string pbirthDate;
//        string pSEX;
//        string medicalHistory;
//        string  allergies;
//        string bloodPressure;
//        int heartRate = 0;
//        float temperature = 0.0;
//        int severity = 0;
//        // for ICU
//        string Iname;
//        string manager;
//        int code;
//        int capacity;
//        int c = 0;

//     cout << "Welcome to our system" << endl;
//        while (c != 4)
//        {
//                cout << "Press 1 to assign new doctor  ,   Press 2 to add new patient  , press 3 to assign new ICU , press 4 to exit" << endl;
//                cin >> c;
//                if (c == 1)
//                {
//                        int i = 0;
//                        while (i != 1) {
//                                cout << "##Please enter doctor informations## " << endl;
//                                cout << "##enter name## " << endl;
//                                cin >> name;
//                                cout << "##enter major## " << endl;
//                                cin >> major;
//                                cout << "##enter degree## " << endl;
//                                cin >> degree;
//                                cout << "##enter birthDate## " << endl;
//                                cin >> birthDate;
//                                cout << "##enter sex##" << endl;
//                                cin >> SEX;
//                                Doctor* d3 = new Doctor(name, major, degree, birthDate, SEX);
//                                h1->addDoctor(d3);
//                                cout << "Press 1 to terminate else Press 2 if you want to add new doctor " << endl;
//                                cin >> i;
//                                if (i == 1)
//                                        break;
//                        }
//                        cout << "##informations of added doctor##" << endl;
//                        h1->displayDoctorsList();
//                }
//                else if (c == 2)
//                {
//                        int j = 0;
//                        while (j != 1) {
//                                cout << "##Enter Patient## " << endl;
//                                cout << "enter name " << endl;
//                                cin >> pname;
//                                cout << "##enter address## " << endl;
//                                cin >> paddress;
//                                cout << "##enter pphone## " << endl;
//                                cin >> pphone;
//                                cout << "##enter birthDate##" << endl;
//                                cin >> pbirthDate;
//                                cout << "##enter patient sex##" << endl;
//                                cin >> pSEX;
//                                cout << "##enter medicalHistory##" << endl;
//                                cin >> medicalHistory;
//                                cout << "##enter allergies##" << endl;
//                                cin >> allergies;
//                                cout << "##enter bloodPressure##" << endl;
//                                cin >> bloodPressure;
//                                cout << "##enter heart rate ##" << endl;
//                                cin >> heartRate;
//                                cout << "##enter temperature ##" << endl;
//                                cin >> temperature;
//                                cout << "##enter severity##" << endl;
//                                cin >> severity;
//                                Patient* p2 = new Patient(pname, paddress, pphone, pbirthDate, pSEX, medicalHistory, allergies, bloodPressure, heartRate, temperature, severity);
//                                h1->EnqueuPatient(p2);
//                                cout << "press 1 to terminate or 2 to enter new patient " << endl;
//                                cin >> j;
//                                if (j == 1)
//                                        break;
//                        }

//                        j = 0;
//                        cout << "##Dequeue Patients##" << endl;
//                        while (j != 2 && h1->getQueueCounter() > 0)
//                        {
//                                cout << "patients queue counter is " << h1->getQueueCounter() << endl;
//                                cout << " patients in hospital is " << h1->getpatientCounter() << endl;
//                                cout << "##dequeue patient press 1 terminate press 2## " << endl;
//                                cin >> j;
//                                if (j == 1)
//                                        h1->DequeuPatient();
//                                if (j == 2)
//                                        break;
//                        }
//                        h1->displayPatientsList();

//                }
//                else if (c == 3)
//                {
//                        int n = 0;
//                        while (n != 1) {
//                                cout << "##Please enter ICU informations## " << endl;
//                                cout << "##enter name## " << endl;
//                                cin >> Iname;
//                                cout << "##enter manager## " << endl;
//                                cin >> manager;
//                                cout << "##enter code## " << endl;
//                                cin >> code;
//                                cout << "##enter capacity## " << endl;
//                                cin >> capacity;
//                                ICU* c2 = new ICU(Iname, manager, code, capacity);
//                                h1->addICU(c2);
//                                cout << "Press 1 to terminate else Press 2 if you want to add new ICU " << endl;
//                                cin >> n;
//                                if (n == 1)
//                                        break;
//                        }

//                        cout << "##informations of added ICU##" << endl;
//                        h1->displayICUList();
//                }
//        }


}

