#include "user.h"

User::User()
{

}

User::User(QString email, QString username, QString password, QString day, QString month, QString year)
{
    m_email = email;
    m_username = username;
    m_password = password;
    m_DOB = day + "/" + month + "/" + year;
}

void User::SetEmail(QString email)
{
    m_email = email;
}

void User::SetUsername(QString username)
{
    m_username = username;
}

void User::SetPassword(QString password)
{
    m_password = password;
}

void User::SetDOB(QString day, QString month, QString year)
{
    m_DOB = day + "/" + month + "/" + year;
}

void User::SetDOB_FromLogin(QString dob)
{
    m_DOB = dob;
}

void User::SetUserID(QString ID)
{
    m_ID = ID;
}

QString User::GetEmail()
{
    return m_email;
}

QString User::GetUsername()
{
    return m_username;
}

QString User::GetPassword()
{
    return m_password;
}

QString User::GetDOB()
{
    return m_DOB;
}

QString User::GetUserID()
{
    return m_ID;
}
