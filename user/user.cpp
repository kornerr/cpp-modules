
#include "user.h"
#include "userdeps.h"

#include <cstdio>

void cppmoduleInit()
{
    cppmodules::userdeps::UserDeps ud;
    ud.printInit();
}

void cppmoduleDeinit()
{
    cppmodules::userdeps::UserDeps ud;
    ud.printDeinit();
}

