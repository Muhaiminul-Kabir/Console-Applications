#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>

using namespace std;


char pass[4678800];
char name[1000000];

char dpath[]= "/storage/emulated/0/Database/";
char file[] ="";
char ext[5] = ".txt";
char pFolder[] = "/storage/emulated/0/Database/";
char univar[]="";


struct userData {

    char passCode[1000000];
    char userName[1000000];

};

enum menu {
    INIT,
    BASE,
    MAIN
};


typedef struct userData User;
typedef enum menu menu;

menu _menu = BASE;


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


void waitCls(){

    if(_getch()){
        cls();
    }

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


void errorMsg(bool msg) {
    if(msg) {
        cout<< "Incorrect Password";
    }
    else {
        cout<< "Something went wrong.";
    }
    cout<<endl<<"press enter to go back";
    char r = _getch();
    if(_menu != MAIN && r == '\n') {
        _menu = BASE;
        cls();
    }
    else if(_menu == MAIN && r == '\n'){
        _menu = MAIN;
        cls();
    }
    else {
        errorMsg(false);
    }

}

void wlcmMsg(bool msg) {

    if(msg) {
        cout<< "Log In Successful";
    }
    else {
        cout<<"Congratulations!! Done successfully";
    }
    cout<<endl<<"press enter to proceed";
    char r = _getch();
    if(r == '\n') {
        cls();
        _menu = MAIN;
    }
    else {
        errorMsg(false);
    }
    

}

void creatPF() {

    strcat(pFolder,name);
    makeDir(pFolder);

}


void fileLinker(char *fileName) {

    creatPF();
    strcat(pFolder,fileName);
    strcat(pFolder,ext);
    strcpy(univar,dpath);
    strcat(univar,"link.txt");
    ofstream myfile (univar);
    if (myfile.is_open()) {
        for(int i = 0; pFolder[i]!='\0'; i++) {
            myfile<<pFolder[i];
        }
        myfile.close();
    }

}


void changePass(char *pass){
    char h[100000];
    FILE *f = fopen(univar,"r");
    for(;;){
        fgets(h,1000000,f);
        if(feof(f)){
            break;
        }
    
    }
    fclose(f);
    cout<<endl<< "Enter new password"<<endl;
    getPass(true);
    ofstream myfile (h);
    if (myfile.is_open()) {
        for(int i = 0; pass[i]!='\0'; i++) {
            myfile<<pass[i];
        }
        myfile.close();
    }
    
    
}



bool readPass(User lcl) {

    FILE *f = fopen(pFolder,"r");
    if(f == NULL) {
        cout<<"Invalid Username";
    }
    fscanf(f,"%s",lcl.passCode);
    if(strcmp(lcl.passCode,pass) != 0) {
        return true;
    }
    else {
        return false;
    }

    fclose(f);

}


void checkData() {
    User temp;
    if(readPass(temp)) {
        errorMsg(true);
        strcpy(pFolder,dpath);

    }
    else {
        wlcmMsg(true);
    }

}


void dataIn() {

    cout<<"User Name ->"<<endl;
    getUserName();
    cout<<"Enter password -> ";
    getPass(false);

}


void logIn() {

    cout <<"---------Plese login to enter---------"<<endl;
    dataIn();
    fileLinker("/password");
    checkData();

}


void passEntry(User lcl,bool way) {

    ofstream myfile (pFolder);
    if (myfile.is_open()) {
        for(int i = 0; lcl.passCode[i]!='\0'; i++) {
            myfile<<lcl.passCode[i];
        }
        myfile.close();
        if(way){
            cout<<"sccess";
        }
        else{
            cout<<"Password changed successfully";
        }
        if(_getch()){
             _menu = MAIN;
        }
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
    fileLinker("/password");
    puts(x.userName);
    puts(pFolder);
    passEntry(x,true);

}


void logOut() {

    strcpy(pass,"\0");
    strcpy(name,"\0");
    strcpy(pFolder,dpath);
    _menu = BASE;

}

void options() {

    cout <<" [1] Update Semester"<<endl;
    cout <<" [2] Semester wise GPA"<<endl;
    cout <<" [3] Update CGPA"<<endl;
    cout <<" [4] Change Password"<<endl;
    cout <<" [5] Log out"<<endl;

}


void mainMenu() {

    puts(name);

    options();
    char i = _getch();
    if(i == '5') {
        logOut();
        cls();

    }
    if(i == '4') {
        changePass(pass);
        cls();

    }
    
}


void signUp() {

    newUser();
    if(_menu == BASE){
        strcpy(pFolder,dpath);
    }
    cls();

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
    else if(in == 'n') {
        cls();
        signUp();
    }
    else {
        errorMsg(false);
    }

}


int main()
{
    for(;;) {
        cout<<endl ;
        cout<<endl ;
        if(_menu == BASE) {
            base();
        }
        else if(_menu == MAIN) {
            mainMenu();
        }
    }
    return 0;
}