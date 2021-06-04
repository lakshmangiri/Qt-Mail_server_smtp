#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "smtp.h"
#include <QMessageBox>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendMail();
    void mailSent(QString);
    void browse();

private:
    Ui::MainWindow *ui;
    QString server;
    QString port;
    QString currentUser;
    QString currentUserPassword;
    QString toAddress;
    QString filePath;
    QStringList fileStringList;
    QString st = QDir::currentPath();
    QFile file;
};
#endif // MAINWINDOW_H
