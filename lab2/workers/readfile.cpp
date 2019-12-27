//
// Created by unval on 06.12.19.
//

#include "readfile.h"

std::vector<std::string> readfile::execute(const std::vector<std::string> &data, const std::vector<std::string> &args)
{
    std::ifstream file;

    file.open(args[1]);
    if(!file.is_open())
    {
        throw FileException("Cant open file " + args[1]);
    }

    std::vector<std::string> strs;
    std::string s;
    while(getline(file, s))
    {
        strs.push_back(s);
    }

    file.close();

    return strs;
}

WorkerType readfile::type()
{
    return WorkerType::IN;
}

