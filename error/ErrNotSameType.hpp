/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_NOT_SAME_TYPE_HPP_
#define ERR_NOT_SAME_TYPE_HPP_

#include "Error.hpp"

class ErrorNotSameType: public Error {
    public:
        ErrorNotSameType() : Error("Error : The operands are not of the same type", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */