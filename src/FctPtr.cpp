/*
** EPITECH PROJECT, 2021
** Delivery [WSL: Ubuntu]
** File description:
** FctPtr
*/

#include "FctPtr.hpp"
#include "ErrPrint.hpp"
#include "ErrAss.hpp"

FctPtr::FctPtr()
{
    FctPtr::init_fct_ptr();
    _stop = false;
}

void FctPtr::push(Memory &stack, IOperand &value)
{
    stack.push(std::shared_ptr<IOperand>(&value));
}

void FctPtr::pop(Memory &stack, IOperand &value)
{
    UNUSED(value);
    stack.pop();
}

void FctPtr::dup(Memory &stack, IOperand &value)
{
    UNUSED(value);
    std::shared_ptr<IOperand> v = stack.pop();
    std::shared_ptr<IOperand> op1 = std::shared_ptr<IOperand>(v->clone());
    stack.push(v);
    stack.push(op1);
}

void FctPtr::clear(Memory &stack, IOperand &value)
{
    UNUSED(value);
    stack.clear();
}

void FctPtr::swap(Memory &stack, IOperand &value)
{
    UNUSED(value);
    std::shared_ptr<IOperand> v1 = stack.pop();
    std::shared_ptr<IOperand> v2 = stack.pop();
    stack.push(v1);
    stack.push(v2);
}

void FctPtr::assert(Memory &stack, IOperand &value)
{
    std::shared_ptr<IOperand> v1 = stack.pop();

    if (*v1 == value)
        stack.push(v1);
    else
        throw (ErrorAss());
}

void FctPtr::dump(Memory &stack, IOperand &value)
{
    UNUSED(value);
    auto v = stack.get_stack();
    for (std::vector<std::shared_ptr<IOperand>>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i)
        std::cout << (*i)->toString() << std::endl;
}

template<class T, class F> std::shared_ptr<IOperand> FctPtr::op(std::shared_ptr<IOperand> op1, std::shared_ptr<IOperand> op2, F f) {
    return (std::shared_ptr<IOperand>(f(static_cast<T &> (*op1), static_cast<T &> (*op2))));
}

template<class F> void FctPtr::operation(Memory &stack, F f) {
    std::shared_ptr<IOperand> v1 = stack.pop();
    std::shared_ptr<IOperand> v2 = stack.pop();
    std::shared_ptr<IOperand> op1 = v1;
    std::shared_ptr<IOperand> op2 = v2;
    std::shared_ptr<IOperand> res = NULL;

    if (v1->getType() < v2->getType()) {
        op1 = v1->convert_to(v2->getType());
    } else {
        op2 = v2->convert_to(v1->getType());
    }
    switch(op2->getType())
    {
        case _Int8:
            res = op<Int8, F>(op1, op2, f);
            break;
        case _Int16:
            res = op<Int16, F>(op1, op2, f);
            break;
        case _Int32:
            res = op<Int32, F>(op1, op2, f);
            break;
        case _Float:
            res = op<Float, F>(op1, op2, f);
            break;
        case _Double:
            res = op<Double, F>(op1, op2, f);
            break;
        case _BigDecimal:
            break;
    }
    if (res != NULL)
        stack.push(res);
}

void FctPtr::add(Memory &stack, IOperand &value)
{
    UNUSED(value);
    operation(stack, [](IOperand &op1, IOperand &op2) { return (op1 + op2);});
}

void FctPtr::sub(Memory &stack, IOperand &value)
{
    UNUSED(value);
    operation(stack, [](IOperand &op1, IOperand &op2) { return (op2 - op1);});
}

void FctPtr::mul(Memory &stack, IOperand &value)
{
    UNUSED(value);
    operation(stack, [](IOperand &op1, IOperand &op2) { return (op1 * op2);});
}

void FctPtr::div(Memory &stack, IOperand &value)
{
    UNUSED(value);
    operation(stack, [](IOperand &op1, IOperand &op2) { return (op2 / op1);});
}

void FctPtr::mod(Memory &stack, IOperand &value)
{
    UNUSED(value);
    operation(stack, [](IOperand &op1, IOperand &op2) { return (op2 % op1);});
}

void FctPtr::load(Memory &stack, IOperand &value)
{
    stack.load(&value);
}

void FctPtr::store(Memory &stack, IOperand &value)
{
    stack.store(&value);
}

void FctPtr::print(Memory &stack, IOperand &value)
{
    UNUSED(value);
    std::shared_ptr<IOperand> v = stack.pop();

    if (v->getType() == _Int8) {
        std::cout << static_cast<char> (static_cast<Int8 &> (*v).getValue()) << std::endl;
        stack.push(v);
    } else
        throw (ErrorPrint());
}

void FctPtr::exit(Memory &stack, IOperand &value)
{
    UNUSED(stack);
    UNUSED(value);
    _stop = true;
}

void FctPtr::find_comms(std::string comms, Memory &stack, IOperand &value)
{
    if (_stop == true)
        return;

    void (FctPtr::*fct)(Memory &stack, IOperand &value);

    if (_comms.find(comms) != _comms.end()) {
        fct = _comms[comms];
        (this->*fct)(stack, value);
    } else
        std::cout << "'" << comms << "': unknown command" << std::endl;
}

void FctPtr::init_fct_ptr()
{
	_comms["push"] = &FctPtr::push;
	_comms["pop"] = &FctPtr::pop;
	_comms["clear"] = &FctPtr::clear;
	_comms["dup"] = &FctPtr::dup;
	_comms["swap"] = &FctPtr::swap;
	_comms["dump"] = &FctPtr::dump;
	_comms["assert"] = &FctPtr::assert;
	_comms["add"] = &FctPtr::add;
	_comms["sub"] = &FctPtr::sub;
	_comms["mul"] = &FctPtr::mul;
	_comms["div"] = &FctPtr::div;
	_comms["mod"] = &FctPtr::mod;
	_comms["load"] = &FctPtr::load;
	_comms["store"] = &FctPtr::store;
	_comms["print"] = &FctPtr::print;
	_comms["exit"] = &FctPtr::exit;
}