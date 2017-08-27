#include "Bitmap.h"
#include "UseAuto.h"
#include <ctime>
#include <iostream>
#include <vector>

// #define DEBUG

#ifdef DEBUG
#define MESSAGE(c, v)          \
    for(int i = 1; i < c; ++i) \
        std::cout << v[i] << std::endl;
#else
#define MESSAGE
#endif

int version = 42;

void print_version()
{
    std::cout << "Version = " << ::version << std::endl;
}
void print_time();
int main(int argc, char* argv[])
{
    MESSAGE(argc, argv);

    print_time();
    std::cout << "南无阿弥陀佛!" << std::endl;

    std::cout << "there are " << argc << " parameters" << std::endl;
    for(int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }

    print_version();

    unsigned int a = 0x0a0a; // this is the binary 0000101000001010
    unsigned int b = 0x00ff; // this is the binary 0000000000001111
    unsigned int c = a & b;  // this is the binary 0000101000001111
    std::cout << std::hex << std::showbase << c << std::endl;

    Bitmap bm;
    bm.PrintNumber(a);
    bm.PrintNumber(b);
    bm.PrintNumber(c);

    // create a vector object that can hold integers and
    // start by reserving space for 42 integers, each initialized to a value of zero
    vector<int> a1(42);
    std::cout << std::dec << std::showbase << std::endl;
    cout << " size " << a1.size() << endl;
    for(int i : a1)
        cout << i << endl;

    // create a vector that can hold integers and 
    // initialize it with the single integer, 42
    vector<int> a2{ 42 };
    cout << " size " << a2.size() << endl;
    for(int i : a2)
        cout << i << endl;

    //UseAuto ua;
    
    char *ptr = "0123456"; 
    // possibly lots of code 
//    ptr[3] = '\0'; // RUNTIME ERROR!
//    char * pWriteable = const_cast<char *>(ptr); 
//    pWriteable[3] = '\0';
    cout << "Hello" << endl;
    
    double pi = 3.1415; 
//    int i = dynamic_cast<int>(&pi); 
    cout << hex << &pi << endl;
    cout << dec << pi << endl;
    
    float num = 9.0;
    //  initialization using curly braces to get warning
    int i = {num};
    cout << dec << i << endl;
    
    
    char cc = 35; 
    cout << cc << endl;
    
    cout << static_cast<short>(cc) << endl; 
    cout << short{ cc } << endl;
    
    return 0;
}

void print_time()
{
    std::time_t now = std::time(nullptr);
    std::cout << ", the time and date are " << std::ctime(&now) << std::endl;
}
class cout;