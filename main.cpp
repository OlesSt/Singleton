#include <QCoreApplication>
#include "Singleton.h"
#include "SingletonDatabase.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "\n===== Basic Singleton =====" << std::endl;
    Singleton::runSingleton();

    std::cout << "\n===== Singleton as Database =====" << std::endl;
    SingletonDatabase::runSingletonDatabase();

    return a.exec();
}
