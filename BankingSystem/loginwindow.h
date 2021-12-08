#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QPointF>
#include "mainwindow.h"
#include "signupwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_lineEdit_username_textChanged(const QString &arg1);

    void on_lineEdit_password_textChanged(const QString &arg1);

    void on_pushButton_signup_clicked();

private:
    Ui::LoginWindow *ui;
    MainWindow* m;
    SignUpWindow* s;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPointF m_Old_Position;
};

#endif // LOGINWINDOW_H
