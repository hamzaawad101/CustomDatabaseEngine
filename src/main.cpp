#include <iostream>
#include <string>
#include "../include/parser.h"
#include "../include/execution.h"

using namespace std;
int main(){
    Parser inputParser;
    Execution exe;
    string userInput;
    ParsedCommand cmd;

    cout << "Welcome to the in-memory DB. Type commands or EXIT to quit." << endl;
    do{
        cout<<"Enter command:";
        getline(cin,userInput);
        if(userInput=="EXIT" || userInput=="exit"){
            cout<<"Exiting program..."<<endl;
            break;
        }
        cmd=inputParser.parse(userInput);
        exe.executeCommand(cmd);
    }while(userInput!="EXIT" && userInput!="exit");
    return 0;
}