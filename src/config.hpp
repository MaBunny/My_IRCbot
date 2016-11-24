#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <fstream>
#include "helpers.hpp"

class Config
{
private:
    std::string cfg_file;
    std::string meta_file;

    Settings settings;
    Metadata meta;

    void GetFilename(std::string &a)
    {
	cfg_file = a;
    }

    //Helper functions to get and put input from user
    Settings GetInput();
    void PutInput(Settings &sett);

    //Read from the meta_file file and return as a Metadata object
    //To be called in ReadData()
    Metadata ReadMetadata();

    //Take a Metadata object as parameter and write it to meta_file file
    //To be called in WriteData()
    void WriteMetadata(Metadata &to_be_written_obj);

    //Read the size of the Metadata file
    std::streamsize ReadSize();

public:

    Config()
    { 
       meta_file = "./meta.logs"; cfg_file = " ";
       logger.GetLogs( static_cast<std::string>("In Config class: Created a Config object with meta_file = ") + meta_file + static_cast<std::string>(" ,and default cfg_file. ") );
       
       logger.GetLogs( static_cast<std::string>("In Config class: Also created a Settings object and Metadata object.") );
       logger.Log(0); 
    }
    
    Config(std::string &file) : cfg_file(file)
    {
       meta_file = "./meta.logs";
       logger.GetLogs( static_cast<std::string>("In Config class: Created a Config object.") );
       logger.GetLogs( static_cast<std::string>("In Config class: meta_file is = ") + meta_file + static_cast<std::string>(" .") );
       logger.GetLogs( static_cast<std::string>("In Config class: cfg_file is = ") + cfg_file + static_cast<std::string>(" .") );
       logger.GetLogs( static_cast<std::string>("In Config class: Also created a Settings object and Metadata object.") );
       logger.Log(0);
    }
    Config(std::string &Cfg_file,std::string &Meta_file) : cfg_file(Cfg_file),
                                                           meta_file(Meta_file)
    {
        logger.GetLogs( static_cast<std::string>("In Config class: Created a Config object.") );
        logger.GetLogs( static_cast<std::string>("In Config class: meta_file is = ") + meta_file + static_cast<std::string>(" .") );
        logger.GetLogs( static_cast<std::string>("In Config class: cfg_file is = ") + cfg_file + static_cast<std::string>(" .") );
        logger.GetLogs( static_cast<std::string>("In Config class: Also created a Settings object and Metadata object.") );
        logger.Log(0);
    }

    ~Config() 
     { 
        logger.GetLogs( static_cast<std::string>("In Config class: Deleted Config object.") );
        logger.Log(0);
     }

    //Take config from user input
    //To call WriteData()
    void Take_Config();

    //Show config to user
    //To call ReadData()
    void Show_Config();

    //Read the data of a Settings object and show it
    //It returns a Settings object
    Settings ReadData();

    //Write to the cfg_file the data stored in Settings object
    //It takes a Settings object as parameter
    void WriteData(Settings &sett);

    //Function to return a config entry
    //void Search(std::string &serv);
};

#endif
