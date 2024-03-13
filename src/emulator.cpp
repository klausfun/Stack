#include "../include/emulator.hpp"
#include "../include/Parser.hpp"
#include "../include/command.hpp"
#include "../include/CPU.hpp"

#include <iostream>
#include <vector>

Emulator::Emulator(const std::string& filename) : filename_(filename) {}

void Emulator::run() {
    // Создаем парсер для файла программы
    Parser parser(filename_.c_str());

    // Получаем последовательность команд
    std::vector<Command*> commands = parser.parse_command_sequence();

    // Создаем стек для CPU
    Stack<int> stack;

    // Создаем CPU и загружаем программу
    CPU cpu(stack);
    cpu.load_program(commands);

    // Выполняем программу
    cpu.execute();
}

int main(int argc, char* argv[]) {
    // Проверяем корректное количество аргументов
    if (argc != 2) {
        std::cout << "Usage: emulator <input file>\n";
        return EXIT_FAILURE;
    }

    // Получаем путь к файлу программы из аргументов
    std::string filename = argv[1];

    // Создаем объект эмулятора и запускаем его
    Emulator emulator(filename);
    emulator.run();

    return EXIT_SUCCESS;
}