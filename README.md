# Limo
A simple logger made for fun
Completely usable no strings attached. Modify, reuse or anything.

How to start
* Download the code
* import it to your project
Thats it.

Examples

```cpp
#include "limbo.h"

int main() {
    Limbo::init();
    return 0;
}
```
This is the base Code to start using the library

```Limbo::``` Main namspace use this to access all the functions for different types of Logs

Success Log

```cpp
#include "limbo.h"

int main() {
    Limbo::init();
    Limbo::SucessLog("Just a test");
    return 0;
}
```
Warning Log

```cpp
#include "limbo.h"

int main() {
    Limbo::init();
    Limbo::WarningLog("Just a test");
    return 0;
}
```

Error Log

```cpp
#include "limbo.h"

int main() {
    Limbo::init();
    Limbo::ErrorLog("Just a test");
    return 0;
}
```

This library can also save the logs just use

```cpp
Limbo::Save("App.log");
```
If you forget to Add a filename in log the Logger will make a file name Limbo.log.
You also add the path were you want the file to be in the ```limbo::Save()``` function just do this
```limbo::Save("C:\Users\me\Desktop\test.log");```


Full example of the library

```cpp
#include "limbo.h"

int main() {
    Limbo::init();
    Limbo::ErrorLog("test");
    Limbo::SucessLog("test");
    Limbo::WarningLog("test");
    Limbo::Save("");
    return 0;
}
```
Thats it.

Thank you.
