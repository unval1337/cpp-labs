//
// Created by unval on 26.12.19.
//

#ifndef LAB2_SORT_H
#define LAB2_SORT_H

#include "../IWorker.h"

#include <algorithm>

class sort: public IWorker  {

public:
    sort(){};
//    ~sort();

    std::vector<std::string> execute(const std::vector<std::string> &data, const std::vector<std::string> &args) override;
    WorkerType type() override;
};


#endif //LAB2_SORT_H
