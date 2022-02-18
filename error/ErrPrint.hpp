/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_PRINT_HPP_
#define ERR_PRINT_HPP_

#include "Error.hpp"

class ErrorPrint: public Error {
    public:
        ErrorPrint() : Error("Error : Value is not Int8", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */