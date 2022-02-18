/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_TYPE_HPP_
#define ERR_TYPE_HPP_

#include "Error.hpp"

class ErrorType: public Error {
    public:
        ErrorType() : Error("Error : Invalid Type", __FILE__, __LINE__) {};
};

#endif /* !ERROR_HPP_ */