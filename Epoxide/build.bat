windres manyscreen.rc -o manifest.o
windres icon.rc -o icon.o
gcc -Os -s -ffunction-sections -fdata-sections -Wl,--gc-sections Epoxide.c manifest.o icon.o -o Epoxide.exe -lgdi32 -mwindows -lwinmm -luser32