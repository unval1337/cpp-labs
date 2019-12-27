//
// Created by unval on 26.12.19.
//

#include "grep.h"

std::vector<std::string> grep::execute(const std::vector<std::string> &data, const std::vector<std::string> &args)
{
    std::vector<std::string> strs;

    for(auto& s: data)
    {
        if(s.find(args[1]) != std::string::npos)
        {
            strs.push_back(s);
        }
    }

    return strs;
}

WorkerType grep::type()
{
    return WorkerType::INOUT;
}
