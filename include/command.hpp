#pragma once
#include "arch.hpp"
#include "Stack.hpp"

enum CommandType : Cmd_t {
    NOTHING = 0,
    BEGIN,
    END,
    PUSH,
    POP,
    PUSHR,
    POPR,
    ADD,
    SUB,
    MUL,
    DIV,
    OUT,
    IN,
    JMP,
    JEQ,
    JNE,
    JA,
    JAE,
    JB,
    JBE,
    CALL,
    RET
};

class Command {
public:
    virtual ~Command() {}
    virtual void execute(Stack<int>& stack, int& ip) const = 0;
};

class CommandBegin : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandBegin() override {}
};

class CommandEnd : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandEnd() override {}
};

class CommandPush : public Command {
public:
    CommandPush(Val_t val);
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandPush() override {}

private:
    Val_t val_;
};

class CommandPop : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandPop() override {}
};

class CommandPushr : public Command {
public:
    CommandPushr(Reg_t reg);
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandPushr() override {}

private:
    Reg_t reg_;
};

class CommandPopr : public Command {
public:
    CommandPopr(Reg_t reg);
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandPopr() override {}

private:
    Reg_t reg_;
};

class CommandAdd : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandAdd() override {}
};

class CommandSub : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandSub() override {}
};

class CommandMul : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandMul() override {}
};

class CommandDiv : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandDiv() override {}
};

class CommandOut : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandOut() override {}
};

class CommandIn : public Command {
public:
    void execute(Stack<int>& stack, int& ip) const override;
    ~CommandIn() override {}
};

//class CommandJmp : public Command {
//public:
//    CommandJmp(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandJmp() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandJeq : public Command {
//public:
//    CommandJeq(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandJeq() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandJne : public Command {
//public:
//    CommandJne(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandJne() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandJa : public Command {
//public:
//    CommandJa(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandJa() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandJae : public Command {
//public:
//    CommandJae(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandJae() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandJb : public Command {
//public:
//    CommandJb(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandJb() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandJbe : public Command {
//public:
//    CommandJbe(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandJbe() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandCall : public Command {
//public:
//    CommandCall(const std::string& label);
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandCall() override {}
//
//private:
//    std::string label_;
//};
//
//class CommandRet : public Command {
//public:
//    void execute(Stack<int>& stack, int& ip) const override;
//    ~CommandRet() override {}
//};