#ifndef MULTITON_H
#define MULTITON_H
#include <iostream>
#include <memory>
#include <map>

namespace Multiton
{

enum class Importance
{
    primary,
    secondary,
    tertiary
};

template <typename T, typename Key = std::string>
class Multiton
{
public:
    static std::shared_ptr<T> get(const Key& key)
    {
        if (const auto it = instances.find(key); it != instances.end())
        {
            return it->second;
        }

        auto instance = std::make_shared<T>();
        instances[key] = instance;
        return instance;
    }

protected:
    Multiton() = default;
    ~Multiton() = default;

private:
    static std::map<Key, std::shared_ptr<T>> instances;

};

class TestClass
{
public:
    TestClass()
    {
        ++TestClass::totalObjCount;
        std::cout << "\nTotal obj : " << TestClass::totalObjCount << " is created\n" << std::endl;

    }

private:
    static int totalObjCount;
};

int TestClass::totalObjCount = 0;

template <typename T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;

void runMultiton()
{
    typedef Multiton<TestClass, Importance> multiton;

    auto first = multiton::get(Importance::primary);
    auto second = multiton::get(Importance::secondary);
    auto third = multiton::get(Importance::tertiary);


}
}

#endif // MULTITON_H
