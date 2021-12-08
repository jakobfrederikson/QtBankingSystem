#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "system.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);

    ui->label_signup->setStyleSheet("font: 24px 'Bebas Neue';");

    setStyleSheet("QDialog {"
                  "background-color: rgba(249,249,249,255);"
                  "border-radius: 3px;"
                  "}"

                  "QLayout {"
                  "margin: -10;"
                  "}"

                  "QLineEdit {"
                  "background-color: rgb(234, 234, 234);"
                  "border-radius: 3px;"
                  "min-height: 35px;"
                  "}"

                  "QPushButton:hover {"
                  "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(151, 0, 255, 255), stop:1 rgba(23, 158, 255, 255));"
                  "color: rgb(255, 255, 255);"
                  "}"

                  "QPushButton:pressed {"
                  "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 0, 255, 255), stop:1 rgba(7, 41, 255, 255));"
                  "color: rgb(255, 255, 255);"
                  "}");

    // Line edits
    ui->lineEdit_email->setPlaceholderText("Email");
    ui->lineEdit_email->setTextMargins(10,0,0,0);
    ui->lineEdit_username->setPlaceholderText("Username");
    ui->lineEdit_username->setTextMargins(10,0,0,0);
    ui->lineEdit_password->setPlaceholderText("Password");
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password->setTextMargins(10,0,0,0);
    ui->lineEdit_confirmPassword->setPlaceholderText("Confirm Password");
    ui->lineEdit_confirmPassword->setEchoMode(QLineEdit::Password);
    ui->lineEdit_confirmPassword->setTextMargins(10,0,0,0);

    // Push buttons
    ui->pushButton_createAccount->setEnabled(false);
    ui->pushButton_createAccount->setText("Create account");
    ui->pushButton_createAccount->setStyleSheet("QPushButton {"
                                                "border-radius: 3px;"
                                                "background-color: rgb(234, 234, 234);"
                                                "min-height: 40px;"
                                                "}"

                                                "QPushButton:enabled {"
                                                "background-color: green;"
                                                "}"

                                                "QPushButton:disabled {"
                                                "background-color: red;"
                                                "}");

    ui->pushButton_back->setText("Back");
    ui->pushButton_back->setStyleSheet("QPushButton {"
                                       "border-radius: 3px;"
                                       "background-color: rgb(234, 234, 234);"
                                       "min-height: 25px;"
                                       "}");

    // Setting combo boxes
    for (int i = 1; i <= 31; i++)
    {
        ui->comboBox_day->addItem(QString::number(i));
    }

    ui->comboBox_month->addItem("January");
    ui->comboBox_month->addItem("February");
    ui->comboBox_month->addItem("March");
    ui->comboBox_month->addItem("April");
    ui->comboBox_month->addItem("May");
    ui->comboBox_month->addItem("June");
    ui->comboBox_month->addItem("July");
    ui->comboBox_month->addItem("August");
    ui->comboBox_month->addItem("September");
    ui->comboBox_month->addItem("October");
    ui->comboBox_month->addItem("November");
    ui->comboBox_month->addItem("December");

    for (int i = 1900; i <= 2014; i++)
    {
        ui->comboBox_year->addItem(QString::number(i));
    }

    // Connecting user input to check values
    connect(ui->lineEdit_email, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
    connect(ui->lineEdit_username, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
    connect(ui->lineEdit_password, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
    connect(ui->lineEdit_confirmPassword, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
}


SignUpWindow::~SignUpWindow()
{
    delete ui;
}


void SignUpWindow::checkLineEdits()
{
    if (!ui->lineEdit_email->text().isEmpty() &&
        !ui->lineEdit_username->text().isEmpty() &&
        !ui->lineEdit_password->text().isEmpty() &&
        !ui->lineEdit_confirmPassword->text().isEmpty())
    {
        ui->pushButton_createAccount->setEnabled(true);
    }
    else
    {
        ui->pushButton_createAccount->setEnabled(false);
    }
}


void SignUpWindow::on_pushButton_createAccount_clicked()
{
    user = new User();

    QString email = ui->lineEdit_email->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    user->SetEmail(email);
    user->SetUsername(username);
    user->SetPassword(password);

    QString day = ui->comboBox_day->currentText();
    QString month = ui->comboBox_month->currentText();
    QString year = ui->comboBox_year->currentText();

    user->SetDOB(day, month, year);

    System::AddNewUser(user);
}


void SignUpWindow::on_lineEdit_email_textChanged(const QString &arg1)
{
    checkLineEdits();
}


void SignUpWindow::on_lineEdit_username_textChanged(const QString &arg1)
{
    checkLineEdits();
}


void SignUpWindow::on_lineEdit_password_textChanged(const QString &arg1)
{
    checkLineEdits();
}


void SignUpWindow::on_lineEdit_confirmPassword_textChanged(const QString &arg1)
{
    checkLineEdits();
}


void SignUpWindow::on_pushButton_back_clicked()
{
    close();
}

