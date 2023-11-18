#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>


HANDLE col;
std::vector<std::string> logs;
std::fstream file;

namespace Limo
{

void Save(std::string FileName)
{
    if(FileName.empty())
    {
        FileName = "Limbo.log";
    }
    file.open(FileName, std::ios_base::out);
    if(file.is_open())
    {
        file << "";
        file.close();
    }
    file.open(FileName, std::ios_base::app);
    if(file.is_open())
    {
        for (auto& s : logs) {
            file << s + "\n";
        }

        file.close();
    }
}

    void init()
    {
        col = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col, 7);


    }
    void ErrorLog(std::string message) {
        SetConsoleTextAttribute(col, 4);
        std::cout << "[Error] " + message << std::endl;
        logs.push_back("[Error] " + message);
    }
    void WarningLog(std::string message) {
        SetConsoleTextAttribute(col, 6);
        std::cout << "[Warning] " + message << std::endl;
        logs.push_back("[Warning] " + message);
    }
    void SucessLog(std::string message) {
        SetConsoleTextAttribute(col, 2);
        std::cout << "[Success] " + message << std::endl;
        logs.push_back("[Success] " + message);
    }
}
