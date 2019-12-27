//
// Created by unval on 26.12.19.
//

#include "replace.h"

std::vector<std::string> replace::execute(const std::vector<std::string> &data, const std::vector<std::string> &args)
{
    std::vector<std::string> strs;

    std::string s;
    for(auto& d: data)
    {
        s = "";
        size_t start = 0;
        size_t end = 0;
        while((end = d.find(args[1], start)) != std::string::npos)
        {
            s += d.substr(start, end-start) + args[2];
            start = end + args[2].size();
        }
        if(s.empty()) s = d;

        strs.push_back(s);
    }


    return strs;
}

WorkerType replace::type()
{
    return WorkerType::INOUT;
}
