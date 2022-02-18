/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_DIV_BY_ZERO_HPP_
#define ERR_DIV_BY_ZERO_HPP_

#include "Error.hpp"

class ErrorDivByZero: public Error {
    public:
        ErrorDivByZero() : Error("Error : Division by zero", __FILE__, __LINE__) {};
};

#endif /* !ERROR_HPP_ */