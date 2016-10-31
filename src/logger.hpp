#ifndef LOGGER_HPP
#define LOGGER_HPP

/* Defines the Logger class
 * which logs the contents
 * of the program to disk.
 */

#include <fstream>
#include <string>
#include "exception.hpp"
#include <iostream>

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
   Logger(const Logger& lvalue); //copy constructor
   
   
   Logger(Logger&& rvalue); //move constructor
   
      
   virtual Logger& operator=(const Logger& lvalue); 
        
   
   
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

   void Log(int state = 0);
      

   void Log(const std::string& msg,unsigned int state=0);
   
}; 
    

#endif

  



