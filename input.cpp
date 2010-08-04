#include "input.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int readFile(CharMap *map, const char *file_name) {
    FILE * pFile;
    string line;
    ifstream myfile (file_name); 
    pFile=fopen(file_name , "wt");
  
    if (myfile.is_open()) {
        while (! myfile.eof()) {
            getline (myfile,line);
	    cout << line << endl; 
        }
        myfile.close();
        return 1; 
    } else {
        cout << "Unable to open file";
        return 0;
    } 
}

