#include<iostream>
#include<vector>
#include<string>
using namespace std;

namespace zw
{
    class Person
    {
    public:
        Person()
            :_name("xxx")
            ,_address("xxx")
            ,_tel("123")
            ,_age(0)
        {
            cout << "Person()" << endl;
        }

        Person(string name, string address, string tel, int age)
            :_name(name)
            ,_address(address)
            ,_tel(tel)
            ,_age(age)
        {
            cout << "Person()" << endl;
        }

        Person(const Person& p)
            :_name(p._name)
            ,_address(p._address)
            ,_tel(p._tel)
            ,_age(p._age)
        {
            cout << "Person(const Person& p)" << endl;
        }

        Person& operator=(const Person& p)
        {
            if(this != &p)
            {
                _name = p._name;
                _address = p._address;
                _tel = p._tel;
                _age = p._age;
            }
            return *this;
        }

        ~Person()
        {
            cout << "~Person()" << endl;
        }

        void identity()
        {
            cout << "void identity()" << _name << endl;
        }

    protected:
        string _name;
        string _address;
        string _tel;
        int _age;
    };

    class Student : public Person
    {
    public:
        Student()
            :Person()
            ,_pi(new int[5]())
        {
            cout << "Student()" << endl;
        }

        Student(string name, string address, string tel, int age)
            :Person(name, address, tel, age)
            ,_pi(new int[5]())
        {
            cout << "Student()" << endl;
        }

        Student(const Student& s)
            :Person(s)
            ,_pi(new int[5])
        {
            for(size_t i = 0; i < 5; i++)
            {
                _pi[i] = s._pi[i];
            }
            cout << "Student(const Student& s)" << endl;
        }

        Student& operator=(Student s)
        {
            Person::operator=(s);
            std::swap(_pi, s._pi);
            cout << "Student& operator=(Student s)" << endl;
            return *this;
        }

        ~Student()
        {
            //Person::~Person()
            delete[] _pi;
            _pi = nullptr;
            cout << "~Student" << endl;
        }

        void study()
        {
            cout << "void study" << endl;
        }
    protected:
        int* _pi;
    };

}

int main()
{
    zw::Student p1("alice", "4609 Union Bay PL NE" , "123456" , 18);
    p1.identity();
    zw::Student p2(p1);
    zw::Student p3;
    p3 = p1;

    return 0;
}