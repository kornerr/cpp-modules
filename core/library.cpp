
#include "library.h"
#include "library-private.h"

#include <dlfcn.h>

namespace cppmodules {
namespace core {
namespace library {

Library load(const char *fileName)
{
    printf("01.load\n");
    // Load library.
    Library library = dlopen(fileName, RTLD_NOW);
    printf("02.load\n");
    if (!library)
    {
        printf(
            "ERROR. Could not open library '%s': '%s'\n",
            fileName,
            dlerror());
        return 0;
    }

    printf("03.load\n");
    // Call init function if it's found.
    LibraryFunction *init = 0;
    printf("03.0.load. init: '%p'\n", init);
    if (findFunction(fileName, library, "cppmoduleInit", init))
    {
        printf("03.1.load. init: '%p'\n", init);
        (*init)();
        printf("03.2.load\n");
        return library;
    }

    printf("04.load\n");
    // Unload library otherwise.
    unload(fileName, library);
    printf("05.load\n");
    return 0;
}

void unload(const char *fileName, Library library)
{
    // Call deinit function if it's found.
    LibraryFunction *deinit;
    if (findFunction(fileName, library, "cppmoduleDeinit", deinit))
    {
        (*deinit)();
    }

    // Close the library.
    dlclose(library);

    // TODO: Do we need to check for dlerror() in case dlclose() failed?
}

} // namespace library
} // namespace core
} // namespace cppmodules

