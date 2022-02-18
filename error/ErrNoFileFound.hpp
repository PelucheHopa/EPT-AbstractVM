/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_NO_FILE_FOUND_HPP_
#define ERR_NO_FILE_FOUND_HPP_

#include "Error.hpp"

class ErrorNoFileFound: public Error {
    public:
        ErrorNoFileFound() : Error("Error : No File Found", __FILE__, __LINE__) {};
};
#endif /* !ERROR_HPP_ */