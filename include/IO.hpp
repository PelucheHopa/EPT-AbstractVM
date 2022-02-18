/*
** EPITECH PROJECT, 2021
** IO
** File description:
** IO
*/

#ifndef IO_HPP_
#define IO_HPP_

#include <iostream>
#include <fstream>
#include "Error.hpp"

class IO
{
    private:
        bool isFile;
        std::ifstream *file;
        void openFile(std::string filename);
    public:
        IO();
        ~IO();
        std::string readLine() const;
        void writeOnSTDOUT(std::string s) const;
        std::string getStringEndOfInput();
        void setFilename(std::string _filename);
};

#endif