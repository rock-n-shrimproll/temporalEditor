#ifndef DB_OPERATING_H
#define DB_OPERATING_H
#include <QtSql>

class db_operating
{
public:
    db_operating();
    QSqlDatabase db;
    bool connection();
    void disconnection();
};

#endif // DB_OPERATING_H
