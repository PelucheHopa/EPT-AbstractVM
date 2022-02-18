/*
** EPITECH PROJECT, 2021
** parser
** File description:
** parser
*/


#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "FctPtr.hpp"
#include "Factory.hpp"
#define UNUSED(x) (void)x

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

class Parser
{
    private:
        std::unordered_map<std::string, eOperandType> SupportedTypes;
        FctPtr *FunctionPointers;
        Memory &Mem;

        void InitSupportedTypes();
        eOperandType StrToType(std::string);

    public:
        Parser(Memory &mem);
        ~Parser();
        void parse_line(std::string &line);
};

#endif