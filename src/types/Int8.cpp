/*
** EPITECH PROJECT, 2021
** Int8
** File description:
** Int8
*/

#include "Int8.hpp"

Int8::Int8(int value) {
    if (value > 127 || value < -128)
        throw (ErrorOutsideBoundaries());
    _value = value;
}

std::string Int8::toString() const {
    return (std::to_string(_value));
}

eOperandType Int8::getType() const {
    return (eOperandType::_Int8);
}

int Int8::getValue() const
{
    return _value;
}

IOperand *Int8::operator+(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int8)
        throw (ErrorNotSameType());
    res = this->_value + (static_cast<const Int8 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int8(res)));
}

IOperand *Int8::operator-(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int8)
        throw (ErrorNotSameType());
    res = this->_value - (static_cast<const Int8 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int8(res)));
}

IOperand *Int8::operator*(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int8)
        throw (ErrorNotSameType());
    res = this->_value * (static_cast<const Int8 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int8(res)));
}

IOperand *Int8::operator/(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int8)
        throw (ErrorNotSameType());
    if ((static_cast<const Int8 &> (rhs))._value == 0)
        throw (ErrorDivByZero());
    res = this->_value / (static_cast<const Int8 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int8(res)));
}

IOperand *Int8::operator%(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int8)
        throw (ErrorNotSameType());
    if ((static_cast<const Int8 &> (rhs))._value == 0)
        throw (ErrorModByZero());
    res = this->_value % (static_cast<const Int8 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int8(res)));
}

bool Int8::operator==(const IOperand &rhs) const {
    if (rhs.getType() != eOperandType::_Int8)
        throw (ErrorNotSameType());
    if (toString() == rhs.toString())
        return (true);
    return (false);
}

std::shared_ptr<IOperand> Int8::convert_to(const eOperandType &type) const {
    switch (type) {
        case _Int8:
            return (std::shared_ptr<IOperand>(new Int8(_value)));
        case _Int16:
            return (std::shared_ptr<IOperand>(new Int16(_value)));
        case _Int32:
            return (std::shared_ptr<IOperand>(new Int32(_value)));
        case _Float:
            return (std::shared_ptr<IOperand>(new Float(_value)));
        case _Double:
            return (std::shared_ptr<IOperand>(new Double(_value)));
        case _BigDecimal:
            throw (ErrorUnsupportedType());
    }
    return (std::shared_ptr<IOperand>(new Int8(_value)));
}

long unsigned int Int8::get_pos() const {
    return (static_cast<long unsigned int> (_value));
}