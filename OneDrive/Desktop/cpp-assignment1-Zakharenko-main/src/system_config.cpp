//
// Created by Serhii Pustovit on 31.10.2025.
//

#include "system_config.hpp"
#include <iostream>

namespace a1 {

void SystemConfig::show()
{
   std::cout << "System configs:" << std::endl;
   for(const auto& s : m_users_systems){
    std::cout << "1. " << s.user << " - " << s.system << std::endl;
   }
}

void SystemConfig::add_system( std::string user,  std::string system)
{
   m_users_systems.push_back({user, system});
}

}