#include <stdio.h>
#include <iostream>
#include <typeinfo>

using namespace std;

int main(int argc, char **argv)
{
	constexpr int size = 4; 
    int squares[size]; 
 
    for (int i = 0; i < size; ++i) 
    { 
        squares[i] = i * i; 
    }
    
    for (int j : squares) 
    { 
        cout << j << endl; 
    }
    
    for (int& k : squares) 
    { 
        k *= 2; 
    }
    
    for (int j : squares) 
    { 
        cout << j << endl; 
    }
    
    
    
    int arr[2][3] { { 2, 3, 4 }, { 5, 6, 7} };   
    
//    for (auto row : arr) 
    for (auto& row : arr) 
    { 
        cout << typeid(row).name() << endl;
        for (auto col : row) // will not compile
        { 
            cout << col << " " << endl; 
        } 
    }
	return 0;
}
