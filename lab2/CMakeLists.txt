cmake_minimum_required(VERSION 3.12)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp IWorker.h
        WorkerFactory.cpp WorkerFactory.h WorkerMaker.h IWorkerMaker.h
        Parser.cpp Parser.h
        workers/readfile.cpp workers/readfile.h
        workers/writefile.cpp workers/writefile.h
        workers/grep.cpp workers/grep.h
        workers/sort.cpp workers/sort.h
        workers/replace.cpp workers/replace.h
        workers/dump.cpp workers/dump.h exceptions/WorkTypeException.h exceptions/FileException.h)
#add_executable(lab2 main.cpp Parser.cpp Parser.h)