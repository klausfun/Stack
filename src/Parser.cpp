#include "../include/Parser.hpp"
#include <iostream>

Parser::Parser(const char* filename) : file_(filename) {
    if (!file_.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
}

void Parser::tokenize_line(std::string line) {
    std::regex re(R"([\s,]+)");
    std::sregex_token_iterator it(line.begin(), line.end(), re, -1);
    std::sregex_token_iterator end;

    for (; it != end; ++it) {
        tokens_.push_back(*it);
    }
}

std::vector<Command*> Parser::parse_command_sequence() {
    std::vector<Command*> commands;
    std::string line;

    while (std::getline(file_, line)) {
        tokens_.clear();
        tokenize_line(line);

        for (const auto& token : tokens_) {
            commands.push_back(parse_command(token));
        }
    }

    return commands;
}

Command* Parser::parse_command(std::string token) {
    if (token == "BEGIN") {
        return new CommandBegin();
    } else if (token == "END") {
        return new CommandEnd();
    } else if (token == "PUSH") {
        Val_t val = get_value(tokens_[1]);
        return new CommandPush(val);
    } else if (token == "POP") {
        return new CommandPop();
    } else if (token == "PUSHR") {
        Reg_t reg = get_register_id(tokens_[1]);
        return new CommandPushr(reg);
    } else if (token == "POPR") {
        Reg_t reg = get_register_id(tokens_[1]);
        return new CommandPopr(reg);
    } else if (token == "ADD") {
        return new CommandAdd();
    } else if (token == "SUB") {
        return new CommandSub();
    } else if (token == "MUL") {
        return new CommandMul();
    } else if (token == "DIV") {
        return new CommandDiv();
    } else if (token == "OUT") {
        return new CommandOut();
    } else if (token == "IN") {
        return new CommandIn();
    } else if (token == "JMP") {
        std::string label = tokens_[1];
        return new CommandJmp(label);
    } else if (token == "JEQ") {
        std::string label = tokens_[1];
        return new CommandJeq(label);
    } else if (token == "JNE") {
        std::string label = tokens_[1];
        return new CommandJne(label);
    } else if (token == "JA") {
        std::string label = tokens_[1];
        return new CommandJa(label);
    } else if (token == "JAE") {
        std::string label = tokens_[1];
        return new CommandJae(label);
    } else if (token == "JB") {
        std::string label = tokens_[1];
        return new CommandJb(label);
    } else if (token == "JBE") {
        std::string label = tokens_[1];
        return new CommandJbe(label);
    } else if (token == "CALL") {
        std::string label = tokens_[1];
        return new CommandCall(label);
    } else if (token == "RET") {
        return new CommandRet();
    } else {
        throw std::runtime_error("Unknown command token: " + token);
    }
}