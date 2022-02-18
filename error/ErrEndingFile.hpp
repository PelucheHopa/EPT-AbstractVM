/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_ENDING_FILE_HPP_
#define ERR_ENDING_FILE_HPP_

#include "Error.hpp"

class ErrorEndingFile: public Error {
    public:
        ErrorEndingFile() : Error("Error : File empty or end of file incorrect. Maybe you forgot 'exit' command", __FILE__, __LINE__) {};
};

#endif /* !ERROR_HPP_ */