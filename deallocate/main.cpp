#include <iostream> 
#include <string> 
#include <cstdarg> 

using namespace std; 

bool get_data(/*in/out*/ int *psize, /*out*/ int **pi)
{
    cout << psize << endl;
    cout << *psize << endl;
    *psize = 30;
    cout << *psize << endl;
    *pi = new int[*psize] {88};
    for (int i = 0; i < *psize; ++i)
    {
        // two equal
        *(*pi + i) = i;
//        (*pi)[i] = i;
        // not this one
        // *pi[i] = i;
    }
//    
//    for (int i = 0; i < *psize; ++i) cout << *pi[i] << endl;
    
    return true;
}

int main(int argc, char **argv)
{

    int size = 10; 
    int *buffer = nullptr; 
    if (get_data(&size, &buffer)) 
    { 
        for (int i = 0; i < size; ++i) 
        { 
            cout << buffer[i] << endl; 
        } 
        delete [] buffer; 
    }
	return 0;
}
