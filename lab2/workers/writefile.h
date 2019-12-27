//
// Created by unval on 06.12.19.
//

#ifndef LAB2_WRITEFILE_H
#define LAB2_WRITEFILE_H


#include "../IWorker.h"

#include <fstream>

class writefile: public IWorker {

public:
    writefile(){};
//    ~writefile();

    std::vector<std::string> execute(const std::vector<std::string> &data, const std::vector<std::string> &args) override;
    WorkerType type() override;

};

#endif //LAB2_WRITEFILE_H
