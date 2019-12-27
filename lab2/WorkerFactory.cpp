//
// Created by unval on 05.12.19.
//

#include "WorkerFactory.h"
#include "IWorkerMaker.h"
#include "IWorker.h"


void WorkerFactory::RegisterMaker(const std::string &key, IWorkerMaker *maker)
{
    if (_makers.find(key) != _makers.end())
    {
        throw std::logic_error("Multiple makers for given key!");
    }
    _makers[key] = maker;
}

WorkerFactory& WorkerFactory::instance()
{
    static WorkerFactory factory;
    return factory;
}

IWorker* WorkerFactory::Create(std::string& name) const
{
//    std::string key(name);
    auto i = _makers.find(name);

    if(i == _makers.end())
    {
        throw std::logic_error("Unrecognized object type!");
    }

    IWorkerMaker* maker = i->second;
    return  maker->Create();
}