/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_OUTSIDE_BOUNDARIES_HPP_
#define ERR_OUTSIDE_BOUNDARIES_HPP_

#include "Error.hpp"

class ErrorOutsideBoundaries: public Error {
    public:
        ErrorOutsideBoundaries() : Error("Error : Underflow or overflow", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */