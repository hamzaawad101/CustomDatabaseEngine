#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <map>
#include <vector>

using namespace std;

struct ParsedCommand{
    string commandType;
    string tableName;
    int key;
    map<string,string> fields;
};

class Parser{
    public:
    ParsedCommand parse(string userInput);
    private:
    vector<string> tokenize(string input);
    bool validate(vector<string> tokens);
    
};

#endif