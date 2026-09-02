#ifndef INGRESOPACIENTES_H
#define INGRESOPACIENTES_H

#include <QDialog>
#include <QQueue>
#include <QString>

namespace Ui {
class IngresoPacientes;
}

class IngresoPacientes : public QDialog
{
    Q_OBJECT

public:
    explicit IngresoPacientes(QWidget *parent = nullptr);
    ~IngresoPacientes();

    /* setters */
    void setListgenero(QStringList);

    /* getters */
    QString getIngresoPacientes();


private slots:
    void on_btnAceptarG_clicked();

private:
    Ui::IngresoPacientes *ui;
    QQueue<QString> pacientes;
};

#endif // INGRESOPACIENTES_H
