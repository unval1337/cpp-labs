//
// Created by unval on 05.12.19.
//

#ifndef LAB2_PARSER_H
#define LAB2_PARSER_H

#include "exceptions/FileException.h"

#include <map>
#include <vector>
#include <fstream>
#include <iostream>

class Parser {
    std::string _infile;
    std::map<int, std::vector<std::string>> _blocks;
    std::vector<int> _nodes;
public:
    std::map<int, std::vector<std::string>> getMapOfstrings() const;
    std::vector<int> getNodes() const;

    Parser(std::string& nameOfFile);
    void Print();
};


std::vector<std::string> devideStringOnDelim(const std::string& str, const std::string& delim);

#endif //LAB2_PARSER_H
