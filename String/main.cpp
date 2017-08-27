#include <stdio.h>
#include <cstring>

int main(int argc, char **argv)
{
    int arr[] { 1, 2, 3, 4 }; 
    for (int i = 0; i < 4; ++i)  
    { 
        arr[i] += arr[i + 1]; // oops, what happens when i == 3? 
        printf("%d -> %d\n", i, arr[i]);
    }
    char pHello[3];
    strncpy(pHello, "hello", 2);
	printf("%s\n", pHello);
	return 0;
}
