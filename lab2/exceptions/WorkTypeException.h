//
// Created by unval on 27.12.19.
//

#ifndef LAB2_WORKTYPEEXCEPTION_H
#define LAB2_WORKTYPEEXCEPTION_H

#include <exception>
#include <string>

class WorkTypeException: public std::exception {

private:
    std::string m_error;

public:
    WorkTypeException(std::string error) : m_error(error) {};

    const char* what() const noexcept override { return m_error.c_str(); }
};


#endif //LAB2_WORKTYPEEXCEPTION_H
