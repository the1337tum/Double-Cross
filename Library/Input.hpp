#include <iostream.h>
#include <fstream>
#include <string>

#define MAX_BUFFER 1000

using namespace std;

/**
 * Used for reading files into datastructures
**/
class ReadFile {
private:
    ifstream infile;
    string *STRING_BUFFER[MAX_BUFFER];
    int str_buff = 0;

    char[MAX_BUFFER]** CHAR_MAPS;
    int char_buff = 0;

public:
    ReadFile(char *fileName, CharMap * charMap);
    virtual ~ReadFile();
    void writeCharMap(CharMap * charMap);
};

