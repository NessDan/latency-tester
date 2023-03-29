# Peripheral Latency Tester

This is a very simple tool for testing latency of mice, gamepads, controllers, and keyboards.

A white window will pop-up and turn black when any input is detected. That means you can time the latency of your mouse clicks, key-presses, and controller button-presses!

This polls as fast as your CPU will allow it (1000hz and beyond!)

For use with high-speed cameras + high refresh rate monitors for capturing.

## Building

`gcc -std=c17 latency-tester.c -I .\SDL2\include -L .\SDL2\lib -Wall -lmingw32 -lSDL2main -lSDL2 -o latency-tester`

# Built with ChatGPT.

Wanted to see if ChatGPT could help build this out. Initially I asked it to be built for Unity, then pivoted to C.
