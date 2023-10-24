#ifndef SINGLETONDATABASE_H
#define SINGLETONDATABASE_H
#include <iostream>
#include <map>

// EXAMPLE WITH SINGLETON AS DATABASE

namespace SingletonDatabase
{
std::map<std::string, int> dataBase         // This is database example
{
    { "Alex",    1000 },
    { "Alina",   2000 },
    { "Max",     800  },
    { "Bob",     1200 },
    { "John",    2100 }
};

class SingletonDatabase                                         // Create basic singleton to use database through it
{
public:
    SingletonDatabase (SingletonDatabase const&) = delete;
    void operator=    (SingletonDatabase const&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }

    int getAmount(const std::string &name) const
    { return singleDatabase.at(name); }

    std::string getNameByAmount(const int amount) const
    {
        for (auto &i : singleDatabase)
            if (i.second == amount) {return i.first;}
        return "Not Found";
    }

private:
    SingletonDatabase()
    {
        // Let's image we open database here
        singleDatabase = dataBase;
        std::cout << "\n....Opening database..." << std::endl;
    }
    std::map<std::string, int> singleDatabase;
};

class SingletonDatanFinder                                     // Create class to calculate or find specific data in database
{
public:
    int totalAmount(std::vector<std::string>names)
    {
        int result{0};
        for (auto &name : names)
        {
            result += SingletonDatabase::get().getAmount(name);
        }
        return result;
    }

    std::string findByAmount(const int amount)
    {
        auto name = SingletonDatabase::get().getNameByAmount(amount);
        return name;
    }
};


void runSingletonDatabase()
{
    auto amountAlex  = SingletonDatabase::get().getAmount("Alex");
    auto amountAlina = SingletonDatabase::get().getAmount("Alina");
    auto amountMax   = SingletonDatabase::get().getAmount("Max");
    auto amountBob   = SingletonDatabase::get().getAmount("Bob");
    auto amountJohn  = SingletonDatabase::get().getAmount("John");

    std::cout << "\n - Amount Alex: "   << amountAlex
              << "\n - Amount Alina: "  << amountAlina
              << "\n - Amount Max: "    << amountMax
              << "\n - Amount Bob: "    << amountBob
              << "\n - Amount John: "   << amountJohn << std::endl;

    std::vector <std::string> names {"Alina", "Bob", "John"};

    SingletonDatanFinder finder;
    int total = finder.totalAmount(names);
    std::cout << "Total amount is " << total << std::endl;

    int findAmount = 1000;
    auto matchName = finder.findByAmount(findAmount);
    std::cout << findAmount << " is " << matchName << std::endl;
}
}

#endif // SINGLETONDATABASE_H
