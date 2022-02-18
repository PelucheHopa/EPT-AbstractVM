/*
** EPITECH PROJECT, 2021
** Int32
** File description:
** Int32
*/

#include "Int32.hpp"

Int32::Int32(int value) {
    _value = value;
}

std::string Int32::toString() const {
    return (std::to_string(_value));
}

eOperandType Int32::getType() const {
    return (eOperandType::_Int32);
}

IOperand *Int32::operator+(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int32)
        throw (ErrorNotSameType());
    res = this->_value + (static_cast<const Int32 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int32(res)));
}

IOperand *Int32::operator-(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int32)
        throw (ErrorNotSameType());
    res = this->_value - (static_cast<const Int32 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int32(res)));
}

IOperand *Int32::operator*(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int32)
        throw (ErrorNotSameType());
    res = this->_value * (static_cast<const Int32 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int32(res)));
}

IOperand *Int32::operator/(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int32)
        throw (ErrorNotSameType());
    if ((static_cast<const Int32 &> (rhs))._value == 0)
        throw (ErrorDivByZero());
    res = this->_value / (static_cast<const Int32 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int32(res)));
}

IOperand *Int32::operator%(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int32)
        throw (ErrorNotSameType());
    if ((static_cast<const Int32 &> (rhs))._value == 0)
        throw (ErrorModByZero());
    res = this->_value % (static_cast<const Int32 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int32(res)));
}

bool Int32::operator==(const IOperand &rhs) const {
    if (rhs.getType() != eOperandType::_Int32)
        throw (ErrorNotSameType());
    if (toString() == rhs.toString())
        return (true);
    return (false);
}

std::shared_ptr<IOperand> Int32::convert_to(const eOperandType &type) const {
    switch (type) {
        case _Int8:
            throw (ErrorRegression());
        case _Int16:
            throw (ErrorRegression());
        case _Int32:
            return (std::shared_ptr<IOperand>(new Int32(_value)));
        case _Float:
            return (std::shared_ptr<IOperand>(new Float(_value)));
        case _Double:
            return (std::shared_ptr<IOperand>(new Double(_value)));
        case _BigDecimal:
            throw (ErrorUnsupportedType());
    }
    return (std::shared_ptr<IOperand>(new Int32(_value)));
}

long unsigned int Int32::get_pos() const {
    return (static_cast<long unsigned int> (_value));
}