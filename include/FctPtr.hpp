/*
** EPITECH PROJECT, 2021
** Delivery [WSL: Ubuntu]
** File description:
** FctPtr
*/

#ifndef FCTPTR_HPP_
#define FCTPTR_HPP_

#include "Memory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#define UNUSED(x) (void)x

class FctPtr {
    public:
        FctPtr();
        ~FctPtr() {};
        void find_comms(std::string str, Memory &stack, IOperand &value);
        void push(Memory &stack, IOperand &value);
        void pop(Memory &stack, IOperand &value);
        void clear(Memory &stack, IOperand &value);
        void dup(Memory &stack, IOperand &value);
        void swap(Memory &stack, IOperand &value);
        void dump(Memory &stack, IOperand &value);
        void assert(Memory &stack, IOperand &value);
        void add(Memory &stack, IOperand &value);
        void sub(Memory &stack, IOperand &value);
        void mul(Memory &stack, IOperand &value);
        void div(Memory &stack, IOperand &value);
        void mod(Memory &stack, IOperand &value);
        void load(Memory &stack, IOperand &value);
        void store(Memory &stack, IOperand &value);
        void print(Memory &stack, IOperand &value);
        void exit(Memory &stack, IOperand &value);
    protected:
    private:
        bool _stop;
        using fct_ptr = void (FctPtr::*)(Memory &stack, IOperand &value);
        std::unordered_map<std::string, fct_ptr> _comms;
        void init_fct_ptr(void);
        template<class T, class F> std::shared_ptr<IOperand> op(std::shared_ptr<IOperand> op1, std::shared_ptr<IOperand> op2, F f);
        template<class F> void operation(Memory &stack, F f);
};

#endif /* !FCTPTR_HPP_ */