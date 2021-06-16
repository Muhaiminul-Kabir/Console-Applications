#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


using namespace std;


char pass[4678800];
char name[1000000];

char dpath[]= "/storage/emulated/0/Database/";
char file[] ="";
char ext[5] = ".txt";
char pFolder[] = "/storage/emulated/0/Database/";
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


void makeDir(char* name) {
#ifdef __linux__ 
    mkdir(name, 777); 
#else
    _mkdir(name); 
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


void creatPF(){

    strcat(pFolder,name);
    makeDir(pFolder);

}


void creatFile(User lcl, char *fileName) {
    
    creatPF();
  //  strcat(file,pFolder);
    strcat(pFolder,fileName);
    strcat(pFolder,ext);

}


void passEntry(User lcl) {

    ofstream myfile (pFolder);
    if (myfile.is_open()) {
        for(int i = 0; lcl.passCode[i]!='\0'; i++) {
            myfile<<lcl.passCode[i];
        }
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
    creatFile(x,"/password");
    puts(x.userName);
    puts(pFolder);
    passEntry(x);

}


void signUp() {

    newUser();
    // cls();

}


void base() {
    //makeDir("/storage/emulated/0/Database");
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