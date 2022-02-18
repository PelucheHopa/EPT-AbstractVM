/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_ARGS_HPP_
#define ERR_ARGS_HPP_

#include "Error.hpp"

class ErrorArgs: public Error {
    public:
        ErrorArgs() : Error("Error : Not enough or too much argument.", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */