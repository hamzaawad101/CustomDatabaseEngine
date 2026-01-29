#include "../include/execution.h"
#include <map>
#include <string>
#include <vector>

#include <iostream>
using namespace std;
void Execution::executeCommand(ParsedCommand cmd)
{

        if (cmd.commandType == "INSERT")
        {
                insertRecords(cmd);
        }
        if (cmd.commandType == "GET")
        {
                getRecords(cmd);
        }

        if (cmd.commandType == "DELETE")
        {
                deleteRecords(cmd);
        }
        if (cmd.commandType == "PATCH")
        {
                updateRecords(cmd);
        }
        if (cmd.commandType == "")
                cout << "INVLID COMMAND..." << endl;
}

void Execution::insertRecords(ParsedCommand cmd)
{

        database[cmd.tableName][cmd.key] = cmd.fields;
}
void Execution::getRecords(ParsedCommand cmd)
{
        map<string, map<int, map<string, string>>>::iterator tableIt;
        tableIt = database.find(cmd.tableName);
        if (tableIt != database.end())
        {
                map<int, map<string, string>>::iterator keyIt;
                keyIt = tableIt->second.find(cmd.key);
                if (keyIt != tableIt->second.end())
                {
                        map<string, string>::iterator fieldIt;
                        for (fieldIt = keyIt->second.begin(); fieldIt != keyIt->second.end(); fieldIt++)
                        {
                                cout << fieldIt->first << " = " << fieldIt->second << endl;
                        }
                }
                else
                {
                        cout << "key not found for: " << cmd.key << "in table " << cmd.tableName << endl;
                }
        }
        else
        {
                cout << "table not found for: " << cmd.tableName << endl;
        }
}

void Execution::deleteRecords(ParsedCommand cmd)
{
        map<string, map<int, map<string, string>>>::iterator tableIt;
        tableIt = database.find(cmd.tableName);
        if (tableIt != database.end())
        {
                map<int, map<string, string>>::iterator keyIt;
                keyIt = tableIt->second.find(cmd.key);
                if (keyIt != tableIt->second.end())
                {
                        tableIt->second.erase(keyIt);
                        cout << "Deleted key " << cmd.key << " from table " << cmd.tableName << endl;
                        if (tableIt->second.empty())
                        {
                                database.erase(tableIt);
                        }
                }
                else
                {
                        cout << "key not found for: " << cmd.key << "in table " << cmd.tableName << endl;
                }
        }
        else
        {
                cout << "table not found for: " << cmd.tableName << endl;
        }
}

void Execution::updateRecords(ParsedCommand cmd)
{
        map<string, map<int, map<string, string>>>::iterator tableIt;
        tableIt = database.find(cmd.tableName);
        if (tableIt != database.end())
        {
                map<int, map<string, string>>::iterator keyIt;
                keyIt = tableIt->second.find(cmd.key);
                if (keyIt != tableIt->second.end())
                {
                        map<string, string>::iterator fieldIt;

                        for (fieldIt = cmd.fields.begin(); fieldIt != cmd.fields.end(); fieldIt++)
                        {
                                string fieldName = fieldIt->first;
                                string fieldValue = fieldIt->second;
                                keyIt->second[fieldName] = fieldValue;

                                cout << "Updated: " << fieldIt->first << " = " << fieldIt->second << endl;
                        }
                }
                else
                {
                        cout << "key not found for: " << cmd.key << "in table " << cmd.tableName << endl;
                }
        }
        else
        {
                cout << "table not found for: " << cmd.tableName << endl;
        }
}