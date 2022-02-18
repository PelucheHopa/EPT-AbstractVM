/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_STACK_FULL_HPP_
#define ERR_STACK_FULL_HPP_

#include "Error.hpp"

class ErrorStackFull: public Error {
    public:
        ErrorStackFull() : Error("Error : The stack is full", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */