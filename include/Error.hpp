/*
** EPITECH PROJECT, 2020
** nms
** File description:
** nms
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>

class Error : public std::exception {
    public:
        Error(const char *msg, const char *file, int line)
            : _msg(msg), _file(file), _line(line) {}
        ~Error() = default;

    const char *what() const noexcept {return _msg;}
    const char *where() const noexcept {return _file;}
    int on() const noexcept {return _line;}

    private:
        const char *_msg;
        const char *_file;
        int _line;
};

#endif /* !ERROR_HPP_ */
