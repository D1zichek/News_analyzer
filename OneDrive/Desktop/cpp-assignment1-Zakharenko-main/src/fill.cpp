#include <singleton.hpp>

#include <user_config.hpp>
#include <system_config.hpp>

void fill_data()
{
   auto& UserConfig = a1::Singleton<a1::UserConfig>::getInstance(); 
   auto& SystemConfig = a1::Singleton<a1::SystemConfig>::getInstance();
   UserConfig.add_user("Zhukovs'ka", "Z-31");
   UserConfig.add_user("Zakharenko","Z-31"); 
   UserConfig.add_user("Kalinichenko","Z-31"); 

   SystemConfig.add_system("Zhukovs'ka", "Windows");
   SystemConfig.add_system("Zakharenko","Linux");
   SystemConfig.add_system("Kalinichenko","MacOS");
    

}
