
#include "user.h"
#include "deps.h"

#include "coreext.h"

#include <cstdio>

void cppmoduleInit()
{
    cppmodules::user::deps::Deps d;
    d.printInit();
    cppmodules::core::print::printFancyString("cppmoduleInit");
}

void cppmoduleDeinit()
{
    cppmodules::user::deps::Deps d;
    d.printDeinit();
    cppmodules::core::print::printFancyString("cppmoduleDeinit");
}

