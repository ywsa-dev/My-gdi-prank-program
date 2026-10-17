#include <windows.h>
#include <math.h>
#include "boomtterbiumsound.h"
#include "ScreenBackupboomtterbiumingdi.h"
#include "screenblackofterbi.h"
unsigned char sound1(unsigned long t) {
    return ((t*8) >> 8) & 200 | t * 3 | t >> 5;
}
unsigned char sound2(unsigned long t) {
    return (t*8+42&t>>4)/3;
}
unsigned char sound3(unsigned long t) {
    return t*(t&16384?6:5)*(3+(3&t>>(t&2048?7:14)))>>(3&t>>9)|t>>2;
}
unsigned char sound4(unsigned long t) {
    return t*(3+(1^t>>10&5))*(5+(3&t>>14))>>(t>>8&3);
}
unsigned char sound5(unsigned long t) {
    return 2*(t>>5&t)-(t>>5)+t*(t>>14&14);
}
unsigned char sound6(unsigned long t) {
    return t>>6^t&37|t+(t^t>>11)-t*((t%24?2:6)&t>>11)^t<<1&(t&598?t>>4:t>>10);
}
unsigned char sound7(unsigned long t) {
    return t>>4|t*t*(t>>6&8^8)*(t>>11^t/3>>12)/(7+(t>>10&t>>14&3));
}
unsigned char sound8(unsigned long t) {
    return 430*(5*t>>11|5*t>>1);
}
unsigned char sound9(unsigned long t) {
    return t*(t>>(t&4096?t*t>>12:t>>12))|t<<(t>>8)|t>>4;
}
unsigned char sound11(unsigned long t) {
    return t/6*(t/t+(t>>12)%6+(t>>16)%3)*10&64;
}
int main(){
    int result=MessageBox(NULL,"Warning\nIt has sound and gdi effects. But It's safety.\nBut you can stop it now.\nDo you want to start it really?","boomtterbium.exe",MB_YESNO | MB_ICONWARNING);
    if(result==IDNO){
        return 0;
    }
    Sleep(1000);
    HDC hdc=GetDC(0);
    int w=GetSystemMetrics(0);
    int h=GetSystemMetrics(1);
    HDC hMemDC=CreateCompatibleDC(hdc);
    HBITMAP hBitmap=CreateCompatibleBitmap(hdc, w, h);
    HBITMAP hOldBitmap=(HBITMAP)SelectObject(hMemDC, hBitmap);
    HDC hTempDC = CreateCompatibleDC(hdc);
    HBITMAP hTempBitmap = CreateCompatibleBitmap(hdc, 30, h);
    HBITMAP hOldTempBitmap = (HBITMAP)SelectObject(hTempDC, hTempBitmap);
    HICON hIcon = LoadIcon(NULL, (LPCTSTR)32518);
    Bytebeat(sound1);
    BackupScreen();
    BitBlt(hMemDC, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
    for(int i=0; i<(w>h ? h : w)/5; i++){
        BitBlt(hdc,i,i,w,h,hdc,0,0,NOTSRCCOPY);
        Sleep(10);
    }
    ReleaseDC(NULL,hdc);
    hdc=GetDC(0);
    for(int i=0; i<(w>h ? h : w)/5; i++){
        BitBlt(hdc,i,i,w,h,hdc,0,0,NOTSRCCOPY);
        Sleep(10);
    }
    BytebeatStop();
    Bytebeat(sound2);
    PullGetScreen();
    for(int i=0; i<300; i++){
        BitBlt(hdc,rand()%5,rand()%5,w,h,hdc,0,0,SRCCOPY);
        Sleep(10);
    }
    PullGetScreen();
    POINT pt[3];
    pt[0]=(POINT){ 50,  0 };
    pt[1]=(POINT){ w,   0 };
    pt[2]=(POINT){ 0,   h };
    BytebeatStop();
    Bytebeat(sound3);
    for(int i=0; i<200; i++){
        PlgBlt(hdc, pt, hdc, 0, 0, w, h, NULL, 0, 0);
        Sleep(15);
    }
    BytebeatStop();
    Bytebeat(sound4);
    PullGetScreen();
    for(int i=0; i<150; i++){
        int x=rand()%(w - 32);
        int y= rand()%(h - 32);
        DrawIcon(hdc, x, y, hIcon);
        Sleep(100);
    }
    BytebeatStop();
    PullGetScreen();
    Bytebeat(sound5);
    for(int i=0; i<250; i++){
        int x=rand()%(w - 32);
        int y= rand()%(h - 32);
        HICON hIcon2 = LoadIcon(NULL, MAKEINTRESOURCE(rand() % 6 + 32512));
        DrawIcon(hdc, x, y, hIcon2);
        BitBlt(hdc,rand()%20-10,rand()%20-10,w,h,hdc,0,0,SRCCOPY);
        BitBlt(hdc,rand()%20-10,rand()%20-10,w,h,hdc,0,0,SRCPAINT);
        Sleep(15);
    }
    BytebeatStop();
    Bytebeat(sound6);
    PullGetScreen();
    for(int i=0; i<50; i++){
        BitBlt(hdc,(i%2)-1,0,w,h,hdc,0,0,SRCCOPY);
        Sleep(10);
        BitBlt(hdc,rand()%20-10,rand()%20-10,w,h,hdc,0,0,SRCCOPY);
        Sleep(50);
        PullGetScreen();
        Sleep(50);
    }
    BytebeatStop();
    Bytebeat(sound7);
    PullGetScreen();
    for(int i=0; i<200; i++){
        BitBlt(hdc,5,rand()%20-10,w,h,hdc,0,0,SRCCOPY);
        Sleep(10);
    }
    BytebeatStop();
    Bytebeat(sound8);
    for(int i=0; i<1000; i++){
        BitBlt(hTempDC,0,0,30,h,hMemDC,0,0,SRCCOPY);
        BitBlt(hMemDC, 0, 0, w-30, h, hMemDC, 30, 0, SRCCOPY);
        BitBlt(hMemDC, w-30, 0, 30, h, hTempDC, 0, 0, SRCCOPY);
        BitBlt(hdc, 0, 0, w, h, hMemDC, 0, 0, SRCCOPY);
        Sleep(10);
    }
    pt[0]=(POINT){-50, 0};
    BytebeatStop();
    Bytebeat(sound9);
    PullGetScreen();
    for(int i=0; i<170; i++){
        PlgBlt(hdc, pt, hdc, 0, 0, w, h, NULL, 0, 0);
        BitBlt(hdc,1,1,w,h,hdc,0,0,SRCCOPY);
        Sleep(15);
    }
    BytebeatStop();
    PullGetScreen();
    for(int i=0; i<200; i++){
        Screenblackinit();
        Sleep(55);
    }
    BitBlt(hdc,0,0,w,h,hdc,0,0,NOTSRCCOPY);
    Sleep(100);
    BitBlt(hdc,0,0,w,h,hdc,0,0,NOTSRCCOPY);
    Bytebeat(sound4);
    PullGetScreen();
    for(int i=0; i<150; i++){
        int x=rand()%(w - 32);
        int y= rand()%(h - 32);
        DrawIcon(hdc, x, y, hIcon);
        Sleep(100);
    }
    SelectObject(hTempDC, hOldTempBitmap);
    DeleteObject(hTempBitmap);
    DeleteDC(hTempDC);
    SelectObject(hMemDC, hOldBitmap);
    DeleteObject(hBitmap);
    DeleteDC(hMemDC);
    ReleaseDC(NULL,hdc);
    BytebeatStop();
    ClearScreenBackup();
    return 0;
}