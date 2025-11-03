#include <singleton.hpp>

#include <user_config.hpp>
#include <system_config.hpp>

extern void fill_data();

int main()
{
    fill_data();

    a1::Singleton<a1::UserConfig>::getInstance().show();
    a1::Singleton<a1::SystemConfig>::getInstance().show();
    return 0;
}
