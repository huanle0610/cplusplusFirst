#include <iostream> 
#include <string> 
#include <cstdarg> 

using namespace std; 

int sum_use_count(int count, ...) 
{ 
    int sum = 0; 
    va_list args; 
    va_start(args, count); 
    while(count--) 
    { 
        int i = va_arg(args, int); 
        sum += i; 
    } 
    va_end(args); 
    return sum; 
}
    
int sum_use_marker(int first, ...)
{
    int sum = 0;
    va_list args;
    va_start(args, first);
    int i = first;
    while(i != -1)
    {
        sum += i;
        i = va_arg(args, int);
    }
    va_end(args);
    
    return sum;
}

int main(int argc, char **argv)
{
    cout << sum_use_marker(-1) << endl;                       // 0 
    cout << sum_use_marker(-6, -5, -4, -3, -2, -1) << endl;   // -20 !!! 
    cout << sum_use_marker(10, 20, 30, -1) << endl;           // 60
	
    cout << sum_use_count(0) << endl;                         // 0 
    cout << sum_use_count(6, -6, -5, -4, -3, -2, -1) << endl; // -21 
    cout << sum_use_count(3, 10, 20, 30) << endl;             // 60
    
    
    cout << sum_use_count(3, 10., 20, 30) << endl;
    return 0;
}
