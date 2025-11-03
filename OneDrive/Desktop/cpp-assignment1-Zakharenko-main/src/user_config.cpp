#include "user_config.hpp"

#include <iostream>

namespace a1 {

void UserConfig::show()
{
    std::cout << "User configs:" << std::endl;
    for(const auto& u : m_users_groups){
        std::cout << "1. - " << u.user << " - " << u.group << std::endl;
    }
}

void UserConfig::add_user(std::string user, std::string group)
{
    m_users_groups.push_back({user, group});
}

} // a1