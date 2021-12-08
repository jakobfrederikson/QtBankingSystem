#ifndef SYSTEM_H
#define SYSTEM_H

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QVector>
#include "user.h"

enum SysFiles
{
    Members = 0
};

class System
{
public:
    static void CreateFiles();
    static void AddNewUser(User* user);
    static QVector<QString> GetFileData(enum SysFiles file);
private:
    static QString folderPath;
    static QFile members;
};

#endif // SYSTEM_H
