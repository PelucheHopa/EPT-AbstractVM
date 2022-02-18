/*
** EPITECH PROJECT, 2021
** IO
** File description:
** IO
*/

#include "IO.hpp"

IO::IO() {
    isFile = false;
}

IO::~IO() {
    if (isFile)
        file->close();
    delete(file);
}

void IO::openFile(std::string filename) {
    file = new std::ifstream(filename);

    if (!file->is_open())
        throw (Error("File not found", __FILE__, __LINE__));
}

void IO::setFilename(std::string filename) {
    if (filename.size() != 0)
        isFile = true;
    if (isFile)
        openFile(filename);
}

std::string IO::readLine() const {
    std::string line;

    if (isFile) {
        getline(file[0],line);
        return (line);
    } else {
        getline (std::cin,line);
        if (line == "") exit(EXIT_SUCCESS);
        return (line);
    }
}

void IO::writeOnSTDOUT(std::string s) const {
    std::cerr << s << std::endl;
    exit(84);
}

std::string IO::getStringEndOfInput() {
    if (isFile)
        return ("exit");
    else
        return (";;");
}