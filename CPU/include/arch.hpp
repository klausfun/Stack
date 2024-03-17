#pragma once
#include <cstdint>
#include <string>

typedef uint8_t Cmd_t;
typedef uint8_t Reg_t;
typedef int32_t Val_t;

Cmd_t get_command_id(std::string str);
Reg_t get_register_id(std::string str);
std::string get_register_name(Reg_t reg);
Val_t get_value(std::string str);