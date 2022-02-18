/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_INVALID_POS_HPP_
#define ERR_INVALID_POS_HPP_

#include "Error.hpp"

class ErrorInvalidPos : public Error {
    public:
        ErrorInvalidPos() : Error("Error : the position is outside the memory", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */