#include "../include/arch.hpp"
#include <vector>
#include <stdexcept>

static std::vector<std::string> CMD_NAME_TO_CMD_ID = {
        "NOTHING",
        "BEGIN",
        "END",
        "PUSH",
        "POP",
        "PUSHR",
        "POPR"
};

Cmd_t get_command_id(std::string str) {
    for (size_t id = 0U; id < CMD_NAME_TO_CMD_ID.size(); ++id) {
        if (CMD_NAME_TO_CMD_ID[id] == str) {
            return id;
        }
    }
    throw std::runtime_error("Unknown command name!");
}

static std::vector<std::string> REG_NAME_TO_REG_ID = {
        "AX", "BX", "CX", "DX", "EX", "FX", "PC"
};

Reg_t get_register_id(std::string str) {
    for (size_t id = 0U; id < REG_NAME_TO_REG_ID.size(); ++id) {
        if (REG_NAME_TO_REG_ID[id] == str) {
            return id;
        }
    }
    throw std::runtime_error("Unknown register name!");
}

std::string get_register_name(Reg_t reg) {
    return REG_NAME_TO_REG_ID.at(reg);
}

Val_t get_value(std::string str) {
    return std::atoi(str.c_str());
}