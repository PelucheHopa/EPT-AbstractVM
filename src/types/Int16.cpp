/*
** EPITECH PROJECT, 2021
** Int16
** File description:
** Int16
*/

#include "Int16.hpp"

Int16::Int16(int value) {
    if (value > 32767 || value < -32768)
        throw (ErrorOutsideBoundaries());
    _value = value;
}

std::string Int16::toString() const {
    return (std::to_string(_value));
}

eOperandType Int16::getType() const {
    return (eOperandType::_Int16);
}

IOperand *Int16::operator+(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int16)
        throw (ErrorNotSameType());
    res = this->_value + (static_cast<const Int16 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int16(res)));
}

IOperand *Int16::operator-(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int16)
        throw (ErrorNotSameType());
    res = this->_value - (static_cast<const Int16 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int16(res)));
}

IOperand *Int16::operator*(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int16)
        throw (ErrorNotSameType());
    res = this->_value * (static_cast<const Int16 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int16(res)));
}

IOperand *Int16::operator/(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int16)
        throw (ErrorNotSameType());
    if ((static_cast<const Int16 &> (rhs))._value == 0)
        throw (ErrorDivByZero());
    res = this->_value / (static_cast<const Int16 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int16(res)));
}

IOperand *Int16::operator%(const IOperand &rhs) const {
    int res;

    if (rhs.getType() != eOperandType::_Int16)
        throw (ErrorNotSameType());
    if ((static_cast<const Int16 &>(rhs))._value == 0)
        throw (ErrorModByZero());
    res = this->_value % (static_cast<const Int16 &> (rhs))._value;
    return (static_cast<IOperand *> (new Int16(res)));
}

bool Int16::operator==(const IOperand &rhs) const {
    if (rhs.getType() != eOperandType::_Int16)
        throw (ErrorNotSameType());
    if (toString() == rhs.toString())
        return (true);
    return (false);
}

std::shared_ptr<IOperand> Int16::convert_to(const eOperandType &type) const {
    switch (type) {
        case _Int8:
            throw (ErrorRegression());
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
    return (std::shared_ptr<IOperand>(new Int16(_value)));
}

long unsigned int Int16::get_pos() const {
    return (static_cast<long unsigned int> (_value));
}