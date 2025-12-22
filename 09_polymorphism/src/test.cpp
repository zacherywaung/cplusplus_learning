#include<iostream>
#include<string>
using namespace std;

namespace zw
{
    class Person
    {
    public:
        //pure virtual Function
        virtual void BuyTicket() = 0;

        virtual ~Person()
        {
            cout << "~Person()" << endl;
        }

    protected:
        string _name;
    };

    class Student : public Person
    {
    public:
        virtual void BuyTicket() override
        {
            cout << "half ticket" << endl;
        }

        virtual ~Student() override
        {
            delete[] _data;
            _data = nullptr;
            cout << "~Student()" << endl;
        }

    protected:
        string _id;
        int* _data = new int[5];
    };

    class Soldier : public Person
    {
    public:
        virtual void BuyTicket() override
        {
            cout << "free ticket" << endl;
        }

        virtual ~Soldier() override
        {
            delete[] _data;
            _data = nullptr;
            cout << "~Soldier()" << endl;
        }
    protected:
        string _codename;
        int* _data = new int[5];
    };
}

int main()
{
    //polymorphism
    zw::Person* pst = new zw::Student();
    zw::Person* psd = new zw::Soldier();
    pst->BuyTicket();
    psd->BuyTicket();

    zw::Student s;
    //print vtable address
    printf("%p\n", *(void**)&s);

    delete pst;
    delete psd;
    cout << "-------------------" << endl;

    return 0;
}