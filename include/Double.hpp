/*
** EPITECH PROJECT, 2021
** Double
** File description:
** Double
*/

#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

class Double : public IOperand
{
    private:
        double _value;

    public:
        Double(double value);
        ~Double() {};
        IOperand *clone() const { return new Double(this->_value); };
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
