#include "ReadFile.h"

ReadFile::ReadFile (char *fileName, CharMap *charMap) { 
    infile.open (filename);
    int line = 0;
    while (!infile.eof && line < MAX_BUFFER)
	getline(infile, array_buffer[line++] = new string ());
}

virtual ReadFile::~ReadFile (){
    if (array_buffer[0] != NULL)
        for (int index = 0; array_buffer[index] != NULL; index++)
	    delete array_buffer[index];

    if (FREE_ME[0] != NULL)
        for (int index = 0; FREE_ME[index] != NULL; index++)
	    delete FREE_ME[index];

    infile.close ();
}

void ReadFile::writeCharMap (CharMap * charMap) {

    int rows = array_buffer[0].size;
    int cols = array_buffer.size ();
    char **array = alloc_array_char (rows, cols);
      
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
	    array[row][col] = array_buffer[row][col];

    charMap->replaceMap (array);
    CHAR_MAPS[buffIndex++] = array;
}

