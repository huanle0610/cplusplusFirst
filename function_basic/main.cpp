#include <iomanip>
#include <iostream> 
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>


using namespace std; 

struct file_size {   
    unsigned int high;   
    unsigned int low;
};

using file_info = tuple<string, file_size>;

ostream& operator<<(ostream& os, const file_size fs) 
{ 
    int flags = os.flags(); 
    unsigned long long ll = fs.low + 
        ((unsigned long long)fs.high << 32); 
    os << hex << ll; 
    os.setf(flags); 
    return os; 
}

bool operator>(const file_size& lhs, const file_size& rhs) 
{ 
    if (lhs.high > rhs.high) return true; 
    if (lhs.high == rhs.high) { 
        if (lhs.low > rhs.low) return true; 
    } 
    return false; 
}

void files_in_folder( 
       const char *folderPath, 
       vector<file_info>& files
) 
{
    string folder(folderPath); 
    folder += "*"; 
    WIN32_FIND_DATAA findfiledata {}; 
    void* hFind = FindFirstFileA(folder.c_str(), &findfiledata); 
 
    if (hFind != INVALID_HANDLE_VALUE) 
    { 
       do 
       { 
            string findItem(folderPath); 
            findItem += ""; 
            findItem += findfiledata.cFileName; 
            if ((findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) 
            { 
                 // this is a folder so recurse 
                string folder(findfiledata.cFileName); 
                // ignore . and .. directories 
                if (folder != "." && folder != "..") 
                { 
                    files_in_folder(findItem.c_str(), files); 
                }
            } 
            else 
            { 
                // this is a file so store information
                file_size fs{}; 
                fs.high = findfiledata.nFileSizeHigh; 
                fs.low = findfiledata.nFileSizeLow; 
                files.push_back(make_tuple(findItem, fs));
            }
       } while (FindNextFileA(hFind, &findfiledata)); 
       FindClose(hFind); 
    }
}

int main(int argc, char **argv)
{
	if(argc < 2) return 1;
    
    vector<file_info> files; 
    files_in_folder(argv[1], files);
    sort(files.begin(), files.end(), 
        [](const file_info& lhs, const file_info& rhs) { 
            return get<1>(rhs) > get<1>(lhs);    
    });
    for (auto file : files) 
    { 
        cout << setw(16) << get<1>(file) << " "  
            << get<0>(file) << endl; 
    }

	return 0;
}
