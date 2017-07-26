
#include "core.h"

using namespace cppmodules;

int main(int argc, char *argv[])
{
    printf("Loading user library the first time\n");

    const std::string fileNameUser = "libuser.so";

    core::Module module = 0;

    // First time.
    module = core::loadModule(fileNameUser);
    if (module)
    {
        core::unloadModule(fileNameUser, module);
    }

    printf("Paused. Change user library dependency, rebuild, and then press Enter\n");
    getchar();
    printf("Loading user library the second time\n");


    // Second time.
    module = core::loadModule(fileNameUser);
    if (module)
    {
        core::unloadModule(fileNameUser, module);
    }

    return 0;
}

