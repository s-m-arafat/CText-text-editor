// Auth: Shakil Mahmud Arafat. AUST EEE 46th batch
// Date of creation: 21 September 2023.
// Purpose: A simple text editor in C++. To understand the basics of text editors and how they work and to understand the basics of terminal programming in C++. Originally inspired by the tutorial at https://viewsourcecode.org/snaptoken/kilo/

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

// start building from here ..yay...!

// for storing the original terminal attributes
struct termios orig_termios;

// function to enable raw mode terminal
void enableRawMode()
{
    // get the terminal attributes for stdin
    tcgetattr(STDIN_FILENO, &orig_termios);

    // register a function to be called when the program exits which will disable raw mode and reset the terminal attributes to their original state either returning from main() or exit() 
    atexit([]
           { tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios); });

    // create a new termios struct and copy the original attributes to it for modification
    struct termios raw = orig_termios;

    // * disable the echo bit flag to disable echoing of input characters and show them on the terminal
    // the bit flag ECHO is represented by the constant ECHO 00000000000000000000000000001000 in binary
    // the bitwise-NOT operator ~ flips all the bits in a value
    // the bitwise-AND operator & sets a bit to 0 if both bits are 0 in the operands
    // ** and the icannonical mode flag is represented by the constant ICANON 00000000000000000000000000000100 in binary
    // so the bitwise-AND operator & is used to set the bits ECHO and ICANON to 0 in the c_lflag field of the termios struct
    // after disabling the canonical mode, the terminal will not wait for the user to press enter to send the input to the program and will send the input to the program as soon as the user presses a key
    raw.c_lflag &= ~(ECHO | ICANON | ISIG );
    
    // set the terminal attributes to the new attributes
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

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