/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_REGRESSION_HPP_
#define ERR_REGRESSION_HPP_

#include "Error.hpp"

class ErrorRegression: public Error {
    public:
        ErrorRegression() : Error("Error : Regression in precision of a value imporssible", __FILE__, __LINE__) {};
};

#endif /* !ERROR_HPP_ */