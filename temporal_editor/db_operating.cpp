#include "db_operating.h"

db_operating::db_operating()
{

}

bool db_operating::connection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/alexandradolidze/Desktop/Editor/temporal_editor/temporal_editor.db");

    if(!db.open())
    {
       qDebug()<<("Failed to open Database");
       return false;
    }
    else
    {
        qDebug()<<("Connected.....");
        return true;
    }
}

void db_operating::disconnection()
{
    QString connection;
    connection=db.connectionName();
    db.close();
    db=QSqlDatabase();
    db.removeDatabase(connection);
    qDebug()<<("Disc.....");
}
