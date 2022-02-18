/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_UNKNOWN_COMMAND_HPP_
#define ERR_UNKNOWN_COMMAND_HPP_

#include "Error.hpp"

class ErrUnknownCommand: public Error {
    public:
        ErrUnknownCommand() : Error("Error : Unknown command", __FILE__, __LINE__) {};
};
#endif