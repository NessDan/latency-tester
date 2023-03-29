# Peripheral Latency Tester

This is a very simple tool for testing latency of mice, gamepads, controllers, and keyboards.

A white window will pop-up.  is white and turns black when any input is detected. For use with high-speed cameras + high refresh rate monitors for capturing.

## Building

`gcc -std=c17 latency-tester.c -I .\SDL2\include -L .\SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -o latency-tester`

# Built with ChatGPT.

Wanted to see if ChatGPT could help build this out. Initially I asked it to be built for Unity, then pivoted to C.
