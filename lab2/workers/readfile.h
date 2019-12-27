//
// Created by unval on 06.12.19.
//

#pragma once
#ifndef LAB2_READFILE_H
#define LAB2_READFILE_H

#include "../IWorker.h"
#include "../exceptions/FileException.h"
#include <fstream>

class readfile: public IWorker {

public:
    readfile() {};
//    ~readfile();

    std::vector<std::string> execute(const std::vector<std::string> &data, const std::vector<std::string> &args) override;
    WorkerType type() override;
};



#endif //LAB2_READFILE_H
