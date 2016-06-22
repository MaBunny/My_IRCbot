#include "./config.hpp"
#include <iostream>

Settings Config :: GetInput()
{
    std::string s,c,n;
    unsigned short p;
    Settings sett;
    std::cout<<"Enter the server IPv4 address:  ";
    std::cin>>s;  std::cout<<"\n";
    std::cout<<"Enter the channel name(eg, #debian ):  ";
    std::cin>>c; std::cout<<"\n";
    std::cout<<"Enter the port to connect to(best: 6667):  ";
    std::cin>>p;std::cout<<"\n";
    std::cout<<"Enter the nickname for that channel:  ";
    std::cin>>n; std::cout<<"\n";

    sett.getData(s,c,p,n);
    return sett;
}

void Config :: PutInput(Settings &sett)
{
    std::string s,n,c;
    unsigned short p;
    sett.putData(s,c,p,n);
    std::cout<<"The server IPv4 address is: "<<s<<std::endl
	         <<"The channel name for that server is: "<<c<<std::endl
             <<"The port used to connect is: "<<p<<std::endl
             <<"The nickname for that channel is: "<<n<<std::endl;
}

//----------------------------------------------------------------------------------


Metadata Config:: ReadMetadata()
{

    m_stream.open(meta_file.c_str(), std::ios::in);
    Metadata m;

    if( !m_stream.is_open() )
        throw (std::string) "Error....open file for read/write ops!!!";
    if(m_stream.bad())
        throw;
    if(m_stream.fail())
        throw;

    /* Read the data from the meta_file.
       Reason why std::string not used is tht it will through
       away precision when cast from const char* to char and
       char to unsigned int.
    */
    unsigned int serv,chan,port,nick;
    m_stream.getline((char*)&serv,5,'\n');
    m_stream.getline((char*)&chan,5,'\n');
    m_stream.getline((char*)&port,5,'\n');
    m_stream.getline((char*)&nick,5,'\n');

    m.GetData(serv,chan,port,nick);

    m_stream.close();

    return m;
}


//----------------------------------------------------------------------------------


void Config :: WriteMetadata(Metadata &m)
{

    m_stream.open(meta_file.c_str(), std::ios::out);

    if( !m_stream.is_open() )
        throw (std::string) "Error....open file for read/write ops!!!";
    if(m_stream.bad())
        throw;
    if(m_stream.fail())
        throw;

    m_stream<<m.rSize_Serv()<<std::endl
            <<m.rSize_Chan()<<std::endl
            <<m.rSize_Port()<<std::endl
            <<m.rSize_Nick()<<std::endl;
    m_stream.flush();

    m_stream.close();
}

//----------------------------------------------------------------------------------

std::streamsize Config :: ReadSize()
{

    m_stream.open(meta_file.c_str(),std::ios::in);
    std::streamsize Size;
    m_stream.ignore(std::numeric_limits<std::streamsize>::max());
    Size = m_stream.gcount();
    m_stream.clear();
    m_stream.seekg(0,std::ios::beg);
    m_stream.close();
    return Size;

}

//----------------------------------------------------------------------------------


Settings Config :: ReadData()
{
    Settings s;

    if( !s_stream.is_open() )
        throw (std::string) "Error....open file for read/write ops!!!";
    if(m_stream.bad())
        throw;
    if(m_stream.fail())
        throw;

    //Metadata m =this->ReadMetadata();
    std::string serv,chan,port,nick;

    std::getline(s_stream,serv,'\n');
    std::getline(s_stream,chan,'\n');
    std::getline(s_stream,port,'\n');
    std::getline(s_stream,nick,'\n');

    unsigned short por = static_cast<unsigned short>(std::stoi(port));

    s.gServer(serv); s.gChannel(chan);
    s.gPort(por);
    s.gNick(nick);

    return s;
}

//----------------------------------------------------------------------------------


void Config :: WriteData(Settings &s)
{
    Metadata m;

    if(!s_stream.is_open())
        throw (std::string) "Error....open file for read/write ops!!!";
    if(s_stream.bad())
        throw;
    if(s_stream.fail())
        throw;

    s_stream<<s.rServer()<<std::endl
            <<s.rChannel()<<std::endl
            <<s.rPort()<<std::endl
            <<s.rNick()<<std::endl;
    s_stream.flush();

    m.Set_Sizes(s);
    this->WriteMetadata(m);

}

//----------------------------------------------------------------------------------

void Config :: Take_Config()
{

    s_stream.open(cfg_file.c_str(), std::ios::out);

    if(s_stream.bad())
        throw;
    if(s_stream.fail())
        throw;

    char ans = 'y';
    while( ans == 'y' || ans == 'Y' )
    {
        *settings = this->GetInput();
        this->WriteData(*settings);
        std::cout<<"Do you want to add more??? (Y/N): ";
        std::cin>>ans;
        if( ans != 'y' || ans != 'Y' )
            break;
    }

    s_stream.close();
}

//-------------------------------------------------------------------------------------------------------------------


void Config :: Show_Config()
{

    s_stream.open(cfg_file.c_str(), std::ios::in);

    if(s_stream.bad())
        throw;
    if(s_stream.fail())
        throw;

    std::streamsize Size = this->ReadSize();
    std::streamsize rSize = Size/sizeof(meta);

    for(;rSize>0;rSize--)
    {
        if(rSize < 0)
            break;
        *settings = this->ReadData();
        this->PutInput(*settings);

    }

    s_stream.close();
}

