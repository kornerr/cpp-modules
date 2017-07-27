
#include "core/library.h"

using namespace cppmodules;

int main(int argc, char *argv[])
{
    printf("Loading user library the first time\n");

    const std::string fileNameUser = "libuser.so";

    core::library::Library library;

    // First time.
    library = core::library::load(fileNameUser.c_str());
    if (library)
    {
        core::library::unload(fileNameUser.c_str(), library);
    }

    printf("Paused. Change user library dependency, rebuild, and then press Enter\n");
    getchar();
    printf("Loading user library the second time\n");


    // Second time.
    library = core::library::load(fileNameUser.c_str());
    if (library)
    {
        core::library::unload(fileNameUser.c_str(), library);
    }

    return 0;
}

