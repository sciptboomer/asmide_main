#include <windows.h>
#include <iostream>
#include <vector>
#include "gui.h"

using namespace std;

GUI::GUI(){}
GUI::GUI(WindowCfg cfg)
    : windowcfg(cfg)
{}

GUIbutton* GUI::createButton(char* name,char* text,int x,int y,int w,int h)
{
    GUIbutton* button = new GUIbutton(windowcfg,text,name,x,y,w,h);
    buttons.push_back(button);
    return button;
}

GUIedit* GUI::createEdit(char* name,char* text,int x,int y,int w,int h)
{
    GUIedit* edit = new GUIedit(windowcfg,text,name,x,y,w,h);
    edits.push_back(edit);
    return edit;
}

int GUI::getButtonID(char* name)
{
    for(auto it : buttons){
        if(it->getName()==name)
            return it->getId();
    }
    return 0;
}

GUIedit* GUI::getEdit(char* name)
{
    for(auto it : edits){
        if(it->getName()==name)
            return it;
    }
}

char* GUIelement::getText()
{
    int textsize = GetWindowTextLength(hwnd) + 1;
    char *textbuff = new char[textsize];
    GetWindowText(hwnd,&textbuff[0],textsize);
    return textbuff;
}

GUIbutton* GUI::getButton(char* name)
{
    for(auto it : buttons){
        if(it->getName()==name)
            return it;
    }
}

GUIelement::GUIelement(){}

GUIelement::GUIelement(WindowCfg windowcfg,char* type,char* text,char* name,int x,int y,int w,int h)
    : windowcfg(windowcfg), type(type), text(text), name(name), x(x), y(y), w(w), h(h)
{
    id = GUIelement::idnext;
    GUIelement::idnext++;
}
void GUIelement::focus(){
    SetFocus(hwnd);
}
int GUIelement::getX(){
    return x;
}
int GUIelement::getY(){
    return y;
}
int GUIelement::getW(){
    return w;
}
int GUIelement::getH(){
    return h;
}
int GUIelement::getId(){
    return id;
}
char* GUIelement::getName(){
    return name;
}
int GUIelement::idnext = 1;

GUIedit::GUIedit(WindowCfg windowcfg,char* text,char* name,int x,int y,int w,int h)
    : GUIelement(windowcfg,"edit",text,name,x,y,w,h)
{
    hwnd = CreateWindow(type, text,
    WS_VSCROLL | WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE,
    x, y, w, h,
    windowcfg.hwnd,
    (HMENU)id,
    windowcfg.hinst, NULL);
}

void GUIedit::clear()
{
    SendMessageA(hwnd,WM_SETTEXT,WPARAM(0),LPARAM(""));
}

GUIbutton::GUIbutton(WindowCfg windowcfg,char* text,char* name,int x,int y,int w,int h)
    : GUIelement(windowcfg,"button",text,name,x,y,w,h)
{
    hwnd = CreateWindow(type, text,
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    x, y, w, h,
    windowcfg.hwnd,
    (HMENU)id,
    windowcfg.hinst, NULL);
}

void GUIelement::setFontDefault(){
    HFONT defaultFont;
    defaultFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    SendMessage(hwnd, WM_SETFONT, WPARAM (defaultFont), TRUE);
}

int OpenFileDialog(HWND hwnd,char* path,char* title,char* filter)
{
    path = new char[MAX_PATH];
    ZeroMemory(path,sizeof(char)*MAX_PATH);
    OPENFILENAME filedlg = {};
    filedlg.lStructSize = sizeof(OPENFILENAME);
    filedlg.hwndOwner = hwnd;
    filedlg.lpstrFilter=filter;
    filedlg.lpstrFile=path;
    filedlg.lpstrFileTitle=title;
    filedlg.nMaxFile=MAX_PATH;
    filedlg.lpstrDefExt="asm";
    filedlg.lpstrInitialDir="c:\\";
    filedlg.Flags=OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    if(GetSaveFileName(&filedlg)){
        return true;
    }
    return false;

}
