# Limo
A easy to use light weight logger made for fun
Completely usable no strings attached. Modify, reuse or anything.
(Under update everyday)
How to start
* Download the code
* import ```limo.h``` to your project
Thats it.

Examples

```cpp
#include "limo.h"

int main() {
    Limo::init();
    return 0;
}
```
This is the base Code to start using the library

```Limo::``` Main namspace use this to access all the functions for different types of Logs

Use
```cpp
Limo::Clear();
```
To clear the console

Success Log

```cpp

#include "limo.h"

int main() {
    Limo::init();
    Limo::SucessLog("Just a test");
    return 0;
}```

Info Log

```cpp

#include "limo.h"

int main()
{
    Limo::init();
    Limo::InfoLog("Just a test");
    return 0;
}```
Warning Log

```cpp
#include "limo.h"

int main()
{
    Limo::init();
    Limo::WarningLog("Just a test");
    return 0;
}
```

Error Log

```cpp
#include "limo.h"

int main()
{
    Limo::init();
    Limo::ErrorLog("Just a test");
    return 0;
}
```

This library can also save and load the logs just use

```cpp
Limo::SaveLog("App.log");
```
If you forget to Add a filename in log the Logger will make a file name Limbo.log.
You also add the path were you want the file to be in the ```Limo::SaveLog()``` function just do this
```Limo::SaveLog("C:\Users\me\Desktop\test.log");```

Load the logs use 
```cpp
std::vector<std::string> logs;
Limo::LoadLogs("", logs);
```

Full example of the library

```cpp
#include "limo.h"

int main()
{
    Limo::init();
    Limo::ErrorLog("test");
    Limo::SucessLog("test");
    Limo::WarningLog("test");
    Limo::SaveLog("");
    return 0;
}
```
Using Imgui with the logger to make a simple console

```cpp
if(ImGui::Begin("Console"))
{
    if (ImGui::ColorButton("Clear", ImVec4(255, 0, 0, 255), ImGuiColorEditFlags_NoTooltip) && Limo.logs.size() >= 0)
    {
        Limo.logs.clear();
    }
    for (auto& log : Limo::logs)
    {
        ImGui::Selectable(log.c_str());
    }
}
```

