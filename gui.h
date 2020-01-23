#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <windows.h>
#include <vector>
#include <iostream>

using namespace std;

typedef struct
{
    HWND hwnd;
    HINSTANCE hinst;
} WindowCfg;

class GUI;

class GUIelement
{
protected:
    int x,y;
    int w,h;
    char* type;
    char* name;
    char* text;
    int id;
    WindowCfg windowcfg;
    HWND hwnd;
public:
    static int idnext;
    GUIelement();
    GUIelement(WindowCfg cfg,char* type,char* text,char* name,int x,int y,int w,int h);
    void setFontDefault();
    int getX();
    int getY();
    int getW();
    int getH();
    int getId();
    char* getName();
    char* getType();
    char* getText();
    void focus();
};

class GUIbutton : public GUIelement
{
public:
    GUIbutton(WindowCfg windowcfg, char* text,char* name,int x,int y,int w,int h);
    void create();
    void clear();
};

class GUIedit : public GUIelement
{
public:
    GUIedit(WindowCfg windowcfg, char* text,char* name,int x,int y,int w,int h);
    void clear();
    void create();
};
class GUI
{
private:
    WindowCfg windowcfg;
    vector<GUIbutton*> buttons;
    vector<GUIedit*> edits;
public:
    GUI();
    GUI(WindowCfg cfg);
    GUIbutton* createButton(char* name,char* text,int x,int y,int w,int h);
    GUIedit* createEdit(char* name,char* text,int x,int y,int w,int h);

    int getButtonID(char* name);
    GUIbutton* getButton(char* name);
    GUIedit* getEdit(char* name);
};
#endif // GUI_H_INCLUDED
