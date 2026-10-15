#ifndef BYTEBEAT_H
#define BYTEBEAT_H

#include <windows.h>
#include <mmsystem.h>
#include <stdbool.h>

typedef unsigned char (*BytebeatFunc)(unsigned long t);

static HWAVEOUT g_hWaveOut=NULL;
static HANDLE g_hThread=NULL;
static bool g_isPlaying=false;
static BytebeatFunc g_func=NULL;

static DWORD WINAPI BytebeatThread(LPVOID lpParam){
    WAVEFORMATEX wave={WAVE_FORMAT_PCM,1,8000,8000,1,8,0};
    if(waveOutOpen(&g_hWaveOut,WAVE_MAPPER,&wave,0,0,CALLBACK_NULL)!=MMSYSERR_NOERROR){
        g_isPlaying=false;
        return 0;
    }
    char buf[2][2048];
    WAVEHDR hdr[2]={{buf[0],2048},{buf[1],2048}};
    waveOutPrepareHeader(g_hWaveOut,&hdr[0],sizeof(WAVEHDR));
    waveOutPrepareHeader(g_hWaveOut,&hdr[1],sizeof(WAVEHDR));
    unsigned long t=0;
    int turn=0;
    while(g_isPlaying){
        if(!(hdr[turn].dwFlags&WHDR_INQUEUE)){
            for(int i=0;i<2048;i++){
                buf[turn][i]=(char)(g_func ? g_func(t) : 0);
                t++;
            }
            waveOutWrite(g_hWaveOut,&hdr[turn],sizeof(WAVEHDR));
            turn=1-turn;
        }
        Sleep(1);
    }
    waveOutReset(g_hWaveOut);
    waveOutUnprepareHeader(g_hWaveOut,&hdr[0],sizeof(WAVEHDR));
    waveOutUnprepareHeader(g_hWaveOut,&hdr[1],sizeof(WAVEHDR));
    waveOutClose(g_hWaveOut);
    g_hWaveOut=NULL;
    return 0;
}

static inline void Bytebeat(BytebeatFunc func){
    if(g_isPlaying)return;
    g_func=func;
    g_isPlaying=true;
    g_hThread=CreateThread(NULL,0,BytebeatThread,NULL,0,NULL);
}

static inline void BytebeatStop(){
    if(!g_isPlaying)return;
    g_isPlaying=false;
    if(g_hThread){
        WaitForSingleObject(g_hThread,INFINITE);
        CloseHandle(g_hThread);
        g_hThread=NULL;
    }
}

#endif