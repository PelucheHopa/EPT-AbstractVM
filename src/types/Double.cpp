/*
** EPITECH PROJECT, 2021
** Double
** File description:
** Double
*/

#include "Double.hpp"
#include <sstream>
#include <iomanip>

Double::Double(double value) {
    _value = value;
}

std::string Double::toString() const {
    std::ostringstream oss;
    oss << std::setprecision(7) << std::noshowpoint << _value;
    return (oss.str());
}

eOperandType Double::getType() const {
    return (eOperandType::_Double);
}

IOperand *Double::operator+(const IOperand &rhs) const {
    double res;

    if (rhs.getType() != eOperandType::_Double)
        throw (ErrorNotSameType());
    res = this->_value + (static_cast<const Double &> (rhs))._value;
    return (static_cast<IOperand *> (new Double(res)));
}

IOperand *Double::operator-(const IOperand &rhs) const {
    double res;

    if (rhs.getType() != eOperandType::_Double)
        throw (ErrorNotSameType());
    res = this->_value - (static_cast<const Double &> (rhs))._value;
    return (static_cast<IOperand *> (new Double(res)));
}

IOperand *Double::operator*(const IOperand &rhs) const {
    double res;

    if (rhs.getType() != eOperandType::_Double)
        throw (ErrorNotSameType());
    res = this->_value * (static_cast<const Double &> (rhs))._value;
    return (static_cast<IOperand *> (new Double(res)));
}

IOperand *Double::operator/(const IOperand &rhs) const {
    double res;

    if (rhs.getType() != eOperandType::_Double)
        throw (ErrorNotSameType());
    if ((static_cast<const Double &> (rhs))._value == 0)
        throw (ErrorDivByZero());
    res = this->_value / (static_cast<const Double &> (rhs))._value;
    return (static_cast<IOperand *> (new Double(res)));
}

IOperand *Double::operator%(const IOperand &rhs) const {
    UNUSED(rhs);
    throw (ErrorInvalidModulo());
    return (NULL);
}

bool Double::operator==(const IOperand &rhs) const {
    if (rhs.getType() != eOperandType::_Double)
        throw (ErrorNotSameType());
    if (toString() == rhs.toString())
        return (true);
    return (false);
}

std::shared_ptr<IOperand> Double::convert_to(const eOperandType &type) const {
    switch (type) {
        case _Int8:
            throw (ErrorRegression());
        case _Int16:
            throw (ErrorRegression());
        case _Int32:
            throw (ErrorRegression());
        case _Float:
            throw (ErrorRegression());
        case _Double:
            return (std::shared_ptr<IOperand>(new Double(_value)));
        case _BigDecimal:
            throw (ErrorUnsupportedType());
    }
    return (std::shared_ptr<IOperand>(new Double(_value)));
}

long unsigned int Double::get_pos() const {
    return (static_cast<long unsigned int> (_value));
}