/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_ASS_HPP_
#define ERR_ASS_HPP_

#include "Error.hpp"

class ErrorAss: public Error {
    public:
        ErrorAss() : Error("Error : Values dont correspond", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */