#ifndef EXECUTION_H
#define EXECUTION_H

#include <string>
#include "parser.h"
#include <map>

using namespace std;
class Execution
{
public:
    void executeCommand(ParsedCommand cmd);

private:
    void insertRecords(ParsedCommand cmd);
    void getRecords(ParsedCommand cmd);
    void deleteRecords(ParsedCommand cmd);
    void updateRecords(ParsedCommand cmd);

    map<string, map<int, map<string, string>>> database;
};

#endif