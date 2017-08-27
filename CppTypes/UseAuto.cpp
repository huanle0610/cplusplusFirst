#include "UseAuto.h"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <limits>

using namespace std;

UseAuto::UseAuto()
{
    auto i = 42;    // int
    auto l = 42l;   // long
    auto ll = 42ll; // long long
    auto f = 1.0f;  // float
    auto d = 1.0;   // double
    auto c = 'q';   // char
    auto b = true;  // bool

    vector<tuple<string, int>> beatles;
    beatles.push_back(make_tuple("John", 1940));
    beatles.push_back(make_tuple("Paul", 1942));
    beatles.push_back(make_tuple("George", 1943));
    beatles.push_back(make_tuple("Ringo", 1940));

    for(tuple<string, int> musician : beatles) {
        cout << get<0>(musician) << " " << get<1>(musician) << endl;
    }

    cout << "See, this is the power of auto:" << endl;
    for(auto musician : beatles) {
        cout << get<0>(musician) << " " << get<1>(musician) << endl;
    }
    
    cout << "The int type can have values between "; 
    cout << numeric_limits<int>::min() << " and  "; 
    cout << numeric_limits<int>::max() << endl;
    
    cout << "The long long int type can have values between "; 
    cout << numeric_limits<long long int>::min() << " and  "; 
    cout << numeric_limits<long long int>::max() << endl;
}

UseAuto::~UseAuto()
{
}
