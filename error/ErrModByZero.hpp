/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_MOD_BY_ZERO_HPP_
#define ERR_MOD_BY_ZERO_HPP_

#include "Error.hpp"

class ErrorModByZero: public Error {
    public:
        ErrorModByZero() : Error("Error : Modulo by zero", __FILE__, __LINE__) {};
};

#endif /* !ERROR_HPP_ */