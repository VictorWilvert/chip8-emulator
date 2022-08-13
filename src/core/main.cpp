#include <iostream>
#include "emulator/emulator.hpp"

int main() {
  Emulator emulator;
  emulator.initialize("C:\\Users\\victo\\Workspace\\tetris.c8");
  emulator.instructionCycle();
  return 0;
}