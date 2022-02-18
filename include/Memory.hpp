/*
** EPITECH PROJECT, 2021
** Memory
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include "IOperand.hpp"
#include "Error.hpp"
#include <vector>
#include <unordered_map>
#include <memory>

class Memory {

    private:
        std::vector<std::shared_ptr<IOperand>> stack;
    public:
        Memory() {};
        ~Memory();
        void push(std::shared_ptr<IOperand> operand);
        std::shared_ptr<IOperand> pop();
        void clear();
        std::vector<std::shared_ptr<IOperand>> get_stack() const;
        void store(IOperand *);
        void load(IOperand *);
};

#endif