/*
** EPITECH PROJECT, 2021
** Float
** File description:
** Float
*/

#include "Float.hpp"
#include <sstream>
#include <iomanip>

Float::Float(float value) {
    _value = value;
}

std::string Float::toString() const {
    std::ostringstream oss;
    oss << std::setprecision(4) << std::noshowpoint << _value;
    return (oss.str());
}

eOperandType Float::getType() const {
    return (eOperandType::_Float);
}

IOperand *Float::operator+(const IOperand &rhs) const {
    float res;

    if (rhs.getType() != eOperandType::_Float)
        throw (ErrorUnsupportedType());
    res = this->_value + (static_cast<const Float &> (rhs))._value;
    return (static_cast<IOperand *> (new Float(res)));
}

IOperand *Float::operator-(const IOperand &rhs) const {
    float res;

    if (rhs.getType() != eOperandType::_Float)
        throw (ErrorUnsupportedType());
    res = this->_value - (static_cast<const Float &> (rhs))._value;
    return (static_cast<IOperand *> (new Float(res)));
}

IOperand *Float::operator*(const IOperand &rhs) const {
    float res;

    if (rhs.getType() != eOperandType::_Float)
        throw (ErrorUnsupportedType());
    res = this->_value * (static_cast<const Float &> (rhs))._value;
    return (static_cast<IOperand *> (new Float(res)));
}

IOperand *Float::operator/(const IOperand &rhs) const {
    float res;

    if (rhs.getType() != eOperandType::_Float)
        throw (ErrorUnsupportedType());
    if ((static_cast<const Float &> (rhs))._value == 0)
        throw (ErrorDivByZero());
    res = this->_value / (static_cast<const Float &> (rhs))._value;
    return (static_cast<IOperand *> (new Float(res)));
}

IOperand *Float::operator%(const IOperand &rhs) const {
    UNUSED(rhs);
    throw (ErrorInvalidModulo());
    return (NULL);
}

bool Float::operator==(const IOperand &rhs) const {
    if (rhs.getType() != eOperandType::_Float)
        throw (ErrorUnsupportedType());
    if (toString() == rhs.toString())
        return (true);
    return (false);
}

std::shared_ptr<IOperand> Float::convert_to(const eOperandType &type) const {
    switch (type) {
        case _Int8:
            throw (ErrorRegression());
        case _Int16:
            throw (ErrorRegression());
        case _Int32:
            throw (ErrorRegression());
        case _Float:
            return (std::shared_ptr<IOperand>(new Float(_value)));
        case _Double:
            return (std::shared_ptr<IOperand>(new Double(_value)));
        case _BigDecimal:
            throw (ErrorUnsupportedType());
    }
    return (std::shared_ptr<IOperand>(new Float(_value)));
}

long unsigned int Float::get_pos() const {
    return (static_cast<long unsigned int> (_value));
}