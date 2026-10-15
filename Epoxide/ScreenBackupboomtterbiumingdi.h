#ifndef SCREEN_BACKUP_BOOMTTERBIUMINGDI_H
#define SCREEN_BACKUP_BOOMTTERBIUMINGDI_H

#include <windows.h>

static HDC sDC = NULL, mDC = NULL;
static HBITMAP bmp = NULL, old = NULL;
static int w = 0, h = 0;

static inline void BackupScreen(void) {
    if (bmp != NULL) {
        SelectObject(mDC, old);
        DeleteObject(bmp);
        DeleteDC(mDC);
        ReleaseDC(NULL, sDC);
    }
    sDC = GetDC(NULL);
    w = GetSystemMetrics(SM_CXSCREEN);
    h = GetSystemMetrics(SM_CYSCREEN);
    mDC = CreateCompatibleDC(sDC);
    bmp = CreateCompatibleBitmap(sDC, w, h);
    old = (HBITMAP)SelectObject(mDC, bmp);
    BitBlt(mDC, 0, 0, w, h, sDC, 0, 0, SRCCOPY);
}

static inline void PullGetScreen(void) {
    if (sDC && mDC && bmp) {
        BitBlt(sDC, 0, 0, w, h, mDC, 0, 0, SRCCOPY);
    }
}

static inline void ClearScreenBackup(void) {
    if (bmp != NULL) {
        SelectObject(mDC, old);
        DeleteObject(bmp);
        DeleteDC(mDC);
        ReleaseDC(NULL, sDC);
        bmp = NULL; mDC = NULL; sDC = NULL;
    }
}

#endif