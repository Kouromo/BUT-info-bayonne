#include "database.h"

database::database()
{

}




bool database::openDatabase()
{
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName(DATABASE_NAME);
    if(mydb.open())
    {
        return true;
    }
    else
    {
        return false;
    }
}



void database::closeDataBase()
{
    mydb.close();
}
