#include <iostream.h>
#include <fstream>
#include <string>

#define MAX_BUFFER 1000

using namespace std;

class ReadFile {
private:
    ifstream infile;
    string *array_buffer[MAX_BUFFER];

public:
    ReadFile(char *fileName, CharMap *charMap) {
        infile.open(filename);
        while (! infile.eof){
            getline(infile, array_buffer[line] = new string());
    }

    virtual ~ReadFile() {
        if (array_buffer[0] != NULL)
            for (int index = 0; array_buffer[index] != NULL; index++)
                delete array_buffer[index];
        
        infile.close();
    }

    void writeCharMap(CharMap *charMap) {
        int rows = array_buffer[0].size;
        int cols = array_buffer.size();
        char **array = alloc_array_char(rows, cols);
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                array[row][col] = array_buffer[row][col];
        
        charMap->replaceMap(array);
    }
};
