//
// Created by unval on 26.12.19.
//

#include "dump.h"

std::vector<std::string> dump::execute(const std::vector<std::string> &data, const std::vector<std::string> &args)
{

    std::ofstream file;
    file.open(args[1]);
    file << data;

    file.close();

    return data;

}

WorkerType dump::type()
{
    return WorkerType::INOUT;
}
