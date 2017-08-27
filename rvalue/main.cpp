#include <stdio.h>
#include <iostream>

using namespace std;

string global{ "global" };
int globalvar = 20;

int& foo()
{
    return globalvar;
}

string& get_global() 
{ 
    return global; 
} 

string& get_static() 
{ 
    static string str { "static" }; 
    return str; 
} 

string get_temp() 
{ 
    return "temp about"; 
}

void use_string(string& rs) 
{ 
    string s { rs }; 
    for (size_t i = 0; i < s.length(); ++i) 
    { 
        if ('a' == s[i] || 'b' == s[i] || 'o' == s[i])  
        s[i] = '_'; 
    } 
    cout << s << endl; 
}

void use_string(string&& s) 
{ 
    for (size_t i = 0; i < s.length(); ++i) 
    { 
        if ('a' == s[i] || 'b' == s[i] || 'o' == s[i]) 
            s[i] = '_'; 
    } 
    cout << s << endl; 
}
    
int main(int argc, char **argv)
{
    cout << global << endl; 
    cout << &global << endl; 
    foo() = 10;
    cout << globalvar << endl; 
    cout << get_global() << endl; 
    cout << get_static() << endl; 
    cout << get_temp() << endl;
    
    cout << "=========" << endl;
    use_string(get_global()); // string&  version 
    use_string(get_static()); // string&  version 
//    use_string(get_temp());   // string&& version 
    use_string("C string about");   // string&& version 
//    string str{"C++ string about"}; 
//    use_string(str);          // string&  version
    
    
    cout << "=========" << endl;
    cout << get_global() << endl; 
    cout << get_static() << endl; 
    cout << get_temp() << endl;
    
    cout << "=========" << endl;
    cout << global << endl; 
    use_string(global);
    cout << global << endl; 
	// printf("hello world\n");
	return 0;
}
