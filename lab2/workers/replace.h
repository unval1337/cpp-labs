//
// Created by unval on 26.12.19.
//

#ifndef LAB2_REPLACE_H
#define LAB2_REPLACE_H

#include "../IWorker.h"


class replace: public IWorker  {

public:
    replace(){};
//    ~replace();

    std::vector<std::string> execute(const std::vector<std::string> &data, const std::vector<std::string> &args) override;
    WorkerType type() override;
};


#endif //LAB2_REPLACE_H
