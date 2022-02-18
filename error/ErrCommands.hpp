/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_COMMANDS_HPP_
#define ERR_COMMANDS_HPP_

#include "Error.hpp"

class ErrorCommands: public Error {
    public:
        ErrorCommands() : Error("Error : Command not found", __FILE__, __LINE__) {};
};

#endif /* !ERROR_HPP_ */