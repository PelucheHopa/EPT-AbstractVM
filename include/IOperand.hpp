/*
** EPITECH PROJECT, 2021
** Delivery [WSL: Ubuntu]
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <string>
#include <iostream>
#include "Error.hpp"
#include "ErrNotSameType.hpp"
#include "ErrDivByZero.hpp"
#include "ErrModByZero.hpp"
#include "ErrRegression.hpp"
#include "ErrUnsupportedType.hpp"
#include "ErrOutsideBoundaries.hpp"
#include "ErrInvalidModulo.hpp"
#define UNUSED(x) (void)x
#include <memory>

enum eOperandType {
    _Int8,
    _Int16,
    _Int32,
    _Float,
    _Double,
    _BigDecimal
};

class IOperand
{
    public:
        virtual ~IOperand() {};
        virtual IOperand *clone() const = 0;
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand *operator+(const IOperand &rhs) const = 0;
        virtual IOperand *operator-(const IOperand &rhs) const = 0;
        virtual IOperand *operator*(const IOperand &rhs) const = 0;
        virtual IOperand *operator/(const IOperand &rhs) const = 0;
        virtual IOperand *operator%(const IOperand &rhs) const = 0;
        virtual bool operator==(const IOperand &rhs) const = 0;
        virtual std::shared_ptr<IOperand> convert_to(const eOperandType &type) const = 0;
        virtual long unsigned int get_pos() const = 0;
};

#endif
