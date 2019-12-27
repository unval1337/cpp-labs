//
// Created by unval on 05.12.19.
//

#include "Parser.h"

Parser::Parser(std::string &nameOfFile)
{
    _infile = nameOfFile;

    std::ifstream file;
    file.open(_infile);
    if(!file)
    {
        throw FileException("Cant open file " + _infile);
    }

    std::vector<std::string> strings;
    std::string str;
    while(!file.eof())
    {
        getline(file, str);
        strings.push_back(str);
    }


    for(int i = 1; i < strings.capacity()-2; i++)
    {
        auto s = strings[i];

        std::vector<std::string> pair = devideStringOnDelim(s, " = ");
        std::vector<std::string> s1 = devideStringOnDelim(pair[1], " ");

        _blocks[std::stoi(pair[0])] = s1;
    }

    auto n = strings[strings.capacity()-1];
    std::vector<std::string> strNodes = devideStringOnDelim(n, " -> ");
    for(auto s: strNodes) _nodes.push_back(std::stoi(s));


    this->Print();
}

std::map<int, std::vector<std::string>> Parser::getMapOfstrings() const
{
    return _blocks;
}

std::vector<int> Parser::getNodes() const
{
    return _nodes;
}

void Parser::Print()
{
    for(auto s : _blocks)
    {
        std::cout << s.first << " ";

        for(auto str: s.second)
        {
            std::cout << str << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;


    for(auto i: _nodes)
    {
        std::cout << i << " " << std::endl;
    }
}


std::vector<std::string> devideStringOnDelim(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;

    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();

        std::string token = str.substr(prev, pos-prev);

        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }

    while (pos < str.length() && prev < str.length());

    return tokens;
}