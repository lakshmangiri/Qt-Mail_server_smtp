#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDir>


// Smart pointer to log file
QScopedPointer<QFile>   m_logFile;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the logging file
    // check which a path to file you use
    m_logFile.reset(new QFile(QDir::currentPath() + "/logFile.txt"));
    // Open the file logging
    m_logFile.data()->open(QFile::Append | QFile::Text);
    // Set handler
    qInstallMessageHandler(messageHandler);

    MainWindow w;
    w.show();
    return a.exec();
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // Open stream file writes
    QTextStream out(m_logFile.data());
    // Write the date of recording
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    // By type determine to what level belongs message
    switch (type)
    {
    case QtInfoMsg:     out << "INF "; break;
    case QtDebugMsg:    out << "DBG "; break;
    case QtWarningMsg:  out << "WRN "; break;
    case QtCriticalMsg: out << "CRT "; break;
    case QtFatalMsg:    out << "FTL "; break;
    }
    // Write to the output category of the message and the message itself
    out << context.category << ": " << msg << endl;
    out.flush();    // Clear the buffered data
}
