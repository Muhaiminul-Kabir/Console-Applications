#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

char pass[4678800];
char name[1000000];



struct userData{

    char passCode[1000000];
    char userName[1000000];

};

typedef struct userData User;

void getPass(User lcl){
    
    for(int i = 0;;i++){
        lcl.passCode[i] = _getch();
        
        if(lcl.passCode[i]=='\n'){
          lcl.passCode[i] = '\0';
              break;
        
        }
        cout<<'*';
        
    }
  //  puts(lcl.passCode);



}

void cls(){

#ifdef __linux__ 
    printf("\e[1;1H\e[2J");
#elif _WIN32
    system("cls");
#else

#endif

}


void getUserName(User lcl){
    
    for(int i = 0;;){
        lcl.userName[i] = _getch();
        if(lcl.userName[i] == '\n'){
            lcl.userName[i] = '\0';
            break;
        }
        cout<<lcl.userName[i];
    
    }
    cout<<endl;


}


void newUser(){

    User x;
    cout<<"New User Name ->"<<endl;
    getUserName(x);
    cout<<"Enter new password -> ";
    getPass(x);

}


void errorMsg(){
    
    cout<< "Incorrect Password";


}



void readPass(){

    


}





void checkPass(){
    
   

}


void dataIn(){
    
    User input;
    cout<<"User Name ->"<<endl;
    getUserName(input);
    cout<<"Enter password -> ";
    getPass(input);

}


void logIn(){

    cout <<"Plese login to enter";
    dataIn();
    //checkPass();
    cls();

}

void signUp(){
    
    newUser();
    cls();
    
}

void home(){

    char in;
    cout<<endl << "If you\'re new then press [N]";
    cout<<endl<<"Otherwise Press [I]";
    in = _getch();
    if(in == 'i'){
        cls();
        logIn();
    }
    else{
        cls();
        signUp();
    }

}


int main()
{
    for(;;){
    
        home();
    
    
    
    }
    return 0;
}