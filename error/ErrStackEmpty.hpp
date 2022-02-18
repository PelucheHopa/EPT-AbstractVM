/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_STACK_EMPTY_HPP_
#define ERR_STACK_EMPTY_HPP_

#include "Error.hpp"

class ErrorStackEmpty: public Error {
    public:
        ErrorStackEmpty() : Error("Error : Line 1: error: pop on empty stack.", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */