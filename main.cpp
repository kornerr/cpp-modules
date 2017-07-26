
#include "core.h"

using namespace cppmodules;

int main()
{
    printf("CPPModules\n");

    const std::string fileNameUser = "libuser.so";

    core::Module module = core::loadModule(fileNameUser);
    if (module)
    {
        core::unloadModule(fileNameUser, module);
    }


    return 0;
}

