/*
** EPITECH PROJECT, 2021
** Memory
** File description:
** Memory
*/

#include "Memory.hpp"
#include "ErrStackEmpty.hpp"
#include "ErrStackFull.hpp"
#include "ErrInvalidPos.hpp"

Memory::~Memory()
{
    stack.clear();
    stack.shrink_to_fit();
}

void Memory::clear()
{
    stack.clear();
    stack.shrink_to_fit();
}

void Memory::push(std::shared_ptr<IOperand> operand) {
    if (stack.size() == 16)
        throw (ErrorStackFull());
    stack.push_back(operand);
}

std::shared_ptr<IOperand> Memory::pop() {
    std::shared_ptr<IOperand> res;
    if (stack.size() == 0)
        throw (ErrorStackEmpty());
    res = stack.back();
    stack.pop_back();
    return (res);
}

std::vector<std::shared_ptr<IOperand>> Memory::get_stack() const {
    return (stack);
}

void Memory::store(IOperand *rg) {
    std::shared_ptr<IOperand> value = pop();

    if (rg->get_pos() >= stack.size())
        throw (ErrorInvalidPos());
    stack.erase(stack.begin() + rg->get_pos());
    stack.emplace(stack.begin() + rg->get_pos(), value->convert_to(rg->getType()));
    delete(rg);
}

void Memory::load(IOperand *rg) {
    if (rg->get_pos() >= stack.size())
        throw (ErrorInvalidPos());
    push(std::shared_ptr<IOperand>(stack[rg->get_pos()]->clone()));
    delete(rg);
}