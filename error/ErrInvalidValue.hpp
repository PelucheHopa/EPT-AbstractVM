/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_INVALID_VALUE_HPP_
#define ERR_INVALID_VALUE_HPP_

#include "Error.hpp"

class ErrorInvalidValue: public Error {
    public:
        ErrorInvalidValue() : Error("Error : Invalid Value", __FILE__, __LINE__) {};
};

#endif /* !ERROR_HPP_ */