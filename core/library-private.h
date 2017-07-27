
#ifndef CPP_MODULES_CORE_LIBRARY_PRIVATE_H
#define CPP_MODULES_CORE_LIBRARY_PRIVATE_H

#include <dlfcn.h>

namespace cppmodules {
namespace core {
namespace library {

// Return located function as the last argument, because NULL pointer
// CAN be the function. See 'man dlsym' for more info.
bool findFunction(
    const char *fileName,
    Library library,
    const char *functionName,
    LibraryFunction **function)
{
    void *rawfunc = dlsym(library, functionName);
    const char *error = dlerror();
    if (error)
    {
        printf(
            "ERROR. Could not find function '%s' inside library '%s': '%s'\n",
            functionName,
            fileName,
            error);
        return false;
    }
    *function = reinterpret_cast<LibraryFunction *>(rawfunc);
    return true;
}

} // namespace library
} // namespace core
} // namespace cppmodules

#endif // CPP_MODULES_CORE_LIBRARY_PRIVATE_H

