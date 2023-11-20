#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>


HANDLE col;

std::fstream file;

const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

namespace Limo
{
    std::vector<std::string> logs;
    
    void SaveLogs(std::string FileName)
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
    void LoadLogs(std::string FileName, std::vector<std::string>& logs)
    {
        if(FileName.empty())
        {
            FileName = "Limbo.log";
        }
        file.open(FileName, std::ios_base::in);
        logs.clear();
        if(file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                line = line + "\n";
                logs.push_back(line);
            }
            file.close();
        }
    }
    void init()
    {
        col = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col, 7);
        logs.clear();
    }

#pragma region String

    void ErrorLog(std::string message)
    {
        SetConsoleTextAttribute(col, 4);
        std::cout << "[" + currentDateTime() +  "] " + " [Error] " + message << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Error] " + message);
    }

    void InfoLog(std::string message)
    {
        SetConsoleTextAttribute(col, 1);
        std::cout <<"[" + currentDateTime() +  "] " + " [Info] " + message << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Info] " + message);
    }

    void WarningLog(std::string message)
    {
        SetConsoleTextAttribute(col, 6);
        std::cout << "[" + currentDateTime() +  "] " + " [Warning] " + message << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Warning] " + message);
    }

    void SucessLog(std::string message)
    {
        SetConsoleTextAttribute(col, 2);
        std::cout << "[" + currentDateTime() +  "] " + " [Success] " + message << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Success] " + message);
    }

#pragma endregion

#pragma region Int

    void ErrorLog(int message)
    {
        SetConsoleTextAttribute(col, 4);
        std::cout << "[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message));
    }

    void InfoLog(int message)
    {
        SetConsoleTextAttribute(col, 1);
        std::cout << "[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message));
    }

    void WarningLog(int message)
    {
        SetConsoleTextAttribute(col, 6);
        std::cout << "[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message));
    }

    void SucessLog(int message)
    {
        SetConsoleTextAttribute(col, 2);
        std::cout << "[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message));
    }

#pragma endregion

#pragma region Float
    void ErrorLog(float message)
    {
        SetConsoleTextAttribute(col, 4);
        std::cout << "[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message));
    }

    void InfoLog(float message)
    {
        SetConsoleTextAttribute(col, 1);
        std::cout << "[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message));
    }

    void WarningLog(float message)
    {
        SetConsoleTextAttribute(col, 6);
        std::cout << "[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message));
    }

    void SucessLog(float message) {
        SetConsoleTextAttribute(col, 2);
        std::cout << "[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message) << std::endl;
        logs.push_back("[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message));
    }
#pragma endregion



    namespace CoolFeatures{
        void CleanLine()
        {
            SetConsoleTextAttribute(col, 7);
            std::cout << "************************************************************************************************************************" << std::endl;
        }
    }

}
