//
// Created by unval on 06.12.19.
//

#include "writefile.h"

std::vector<std::string> writefile::execute(const std::vector<std::string> &data, const std::vector<std::string> &args)
{

    std::ofstream file;
    file.open(args[1]);
    file << data;

    file.close();

    return {"end"};

}

WorkerType writefile::type()
{
    return WorkerType::OUT;
}
