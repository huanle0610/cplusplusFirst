#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
const int block_length = 16;

void usage(const char* msg)
{
    cout << "filedump filename blocks" << endl;
    cout << "filename (mandatory) is the name of the file to dump" << endl;
    cout << "blocks (option) is the number of 16 byte blocks" << endl;
    
    if(nullptr == msg) return;
    cout << endl << "Error!";
    cout << msg << endl;
}

int read16(ifstream& stm)
{
    if(stm.eof()) return -1;
    ios::fmtflags flags = cout.flags();
    cout << hex;
    
    string line;
    
    // print bytes
    for(int i = 0; i< block_length; ++i)
    {
        // read a single character from stream
        unsigned char c = stm.get();
        if(stm.eof())
        {
            break;
        }
        // need to make sure that all hex are printed
        // two character padding with zeros
        cout << setw(2) << setfill('0');
        cout << static_cast<short>(c) << " ";
        if(0 == isprint(c))
        {
            line += '.';
        }
        else
        {
            line += c;
        }
    }
    
    string padding = "  ";
    if(line.length() < block_length)
    {
        padding += string(
            3 * (block_length - line.length()), '  ');
    }
    cout << padding;
    cout << line << endl;
    
//    cout << dec;
//    cout << block_length << "-" << line.length() << endl;
//    cout << 3 * (block_length - line.length()) << endl;
    
    cout.setf(flags);
    return line.length();
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        usage("not enough parameters");
        return 1;
    }
    
    if(argc > 3)
    {
        usage("too many parameters");
        return 1;
    }
    
    string filename = argv[1];
    int blocks = 1; // default value
    if(3 == argc)
    {
        // we have been passed the number of blocks
        istringstream ss(argv[2]);
        ss >> blocks;
        if(ss.fail() || 0 >= blocks)
        {
            // cannot convert to a number
            usage("second parameter: must be a number, "
        "and greater than zero");
            return 1;
        }
    }
    
    ifstream file(filename, ios::binary);
    if(!file.good())
    {
        usage("first parameter: file does not exist");
        return -1;
    }
    
    while(blocks-- && read16(file) != 1);
    file.close();
    printf("Good Job!\n");
    return 0;
}
