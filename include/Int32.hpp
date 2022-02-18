/*
** EPITECH PROJECT, 2021
** Int8
** File description:
** Int8
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Float.hpp"
#include "Double.hpp"

class Int32 : public IOperand {

    private:
        int _value;

    public:
        Int32(int value);
        ~Int32() {};
        IOperand *clone() const { return new Int32(this->_value); };
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
