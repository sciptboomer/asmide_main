#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

class File
{
private:
    char* buff;
    char* name;

public:
    File();
    void open();
    void write();

    void setname(char* name);
    void setbuff(char* buff);
    char* getbuff();
    char* getname();
};
#endif // FILE_H_INCLUDED
