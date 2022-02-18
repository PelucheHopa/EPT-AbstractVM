/*
** EPITECH PROJECT, 2021
** FctPtr tests
** File description:
** FctPtr tests
*/

#include <criterion/criterion.h>
#include "Error.hpp"
#include "FctPtr.hpp"

Test (push, push_in_empty_stack) {
    Memory mem = Memory();
    IOperand *op = new Int8(5);
    FctPtr *f = new  FctPtr();

    f->push(mem, *op);
    cr_assert_eq(mem.get_stack().size(), 1);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "5");
}

Test (push, push_in_stack) {
    Memory mem = Memory();
    IOperand *op = new Int8(5);
    IOperand *op1 = new Int16(16);
    IOperand *op2 = new Int32(32);
    FctPtr *f = new  FctPtr();

    f->push(mem, *op);
    f->push(mem, *op1);
    f->push(mem, *op2);
    cr_assert_eq(mem.get_stack().size(), 3);
}

Test (push, push_in_full_stack) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();
    IOperand *op1 = new Int8(8);
    IOperand *op2 = new Int8(8);
    IOperand *op3 = new Int8(8);
    IOperand *op4 = new Int8(8);
    IOperand *op5 = new Int8(8);
    IOperand *op6 = new Int8(8);
    IOperand *op7 = new Int8(8);
    IOperand *op8 = new Int8(8);
    IOperand *op9 = new Int8(8);
    IOperand *op10 = new Int8(8);
    IOperand *op11 = new Int8(8);
    IOperand *op12 = new Int8(8);
    IOperand *op13 = new Int8(8);
    IOperand *op14 = new Int8(8);
    IOperand *op15 = new Int8(8);
    IOperand *op16 = new Int8(8);
    IOperand *op17 = new Int8(8);
    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->push(mem, *op3);
    f->push(mem, *op4);
    f->push(mem, *op5);
    f->push(mem, *op6);
    f->push(mem, *op7);
    f->push(mem, *op8);
    f->push(mem, *op9);
    f->push(mem, *op10);
    f->push(mem, *op11);
    f->push(mem, *op12);
    f->push(mem, *op13);
    f->push(mem, *op14);
    f->push(mem, *op15);
    f->push(mem, *op16);
    try {
        f->push(mem, *op17);
    } catch (Error &e) {
        std::string s = e.what();
        if (s == "Error : The stack is full")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (pop, pop_stack) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();
    IOperand *op = new Int8(8);

    f->push(mem, *op);
    cr_assert_eq(mem.get_stack().size(), 1);
    f->pop(mem, *op);
    cr_assert_eq(mem.get_stack().size(), 0);

}

Test (pop, pop_empty_stack) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();
    IOperand *unused = NULL;
    int success = 0;

    try {
        f->pop(mem, *unused);
    } catch(Error &e) {
        std::string c = e.what();
        if (c == "Error : Line 1: error: pop on empty stack.")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (clear, clear_empty) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();
    IOperand *unused = NULL;

    f->clear(mem, *unused);
    auto i = mem.get_stack().size();
    cr_assert_eq(i, 0);
}

Test (clear, clear_some) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();
    IOperand *op1 = new Int8(8);
    IOperand *op2 = new Double(55.2);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->clear(mem, *unused);
    auto i = mem.get_stack().size();
    cr_assert_eq(i, 0);
}

Test (swap, normal_swap) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();
    IOperand *op1 = new Int8(32);
    IOperand *op2 = new Int16(32000);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->swap(mem, *unused);

    auto stack = mem.get_stack();
    auto str1 = stack[0]->toString().c_str();
    auto str2 = stack[1]->toString().c_str();
    cr_assert_str_eq(str1, "32000");
    cr_assert_str_eq(str2, "32");
}

Test (assert, assert_true) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();
    IOperand *op = new Float(12.5);
    IOperand *is_same = new Float(12.5);
    int success = 1;

    f->push(mem, *op);
    try {
        f->assert(mem, *is_same);
    } catch (Error &e) {
        std::cout << e.what() << std::endl;
        success = 0;
    }
    cr_assert_eq(success, 1);
}

Test (assert, assert_false1) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op = new Int8(100);
    IOperand *not_same = new Int8(20);
    int success = 0;

    f->push(mem, *op);
    try {
        f->assert(mem, *not_same);
    } catch (Error &e) {
        std::string s = e.what();
        if (s == "Error : Values dont correspond")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (assert, assert_false2) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op = new Int8(100);
    IOperand *not_same = new Float(50.3);
    int success = 0;

    f->push(mem, *op);
    try {
        f->assert(mem, *not_same);
    } catch (Error &e) {
        std::string s = e.what();
        if (s == "Error : The operands are not of the same type")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (add, simple_add_int8) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Int8(40);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
}

Test (add, convert_int8_to_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Int16(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int16)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, convert_int8_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Int32(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, convert_int8_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Float(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, convert_int8_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, simple_add_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(100);
    IOperand *op1 = new Int16(400);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "500");
}

Test (add, convert_int16_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(20);
    IOperand *op1 = new Int32(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, convert_int16_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(20);
    IOperand *op1 = new Float(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, convert_int16_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, simple_add_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(-1000000);
    IOperand *op1 = new Int32(60000);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-940000");
}

Test (add, convert_int32_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(20);
    IOperand *op1 = new Float(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, convert_int32_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, simple_add_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(2.5);
    IOperand *op1 = new Float(4.3);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "6.8");
}

Test (add, convert_float_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "60");
    cr_assert_eq(success, 1);
}

Test (add, simple_add_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Double(20.233);
    IOperand *op1 = new Double(90.5);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->add(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "110.733");
}

///////////

Test (sub, simple_sub_int8) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(40);
    IOperand *op1 = new Int8(20);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->sub(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "20");
}

Test (sub, convert_int8_to_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Int16(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int16)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "20");
    cr_assert_eq(success, 1);
}

Test (sub, convert_int8_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(40);
    IOperand *op1 = new Int32(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, convert_int8_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(40);
    IOperand *op1 = new Float(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, convert_int8_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(40);
    IOperand *op1 = new Double(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, simple_sub_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(400);
    IOperand *op1 = new Int16(100);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->sub(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "300");
}

Test (sub, convert_int16_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(40);
    IOperand *op1 = new Int32(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, convert_int16_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(20);
    IOperand *op1 = new Float(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, convert_int16_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(40);
    IOperand *op1 = new Double(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, simple_sub_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(-1000000);
    IOperand *op1 = new Int32(60000);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->sub(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-1060000");
}

Test (sub, convert_int32_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(40);
    IOperand *op1 = new Float(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, convert_int32_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(40);
    IOperand *op1 = new Double(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, simple_sub_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(2.5);
    IOperand *op1 = new Float(4.3);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->sub(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-1.8");
}

Test (sub, convert_float_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(40);
    IOperand *op1 = new Double(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->sub(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-20");
    cr_assert_eq(success, 1);
}

Test (sub, simple_sub_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Double(20.233);
    IOperand *op1 = new Double(90.5);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->sub(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-70.267");
}

///////////

Test (mul, simple_mul_int8) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(2);
    IOperand *op1 = new Int8(4);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "8");
}

Test (mul, convert_int8_to_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(10);
    IOperand *op1 = new Int16(10);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int16)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "100");
    cr_assert_eq(success, 1);
}

Test (mul, convert_int8_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Int32(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, convert_int8_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Float(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, convert_int8_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, simple_mul_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(20);
    IOperand *op1 = new Int16(40);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
}

Test (mul, convert_int16_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(40);
    IOperand *op1 = new Int32(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, convert_int16_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(20);
    IOperand *op1 = new Float(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, convert_int16_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, simple_mul_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(-100);
    IOperand *op1 = new Int32(600);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "-60000");
}

Test (mul, convert_int32_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op1 = new Float(40);
    IOperand *op2 = new Int32(20);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, convert_int32_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, simple_mul_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(2.5);
    IOperand *op1 = new Float(4.3);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "10.75");
}

Test (mul, convert_float_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(20);
    IOperand *op1 = new Double(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "800");
    cr_assert_eq(success, 1);
}

Test (mul, simple_mul_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Double(20.233);
    IOperand *op1 = new Double(90.5);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mul(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "1831.0865");
}

///////////

Test (div, simple_div_int8) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(8);
    IOperand *op1 = new Int8(2);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "4");
}

Test (div, convert_int8_to_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(10);
    IOperand *op1 = new Int16(10);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int16)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "1");
    cr_assert_eq(success, 1);
}

Test (div, convert_int8_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(2);
    IOperand *op1 = new Int32(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "20");
    cr_assert_eq(success, 1);
}

Test (div, convert_int8_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(2);
    IOperand *op1 = new Float(40);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "20");
    cr_assert_eq(success, 1);
}

Test (div, convert_int8_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(40);
    IOperand *op1 = new Double(5);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "8");
    cr_assert_eq(success, 1);
}

Test (div, simple_div_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(60);
    IOperand *op1 = new Int16(5);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "12");
}

Test (div, convert_int16_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(80);
    IOperand *op1 = new Int32(4);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "20");
    cr_assert_eq(success, 1);
}

Test (div, convert_int16_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(3);
    IOperand *op1 = new Float(8);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "2.667");
    cr_assert_eq(success, 1);
}

Test (div, convert_int16_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(7);
    IOperand *op1 = new Double(4);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "1.75");
    cr_assert_eq(success, 1);
}

Test (div, simple_div_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(600);
    IOperand *op1 = new Int32(100);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "6");
}

Test (div, convert_int32_to_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(3);
    IOperand *op1 = new Float(33);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Float)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "11");
    cr_assert_eq(success, 1);
}

Test (div, convert_int32_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(40);
    IOperand *op1 = new Double(80);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "2");
    cr_assert_eq(success, 1);
}

Test (div, simple_div_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(2.5);
    IOperand *op1 = new Float(4.3);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "0.5814");
}

Test (div, convert_float_to_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(555555);
    IOperand *op1 = new Double(111111);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->div(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Double)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "5");
    cr_assert_eq(success, 1);
}

Test (div, simple_div_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Double(90.5);
    IOperand *op1 = new Double(90.5);
    IOperand *unused = NULL;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->div(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "1");
}

Test (div, civ_zero_int8) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(90);
    IOperand *op1 = new Int8(0);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    try {
        f->div(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Division by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (div, civ_zero_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(90);
    IOperand *op1 = new Int16(0);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    try {
        f->div(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Division by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (div, civ_zero_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(0);
    IOperand *op1 = new Int32(90);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    try {
        f->div(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Division by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (div, civ_zero_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(90);
    IOperand *op1 = new Float(0);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    try {
        f->div(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Division by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (div, civ_zero_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Double(90);
    IOperand *op1 = new Double(0);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    try {
        f->div(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Division by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

///////////

Test (mod, simple_mod_int8) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(8);
    IOperand *op1 = new Int8(2);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->mod(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "0");
}

Test (mod, convert_int8_to_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(10);
    IOperand *op1 = new Int16(10);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->mod(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int16)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "0");
    cr_assert_eq(success, 1);
}

Test (mod, convert_int8_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(4);
    IOperand *op1 = new Int32(6);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    f->mod(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "2");
    cr_assert_eq(success, 1);
}

Test (mod, simple_mod_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(13);
    IOperand *op1 = new Int16(9);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->mod(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "4");
}

Test (mod, convert_int16_to_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(7);
    IOperand *op1 = new Int32(4);
    IOperand *unused = NULL;

    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->mod(mem, *unused);
    if (mem.get_stack()[0]->getType() == _Int32)
        success = 1;
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "3");
    cr_assert_eq(success, 1);
}

Test (mod, simple_mod_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(600);
    IOperand *op1 = new Int32(100);
    IOperand *unused = NULL;

    f->push(mem, *op2);
    f->push(mem, *op1);
    f->mod(mem, *unused);
    cr_assert_str_eq(mem.get_stack()[0]->toString().c_str(), "0");
}

Test (mod, simple_mod_float) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Float(90.5);
    IOperand *op1 = new Float(90.5);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    try {
        f->mod(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Invalid arg for modulo")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (mod, simple_mod_double) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Double(90.5);
    IOperand *op1 = new Double(90.5);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op1);
    f->push(mem, *op2);
    try {
        f->mod(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Invalid arg for modulo")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (mod, mod_zero_int8) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int8(90);
    IOperand *op1 = new Int8(0);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    try {
        f->mod(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Modulo by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (mod, mod_zero_int16) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int16(90);
    IOperand *op1 = new Int16(0);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    try {
        f->mod(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Modulo by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}

Test (mod, mod_zero_int32) {
    Memory mem = Memory();
    FctPtr *f = new FctPtr();

    IOperand *op2 = new Int32(90);
    IOperand *op1 = new Int32(0);
    IOperand *unused = NULL;
    int success = 0;

    f->push(mem, *op2);
    f->push(mem, *op1);
    try {
        f->mod(mem, *unused);
    } catch(Error &e) {
        std::string s = e.what();
        if (s == "Error : Modulo by zero")
            success = 1;
    }
    cr_assert_eq(success, 1);
}