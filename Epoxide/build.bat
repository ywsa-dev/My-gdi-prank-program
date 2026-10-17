windres manyscreen.rc -o manifest.o
windres icon.rc -o icon.o
gcc -Os -s -ffunction-sections -fdata-sections -Wl,--gc-sections Epoxide-safety.c manifest.o icon.o -o Epoxide-safety.exe -lgdi32 -mwindows -lwinmm -luser32