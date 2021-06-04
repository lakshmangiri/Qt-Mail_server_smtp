#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QWidget>

namespace Ui {
class reportDialog;
}

class reportDialog : public QWidget
{
    Q_OBJECT

public:
    explicit reportDialog(QWidget *parent = nullptr);
    ~reportDialog();

private:
    Ui::reportDialog *ui;
};

#endif // REPORTDIALOG_H
