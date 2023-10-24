#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>

namespace Singleton
{
class Singleton
{
public:
    Singleton(Singleton const&)      = delete;                       // must delete copy contructor to avoid copying
    void operator=(Singleton const&) = delete;                       // must delete copy assigntment operator

    static Singleton& get()                                          // static method that return a singleton object
    {
        static Singleton single;
        return single;
    }

    void doStuff()
    { std::cout << "Singletone - do Stuff" << std::endl; }

private:
    Singleton()
    { std::cout << "Constructor Signleton" << std::endl; }           // must make contructor private to avoid creation of any other objects
};

void runSingleton()
{
    auto &singleObj = Singleton::get();             // create singleton with static method ::get(), using &
    singleObj.doStuff();
}
}

#endif // SINGLETON_H
