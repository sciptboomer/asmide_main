#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <windows.h>
#include "gui.h"

class Window
{
private:
    int width;
    int height;
    char* windowname;
    char* classname;
    WNDCLASS wndclass;
    HWND hwnd;
    HWND parent;
    HINSTANCE hinst;

    GUI gui;
    WindowCfg cfg;
public:
    Window();
    Window(int width, int height, char* windowname, char* classname, HWND parent=NULL);
    void createWindow(LRESULT CALLBACK(*wndproc)(HWND,UINT,WPARAM,LPARAM));
    void hide();
    void show();
    void close();
    void focus();
    GUI* getGUI();
    HWND getHWND();
    int getW();
    int getH();

};

#endif // WINDOW_H_INCLUDED
