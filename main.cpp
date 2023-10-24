#include <QCoreApplication>
#include "Singleton.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "\n===== Basic Singleton =====" << std::endl;
    Singleton::runSingleton();

    return a.exec();
}
