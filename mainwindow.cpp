#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Patient.h"
#include "Doctor.h"
#include "ICU.h"
#include "Prescription.h"
#include "Hospital.h"
#include <QMessageBox>
Hospital* h1 = new Hospital();
ICU* c2;
int co=0 ;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    QMessageBox msgBox;
    msgBox.setText("Welcome to our system");
    msgBox.exec();
    ui->setupUi(this);
    //patient
    connect(ui->Padd_pushButton,SIGNAL(clicked()),this,SLOT(get_patientData()));
    connect(ui->counter_pushButton,SIGNAL(clicked()),this,SLOT(get_counter()));
    connect(ui->display_pushButton,SIGNAL(clicked()),this,SLOT(display_patient_list()));
    //doctor
    connect(ui->Dadd_pushButton,SIGNAL(clicked()),this,SLOT(get_DoctorData()));
    connect(ui->Ddisplay_pushButton,SIGNAL(clicked()),this,SLOT(display_doctor_list()));
    //ICU
    connect(ui->Iadd_pushButton,SIGNAL(clicked()),this,SLOT(get_ICUData()));
    connect(ui->Idisplay_pushButton,SIGNAL(clicked()),this,SLOT(display_ICU_list()));
    connect(ui->ass_pushButton,SIGNAL(clicked()),this,SLOT(ass_patient()));


 cout << "Welcome to our system" << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// patient
void MainWindow::get_patientData()
{   // patient
    string pname;
    string paddress;
    string pphone;
    string pbirthDate;
    string pSEX;
    string medicalHistory;
    string  allergies;
    string bloodPressure;
    int heartRate = 0;
    float temperature = 0.0;
    int severity = 0;


    if (ui->Pname_lineEdit->text().isEmpty()&&ui->Paddress_lineEdit->text().isEmpty()&&ui->Pphone_lineEdit->text().isEmpty()
            &&ui->Pbirthday_lineEdit->text().isEmpty()&&ui->Psex_lineEdit->text().isEmpty()&&ui->Pmedical_history_lineEdit->text().isEmpty()
            &&ui->Pblood_pressure_lineEdit->text().isEmpty()&&ui->Pheart_rate_lineEdit->text().isEmpty()
            &&ui->Ptemp_lineEdit->text().isEmpty()&&ui->Pseverity_lineEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Please add all information ");
        msgBox.exec();
    }
    else
    {
        pname = ui->Pname_lineEdit->text().toStdString();
        paddress= ui->Paddress_lineEdit->text().toStdString();
        pphone= ui->Pphone_lineEdit->text().toStdString();
        pbirthDate= ui->Pbirthday_lineEdit->text().toStdString();
        pSEX= ui->Psex_lineEdit->text().toStdString();
        medicalHistory= ui->Pmedical_history_lineEdit->text().toStdString();
        allergies= ui->Pallergies_lineEdit->text().toStdString();
        bloodPressure= ui->Pblood_pressure_lineEdit->text().toStdString();
        heartRate= ui->Pheart_rate_lineEdit->text().toInt();
        temperature= ui->Ptemp_lineEdit->text().toFloat();
        severity=ui->Pseverity_lineEdit->text().toInt();
        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "Save", "Do you want save changes?",
            QMessageBox::Save |  QMessageBox::Cancel);

        if (reply == QMessageBox::Save) {
            Patient* p2 = new Patient(pname, paddress, pphone, pbirthDate, pSEX, medicalHistory, allergies, bloodPressure, heartRate, temperature, severity);

            h1->EnqueuPatient(p2);
            co=co+1;
            ui->Pname_lineEdit->clear();
            ui->Paddress_lineEdit->clear();
            ui->Pphone_lineEdit->clear();
            ui->Pbirthday_lineEdit->clear();
            ui->Psex_lineEdit->clear();
            ui->Pmedical_history_lineEdit->clear();
            ui->Pallergies_lineEdit->clear();
            ui->Pblood_pressure_lineEdit->clear();
            ui->Pheart_rate_lineEdit->clear();
            ui->Ptemp_lineEdit->clear();
            ui->Pseverity_lineEdit->clear();

            QMessageBox* m_setting2 = new QMessageBox();
            QString text = QString("You have entered a new patient to our seystem with id= %1").arg(p2->getID());
            m_setting2->setText(text);
            int ret = m_setting2->exec();

        }
    }

}
void MainWindow:: get_counter()
{
    QMessageBox msgBox;

    QString text = QString("Counter of Queue = %1 & Counter of Patient = %2").arg(h1->getQueueCounter()).arg(h1->getpatientCounter());
    msgBox.setText(text);
    QAbstractButton* pButtonYes = msgBox.addButton(tr("Dequeue"), QMessageBox::YesRole);
    msgBox.addButton(tr("OK"), QMessageBox::NoRole);

    msgBox.exec();

    if (msgBox.clickedButton()==pButtonYes) {
        if (co == 0 ){
            QMessageBox msgBox;
            msgBox.setText("The Heap is empty!");
            msgBox.exec();
        }
        else
        {
            h1->DequeuPatient();
            co=co-1;
        }

    }
}
void MainWindow::display_patient_list()
{
    h1->displayPatientsList();
}

// doctor
void MainWindow::get_DoctorData()
{
    // doctor
    string name;
    string major;
    string degree;
    string birthDate;
    string SEX;
    if (ui->Dname_lineEdit->text().isEmpty()&&ui->DMajor_lineEdit->text().isEmpty()&&
            ui->DDegree_lineEdit->text().isEmpty()&&ui->Dbirthday_lineEdit->text().isEmpty()&&ui->Dsex_lineEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Please add all information ");
        msgBox.exec();
    }
   else
    {
        name = ui->Dname_lineEdit->text().toStdString();
        major= ui->DMajor_lineEdit->text().toStdString();
        degree= ui->DDegree_lineEdit->text().toStdString();
        birthDate= ui->Dbirthday_lineEdit->text().toStdString();
        SEX= ui->Dsex_lineEdit->text().toStdString();

        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "Save", "Do you want save changes?",
            QMessageBox::Save |  QMessageBox::Cancel);

        if (reply == QMessageBox::Save) {
            Doctor* d3 = new Doctor(name, major, degree, birthDate, SEX);
            h1->addDoctor(d3);

            ui->Dname_lineEdit->clear();
            ui->DMajor_lineEdit->clear();
            ui->DDegree_lineEdit->clear();
            ui->Dbirthday_lineEdit->clear();
            ui->Dsex_lineEdit->clear();


        }
    }

}

void MainWindow::display_doctor_list()
{
    h1->displayDoctorsList();
}



// ICU
void MainWindow::get_ICUData()
{
    // for ICU
    string Iname;
    string manager;
    int code;
    int capacity;
    int c = 0;
    if (ui->Iname_lineEdit->text().isEmpty()&&ui->IManager_lineEdit->text().isEmpty()&&
            ui->Icode_lineEdit->text().isEmpty()&&ui->Icapacity_lineEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Please add all information ");
        msgBox.exec();
    }
   else
    {
        Iname = ui->Iname_lineEdit->text().toStdString();
        manager=ui->IManager_lineEdit->text().toStdString();
        code= ui->Icode_lineEdit->text().toInt();
        capacity= ui->Icapacity_lineEdit->text().toInt();


        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "Save", "Do you want save changes?",
            QMessageBox::Save |  QMessageBox::Cancel);

        if (reply == QMessageBox::Save) {

            c2 = new ICU(Iname, manager, code, capacity);
            h1->addICU(c2);

            ui->Iname_lineEdit->clear();
            ui->IManager_lineEdit->clear();
            ui->Icode_lineEdit->clear();
            ui->Icapacity_lineEdit->clear();


        }
    }

}

void MainWindow::display_ICU_list()
{
    h1->displayICUList();
   // c2->AssignPatient(5);


}
void MainWindow::ass_patient()
{
    c2->AssignPatient(ui->ass_lineEdit->text().toInt());
    ui->ass_lineEdit->clear();
}


