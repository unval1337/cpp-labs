
#include "WorkerMaker.h"
//#include "WorkerFactory.h"
#include "Parser.h"
#include "workers/readfile.h"
#include "workers/writefile.h"
#include "workers/grep.h"
#include "workers/sort.h"
#include "workers/replace.h"
#include "workers/dump.h"
#include <iostream>

#include "exceptions/WorkTypeException.h"



//REGISTER_WORKER(writefile);
//REGISTER_WORKER(grep);
//REGISTER_WORKER(sort);
//REGISTER_WORKER(replace);
//REGISTER_WORKER(dump);

int main() {
    static WorkerMaker<readfile> maker("readfile");
    static WorkerMaker<writefile> maker1("writefile");
    static WorkerMaker<grep> maker2("grep");
    static WorkerMaker<sort> maker3("sort");
    static WorkerMaker<replace> maker4("replace");
    static WorkerMaker<dump> maker5("dump");


    std::string infile("/home/unval/CLionProjects/c++/lab2/workflow.txt");
    Parser p(infile);

    auto blocks = p.getMapOfstrings();
    auto nodes = p.getNodes();



    WorkerType prev = WorkerType::INIT;
    std::vector<std::string> data;


    for(int i = 0; i < nodes.capacity(); i++)
    {
        auto worker = WorkerFactory::instance().Create(blocks[nodes[i]][0]);
        if(worker->type() < prev || (worker->type() != WorkerType::INOUT && worker->type() == prev))
        {
            throw WorkTypeException("Uncorrect type of worker");
        }

        data = worker->execute(data, blocks[nodes[i]]);
        prev = worker->type();
    }

    return 0;
}