windres manyscreen.rc -o manifest.o
windres icon.rc -o icon.o
gcc -Os -s -ffunction-sections -fdata-sections -Wl,--gc-sections boomtterbium.c icon.o manifest.o -o boomtterbium.exe -mwindows -lgdi32 -lwinmm -luser32
del icon.o