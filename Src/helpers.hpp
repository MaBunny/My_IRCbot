#ifndef HELPERS_HPP_INCLUDED
#define HELPERS_HPP_INCLUDED

#include <string>
#include <algorithm>
#include "./Settings_Exceptions.hpp"
 
class Settings
    {
private:
        std::string server;
	std::string channel;
	unsigned short port;
	std::string nick;
        Settings_Exception *SE;
        //friend class Config;
 
public:

	Settings() { SE = new Settings_Exception; }
	Settings (Settings &a) : server(a.server), channel(a.channel),
	                         port(a.port), nick(a.nick) 
        {
            try
            {
                SE = new Settings_Exception(a.server,a.port);
            }
            catch(Settings_Exception &S)
            {
                std::cout<<"Oops....found an error!!!\n";
                std::cout<<S.what()<<std::endl; 
            }
        }
        Settings(std::string &Serv,std::string &Chan,unsigned short &Port,
           std::string &Nick): server(Serv),channel(Chan),port(Port),nick(Nick)
        {
            try 
            {
                SE = new Settings_Exception(Serv,Port);
            } 
            catch(Settings_Exception &S)
            {
                std::cout<<"Oops....found an error!!!\n";
                std::cout<<S.what()<<std::endl; 
            } 
        } 
	~Settings() { delete SE; }

	std::string rServer() { return this->server; }
	std::string rChannel() { return this->channel; }
	unsigned short rPort() { return this->port; }
	std::string rNick() { return this->nick; }

	void gServer(std::string &Serv) 
        { 
          server = Serv; 
          try { SE->getServ(server); }
          catch(Settings_Exception &S)
          {
              std::cout<<"Oops....found an error!!!\n";
              std::cout<<S.what()<<std::endl;
          }    
        }
        void gChannel(std::string &Chan) 
        { channel = Chan;  }
        void gPort(unsigned short &Port) 
        { 
          port = Port; 
          try { SE->getPort(port); }
          catch(Settings_Exception &S)
          {
              std::cout<<"Oops....found an error!!!\n";
              std::cout<<S.what()<<std::endl;
          }     
        }
	void gNick(std::string &Nick) { nick = Nick; }

	//Get the data
	inline void getData(std::string &serv,std::string &chan,
			    unsigned short &p,std::string &n)
	{
	    server = serv; channel = chan; port = p; nick = n;
            try
            {
               SE->getServ(server); SE->getPort(port);
            }
            catch(Settings_Exception &S)
            {
              std::cout<<"Oops....found an error!!!\n";
              std::cout<<S.what()<<std::endl;
            }  
	}
	inline void putData(std::string &serv,std::string &chan,
			    unsigned short &p,std::string &n)
	{
	    serv = server; chan = channel; p = port; n = nick;
	}
        //Compare two strings
	inline bool Compare_To(std::string param1,std::string param2)
	{
	    std::transform(param1.begin(),param1.end(),param1.begin(),
			   std::ptr_fun<int,int>(std::toupper));
	    std::transform(param2.begin(),param2.end(),param2.begin(),
			   std::ptr_fun<int,int>(std::toupper));
	    if( param1.compare(param2) == 0 )
		return true;
	    else if( param1.compare(param2) != 0 )
                return false;
	}
	//Compare two unsigned shorts
	inline bool Compare_To(unsigned short param1,unsigned short param2)
	{
	    if( param1 == param2 )
		return true;
	    else if ( param1 != param2 )
		return false;
	}
	//Clear the contents of the variables
	inline void clear()
	{
	    server.clear();
	    channel.clear();
	    nick.clear();
	    port = 0;
	}
};

class Metadata
{
private:
    unsigned int count;
    friend class Config;

    void clear()
    {
       count = 0;
    }
    void gCount(unsigned int &Count) { count = Count; }
    void upCount() { ++count; }    

public:
    Metadata() {}
    Metadata(Metadata &a) : count(a.count) {}
    ~Metadata() {}

    unsigned int rCount() { return count; }

    bool Compare_To(unsigned int &param1,unsigned int &param2)
    {
       if(param1 == param2)
            return true;
       else if(param1 != param2)
            return false;
       return false;
    }

    std::streamsize size()
    {
	return  sizeof(Metadata);
    }
};


#endif // HELPERS_HPP_INCLUDED
