#ifndef LOGGER_HPP
#define LOGGER_HPP

/* Defines the Logger class
 * which logs the contents
 * of the program to disk.
 */

#include <fstream>
#include <string>
#include <exception>


class Logger
{
private:
   std::string logs;
   std::string logfile;
   std::fstream logstream;
   enum LOG_STATES { APP = 0, NON_APP };
 
public:
   Logger() 
   { 
      try
      {
         logs = " "; 
         logfile = " "; 
      }
      catch(const std::exception& e)
      {
         std::cerr<<"Oops...caught an error!!!\n"
                  <<e.what()<<std::endl;
      }  
   Logger(std::string Logfile)
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
         logs = lvalue.logs;
         logfile = lvalue.logfile;
         lvalue.logs = nullptr;
         lvalue.logfile = nullptr;  
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
         return *this;
      }
      catch(const std::exception& e)
      {
         std::cerr<<"Oops...caught an error!!!\n"
                  <<e.what()<<std::endl;
      }
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
   
   void Log(unsigned in state = 0)
   {
      if(state == APP)
        logstream.open(logfile.c_str(),std::ios::out | std::ios::app);
      else
        logstream.open(logfile.c_str(),std::ios::out);
      
      logstream<<logs<<std::endl;
      logstream.flush();
      
      logstream.close();
   }   
   void Log(const std::string& msg,unsigned int state=0)
   {
      if(state == APP)
        logstream.open(logfile.c_str(),std::ios::out | std::ios::app);
      else
        logstream.open(logfile.c_str(),std::ios::out);
      
      logstream<<msg<<std::endl;
      logstream.flush();
      
      logstream.close();
   }
   
   void Log(const char* msg,unsigned int state=0)
   {
      if(state == APP)
        logstream.open(logfile.c_str(),std::ios::out | std::ios::app);
      else
        logstream.open(logfile.c_str(),std::ios::out);
      
      logstream<<&msg<<std::endl;
      logstream.flush();
     
      logstream.close();
   }

}; 
    



  



