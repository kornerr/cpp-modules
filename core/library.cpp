
#include "library.h"
#include "library-private.h"

#include <dlfcn.h>

namespace cppmodules {
namespace core {
namespace library {

Library load(const char *fileName)
{
    // Load library.
    Library library = dlopen(fileName, RTLD_NOW);
    if (!library)
    {
        printf(
            "ERROR. Could not open library '%s': '%s'\n",
            fileName,
            dlerror());
        return 0;
    }

    // Call init function if it's found.
    LibraryFunction *init;
    if (findFunction(fileName, library, "cppmoduleInit", init))
    {
        (*init)();
        return library;
    }

    // Unload library otherwise.
    unload(fileName, library);
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

