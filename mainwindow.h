#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:

    void get_patientData();
    void get_counter();
    void display_patient_list();
    void get_DoctorData();
    void display_doctor_list();
    void get_ICUData();
    void display_ICU_list();
    void ass_patient();


};
#endif // MAINWINDOW_H
