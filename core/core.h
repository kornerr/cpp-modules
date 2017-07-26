
#ifndef CPP_MODULES_CORE_H
#define CPP_MODULES_CORE_H

#include <string>

namespace cppmodules {
namespace core {

// A bit safer void* handler.
typedef void * Module;
// Function pointer declaration.
typedef void ModuleFunction();

Module loadModule(const std::string &fileName);
void unloadModule(const std::string &fileName, Module module);

} // namespace core
} // namespace cppmodules

#endif // CPP_MODULES_CORE_H

