#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
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

#pragma region Vector

template <typename T>
struct vector
{
private:
    T* data;
    size_t size;
    size_t capacity;
public:
    vector() : data(nullptr), capacity(0), size(0) {}

    ~vector() {
        delete[] data;
    }

    void pushback(const T& value)
    {
        if(size == capacity)
        {
            if (capacity == 0)
            {
                capacity = 1;
            }
            else
            {
                capacity = capacity * 2;
            }
            T* new_data = new T[capacity];


            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }
    T& operator[](size_t index)
    {
        if (index < size)
        {
            return data[index];
        } else
        {
            throw std::out_of_range("Index greater than size");
        }
    }
    size_t GetSize() const {
        return size;
    }
    bool IsEmpty() const {
        return size == 0;
    }
    size_t GetCapacity() const {
        return capacity;
    }
    void clear()
    {
        size = 0;
    }
};

#pragma endregion

namespace Limo
{

vector<std::string> logs;

    void init()
    {
        col = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col, 7);
        logs.clear();
    }

#pragma region String

    void ErrorLog(const std::string& message)
    {
        SetConsoleTextAttribute(col, 4);
        std::cout << "[" + currentDateTime() +  "] " + " [Error] " + message << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Error] " + message);
    }

    void InfoLog(const std::string& message)
    {
        SetConsoleTextAttribute(col, 1);
        std::cout <<"[" + currentDateTime() +  "] " + " [Info] " + message << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Info] " + message);
    }

    void WarningLog(const std::string& message)
    {
        SetConsoleTextAttribute(col, 6);
        std::cout << "[" + currentDateTime() +  "] " + " [Warning] " + message << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Warning] " + message);
    }

    void SucessLog(const std::string& message)
    {
        SetConsoleTextAttribute(col, 2);
        std::cout << "[" + currentDateTime() +  "] " + " [Success] " + message << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Success] " + message);
    }

#pragma endregion

#pragma region Int

    void ErrorLog(int message)
    {
        SetConsoleTextAttribute(col, 4);
        std::cout << "[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message));
    }

    void InfoLog(int message)
    {
        SetConsoleTextAttribute(col, 1);
        std::cout << "[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message));
    }

    void WarningLog(int message)
    {
        SetConsoleTextAttribute(col, 6);
        std::cout << "[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message));
    }

    void SucessLog(int message)
    {
        SetConsoleTextAttribute(col, 2);
        std::cout << "[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message));
    }

#pragma endregion

#pragma region Float
    void ErrorLog(float message)
    {
        SetConsoleTextAttribute(col, 4);
        std::cout << "[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Error] " + std::to_string(message));
    }

    void InfoLog(float message)
    {
        SetConsoleTextAttribute(col, 1);
        std::cout << "[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Info] " + std::to_string(message));
    }

    void WarningLog(float message)
    {
        SetConsoleTextAttribute(col, 6);
        std::cout << "[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Warning] " + std::to_string(message));
    }

    void SucessLog(float message) {
        SetConsoleTextAttribute(col, 2);
        std::cout << "[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message) << std::endl;
        logs.pushback("[" + currentDateTime() +  "] " + " [Success] " + std::to_string(message));
    }
#pragma endregion

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
            for (size_t i = 0; i < logs.GetSize(); ++i)
            {
               file << logs[i] + "\n";
            }

            file.close();
        }
    }
    void Clear()
    {
        system("cls");
    }

    namespace CoolFeatures{
        void CleanLine()
        {
            SetConsoleTextAttribute(col, 7);
            std::cout << "************************************************************************************************************************" << std::endl;
        }
    }

}
