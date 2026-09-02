#include "ingresopacientes.h"
#include "ui_ingresopacientes.h"

IngresoPacientes::IngresoPacientes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IngresoPacientes)
{
    ui->setupUi(this);
}

IngresoPacientes::~IngresoPacientes()
{
    delete ui;
}

void IngresoPacientes::on_btnAceptarG_clicked()
{
    QString inputNa = ui->lineEdit->text();
    QString inputEdad = ui->lineEdit_2->text();
    QString inputGen = ui->cboxGenero->currentText();
    QString inputDni = ui->lineEdit_4->text();


    if(!inputNa.isEmpty() && !inputEdad.isEmpty() && !inputDni.isEmpty()) {
            accept();
        pacientes.enqueue(inputNa);
        }

    /*ui->lineEdit ->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_4->clear();*/
}

void IngresoPacientes::setListgenero(QStringList list){
    ui->cboxGenero->clear();
    ui->cboxGenero->addItems(list);
}

QString IngresoPacientes::getIngresoPacientes(){
    QString nombre;

    nombre= ui->lineEdit->text();

    //limpiamos todos los campos para la próxima vez que se abra
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_4->clear();
    ui->cboxGenero->setCurrentIndex(0);//reinicia el combo al primer elemento



    return nombre;
}

