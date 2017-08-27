#include <stdio.h>
#include <iostream>
#include <array>

using namespace std;

void use_ten_ints(int*);

void use_ten_ints(int*)
{
}

void use_four_ints(array<int, 4> arr)
{
}
void eg_bad_alloc()
{
    int *pi; 
    int VERY_BIG_NUMBER = 9999999999999999999999999999999;
//    int VERY_BIG_NUMBER = 9;
    cout << VERY_BIG_NUMBER << endl;
    try 
    { 
        pi = new int[VERY_BIG_NUMBER]; 
        *pi = 123;
        // other code 
    } 
    catch(const std::bad_alloc& e)  
    {  
        cout << "cannot allocate" << endl;
        return;
    } 
    cout << *pi << endl;
    // use pointer 
    delete [] pi;
}

int main(int argc, char **argv)
{
    char c[] { "hello" }; // c can be used as a pointer 
    *c = 'H';             // OK, can write thru the pointer 
    const char *ptc {c};  // pointer to constant 
    cout << ptc << endl;  // OK, can read the memory pointed to 
//    *ptc =  'Y';          // cannot write to the memory 
    *c =  'Y';          // can write to the memory 
    cout << ptc << endl;
    char *const cp {c};   // constant pointer 
    *cp = 'y';            // can write thru the pointer 
//    cp++;                 // cannot point to anything else

    char sc[] {"hello"};
    wchar_t wc[] { L"hello" }; 
    void *psc = reinterpret_cast<void*>(sc);
    void *pwc = reinterpret_cast<void*>(wc);
    wcout << wc << " is stored in memory at "; 
    wcout << hex; 
    wcout << psc << " and ";
    wcout << pwc << endl;
    
    wcout << "The characters are:" << endl; 
    short* ps = reinterpret_cast<short*>(wc);
    int i = 0;
    while (*(wc + i))  
    {  
        printf("%c -> %x -> %d\n", *(wc+ i), *(wc+ i), *(wc+ i));  
        i++;
    }
    
    eg_bad_alloc();
    
    int arr1[] { 1, 2, 3, 4 }; 
    use_ten_ints(arr1); // oops will read past the end of the buffer
    
    array<int, 4> arr2 { 1, 2, 3, 4 };  
    use_four_ints(arr2); // will not compile
    
	printf("hello world\n");
	return 0;
}
