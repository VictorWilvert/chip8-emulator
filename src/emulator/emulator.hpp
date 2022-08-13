#include <array>
#include <cstdint>
#include <string>

class Emulator {
  public:
    void initialize(std::string path);
    void instructionCycle();
  private:
    std::array<uint8_t, 16> cpu_registers;
    uint16_t index_register;
    uint16_t program_counter;
    uint16_t stack_pointer;
    uint8_t delay_timer;
    uint8_t sound_timer;
    std::array<uint8_t, 4096> memory;
};
