#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "reportdialog.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->senbButton, SIGNAL(clicked()), this, SLOT(sendMail()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));


    fileStringList.clear();
    server = "smtp.gmail.com";
    port = "465";
    currentUser = "lakshmananb1598@gmail.com";
    currentUserPassword = "Iamadeveloper2020";
    toAddress = "lakshmananb16mss023@skasc.ac.in";
    filePath = QDir::currentPath() + "/logFile.txt";

    qDebug() << "file line no 23" << filePath;
    QFile file(filePath);

    qDebug() << "file line no 24" << file;

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(currentUser, currentUserPassword, server, port.toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if (!filePath.isNull())
    {
        qDebug() << "Not Null";
        smtp->sendMail(currentUser, toAddress, ui->subjectTextField->text(), ui->messageTextField->toPlainText(), filePath);
    }
    else
    {
        qDebug() << "Null";
        //smtp->sendMail(currentUser, toAddress, ui->subjectTextField->text(), ui->messageTextField->toPlainText());
    }

}
void MainWindow::browse()
{

}
void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning(0, tr("Qt Simple Smtp client" ), tr("Message sent ! \n\n"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


