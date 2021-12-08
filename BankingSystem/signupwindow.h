#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDate>
#include "user.h"

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private slots:
    void checkLineEdits();

    void on_pushButton_createAccount_clicked();

    void on_lineEdit_email_textChanged(const QString &arg1);

    void on_lineEdit_username_textChanged(const QString &arg1);

    void on_lineEdit_password_textChanged(const QString &arg1);

    void on_lineEdit_confirmPassword_textChanged(const QString &arg1);

    void on_pushButton_back_clicked();

private:
    Ui::SignUpWindow *ui;
    QRegularExpression regex;
    User* user;
};

#endif // SIGNUPWINDOW_H
