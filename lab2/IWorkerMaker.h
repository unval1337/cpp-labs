//
// Created by unval on 06.12.19.
//
#pragma once
#ifndef LAB2_IWORKERMAKER_H
#define LAB2_IWORKERMAKER_H

#include <string>

class IWorker;

class IWorkerMaker
{
public:
    virtual IWorker * Create() const = 0;
    virtual ~IWorkerMaker() {};
};

#endif //LAB2_IWORKERMAKER_H
