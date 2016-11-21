#include "logger.hpp"

Logger :: Logger(const Logger& lvalue)
{
  try
  {
    logs = lvalue.logs;
    logfile = lvalue.logfile;
  }
  catch(const std::exception& e)
  {
    std::cerr<<"Oops...caught an error!!!\n"
             <<e.what()<<std::endl;
  }
}

Logger :: Logger(Logger&& rvalue)
{
  try
  {
    logs = rvalue.logs;
    logfile = rvalue.logfile;
    rvalue.logs = nullptr;
    rvalue.logfile = nullptr;  
  }
  catch(const std::exception& e)
  {
    std::cerr<<"Oops...caught an error!!!\n"
            <<e.what()<<std::endl;
  }
} 

Logger& Logger :: operator=(const Logger& lvalue)
{
  try
  {
    logs = lvalue.logs;
    logfile = lvalue.logfile;
  }
  catch(const std::exception& e)
  {
    std::cerr<<"Oops...caught an error!!!\n"
             <<e.what()<<std::endl;
  }
  return *this;
}

void Logger :: Log(int state )
{
  if(state!=0 && state!=1)
    throw Exception(static_cast<std::string>("Logger Error: Wrong Log State...\n") + static_cast<std::string>("Log State = ") + std::to_string(state) + static_cast<std::string>(".\n"));

  if(state == APP)
    logstream.open(logfile.c_str(),std::ios::out | std::ios::app);
  else if(state == NON_APP)
    logstream.open(logfile.c_str(),std::ios::out);
      
  logstream<<logs<<std::endl;
  logstream.flush();
      
  logstream.close();
}

void Logger :: Log(const std::string& msg,unsigned int state)
{
  if(state!=0 && state!=1)
    throw Exception(static_cast<std::string>("Logger Error: Wrong Log State...\n") + static_cast<std::string>("Log State = ") + std::to_string(state) + static_cast<std::string>(".\n"));  
    
  if(state == APP)
    logstream.open(logfile.c_str(),std::ios::out | std::ios::app);
  else if(state == NON_APP)
    logstream.open(logfile.c_str(),std::ios::out);
      
  logstream<<msg<<std::endl;
  logstream.flush();
      
  logstream.close();
}

