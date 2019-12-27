//
// Created by unval on 05.12.19.
//
#pragma once
#ifndef LAB2_WORKERFACTORY_H
#define LAB2_WORKERFACTORY_H

#include "IWorker.h"
#include "IWorkerMaker.h"
#include <exception>
#include <map>

class WorkerFactory
{
    WorkerFactory(){};
    WorkerFactory(const WorkerFactory& other);
    WorkerFactory& operator =(const WorkerFactory& other);

    std::map<std::string, IWorkerMaker*> _makers;
public:
    static WorkerFactory& instance();
    IWorker* Create(std::string& name) const;

    void RegisterMaker(const std::string& key, IWorkerMaker * maker);
};


#endif //LAB2_WORKERFACTORY_H
