/*
** EPITECH PROJECT, 2021
** Int8
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "IOperand.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

class Int8 : public IOperand {

    private:
        int _value;

    public:
        Int8(int value);
        ~Int8() {};
        IOperand *clone() const { return new Int8(this->_value); };
        std::string toString() const;
        eOperandType getType() const;
        int getValue() const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
        bool operator==(const IOperand &rhs) const;
        std::shared_ptr<IOperand> convert_to(const eOperandType &type) const;
        long unsigned int get_pos() const;
};

#endif
