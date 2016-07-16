#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <utility>

class Exception : public std::runtime_error
{   
protected:   
    std::string _msg;
  
public:
    
    Exception(): std::runtime_error("Created Exception.\n") {}
    Exception(const std::string &m) : std::runtime_error(m), _msg(m) {}
    
    virtual ~Exception(void) {}
    virtual const char* what() const noexcept { return _msg.c_str(); }
    
    //Copy Constructor  
    Exception(const Exception &lvalue_copy): std::runtime_error(lvalue_copy._msg)
    {
       try
        {
           _msg = lvalue_copy._msg;
        }
        catch(...)
        {
           throw; 
        }
    }
   
    //Move Constructor
    Exception(Exception&& rvalue): std::runtime_error(rvalue._msg) 
    {
        try
        {
           _msg = rvalue._msg;
           rvalue._msg = nullptr;
        }
        catch(...)
        { throw; } 
    }
   
    //Assignment Operator
    virtual Exception& operator=(const Exception& lvalue) 
    {
        try
        {   
           _msg = lvalue._msg; 
           return *this;
        }
        catch(...)
        { throw; }
    }
   
    //Move assignment
    virtual Exception& operator=(Exception &&rvalue) 
    {
        try
        {
           std::swap(_msg,rvalue._msg);  
           return *this;
        }
        catch(...)
        { throw; }
    }  
};

#endif
