#ifndef HELPERS_HPP_INCLUDED
#define HELPERS_HPP_INCLUDED

#include <string>
#include <algorithm>

class Settings
    {
private:
    std::string server;
	std::string channel;
	unsigned short port;
	std::string nick;

public:

	Settings() {}
	Settings (Settings &a) : server(a.server), channel(a.channel),
	                         port(a.port), nick(a.nick) {}
	~Settings() {}

	std::string rServer() { return this->server; }
	std::string rChannel() { return this->channel; }
	unsigned short rPort() { return this->port; }
	std::string rNick() { return this->nick; }

	void gServer(std::string &Serv) { server = Serv; }
    void gChannel(std::string &Chan) { channel = Chan; }
    void gPort(unsigned short &Port) { port = Port; }
    void gPort(char* Port) { unsigned int *P = reinterpret_cast<unsigned int*>(Port);
                                   port = *P; }
	void gNick(std::string &Nick) { nick = Nick; }

	//Get the data
	inline void getData(std::string &serv,std::string &chan,
			    unsigned short &p,std::string &n)
	{
	    server = serv; channel = chan; port = p; nick = n;
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
    unsigned int size_Serv;
    unsigned int size_Chan;
    unsigned int size_Port;
    unsigned int size_Nick;
    friend class Settings;

public:
    Metadata() {}
    Metadata(Metadata &a) : size_Serv(a.size_Serv), size_Chan(a.size_Chan),
                            size_Port(a.size_Port), size_Nick(a.size_Nick) {}
    ~Metadata() {}

    unsigned int rSize_Serv() { return size_Serv; }
    unsigned int rSize_Chan() { return size_Chan; }
    unsigned int rSize_Port() { return size_Port; }
    unsigned int rSize_Nick() { return size_Nick; }

    void gSize_Serv(unsigned int &serv) { size_Serv = serv; }
    void gSize_Chan(unsigned int &chan) { size_Chan = chan; }
    void gSize_Port(unsigned int &port) { size_Port = port; }
    void gSize_Nick(unsigned int &nick) { size_Nick = nick; }

    void Set_Sizes(Settings &param)//To be used in Show_Config()
    {
        size_Serv = static_cast<unsigned int>(param.rServer().size());
        size_Chan = static_cast<unsigned int>(param.rChannel().size());
        size_Port = static_cast<unsigned int>(param.rPort());
        size_Nick = static_cast<unsigned int>(param.rNick().size());
    }

    void GetData(unsigned int &serv,unsigned int &chan,unsigned int &port,
                 unsigned int &nick)
    {
        size_Serv = serv; size_Chan = chan; size_Port = port;
        size_Nick = nick;
    }

    void PutData(unsigned int &serv,unsigned int &chan,unsigned int &port,
                 unsigned int &nick)
    {
        serv = size_Serv; chan = size_Chan; port = size_Port;
        nick = size_Nick;
    }

    bool Compare_To(unsigned int &param1,unsigned int &param2)
    {
       if(param1 == param2)
            return true;
       else if(param1 != param2)
            return false;
       return false;
    }

    void clear()
    {
        size_Serv = size_Chan = size_Port = size_Nick = 0;
    }

};


#endif // HELPERS_HPP_INCLUDED
