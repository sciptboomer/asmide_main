#include <iostream>
#include <windows.h>
#include "window.h"
#include "gui.h"

using namespace std;

Window::Window(){}
Window::Window(int width, int height, char* windowname, char* classname, HWND parent)
    : width(width), height(height), windowname(windowname), classname(classname), hinst(GetModuleHandle(NULL)), parent(parent)
{

}

void Window::createWindow(LRESULT CALLBACK(*wndproc)(HWND,UINT,WPARAM,LPARAM))
{
    wndclass = {};
    wndclass.lpfnWndProc = wndproc;
    wndclass.hInstance = hinst;
    wndclass.lpszClassName = classname;
    RegisterClass(&wndclass);

    hwnd = CreateWindowEx(0,
            classname,
            windowname,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,CW_USEDEFAULT,width,height,
            NULL,
            NULL,
            hinst,
            NULL);
    if(!hwnd)
        MessageBox(NULL,"ASMIDE ERROR","Cant create window!",MB_ICONERROR);
    gui = GUI({hwnd,hinst});
}

void Window::show(){
    ShowWindow(hwnd,1);
}

void Window::hide(){
    ShowWindow(hwnd,0);
}

void Window::close(){
    DestroyWindow(hwnd);
}
void Window::focus(){
    SetFocus(hwnd);
}
GUI* Window::getGUI(){
    return &gui;
}

int Window::getW(){
    return width;
}

int Window::getH(){
    return height;
}

HWND Window::getHWND(){
    return hwnd;
}
