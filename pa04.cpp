#include <vector>

#include "MyVector.h"

int main()
{
    MyVector<int> v;
    // std::vector<int> v;
    
    cout << v.size() << endl;
    v.push_back(4000);
    cout << v.at(0) << endl;
    cout << "capacity: " << v.capacity() << endl;
    v.reserve(10);
    cout <<  "capacity: " << v.capacity() << endl;
    v.push_back(200);
    v.push_back(100);
    return 0;
}

