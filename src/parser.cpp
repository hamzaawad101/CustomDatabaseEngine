#include "../include/parser.h"
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
ParsedCommand Parser::parse(string userInput){
    ParsedCommand cmd;
    vector<string> tokenizedInput=tokenize(userInput);
    bool correct=validate(tokenizedInput);
    if(correct){
        cmd.commandType=tokenizedInput[0];
        cmd.tableName=tokenizedInput[1];
        try{
             cmd.key=stoi(tokenizedInput[2]);
        }catch(...){
            cmd.commandType="";
            cmd.tableName="";
            cmd.key= -1;
            return cmd;
        }
        for (int i=3;i<tokenizedInput.size();i++){
            string token=tokenizedInput[i];
            size_t pos=token.find('=');
              if (pos != string::npos && pos != 0 && pos != token.size() - 1) {
                string key = token.substr(0, pos);
                string value = token.substr(pos + 1);
                cmd.fields[key] = value;
            }
        }
     
    }else{
        cmd.commandType="";
        cmd.tableName="";
        cmd.key= -1;
        return cmd;
    }
       return cmd;
 
}

vector<string> Parser::tokenize(string input){
    vector<string> words;
    stringstream ss(input);
    string word;
    while(ss>>word){
        words.push_back(word);
    }

    return words;
}

bool Parser::validate( vector<string>tokenizedInput){
    if(tokenizedInput.size()==0){
        return false;
    }
    if (tokenizedInput[0] != "INSERT" &&
        tokenizedInput[0] != "GET" &&
        tokenizedInput[0] != "DELETE") {
        return false;
    }
    if ((tokenizedInput[0] == "INSERT" || tokenizedInput[0] =="GET" ||tokenizedInput[0] == "DELETE") && tokenizedInput.size() < 3) {
        return false;
    }

    return true;

}