//
// Created by unval on 27.12.19.
//

#ifndef LAB2_FILEEXCEPTION_H
#define LAB2_FILEEXCEPTION_H

#include <exception>
#include <string>

class FileException: public std::exception {

private:
    std::string m_error;

public:
    FileException(std::string error) : m_error(error) {};

    const char* what() const noexcept override { return m_error.c_str(); }
};

#endif //LAB2_FILEEXCEPTION_H
