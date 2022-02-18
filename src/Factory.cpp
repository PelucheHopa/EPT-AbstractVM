/*
** EPITECH PROJECT, 2021
** Delivery [WSL: Ubuntu]
** File description:
** main
*/

#include "Factory.hpp"

Factory::Factory() {
    Factory::InitFctPtr();
}

Factory::~Factory() {}

IOperand* Factory::createInt8(const std::string& value)
{
    return (new Int8(stoi(value)));
}

IOperand* Factory::createInt16(const std::string& value)
{
    return (new Int16(stoi(value)));
}

IOperand* Factory::createInt32(const std::string& value)
{
    return (new Int32(stoi(value)));
}

IOperand* Factory::createFloat(const std::string& value)
{
    return (new Float(std::stof(value)));
}

IOperand* Factory::createDouble(const std::string& value)
{
    return (new Double(std::stof(value)));
}

IOperand* Factory::createBigDecimal(const std::string& value)
{
    UNUSED(value);
    return (NULL);
}

IOperand* Factory::createOperand(eOperandType type, const std::string& value)
{
    Factory Fact;

    return Fact.FindOperand(type, value);
}

IOperand* Factory::FindOperand(eOperandType operand, const std::string& value)
{
    IOperand* (Factory::*fct)(const std::string& value);

    if (_operand.find(operand) != _operand.end()) {
        fct = _operand[operand];
        return (this->*fct)(value);
    } else {
        std::cout << "'" << operand << "': unknown operand" << std::endl;
        return NULL;
    }
}

void Factory::InitFctPtr()
{
	_operand[_Int8] = &Factory::createInt8;
	_operand[_Int16] = &Factory::createInt16;
	_operand[_Int32] = &Factory::createInt32;
	_operand[_Float] = &Factory::createFloat;
	_operand[_Double] = &Factory::createDouble;
	_operand[_BigDecimal] = &Factory::createBigDecimal;
}