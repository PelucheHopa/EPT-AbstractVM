/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_INVALID_MODULO_HPP_
#define ERR_INVALID_MODULO_HPP_

#include "Error.hpp"

class ErrorInvalidModulo: public Error {
    public:
        ErrorInvalidModulo() : Error("Error : Invalid arg for modulo", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */