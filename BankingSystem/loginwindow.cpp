// LOGIN SCREEN
// This screen opens on start up

#include <QMouseEvent>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include "loginwindow.h"
#include "./ui_LoginWindow.h"
#include "system.h"
#include "user.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Setting style sheets and othe design elements for widgets
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
                  "}");

    ui->pushButton_login->setStyleSheet("QPushButton {"
                                        "border-radius: 3px;"
                                        "background-color: rgb(234, 234, 234);"
                                        "min-height: 50px;"
                                        "max-width: 100px;"
                                        "}"

                                        "QPushButton:hover {"
                                        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(151, 0, 255, 255), stop:1 rgba(23, 158, 255, 255));"
                                        "color: rgb(255, 255, 255);"
                                        "}"

                                        "QPushButton:pressed {"
                                        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 0, 255, 255), stop:1 rgba(7, 41, 255, 255));"
                                        "}");

    ui->checkBox_rememberMe->setStyleSheet("QCheckBox::indicator {"
                                           "height: 16px;"
                                           "width: 16px;"
                                           "border-radius: 2px;"
                                           "background-color: rgb(234, 234, 234);"
                                           "}"

                                           "QCheckBox::indicator:hover {"
                                           "background-color: rgb(220, 220, 220);"
                                           "}"

                                           "QCheckBox::indicator:checked {"
                                           "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(168, 234, 148, 255), stop:1 rgba(62, 230, 166, 255));"
                                           "}"

                                           "QCheckBox::indicator:checked:disabled {"
                                           "background-color: rgb(220, 220, 220);"
                                           "}");

    ui->label_signin->setStyleSheet("font: 24px 'Bebas Neue';");
    ui->pushButton_signup->setText("Sign up");
    ui->pushButton_signup->setStyleSheet("QPushButton {"
                                         "border-radius: 3px;"
                                         "background-color: rgb(234, 234, 234);"
                                         "min-height: 25px;"
                                         "max-width: 60px;"
                                         "}"

                                         "QPushButton:hover {"
                                         "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(151, 0, 255, 255), stop:1 rgba(23, 158, 255, 255));"
                                         "color: rgb(255, 255, 255);"
                                         "}"

                                         "QPushButton:pressed {"
                                         "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 0, 255, 255), stop:1 rgba(7, 41, 255, 255));"
                                         "color: rgb(255, 255, 255);"
                                         "}");

    ui->lineEdit_username->setPlaceholderText("Username");
    ui->lineEdit_username->setTextMargins(10,0,0,0);
    ui->lineEdit_password->setPlaceholderText("Password");
    ui->lineEdit_password->setTextMargins(10,0,0,0);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    ui->pushButton_login->setText("Login");

    // Creating minimize and close button
    QPushButton* minimize = new QPushButton(this);
    minimize->setText("-");
    QPushButton* close = new QPushButton(this);
    close->setText("x");

    QString customWindowButtonStyle = "QPushButton {"
                                      "color: white;"
                                      "background-color: transparent;"
                                      "min-height: 10px;"
                                      "max-width: 50px;"
                                      "}"
                                      ""
                                      "QPushButton:hover {"
                                      "background-color: rgba(255, 255, 255, 10);"
                                      "}";

    minimize->setStyleSheet(customWindowButtonStyle);
    close->setStyleSheet(customWindowButtonStyle);

    QSize mSize = minimize->frameSize();
    QSize cSize = close->frameSize();
    QSize containerSize = this->size();
    int m_NewX = containerSize.width() - mSize.width() - 12;
    int m_NewY = containerSize.height() - mSize.height() - 685;
    int c_NewX = containerSize.width() - cSize.width() + 38;
    int c_NewY = containerSize.height() - cSize.height() - 685;
    minimize->move(m_NewX, m_NewY);
    close->move(c_NewX, c_NewY);

    connect(minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(close, SIGNAL(clicked()), this, SLOT(close()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::mousePressEvent(QMouseEvent *event)
{
    m_Old_Position = event->globalPosition();
}

void LoginWindow::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - m_Old_Position;
    this->move(x()+delta.x(), y()+delta.y());
    m_Old_Position = event->globalPosition();
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QVector<QString> members_data = System::GetFileData(SysFiles::Members);
    User* user = new User();

    int col = 0;
    bool found_user = false;
    int usernameIndex = 0;

    for (int i = 0; i < members_data.size(); i++)
    {
        if (col == 2)
        {
            if (username == members_data[i] &&
                password == members_data[i + 1])
            {
                user->SetUserID(members_data[i - 2]);
                user->SetEmail(members_data[i - 1]);
                user->SetUsername(members_data[i]);
                user->SetPassword(members_data[i + 1]);
                user->SetDOB_FromLogin(members_data[i + 2]);
                found_user = true;
                break;
            }
        }
        else if (col == 4)
        {
            col = 0;
        }
        else
        {
            col++;
        }
    }

    if (found_user)
    {
        m = new MainWindow(nullptr, user);
        m->show();
    }
    else
    {
        QMessageBox::information(NULL, "Login Failed", "Sorry, we couldn't find your username or password. Please try again.");
    }

    delete user;
    qDebug() << "test";
}

void LoginWindow::on_pushButton_signup_clicked()
{
    s = new SignUpWindow(nullptr);
    s->show();
}


void LoginWindow::on_lineEdit_username_textChanged(const QString &arg1)
{
    if (arg1 == "")
    {
        ui->lineEdit_username->setStyleSheet("QLineEdit {"
                                              "background-color: rgb(234, 234, 234);"
                                              "border-radius: 3px;"
                                              "min-height: 35px;"
                                              "}");
    }
    else
    {
        ui->lineEdit_username->setStyleSheet("QLineEdit {"
                                              "background-color: rgb(255,255,255);"
                                              "border-radius: 3px;"
                                              "min-height: 35px;"
                                              "}");
    }
}

void LoginWindow::on_lineEdit_password_textChanged(const QString &arg1)
{
    if (arg1 == "")
    {
        ui->lineEdit_password->setStyleSheet("QLineEdit {"
                                             "background-color: rgb(234, 234, 234);"
                                             "border-radius: 3px;"
                                             "min-height: 35px;"
                                             "}");
    }
    else
    {
        ui->lineEdit_password->setStyleSheet("QLineEdit {"
                                             "background-color: rgb(255,255,255);"
                                             "border-radius: 3px;"
                                             "min-height: 35px;"
                                             "}");
    }
}

