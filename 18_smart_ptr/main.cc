#include "smart_ptr.hpp"
using namespace SmartPtrModule;

int main()
{
    shared_ptr<int> p1(new int(1));
    shared_ptr<int> p2(p1);
    shared_ptr<int> p3 = p2;
    
    return 0;
}