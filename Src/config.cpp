#include "./config.hpp"
#include <fstream>
#include <limits>
#include <exception>

Settings Config :: GetInput()
{
    std::string s,c,n;
    unsigned short p;
 
    Settings sett;
    logger.getLogs( static_cast<std::string>("In Config class: In GetInput() ftor, created a Settings object.") );
    std::cout<<"Enter the server IPv4 address:  ";
    std::cin>>s;  std::cout<<"\n";
    std::cout<<"Enter the channel name(eg, #debian ):  ";
    std::cin>>c; std::cout<<"\n";
    std::cout<<"Enter the port to connect to(best: 6667):  ";
    std::cin>>p;std::cout<<"\n";
    std::cout<<"Enter the nickname for that channel:  ";
    std::cin>>n; std::cout<<"\n";
    
    logger.getLogs( static_cast<std::string>("In Config class: In GetInput() ftor, accepted the inputs.") ); 
    
    sett.getData(s,c,p,n);
    logger.getLogs( static_cast<std::string>("In Config class: In GetInput() ftor, passed values to Settings object.Returning the object.") ); 
    logger.Log(0);
 
    return sett;
}

void Config :: PutInput(Settings &sett)
{
    std::string s,n,c;
    unsigned short p;
    logger.getLogs( static_cast<std::string>("In Config class: In PutData() ftor, transferring data from Settings object to temporary variables.") );
    sett.putData(s,c,p,n);
    std::cout<<"The server IPv4 address is: "<<s<<std::endl
	     <<"The channel name for that server is: "<<c<<std::endl
             <<"The port used to connect is: "<<p<<std::endl
             <<"The nickname for that channel is: "<<n<<std::endl;
    logger.getLogs( static_cast<std::string>("In Config class: In PutData() ftor,printed the temporary variables.") );
    logger.Log(0);
}

//----------------------------------------------------------------------------------


Metadata Config:: ReadMetadata()
{

    m_stream.open(meta_file.c_str(), std::ios::in);
    Metadata m;
    
    logger.getLogs( static_cast<std::string>("In Config class: In ReadMetadata() ftor,opened m_stream object in ios::in file mode.") );
    logger.getLogs( static_cast<std::string>("In Config class: In ReadMetadata() ftor,created a Metadata object") );

    try{ m_stream.is_open(); }
    catch(std::ios_base::failure &e)
    { 
        std::cout<<"Found an exception while opening file....\n"
                 <<e.what()<<std::endl;
    }
    if(m_stream.bad())
        throw;
    if(m_stream.fail())
        throw;

    /* Read the data from the meta_file.
       Reason why std::string not used is tht it will through
       away precision when cast from const char* to char and
       char to unsigned int.
    */
    
    logger.getLogs( static_cast<std::string>("In Config class: In ReadMetadata() ftor,reading the count variable in meta_file.") );
    std::string count;
    std::getline(m_stream,count,'\n');
    
    unsigned int coun = std::stoi(count);
    m.gCount(coun);
    
    logger.getLogs( static_cast<std::string>("In Config class: In ReadMetadata() ftor,stored the count variable in Metadata object.Now returning it.") ); 
    m_stream.close();
    logger.Log(0);
    return m;
}


//----------------------------------------------------------------------------------


void Config :: WriteMetadata(Metadata &m)
{

    m_stream.open(meta_file.c_str(), std::ios::out);
    logger.getLogs( static_cast<std::string>("In Config class: In ReadMetadata() ftor,opened m_stream object in ios::out file mode.") );
     
    try{ m_stream.is_open(); }
    catch(std::ios_base::failure &e)
    { 
        std::cout<<"Found an exception while opening file....\n"
                 <<e.what()<<std::endl; 
    }
    if(m_stream.bad())
        throw;
    if(m_stream.fail())
        throw;
    
    logger.getLogs( static_cast<std::string>("In Config class: In ReadMetadata() ftor,done reading the count variable in Metadata object.Now writing it to file.") ); 
    logger.Log(0);
    m_stream<<m.rCount();
    m_stream.flush();

    m_stream.close();
}

//----------------------------------------------------------------------------------

std::streamsize Config :: ReadSize()
{

    m_stream.open(meta_file.c_str(),std::ios::in);
     logger.getLogs( static_cast<std::string>("In Config class: In ReadSize() ftor,opened m_stream object in ios::in file mode.") );
    std::streamsize Size;
    m_stream.ignore(std::numeric_limits<std::streamsize>::max());
    Size = m_stream.gcount();
    m_stream.clear();
    m_stream.seekg(0,std::ios::beg);
    m_stream.close();
    logger.getLogs( static_cast<std::string>("In Config class: In ReadSize() ftor,done reading the size of the file,returning the Size variable.") );
    logger.Log(0); 
    return Size;

}

//----------------------------------------------------------------------------------


Settings Config :: ReadData()
{
    Settings s;
    logger.getLogs( static_cast<std::string>("In Config class: In ReadData() ftor,created a Settings object.") );
 
    try{ s_stream.is_open(); }
    catch(std::ios_base::failure &e)
    { 
        std::cout<<"Found an exception while opening file....\n"
                 <<e.what()<<std::endl; 
    }         
    if(s_stream.bad())
        throw std::ios_base::badbit;
    if(s_stream.fail())
        throw std::ios_base::failbit;
    
    logger.getLogs( static_cast<std::string>("In Config class: In ReadData() ftor,reading the appropriate Settings data members from the file.") );
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
    logger.getLogs( static_cast<std::string>("In Config class: In ReadData() ftor,done storing the data members in the Settings object,now returning the object.") );
    logger.Log(0);
    return s;
}

//----------------------------------------------------------------------------------


void Config :: WriteData(Settings &s)
{
    Metadata m;
    logger.getLogs( static_cast<std::string>("In Config class: In WriteData() ftor,created a Metadata object.Now proceeding to write the Settings object.") );
 
    try{ s_stream.is_open(); }
    catch(std::ios_base::failure &e)
    { 
        std::cout<<"Found an exception while opening file....\n"
                 <<e.what()<<std::endl; 
    }         
    if(s_stream.bad())
        throw std::ios_base::badbit;
    if(s_stream.fail())
        throw std::ios_base::failbit;
   
    s_stream<<s.rServer()<<std::endl
            <<s.rChannel()<<std::endl
            <<s.rPort()<<std::endl
            <<s.rNick()<<std::endl;
    s_stream.flush();
    logger.getLogs( static_cast<std::string>("In Config class: In WriteData() ftor,done writing the Settings object taken as parameter.") );

    m.upCount();
    this->WriteMetadata(m);
    logger.getLogs( static_cast<std::string>("In Config class: In WriteData() ftor,done writing the Metadata object.") );  
    logger.Log(0);
}

//----------------------------------------------------------------------------------

void Config :: Take_Config()
{

    s_stream.open(cfg_file.c_str(), std::ios::out);
    logger.getLogs( static_cast<std::string>("In Config class: In Take_Config() ftor,opened s_stream object in ios::in file mode.") );
 
    if(s_stream.bad())
        throw;
    if(s_stream.fail())
        throw;

    char ans = 'y';
    while( ans == 'y' || ans == 'Y' )
    {
        *settings = this->GetInput();
        this->WriteData(*settings);
        logger.getLogs( static_cast<std::string>("In Config class: In Take_Config() ftor,done taking a settings config.") );
        std::cout<<"Do you want to add more??? (Y/N): ";
        std::cin>>ans;
        if( ans != 'y' || ans != 'Y' )
            break;
    }
    logger.getLogs( static_cast<std::string>("In Config class: In Take_Config() ftor,going out of the fuction.") );
    s_stream.close();
    logger.Log(0); 
}

//-------------------------------------------------------------------------------------------------------------------


void Config :: Show_Config()
{

    s_stream.open(cfg_file.c_str(), std::ios::in);
    logger.getLogs( static_cast<std::string>("In Config class: In Show_Config() ftor,opened s_stream object in ios::in file mode.") );
 
    if(s_stream.bad())
        throw;
    if(s_stream.fail())
        throw;

    Metadata m;
    m = this->ReadMetadata();   
    logger.getLogs( static_cast<std::string>("In Config class: In Show_Config() ftor,created a Metadata object and read into it.") );
    unsigned int rSize = m.rCount();
    logger.getLogs( static_cast<std::string>("In Config class: In Show_Config() ftor,read the count of the Metadata object as = ") + std::to_string(rSize) + static_cast<std::string>(".") );
    while( rSize > 0 )
    {
        *settings = this->ReadData();
        logger.getLogs( static_cast<std::string>("In Config class: In Show_Config() ftor,read into the Settings* settings object.") ); 
        this->PutInput(*settings);
        logger.getLogs( static_cast<std::string>("In Config class: In Show_Config() ftor,outputed the values of the Settings* settings object.") );  
        --rSize;
        logger.getLogs( static_cast<std::string>("In Config class: In Show_Config() ftor,subtracted one from rSize,its value now is = ") + std::to_string(rSize) + static_cast<std::string>(".") );   
        if( rSize <= 0 )
           break;
    }

    s_stream.close();
    logger.getLogs( static_cast<std::string>("In Config class: In Show_Config() ftor,going out of the function.") ); 
    logger.Log(0);
}

