#ifndef HELPERS_HPP_INCLUDED
#define HELPERS_HPP_INCLUDED

#include <string>
#include <algorithm>
#include "settings_exception.hpp"
 
class Settings
    {
private:
        std::string server;
	std::string channel;
	unsigned int port;
	std::string nick;
        Settings_Exception *SE;
 
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
	inline bool Compare_To(unsigned int param1,unsigned int param2)
	{
	    if( param1 == param2 )
		return true;
	    else if ( param1 != param2 )
		return false;
	}
	//Clear the contents of the variables
	inline void Clear()
	{
	    server.clear();
	    channel.clear();
	    nick.clear();
	    port = 0;
            logger.GetLogs(static_cast<std::string>("In Settings class: Cleared the data members."));
            logger.Log(0);
	} 

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
            std::string Msg;
            
            Msg = static_cast<std::string>("In Settings class: Created a Settings object with server = ") + a.server +  static_cast<std::string>(",Channel = ") + a.channel + static_cast<std::string>(",Port = ") + std::to_string(a.port) + static_cast<std::string>(",Nick = ") + a.nick + static_cast<std::string>(".");

            logger.GetLogs(Msg);
            Msg = static_cast<std::string>("In Settings class: Created an Settings_Exception object with Server= ") + a.server + static_cast<std::string>("\n and Port = ") + std::to_string(a.port) + static_cast<std::string>(".");

            logger.GetLogs(Msg);
            logger.Log(0);
      }
        
        Settings& operator=(const Settings& lvalue)
        {
        	   try
        	   {
        	   	  server.assign(lvalue.server);
        	   	  channel.assign(lvalue.channel);
        	   	  nick.assign(lvalue.nick);
        	   	  port = lvalue.port;
                          return *this;
        	   }
        	   catch(std::exception& e)
                   {
       	             std::cout<<"Oops...caught an error !!!"<<std::endl
                              <<e.what()<<std::endl;
                   }
                   return *this;
        }
        
        Settings(std::string &Serv,std::string &Chan,unsigned int &Port,
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
            std::string Msg;
           
            Msg = static_cast<std::string>("In Settings class: Created a Settings object with server = ") + Serv +  static_cast<std::string>(",Channel = ") + Chan + static_cast<std::string>(",Port = ") +std::to_string(Port) + static_cast<std::string>(",Nick = ") +Nick+ static_cast<std::string>(".");
 
            logger.GetLogs(Msg);
           
            Msg = static_cast<std::string>("In Settings class: Created an Settings_Exception object with Server= ") + Serv + static_cast<std::string>("\n and Port = ") + std::to_string(Port) + static_cast<std::string>(".");  
           
            logger.GetLogs(Msg);
            logger.Log(0);
        } 
	~Settings() { delete SE; }

	std::string RetServer() { return this->server; }
	std::string RetChannel() { return this->channel; }
	unsigned short RetPort() { return this->port; }
	std::string RetNick() { return this->nick; }

	void GetServer(std::string &Serv) 
        { 
          server = Serv; 
          try { SE->GetServ(server); }
          catch(Settings_Exception &S)
          {
              std::cout<<"Oops....found an error!!!\n";
              std::cout<<S.what()<<std::endl;
          }   
          logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Server = ") + Serv +static_cast<std::string>(".")); 
          logger.Log(0);  
        }
        void GetChannel(std::string &Chan) 
        { 
          channel = Chan;
          logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Channel = ") + Chan +static_cast<std::string>("."));
          logger.Log(0);
        }
        void GetPort(unsigned int &Port) 
        { 
          port = Port; 
          try { SE->GetPort(port); }
          catch(Settings_Exception &S)
          {
              std::cout<<"Oops....found an error!!!\n";
              std::cout<<S.what()<<std::endl;
          }     
          logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Port = ") + std::to_string(Port) +static_cast<std::string>(".")); 
          logger.Log(0);
        }
	void GetNick(std::string &Nick) 
        { 
          nick = Nick;
          logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Nick = ") + Nick +static_cast<std::string>(".")); 
          logger.Log(0);
        }

	//Get the data
	inline void GetData(std::string &serv,std::string &chan,
			    unsigned int &p,std::string &n)
	{
	    server = serv; channel = chan; port = p; nick = n;
            try
            {
               SE->GetServ(server); SE->GetPort(port);
            }
            catch(Settings_Exception &S)
            {
              std::cout<<"Oops....found an error!!!\n";
              std::cout<<S.what()<<std::endl;
            }  
            logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Server = ") + serv +static_cast<std::string>(".")); 
            logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Channel = ") + chan +static_cast<std::string>(".")); 
            logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Port = ") + std::to_string(p) +static_cast<std::string>(".")); 
            logger.GetLogs(static_cast<std::string>("In Settings class: Used get function to store Nick  = ") + n +static_cast<std::string>(".")); 
           
	}
	inline void PutData(std::string &serv,std::string &chan,
			    unsigned int &p,std::string &n)
	{
	    serv = server; chan = channel; p = port; n = nick;
            logger.GetLogs(static_cast<std::string>("In Settings class: Used put function to return Server = ") + server + static_cast<std::string>(",Channel = ") + channel + static_cast<std::string>(",Port = ") + std::to_string(port) + static_cast<std::string>(",Nick = ") + nick + static_cast<std::string>(".")); 
          logger.Log(0); 
	}
};

class Metadata
{
private:
    unsigned int count = 0;
    friend class Config;

    void Cear()
    {
       count = 0;
    }
    void GetCount(unsigned int &Count) 
    { 
       count = Count; 
       logger.GetLogs(static_cast<std::string>("In Metadata class: Inputed the number of Counts as: ") + std::to_string(count));
       logger.Log(0);
    }
    void UpCount() 
    { 
       count++;
       logger.GetLogs(static_cast<std::string>("In Metadata class: Updated Count by one. "));
       logger.Log(0);  
    }    

public:
    Metadata() { count=0; }
    Metadata(Metadata &a) : count(a.count) {}
    ~Metadata() {}

    unsigned int RetCount() { return count; }

    bool Compare_To(unsigned int &param1,unsigned int &param2)
    {
       if(param1 == param2)
            return true;
       else if(param1 != param2)
            return false;
       return false;
    }
};


#endif // HELPERS_HPP_INCLUDED
