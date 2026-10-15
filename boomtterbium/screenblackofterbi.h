#ifndef SCREENBLACKOFTERBI_H
#define SCREENBLACKOFTERBI_H
#include <windows.h>
#include <math.h>
static int _s_frame=0;
void Screenblackinit(){
HWND hwnd=GetDesktopWindow();
HDC hdc=GetDC(hwnd);
int w=GetSystemMetrics(SM_CXSCREEN);
int h=GetSystemMetrics(SM_CYSCREEN);
HDC hMemDC=CreateCompatibleDC(hdc);
BITMAPINFO bmi={0};
bmi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
bmi.bmiHeader.biWidth=w;
bmi.bmiHeader.biHeight=-h;
bmi.bmiHeader.biPlanes=1;
bmi.bmiHeader.biBitCount=32;
bmi.bmiHeader.biCompression=BI_RGB;
void* pixelBits=NULL;
HBITMAP hbmMem=CreateDIBSection(hdc,&bmi,DIB_RGB_COLORS,&pixelBits,NULL,0);
HBITMAP hOldBmp=(HBITMAP)SelectObject(hMemDC,hbmMem);
BitBlt(hMemDC,0,0,w,h,hdc,0,0,SRCCOPY);
DWORD* pixels=(DWORD*)pixelBits;
if(pixels){
float time=_s_frame*0.2f;
for(int y=0;y<h;y++){
int offset=(int)(sin(y*0.05+time)*15);
if(offset!=0){
DWORD* row=&pixels[y*w];
if(offset>0){
for(int x=w-1;x>=offset;x--){
row[x]=row[x-offset];
}
}else{
for(int x=0;x<w+offset;x++){
row[x]=row[x-offset];
}
}
}
}
}
BitBlt(hdc,0,0,w,h,hMemDC,0,0,SRCCOPY);
SelectObject(hMemDC,hOldBmp);
DeleteObject(hbmMem);
DeleteDC(hMemDC);
ReleaseDC(hwnd,hdc);
_s_frame++;
}
#endif