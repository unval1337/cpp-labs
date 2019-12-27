//
// Created by unval on 26.12.19.
//

#ifndef LAB2_DUMP_H
#define LAB2_DUMP_H

#include "../IWorker.h"

#include <fstream>

class dump: public IWorker {

public:
    dump(){};
//    ~dump();

    std::vector<std::string> execute(const std::vector<std::string> &data, const std::vector<std::string> &args) override;
    WorkerType type() override;
};


#endif //LAB2_DUMP_H
