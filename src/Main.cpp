/*
** EPITECH PROJECT, 2021
** Delivery [WSL: Ubuntu]
** File description:
** main
*/

#include <iostream>
#include "IO.hpp"
#include "Parser.hpp"
#include "Memory.hpp"
#include "FctPtr.hpp"

void process(IO &io) {
    std::string line;
    Memory mem = Memory();
    Parser parser = Parser(mem);

    while (line != io.getStringEndOfInput()) {
        line = io.readLine();
        parser.parse_line(line);
    }
}

int main(int ac, char **av)
{
    std::string arg;
    std::unique_ptr<IO> io = std::unique_ptr<IO>(new IO());

    try {
        if (ac == 1) {
            io->setFilename("");
            process(*io);
        } else if (ac == 2) {
            io->setFilename(av[1]);
            process(*io);
        } else {
            std::cout << "Invalid arguments" << std::endl;
            exit(84);
        }
    } catch (Error &e) {
        io->writeOnSTDOUT(e.what());
    } catch (std::logic_error &e) {
        io->writeOnSTDOUT(e.what());
    }
    return (0);
}
