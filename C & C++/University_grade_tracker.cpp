#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;


char pass[4678800];
char name[1000000];

char dpath[]= "\storage\emulated\0/Students/";
char file[] ="";
char ext[5] = ".txt";


struct userData {

    char passCode[1000000];
    char userName[1000000];

};

typedef struct userData User;


User getPass(bool showPass) {

    for(int i = 0;; i++) {
        pass[i] = _getch();

        if(pass[i]=='\n') {
            pass[i] = '\0';
            break;

        }
        if(!showPass) {
            cout<<'*';
        }
        else {
            cout<<pass[i];
        }

    }
    //  puts(lcl.passCode);


}

void cls() {

#ifdef __linux__
    printf("\e[1;1H\e[2J");
#elif _WIN32
    system("cls");
#else

#endif

}


void getUserName() {

    for(int i = 0;; i++) {
        name[i] = _getch();
        if(name[i] == '\n') {
            name[i] = '\0';
            break;
        }
        cout<<name[i];

    }
    cout<<endl;

}


void errorMsg() {

    cout<< "Incorrect Password";


}


void readPass() {




}


bool checkData() {



}


void dataIn() {

    User input;
    cout<<"User Name ->"<<endl;
    getUserName();
    strcpy(input.userName,name);
    cout<<"Enter password -> ";
    getPass(false);
    strcpy(input.passCode,pass);

}


void logIn() {

    cout <<"Plese login to enter";
    dataIn();
    checkData();
    cls();

}

/***********bug*********************/
void creatFile(User lcl/*char *fileName*/) {

    strcat(file,dpath);
    strcat(file,lcl.userName);
    strcat(file,ext);

}


void passEntry(User lcl) {

   ofstream myfile (file);
    if (myfile.is_open()) {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
        cout<<"sccess";
    }
    else cout << "Unable to open file";

}


void newUser() {

    User x;
    cout<<"New User Name ->"<<endl;
    getUserName();
    strcpy(x.userName,name);
    cout<<"Enter new password -> ";
    getPass(true);
    strcpy(x.passCode,pass);
    creatFile(x);
    puts(x.userName);
    puts(file);
    passEntry(x);

}


void signUp() {

    newUser();
   // cls();

}


void base() {

    char in;
    cout<<endl << "If you\'re new then press [N]";
    cout<<endl<<"Otherwise Press [I]";
    in = _getch();
    if(in == 'i') {
        cls();
        logIn();
    }
    else {
        cls();
        signUp();
    }

}


int main()
{
    for(;;) {

        base();

    }
    return 0;
}