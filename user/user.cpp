
#include "user.h"
#include "userdeps.h"

#include <cstdio>

void cppmoduleInit()
{
    printf("01.cppmoduleInit\n");
    cppmodules::userdeps::UserDeps ud;
    ud.printInit();
}

void cppmoduleDeinit()
{
    cppmodules::userdeps::UserDeps ud;
    ud.printDeinit();
}

