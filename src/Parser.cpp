/*
** EPITECH PROJECT, 2021
** parser
** File description:
** parser
*/

#include "Parser.hpp"
#include "ErrUnknowCommand.hpp"

Parser::Parser(Memory &mem) : Mem(mem) {
    FunctionPointers = new FctPtr();

    InitSupportedTypes();
}

void Parser::InitSupportedTypes() {
    SupportedTypes["int8"] = _Int8;
    SupportedTypes["int16"] = _Int16;
    SupportedTypes["int32"] = _Int32;
    SupportedTypes["float"] = _Float;
    SupportedTypes["double"] = _Double;
}

eOperandType Parser::StrToType(std::string type) {
    if (SupportedTypes.find(type) != SupportedTypes.end())
        return (SupportedTypes[type]);
    throw (new Error("type not found", __FILE__, __LINE__));
}

Parser::~Parser() {
    delete(FunctionPointers);
}

void Parser::parse_line(std::string &line) {

    std::regex simpleCommand("^\\s*(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print)\\s*(;.*)?");
    std::regex complexCommandInteger("^\\s*(push|assert|load|store)\\s*(int8|int16|int32)\\(([-]?[0-9]+)\\)\\s*(;.*)?");
    std::regex complexCommandDecimal("^\\s*(push|assert|load|store)\\s*(float|double)\\(([-]?[0-9]+[.]?[0-9]*)\\)\\s*(;.*)?");
    std::regex exitRegex("^\\s*(exit(\\s*;.*)?)");
    std::regex endOfManualInput("^\\s*(;;)(\\s+;.*)?");
    std::regex commentary("^\\s*(;.*)");

    std::smatch matchs;
    IOperand *unused = NULL;
    Factory fact;

    if (std::regex_search(line, matchs, simpleCommand)) {
        FunctionPointers->find_comms(matchs[1], Mem, *unused);
        return;
    }
    if (std::regex_search(line, matchs, complexCommandInteger)) {
        FunctionPointers->find_comms(matchs[1], Mem, *fact.createOperand(StrToType(matchs[2]), matchs[3]));
        return;
    }
    if (std::regex_search(line, matchs, complexCommandDecimal)) {
        FunctionPointers->find_comms(matchs[1], Mem, *fact.createOperand(StrToType(matchs[2]), matchs[3]));
        return;
    }
    if (std::regex_search(line, matchs, exitRegex)) {
        FunctionPointers->find_comms(matchs[1], Mem, *unused);
        return;
    }
    if (std::regex_search(line, matchs, endOfManualInput)) {
        exit(EXIT_SUCCESS);
    }
    if (std::regex_search(line, matchs, commentary)) {
        return;
    }
    throw (ErrUnknownCommand());
}