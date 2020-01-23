#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <iostream>

using namespace std;

class File
{
private:
    char* buff;
    string name;

public:
    File();
    void open();
    void write();

    void setname(string name);
    void setbuff(char* buff);
    char* getbuff();
    char* getname();
};
#endif // FILE_H_INCLUDED
