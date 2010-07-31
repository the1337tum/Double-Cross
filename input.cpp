#include "input.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int readFile(struct *map, const char *name) {
    const char* yup;
    int n;
    int count = 0;
    FILE * pFile;
    string line;
    ifstream myfile ("MAIN.LOAD.txt"); 
    pFile=fopen(name , "wt");
  
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

