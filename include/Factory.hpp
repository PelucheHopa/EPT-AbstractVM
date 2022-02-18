/*
** EPITECH PROJECT, 2021
** tool
** File description:
** tool
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <unordered_map>
#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#define UNUSED(x) (void)x

class Factory
{
    public:
        Factory();
        ~Factory();

        static IOperand* createOperand(eOperandType type, const std::string& value);
    private:
        using fct_ptr = IOperand* (Factory::*)(const std::string& value);
        std::unordered_map<eOperandType, fct_ptr> _operand;
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);
        IOperand* createBigDecimal(const std::string& value);
        void InitFctPtr(void);
        IOperand* FindOperand(eOperandType operand, const std::string& value);
};

#endif