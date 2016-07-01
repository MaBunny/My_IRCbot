#ifndef SETTINGS_EXCEPTION_HPP
#define SETTINGS_EXCEPTION_HPP

#include "./Exceptions.hpp"
#include <utility>
#include <iostream>
#include <cstdlib>
#include <memory>

/* Error types:-
 * i)No errors(error type 0)
 * ii)Wrong assignement of port(error type 1) 
 * iii)Wrong assignment of server domain(error type 2)
 * This errors are stored in msg_error variable.
*/

class Settings_Exception : public Exception
{
private:
    unsigned short Port;
    std::string Serv;
    std::string Chan;
    int msg_error;//Stores the error type

    friend class Settings;
  
    void gPort(unsigned short &port) //To be used in a try-catch block 
    { 
        Port = port; 
        CheckPort();
        Catch(); 
    }
    void gServ(std::string &serv) //To be used in a try-catch block
    {   
        Serv = serv; 
        CheckServ();
        Catch(); 
    }
    void gChan(std::string &chan) //To be used in a try-catch block
    { Chan = chan; }
    
    //Helper functions....to be not used by the
    //programmer...just inside this header.
    void CheckServ()   
    {
        std::string a,b,c;
        a = Serv.substr(Serv.size()-3,50);
        //b = Serv.substr(Serv.size()-2,50);
        //c = Serv.substr(Serv.size()-4,50);
        if( a != "com" && a != "net" )   
            { msg_error = 2; }
        else if( a == "com" || a == "net" )
            { msg_error = 0; }
    }  

    //Helper functions....to be not used by the
    //programmer...just inside this header.
    void CheckPort()
    {
	if( Port != 6667 && Port != 6697 )
	    { msg_error = 1; }
        else if( Port == 6667 || Port == 6697 )
            { msg_error = 0; }    
    }
    
    //Helper functions....to be not used by the
    //programmer...just inside this header.
    void WrongPort()
    {
	msg = static_cast<std::string>("Assigned wrong port to the bot.\nPort is: ") + std::to_string(Port) + static_cast<std::string>(".\n");
    }
    
    //Helper functions....to be not used by the
    //programmer...just inside this header. 
    void DomainError()
    {
        msg = static_cast<std::string>("Assigned wrong server to the bot.\nServer is: ") + static_cast<std::string>(Serv) + static_cast<std::string>(".\n"); 
    }

public:
    
    //When using the default one,when you include values by the getter methods
    //put them in a try-catch block.
    Settings_Exception(): Exception() {}
    Settings_Exception(std::string M) : Exception(std::forward<std::string>(M)) {}
    
    //Use only this constructor while initialising with values,else the default
    //one.
    Settings_Exception(std::string serv,std::string chan,unsigned short port) : Exception(), Port(port),Serv(serv) , Chan(chan) 
    {
        CheckPort();  CheckServ();
        Catch();
    }
    
    ~Settings_Exception(void) {}
    const char* what() { return msg.c_str(); }
    void getMsg(std::string &Msg) { msg = Msg; }

    //Returning functions
    unsigned short rPort() { return Port; }
    std::string rServ() { return Serv; }
    std::string rChan() { return Chan; }
    
    //Main code handling errors
    Settings_Exception Catch()
    {
        std::unique_ptr<Settings_Exception> S(new Settings_Exception);
        switch(msg_error)
        {
          case 0:  break;
          case 1:  WrongPort();
                   S->getMsg(msg);
                   //std::exit(EXIT_FAILURE); 
                   break;
          case 2:  DomainError();
                   S->getMsg(msg);
                   //std::exit(EXIT_FAILURE);   
                   break;   
        }  
        throw *S;   
    }
};

#endif
