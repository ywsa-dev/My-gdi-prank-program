#include <windows.h>
#include <windowsx.h>
#include <math.h>
#include "boomtterbiumsound.h"
#include "ScreenBackupboomtterbiumingdi.h"
#define PI 3.141592
unsigned char sound1(unsigned long t) {
    return t*(t^t+(t>>15|1)^(t-1280^t)>>10);
}
unsigned char sound2(unsigned long t) {
    return t|t%255|t%257;
}
unsigned char sound3(unsigned long t) {
    return t+(t&t^t>>6)-t*(t>>9&(t%16?2:6)&t>>9);
}
unsigned char sound4(unsigned long t) {
    return t*((t&4096?6:16)+(1&t>>14))>>(3&t>>8)|t>>(t&4096?3:4);
}
unsigned char sound5(unsigned long t) {
    return 430*(5*t>>11|5*t>>1);
}
unsigned char sound6(unsigned long t) {
    return (-t&t>>4&t>>4&t>>11)-1&-t>>4;
}
unsigned char sound7(unsigned long t) {
    return 10*(t>>7|t|t>>6)+4*(t&t>>13|t>>6);
}
unsigned char sound8(unsigned long t) {
    return 43*(t>>9|t>>2);
}
unsigned char sound9(unsigned long t) {
    return t>>4+t%34|t>>5+t%(t/31108&1?46:43)|t/4|t/8%35;
}
int main(void){
    int result=MessageBox(NULL,"Warning\nIt has sound, gdi effects and move Cursor effects. But It's safety.\nBut you can stop it now.\nDo you want to start it really?","Epoxide.exe",MB_YESNO | MB_ICONWARNING);
    if(result==IDNO){
        return 0;
    }
    POINT pt;
    HICON hicon1=LoadIcon(NULL, IDI_ASTERISK);
    Sleep(500);
    Bytebeat(sound1);
    int w=GetSystemMetrics(0);
    int h=GetSystemMetrics(1);
    int count=w*h;
    HDC hdc=GetDC(NULL);
    HDC memDc=CreateCompatibleDC(hdc);
    COLORREF* pixels=NULL;
    BITMAPINFO bmi;
    ZeroMemory(&bmi,sizeof(BITMAPINFO));
    bmi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth=w;
    bmi.bmiHeader.biHeight=-h;
    bmi.bmiHeader.biPlanes=1;
    bmi.bmiHeader.biBitCount=32;
    bmi.bmiHeader.biCompression=BI_RGB;
    HBITMAP hBmp=CreateDIBSection(hdc,&bmi,DIB_RGB_COLORS,(void**)&pixels,NULL,0);
    if (hBmp&&pixels) {
        SelectObject(memDc, hBmp);
        BitBlt(memDc,0,0,w,h,hdc,0,0,SRCCOPY);
        BackupScreen();
        for (int i = 0; i < count; i++){
            pixels[i]+=0x00132475;
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
        Sleep(100);
        for (int i = 0; i < count; i++){
            pixels[i]+=0x00169827;
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
        Sleep(100);
        Sleep(10);
        for(int j=0; j<160; j++){
            for (int i = 0; i < count; i++){
                pixels[i]+=0x00132475;
            }
            Sleep(5);
            BitBlt(hdc,1,1,w,h,hdc,0,0,SRCCOPY);
            Sleep(7);
            BitBlt(hdc,-1,-1,w,h,hdc,0,0,SRCCOPY);
            BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
            Sleep(30);
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
    }
    BytebeatStop();
    Bytebeat(sound2);
    for(int j=0; j<500; j++){
        for (int i=0; i<count; i++){
            pixels[i]=(pixels[i] << 8)|(pixels[i]>> 16);
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
        Sleep(10);
    }
    BytebeatStop();
    Bytebeat(sound3);
    for(int j=0; j<420; j++){
        for (int i=0; i<count; i++){
            pixels[i] ^= (pixels[i] << 13) | 0x00FF00FF | (rand() % 0xFFFFFF);
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
        Sleep(10);
    }
    BytebeatStop();
    Bytebeat(sound4);
    for(int j=0; j<500; j++){
        for (int i=0; i<count; i++){
            pixels[i] = ~(pixels[i] ^ 0x00FFFFFF)+(pixels[i] << 4);
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
        Sleep(10);
    }
    BytebeatStop();
    Bytebeat(sound5);
    PullGetScreen();
    for(int j=0; j<400; j++){
        BitBlt(hdc,15,0,w,h,hdc,0,0,SRCCOPY);
        SetCursorPos(rand()%w,rand()%h);
        GetCursorPos(&pt);
        DrawIcon(hdc, pt.x, pt.y, hicon1);
        Sleep(10);
    }
    PullGetScreen();
    BytebeatStop();
    Bytebeat(sound6);
    int rx=50,ry=50,rvx=38,rvy=38,rr=40;
    HBRUSH hBrush=CreateSolidBrush(RGB(99, 225, 221));
    HBRUSH hOld=(HBRUSH)SelectObject(hdc, hBrush);
    for(int i=0; i<350; i++){
        rx+=rvx;
        ry+=rvy;
        if(rx-rr<0||rx+rr>w)rvx=-rvx;
        if(ry-rr<0||ry+rr>h)rvy=-rvy;
        Ellipse(hdc,rx-rr,ry-rr,rx+rr,ry+rr);
        if(i%2==0){
            BitBlt(hdc,rand()%20-10,rand()%20-10,w,h,hdc,0,0,SRCCOPY);
            BitBlt(hdc,rand()%20-10,rand()%20-10,w,h,hdc,0,0,SRCPAINT);
        }
        Sleep(10);
    }
    rx=50;ry=50;rvx=38;rvy=38;rr=40;
    PullGetScreen();
    BytebeatStop();
    Bytebeat(sound7);
    int crc=0,cgc=0,cbc=0;
    hBrush=CreateSolidBrush(RGB(crc, cgc, cbc));
    hOld=(HBRUSH)SelectObject(hdc, hBrush);
    for(int i=0; i<350; i++){
        rx+=rvx;
        ry+=rvy;
        if(rx-rr<0||rx+rr>w)rvx=-rvx;
        if(ry-rr<0||ry+rr>h)rvy=-rvy;
        crc+=2;
        cgc++;
        cbc++;
        if(cgc>=255){
            cgc=0;
            crc=0;
            cbc=0;
        }
        if(crc>=255){
            crc=0;
        }
        hBrush=CreateSolidBrush(RGB(crc, cgc, cbc));
        hOld=(HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc,rx-rr,ry-rr,rx+rr,ry+rr);
        SelectObject(hdc,hOld);
        DeleteObject(hBrush);
        if(rand()%30==1){
            BitBlt(hdc,rand()%20-10,rand()%20-10,w,h,hdc,0,0,SRCCOPY);
            BitBlt(hdc,rand()%20-10,rand()%20-10,w,h,hdc,0,0,SRCAND);
        }
        Sleep(16);
    }
    PullGetScreen();
    HPEN hOldPen=(HPEN)SelectObject(hdc, GetStockObject(BLACK_PEN));
    BytebeatStop();
    Bytebeat(sound8);
    for(int i=0; i<300; i++){
        hBrush=CreateSolidBrush(RGB(rand()%256,rand()%256,rand()%256));
        hOld=(HBRUSH)SelectObject(hdc, hBrush);
        int ptc=rand()%5+3;
        POINT pt[8];
        for(int j=0; j<ptc; j++){
            pt[j].x=rand()%w;pt[j].y=rand()%h;
        }
        Polygon(hdc,pt,ptc);
        SelectObject(hdc, hOld);
        DeleteObject(hBrush);
        Sleep(30);
    }
    PullGetScreen();
    Sleep(10);
    BytebeatStop();
    Bytebeat(sound9);
    for(int j=0; j<50; j++){
        for (int i=0; i<count-1; i++){
            pixels[i]=pixels[i]==pixels[i+1] ? 0xFF000000 : 0xFFFFFFFF;
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
        Sleep(105);
        SetCursorPos(rand()%w,rand()%h);
        for (int i=0; i<count-1; i++){
            pixels[i]=pixels[i]==pixels[i+1] ? 0x00132475 : 0x00918623;
        }
        BitBlt(hdc,0,0,w,h,memDc,0,0,SRCCOPY);
        Sleep(100);
        SetCursorPos(rand()%w,rand()%h);
    }
    SelectObject(hdc, hOld);
    SelectObject(hdc, hOldPen);
    if(hBrush)DeleteObject(hBrush);
    SelectObject(hdc,hOld);
    DeleteDC(memDc);
    ReleaseDC(NULL, hdc);
    DeleteObject(hBmp);
    BytebeatStop();
    ClearScreenBackup();
    return 0;
}