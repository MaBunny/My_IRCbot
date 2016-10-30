#include <iostream>
#include <memory>
#include <string>
#include "./Src/config.hpp"

Logger logger;

int main()
{
    try
    {
        std::string Configs = "./Config.log";
        std::string Metadata = "./Metadata.log";
        std::unique_ptr<Config> c(new Config(Configs,Metadata));
        std::cout<<"This is a demo...it'll only take and show input only....\n";
        std::cout<<"Now enter the filename to be worked upon...\n";
        char ans = 'y'; int var = 3;
        while(ans == 'y' || ans =='Y')
        {
            std::cout<<"1: Enter a config.\n"
                     <<"2: Show the configs.\n"
                     <<"3: Exit program.\n";
            std::cout<<"Enter choice: "; std::cin>>var; std::cout<<"\n";
            switch(var)
            {
            case 1:
                std::cout<<"Taking configs....\n";
                c->Take_Config();
                break;
            case 2:
                std::cout<<"Showing configs...\n";
                c->Show_Config();
            case 3:
                ans = 'n';
                break;
            default:
                std::cout<<"Srry....Wrong Input !!! \n";
                break;
            }
        }

        std::cout<<"Thank you !!!\n";
        return 0;

    }
    catch(std::fstream::failure exceptions)
    {
        std::cout<<"Oops...found an exception !!!\n";
        std::cout<<exceptions.what()<<std::endl;
    }
}
