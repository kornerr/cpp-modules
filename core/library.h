
#ifndef CPP_MODULES_CORE_LIBRARY_H
#define CPP_MODULES_CORE_LIBRARY_H

#include <string>

namespace cppmodules {
namespace core {
namespace library {

// Handle void * a bit safer.
typedef void * Library;
// Function pointer declaration.
typedef void LibraryFunction();

Library load(const char *fileName);
void unload(const char *fileName, Library library);

} // namespace library
} // namespace core
} // namespace cppmodules

#endif // CPP_MODULES_CORE_LIBRARY_H

