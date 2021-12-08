#include <QRandomGenerator>
#include "system.h"

QString System::folderPath = "CSV/";
QFile System::members(folderPath + "members.csv");

void System::CreateFiles()
{
    if (!QDir(folderPath).exists())
    {
        QDir().mkdir(folderPath);
    }

    if(!members.exists())
    {
        if(members.open(QIODevice::WriteOnly | QFile::Text))
        {
            QTextStream in(&members);
            in << "USER_ID" << "," << "EMAIL" << "," << "USERNAME" << "," << "PASSWORD" << "," << "DOB" << "\n";
        }
        else
        {
            QMessageBox::warning(NULL, "Could not open members.csv", members.errorString());
        }
        members.close();
    }
}

void System::AddNewUser(User *user)
{
    quint32 num = QRandomGenerator::global()->bounded(1000,9999);
    QString user_id = "user_" + QString::number(num);
    QVector<QString> members_data = GetFileData(SysFiles::Members);
    if(members_data.contains(user_id))
    {
        QMessageBox::information(NULL, "WOAH", "The same member ID was somehow just created! That's insane!");
        while(members_data.contains(user_id))
        {
            quint32 num = QRandomGenerator::global()->bounded(1000,9999);
            user_id = "user_" + QString::number(num);
        }
    }

    if (members.open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text))
    {
        QTextStream in(&members);
        in << user_id << "," << user->GetEmail() << "," << user->GetUsername() << "," << user->GetPassword() << "," << user->GetDOB() << "\n";
    }
    else
    {
        QMessageBox::warning(NULL, "Could not open members.csv", members.errorString());
    }

    members.close();
}

QVector<QString> System::GetFileData(SysFiles file)
{
    QVector<QString> file_data;

    switch(file)
    {
    case SysFiles::Members:
        if(members.open(QIODevice::ReadOnly))
        {
            QTextStream in(&members);
            while(!in.atEnd())
            {
                QString line = members.readLine().replace("\r\n","");
                file_data.append(line.split(','));
            }
        }
        else
        {
            QMessageBox::warning(NULL, "Could not open members.csv", members.errorString());
        }
        members.close();
        break;
    default: break;
    }

    return file_data;
}
