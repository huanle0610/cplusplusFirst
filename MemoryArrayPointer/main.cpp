#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int i = 42; 
    int *pi = &i;
    
    int f = 1; 
    int *pf = &f;
    
    cout << hex;
    cout << "i address: " << pi << "    " << sizeof(int) << endl;
    cout << "pi address:" << &pi<< "    " << sizeof(int *) << endl;    
    
    cout << "f address: " << pf << "    "  << sizeof(int) << endl;
    cout << "pf address:" << &pf<< "    " << sizeof(int *) << endl;
    
    char *p1 { "hello" }; 
    char *p2 { "hello" };
    char *p6 { "hell" };
    void *p3 = reinterpret_cast<void*>(p1);
    void *p4 = reinterpret_cast<void*>(p2);
    void *p5 = reinterpret_cast<void*>(p6);
    printf("%s@%x\n", p1, p1);
    printf("%s@%x\n", p2, p2);
    printf("%s@%x\n", p6, p6);
    cout << hex; 
    cout << p3 << endl; 
    cout << p4 << endl;
    cout << p5 << endl;
    
    cout << "hello world" << endl;
	return 0;
}
