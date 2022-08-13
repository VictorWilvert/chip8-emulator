#include "emulator.hpp"
#include <fstream>

#include <iostream>

void Emulator::initialize(std::string path) {
  // initialize stack pointer at memory location 3744 (0xEA0) 
  stack_pointer = 0xEA0;

  // initialize program counter at memory location 512 (0x200) 
  program_counter = 0x200;

  // clear remaining registers
  index_register = 0x0000;
  delay_timer = 0x00;
  sound_timer = 0x00;
  std::fill(cpu_registers.begin(), cpu_registers.end(), 0x00);
  std::fill(memory.begin(), memory.end(), 0x00);

  // 
  if (std::ifstream is{path, std::ios::binary | std::ios::ate}) {
    auto size = is.tellg();
    is.seekg(0);
    is.read((char*)(&memory[0x200]), size);
  }
}

void Emulator::instructionCycle() {
  // fetch instruction
  uint16_t opcode = memory[program_counter] << 8 | memory[program_counter + 1];

  // increment program counter
  program_counter += 2;

  // decode and execute instruction
  switch ((opcode & 0xF000) >> 12)
  {
    case 0x00:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x01:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x02:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x03:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x04:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x05:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x06:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x07:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x08:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x09:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0A:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0B:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0C:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0D:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0E:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0F:
      std::cout << "NotImplementedException" << std::endl;
      break;
    default:
      break;
  }
}