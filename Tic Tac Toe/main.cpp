/* Compact TIC-TAC-TOE */
#include <iostream>
#include <windows.h>
using namespace std;

int main(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console,BACKGROUND_BLUE | BACKGROUND_GREEN);
    
    cout << "3 2 1 Check!" << endl;

    

    return 0;
}