/*
** EPITECH PROJECT, 2021
** Int8
** File description:
** Int8
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

class Int16 : public IOperand {

    private:
        int _value;

    public:
        Int16(int value);
        ~Int16() {};
        IOperand *clone() const { return new Int16(this->_value); };
        std::string toString() const;
        eOperandType getType() const;
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
