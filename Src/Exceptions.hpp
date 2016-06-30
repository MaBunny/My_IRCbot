#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class Exception : public std::exception
{
protected:
    std::string msg;
public:
    
    Exception() { msg = "Exceptions created"; }
    Exception(const std::string &m)
    {
        msg = m;
    }
    virtual ~Exception(void) {}
    virtual const char* what() { return msg.c_str(); }
};

#endif
