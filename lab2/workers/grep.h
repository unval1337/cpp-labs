//
// Created by unval on 26.12.19.
//

#ifndef LAB2_GREP_H
#define LAB2_GREP_H

#include "../IWorker.h"

class grep: public IWorker {

public:
    grep(){};
//    ~grep();

    std::vector<std::string> execute(const std::vector<std::string> &data, const std::vector<std::string> &args) override;
    WorkerType type() override;
};


#endif //LAB2_GREP_H
