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


void errorMsg(bool msg) {
    if(msg){
        cout<< "Incorrect Password";
    }
    else{
        cout<< "Something went wrong.";
    }
    cout<<endl<<"press enter to go back";
    char r = _getch();
    if(r == '\n'){
        cls();
    }
    else{
        errorMsg(false);
    }

}

void wlcmMsg(bool msg){

    if(msg){
        cout<< "Log In Successful";
    }
    else{
        cout<<"Congratulations!! Done successfully";
    }
    cout<<endl<<"press enter to proceed";
    char r = _getch();
    if(r == '\n'){
        cls();
        //mainMenu();
    }
    else{
        errorMsg(false);
    }

}

void creatPF(){

    strcat(pFolder,name);
    makeDir(pFolder);

}


void fileLinker(char *fileName) {
    
    creatPF();
  //  strcat(file,pFolder);
    strcat(pFolder,fileName);
    strcat(pFolder,ext);

}





bool readPass(User lcl) {
  
    FILE *f = fopen(pFolder,"r");
    if(f == NULL){
        cout<<"Invalid Username";
    }
    fscanf(f,"%s",lcl.passCode);
    if(strcmp(lcl.passCode,pass) != 0){
        return true;
    }
    else{
        return false;
    }



}


void checkData() {
    User temp;
    if(readPass(temp)){
        errorMsg(true);
        strcpy(pFolder,dpath);
        
    }
    else{
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

    cout <<"Plese login to enter";
    dataIn();    
    fileLinker("/password");
    checkData();
    //cls();

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
    fileLinker("/password");
    puts(x.userName);
    puts(pFolder);
    passEntry(x);

}


void signUp() {

    newUser();
    strcpy(pass,"\0");
    strcpy(name,"\0");
    strcpy(pFolder,dpath);
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
    else if(in == 'n'){
        cls();
        signUp();
    }
    else{
        errorMsg(false);
    }

}


int main()
{
    for(;;) {

        base();

    }
    return 0;
}