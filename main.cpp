#include <QCoreApplication>
#include "Singleton.h"
#include "SingletonDatabase.h"
#include "Multiton.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "\n===== Basic Singleton =====" << std::endl;
    Singleton::runSingleton();

    std::cout << "\n===== Singleton as Database =====" << std::endl;
    SingletonDatabase::runSingletonDatabase();

    std::cout << "\n===== Muliton Example =====" << std::endl;
    Multiton::runMultiton();

    return a.exec();
}
