/*
** EPITECH PROJECT, 2021
** Float
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Double.hpp"

class Float : public IOperand {

    private:
        float _value;

    public:
        Float(float value);
        ~Float() {};
        IOperand *clone() const { return new Float(this->_value); };
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
