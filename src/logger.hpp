#ifndef LOGGER_HPP
#define LOGGER_HPP

/* Defines the Logger class
 * which logs the contents
 * of the program to disk.
 */

#include <fstream>
#include <string>
#include "./exception.hpp"


class Logger
{
private:
   std::string logs;
   std::string logfile;
   std::fstream logstream;
   enum LOG_STATES { APP = 0, NON_APP };


public:
/*  
  Logger() 
   { 
      try
      {
         logs = " "; 
         logfile = "./log.log"; 
      }
      catch(const std::exception& e)
      {
         std::cerr<<"Oops...caught an error!!!\n"
                  <<e.what()<<std::endl;
      }
   }  
*/

   Logger(const std::string& Logfile = "./log.log")
   {
      try
      {
         logs = " ";
         logfile = Logfile;
      }
      catch(const std::exception& e)
      {
         std::cerr<<"Oops...caught an error!!!\n"
                  <<e.what()<<std::endl;
      }
   }
   
/* Logger(const char* Logfile = "./log.log")
   {
      try
      {
         logs = " ";
         logfile.assign(Logfile);
      }
      catch(const std::exception& e)
      {
         std::cerr<<"Oops...caught an error!!!\n"
                  <<e.what()<<std::endl;
      }
   }
*/   
   Logger(const Logger& lvalue)
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
   
   Logger(Logger&& rvalue)
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
      
   virtual Logger& operator=(const Logger& lvalue)
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
   
   
   virtual void getLogs(const std::string& msg)
   {
      logs = msg;
      logs += "\n";  
   }
   
   virtual void getLogs(const char* msg)
   {
      logs.assign(msg);
      logs += "\n";
   }   

   void Log(int state = 0)
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

   void Log(const std::string& msg,unsigned int state=0)
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

}; 
    

#endif

  



