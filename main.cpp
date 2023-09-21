// Auth: Shakil Mahmud Arafat. AUST EEE 46th batch
// Date of creation: 21 September 2023.
// Purpose: A simple text editor in C++. To understand the basics of text editors and how they work and to understand the basics of terminal programming in C++. Originally inspired by the tutorial at https://viewsourcecode.org/snaptoken/kilo/

#include <iostream>
#include <unistd.h>
#include "headers/terminal.h"
using namespace std;

// start building from here ..yay...!


int main()
{
    // enable flushing for cout
    cout.setf(ios::unitbuf);
    
    // enabling raw mode at the start of the program
    enableRawMode();
    char c;
    // read and write are lower-level functions used for reading and writing binary data directly from/to files or file descriptors. 
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'){
        if(iscntrl(c))cout<<c<<" ";
        else cout<<c<<" "<<(int)c<<" ";
    }

    cout<<endl;
    return 0;
}