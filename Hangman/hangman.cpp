#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

string word[] = {"Egg","Tea","Pot","Pen","Cow","Dog","Cat","Milk","Hen","Peakcock","Dangerous","Planetorium","Hyperactive","Condensed","Powder","Blond",
                 "Peahen","Blasmphemous","Drenched","Native","Origin"};


void ShowHangMan()
{
   printf("+---------------\n"); 
   printf(" |     |     \n"); 
   printf(" |    ( )    \n"); 
   printf(" |  ---|---  \n");
   printf(" |     |     \n");
   printf(" |    / \\   \n");
   printf(" |   /   \\  \n");
   printf(" |           \n");
   printf("+---------------\n");
}

void HowToPlay(HANDLE console)
{
    cout << endl;
    SetConsoleTextAttribute(console,FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "How To Play: " << endl;
    cout << "======================================================================" << endl;
    cout << "You have to crack a password to prove that hangman is innocent" << endl;
    cout << "You have 3 tries to crack if you exceed tries hangman will be executed" << endl;
    cout << "======================================================================" << endl;
    cout << endl;

    cout << "Enter any Key to Exit" << endl;

    char tmp;
    cin >> tmp;
}

void Play(HANDLE console)
{
    system("CLS");
    srand(time(nullptr));

    SetConsoleTextAttribute(console,FOREGROUND_GREEN | FOREGROUND_RED);

    string thisword = word[rand() % sizeof(word)/sizeof(word[0])];
    
    int tries = 3;
    int mark = -1;
    int blanks = 0;
    string nstr = thisword;
    bool has_cor = false;
    bool first_try = true;   

    while(tries > 0){
        system("cls");
        ShowHangMan();


        cout << "TRIES LEFT: " << tries << endl << endl;
        cout << "PASSWORD: " << endl;

        for(size_t i = 0; i < thisword.size(); i++){
            if(i == 0){
                nstr[i] = thisword[i];
            }
            else if(has_cor == true && i == mark){
                nstr[i] = thisword[i];
                has_cor = false;
            }
            else if(i%3 == 0){
                nstr[i] = thisword[i];
            }
            else if(first_try == true){
                nstr[i] = '_';
                blanks++;
            }
        }

        if(nstr == thisword){
            cout << "YOU SAVED THE HANGMAN IN TIME!" << endl;
            char tmp;
            cin >> tmp; 
            break;
        }

        cout << nstr;
        cout << endl;

        cout << "Enter Letter: ";
        char ltr;
        cin >> ltr;

        bool found_this = false;
        for(size_t j = 0; j < thisword.size(); j++){
            if(ltr == thisword[j] && mark != j){
                mark = j;
                blanks--;
                found_this = true;
                has_cor = true;
                break;
            }
        }

        if(found_this == false){
            tries--;
        }
        if(first_try == true)
            first_try = false;
    }

    if(tries == 0 && blanks > 0){
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "THE INNOCENT HANGMAN HAS DIED!" << endl;
        cout << "YOU COULDN'T SAVE HIS LIFE!" << endl;
        cout << "THE SECRET PASSWORD WAS: " << thisword << endl;
        cout << "--------------------------------" << endl;

        char tmp;
        cin >> tmp;
    }
}

void About(HANDLE console)
{
    cout << endl;
    SetConsoleTextAttribute(console,FOREGROUND_RED | FOREGROUND_BLUE);
    cout << "About:" << endl;
    cout << "===============================" << endl;
    cout << "MADE BY: ImmortalBotYT" << endl;
    cout << "DATE: 14.11.2022" << endl;
    cout << "===============================" << endl;
    cout << endl;

    cout << "Enter any Key to Exit" << endl;
    char tmp;
    cin >> tmp;
}


int main(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console,FOREGROUND_BLUE | FOREGROUND_GREEN);

    while(true)
    {
        char input;
        system("CLS");
        cout << "\t\t\t\t\t======================" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++|      HAMG-MAN      |++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "\t\t\t\t\t|        2022        |" << endl;
        cout << "\t\t\t\t\t======================" << endl;

        cout << endl;
        cout << "\t\t\t\t\t----------------" << endl;
        cout << "\t\t\t\t\t[P]LAY" << endl;
        cout << "\t\t\t\t\t[A]BOUT" << endl;
        cout << "\t\t\t\t\t[H]OW TO PLAY" << endl;
        cout << "\t\t\t\t\t[Q]UIT" << endl;
        cout << "\t\t\t\t\t----------------" << endl;
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << endl << endl;

        cout << ">> ";
        cin >> input;

        if(input == 'H')
        {
            HowToPlay(console);
            SetConsoleTextAttribute(console,FOREGROUND_BLUE | FOREGROUND_GREEN);
        }
        else if(input == 'A')
        {
            About(console);
            SetConsoleTextAttribute(console,FOREGROUND_BLUE | FOREGROUND_GREEN);
        }
        else if(input == 'P')
        {
            Play(console);
            SetConsoleTextAttribute(console,FOREGROUND_BLUE | FOREGROUND_GREEN);
        }
        else if(input == 'Q')
        {
            break;
        }
        else{
            cout << "INVALID CHOICE" << endl;
            int tmp;
            cin >> tmp;
        }
    }

    return 0;
}