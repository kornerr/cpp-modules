
#include "core.h"

#include <dlfcn.h>

namespace cppmodules {
namespace core {

Module loadModule(const std::string &fileName)
{
    // Load library.
    Module module = dlopen(fileName.c_str(), RTLD_NOW);
    if (!module)
    {
        printf(
            "ERROR. Could not open module file '%s': '%s'\n",
            fileName.c_str(),
            dlerror());
        return 0;
    }
    // Get init function.
    const std::string INIT_FUNCTION = "cppmoduleInit";
    void *cppmoduleInitFunction = dlsym(module, INIT_FUNCTION.c_str());
    const std::string possibleError(dlerror());
    if (!possibleError.empty())
    {
        printf(
            "ERROR. Could not find function '%s' inside module file '%s': '%s'\n",
            INIT_FUNCTION.c_str(),
            fileName.c_str(),
            possibleError.c_str());
        unloadModule(module);
        return 0;
    }
    ModuleFunction *init =
        reinterpret_cast<ModuleFunction *>(cppmoduleInitFunction);
    // Call init function.
    (*init)();
}

void unloadModule(Module module)
{
    // Get deinit function.
    const std::string DEINIT_FUNCTION = "cppmoduleDeinit";
    void *cppmoduleDeinitFunction = dlsym(module, DEINIT_FUNCTION.c_str());
    const std::string possibleError(dlerror());
    if (!possibleError.empty())
    {
        printf(
            "ERROR. Could not find function '%s' inside module file 'TODO': '%s'\n",
            DEINIT_FUNCTION.c_str(),
            //fileName.c_str(),
            possibleError.c_str());
    }
    // Call deinit function if it's present.
    else {
        ModuleFunction *deinit =
            reinterpret_cast<ModuleFunction *>(cppmoduleDeinitFunction);
        (*deinit)();
    }
    // Unload library.
    dlclose(module);
}

} // namespace core
} // namespace cppmodules

