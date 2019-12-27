//
// Created by unval on 03.12.19.
//
#pragma once
#ifndef LAB2_IWORKER_H
#define LAB2_IWORKER_H

//#include "WorkerMaker.h"
//#define REGISTER_WORKER(T) static WorkerMaker<T> maker(#T);

#include <vector>
#include <string>
#include <iostream>

enum class WorkerType
{
    INIT,
    IN,
    INOUT,
    OUT,

};

class IWorker
{
public:
    virtual std::vector<std::string> execute(const std::vector<std::string> &data, const std::vector<std::string> &args) = 0;
    virtual WorkerType type() = 0;

    virtual ~IWorker() = default;
};


template <typename T>
std::ostream& operator<< (std::ostream &out, const std::vector<T> &v)
{

    for(auto& s: v)
    {
        out << s << std::endl;
    }

    return out;
}


#endif //LAB2_IWORKER_H
