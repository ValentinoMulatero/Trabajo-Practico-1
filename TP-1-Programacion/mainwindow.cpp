#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow )
{
    ui->setupUi(this);

    /*reservo memoria para ventanas secundarias*/
    uiWinIngresoPacientes=new IngresoPacientes(nullptr);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setUserLogin(QString usuario)
{

}

 void MainWindow::addMovimientos(QString msj){

     ui->listMovimientos_1->addItem(msj);
     ui->listMovimientos_1->scrollToBottom();
}

 void MainWindow::updateEspera(){
     ui->listMovimientos_1->addItem("Próximo paciente a ser atendido: ");
     ui->listMovimientos_1->scrollToBottom();
 }

 void MainWindow::updateAtendido(){
     ui->listMovimientos_1->addItem("Paciente en consulta: ");
     ui->listMovimientos_1->scrollToBottom();
 }

 void MainWindow::lastAtendido(){
     ui->listMovimientos_2->addItem("Pacientes atendidos: ");
     ui->listMovimientos_2->scrollToBottom();
 }

 void MainWindow::on_btnSiguiente_clicked(){
     if(!pacientes.isEmpty()){
        QString pacientePop = pacientes.front();

        updateEspera();

        ui->listMovimientos_1->addItem(pacientePop);
        ui->listMovimientos_1->scrollToBottom();
     } else {
         ui->listMovimientos_1->addItem("No hay pacientes por atender");
         ui->listMovimientos_1->scrollToBottom();
     }
 }

 void MainWindow::on_btnAtender_clicked(){
     if (!pacientes.isEmpty()) {

        updateAtendido();

        ui->listMovimientos_1->addItem(pacientes.front());

        //Saca de pacientes y mete a atendidos
        QString pacienteAtendido = pacientes.dequeue();
        atendidos.enqueue(pacienteAtendido);
        ui->listMovimientos_1->scrollToBottom();
     } else {
        ui->listMovimientos_1->addItem("Se atendieron todos los pacientes");
        ui->listMovimientos_1->scrollToBottom();
     }
 }

 void MainWindow::on_btnAtendidos_clicked(){
    //QString pacientePap = atendidos.front();

    lastAtendido();

    QQueue<QString> copiaCola2 = atendidos;
    while(!copiaCola2.isEmpty()) {
        ui->listMovimientos_2->addItem(copiaCola2.dequeue());
        ui->listMovimientos_2->scrollToBottom();
    }
 }

void MainWindow::on_btnAnadir_clicked()
{
    //Creacion de la lista para QComboBox
    uiWinIngresoPacientes->setListgenero({"Femenino", "Masculino", "No binario", "No responde"});

    //Si el usuario presiona "aceptar" en la ventana de ingreso
    if(uiWinIngresoPacientes->exec() == QDialog::Accepted){


        //recuperamos el nombre desde la interfaz
        QString IngresoPacientesSelect = uiWinIngresoPacientes->getIngresoPacientes();
        //Metemos el elemento a la Cola
        pacientes.enqueue(IngresoPacientesSelect);
        //limpiamos la lista visual para redibujarla actualizada
        ui->listMovimientos_1->clear();

        ui->listMovimientos_1->addItem("Pacientes en espera: ");

        //Recorremos la cola usando una copia temporal y agregamos cada uno ABAJO
        QQueue<QString> copiaCola = pacientes;
        while(!copiaCola.isEmpty()) {
            ui->listMovimientos_1->addItem(copiaCola.dequeue());
        }
     }

}


