//
// Created by unval on 26.12.19.
//

#include "sort.h"

std::vector<std::string> sort::execute(const std::vector<std::string> &data, const std::vector<std::string> &args)
{
    std::vector<std::string> strs(data);

    std::sort(strs.begin(), strs.end()); //, [](std::string const & a, std::string const & b) { return a < b; });


    return strs;
}

WorkerType sort::type()
{
    return WorkerType::INOUT;
}
