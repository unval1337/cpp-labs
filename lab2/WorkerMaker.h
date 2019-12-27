//
// Created by unval on 05.12.19.
//
#pragma once
#ifndef LAB2_WORKERMAKER_H
#define LAB2_WORKERMAKER_H


#include "IWorkerMaker.h"
#include "WorkerFactory.h"

template<typename T>
class WorkerMaker : public IWorkerMaker
{
public:

    WorkerMaker(const std::string & key)
    {
        WorkerFactory::instance().RegisterMaker(key, this);
    }

    virtual IWorker * Create() const
    {
        return new T();
    }
};


#endif //LAB2_WORKERMAKER_H
