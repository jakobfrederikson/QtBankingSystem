#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>

class User
{
public:
    User();
    User(QString email, QString username, QString password, QString day, QString month, QString year);
    void SetEmail(QString email);
    void SetUsername(QString username);
    void SetPassword(QString password);
    void SetDOB(QString day, QString month, QString year);
    void SetDOB_FromLogin(QString dob);
    void SetUserID(QString ID);
    QString GetEmail();
    QString GetUsername();
    QString GetPassword();
    QString GetDOB();
    QString GetUserID();

private:  
    QString m_email;
    QString m_username;
    QString m_password;
    QString m_DOB;
    QString m_ID;
};

#endif // USER_H
