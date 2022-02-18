/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_UNUPPORTED_TYPE_HPP_
#define ERR_UNUPPORTED_TYPE_HPP_

#include "Error.hpp"

class ErrorUnsupportedType: public Error {
    public:
        ErrorUnsupportedType() : Error("Error : Unsupported type", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */