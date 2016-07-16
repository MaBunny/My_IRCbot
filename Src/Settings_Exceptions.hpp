#ifndef SETTINGS_EXCEPTION_HPP
#define SETTINGS_EXCEPTION_HPP

#include "./Exceptions.hpp"
#include <utility>
#include <iostream>
#include <cstdlib>

class Settings_Exception : public Exception
{
private:
    unsigned short Port;
    std::string Serv;

    friend class Settings;
     
    void getPort(const unsigned short& port)
    {   
       try
       {
          Port = port;
          if(Port !=6667 && Port !=6697)
             throw Settings_Exception("Oops....Wrong port assigned !!!\n");
       }
       catch(Settings_Exception& error)
       {
            std::cout<<"Oops...Caught an error !!!"<<std::endl
                     <<error.what()<<std::endl;
       }
       catch(const std::exception &e)
        {
            std::cout<<"Oops...caught an error !!!"<<std::endl
                     <<e.what()<<std::endl;
        }
        catch(...)
        {
            std::cout<<"Oops...caught an error !!!"<<std::endl;
        }  
    }
    
    void getServ(const std::string& serv)
    {
       try
       {
          Serv = serv;
          if( Serv.substr(Serv.size()-3,100) != "com" && Serv.substr(Serv.size()-3,100) != "net")
               throw Settings_Exception("Oops....Wrong server assigned !!!\n");  
        }
        catch(Settings_Exception& error)
        {
            std::cout<<"Oops...Caught an error !!!"<<std::endl
                     <<error.what()<<std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout<<"Oops...caught an error !!!"<<std::endl
                     <<e.what()<<std::endl;
        }
        catch(...)
        {
            std::cout<<"Oops...caught an error !!!"<<std::endl;
        }   
    }   
      
public:
    
    Settings_Exception(): Exception() {}
    Settings_Exception(std::string M) : Exception(std::forward<std::string>(M)) {}
    
    //Use only this constructor while initialising with values,else the default
    //one.
    Settings_Exception(std::string serv,unsigned short port) : Exception()
    {
        try
        {
            Port = port; Serv = serv;
            if(Port != 6667 && Port != 6697)
               throw Settings_Exception("Oops....Wrong port assigned !!!\n");
            else if( Serv.substr(Serv.size()-3,100) != "com" && Serv.substr(Serv.size()-3,100) != "net")
               throw Settings_Exception("Oops....Wrong server assigned !!!\n");  
        }
        catch(Settings_Exception& error)
        {
            std::cout<<"Oops...Caught an error !!!"<<std::endl
                     <<error.what()<<std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout<<"Oops...caught an error !!!"<<std::endl
                     <<e.what()<<std::endl;
        }
        catch(...)
        {
            std::cout<<"Oops...caught an error !!!"<<std::endl;
        }   
    }
    
    ~Settings_Exception(void) {}
    const char* what() { return _msg.c_str(); }
    void getMsg(std::string &Msg) { this->_msg = Msg; }

    //Returning functions
    unsigned short rPort() { return Port; }
    std::string rServ() { return Serv; }
    
};

#endif
