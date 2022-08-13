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
  switch ((opcode & 0xf000) >> 12)
  {
    case 0x00:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x01:
      program_counter = opcode & 0x0fff;
      break;
    case 0x02:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x03:
      if (cpu_registers[(opcode & 0x0f00) >> 8] == (opcode & 0x00ff))
        program_counter += 2;
      break;
    case 0x04:
      if (cpu_registers[(opcode & 0x0f00) >> 8] != (opcode & 0x00ff))
        program_counter += 2;
      break;
    case 0x05:
      if (cpu_registers[(opcode & 0x0f00) >> 8] == cpu_registers[(opcode & 0x00f0) >> 4])
        program_counter += 2;
      break;
    case 0x06:
      cpu_registers[(opcode & 0x0f00) >> 8] = opcode & 0x00ff;
      break;
    case 0x07:
      cpu_registers[(opcode & 0x0f00) >> 8] += opcode & 0x00ff;
      break;
    case 0x08:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x09:
      if (cpu_registers[(opcode & 0x0f00) >> 8] != cpu_registers[(opcode & 0x00f0) >> 4])
        program_counter += 2;
      break;
    case 0x0a:
      index_register = opcode & 0x00ff;
      break;
    case 0x0b:
      program_counter = opcode & 0x0fff + cpu_registers[0];
      break;
    case 0x0c:
      cpu_registers[(opcode & 0x0f00) >> 8] = (opcode & 0x00f);
      break;
    case 0x0d:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0e:
      std::cout << "NotImplementedException" << std::endl;
      break;
    case 0x0f:
      std::cout << "NotImplementedException" << std::endl;
      break;
    default:
      break;
  }
}
