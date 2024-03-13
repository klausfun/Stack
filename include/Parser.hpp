#pragma once
#include "arch.hpp"
#include "command.hpp"

#include <fstream>
#include <vector>
#include <regex>

class Parser {
public:
    Parser(const char* filename);
    std::vector<Command*> parse_command_sequence();

private:
    std::ifstream file_;
    std::vector<std::string> tokens_;

    void tokenize_line(std::string line);
    Command* parse_command(std::string token);
};