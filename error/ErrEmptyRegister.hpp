/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_EMPTY_REGISTER_HPP_
#define ERR_EMPTY_REGISTER_HPP_

#include "Error.hpp"

class ErrorEmptyRegister: public Error {
    public:
        ErrorEmptyRegister() : Error("Error : Empty Register", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */