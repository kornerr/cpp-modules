
#include "user/coreext.h"

#include <cstdio>

namespace cppmodules {
namespace core {
namespace print {

void printFancyString(const std::string &value)
{
    printf("printFancyString(%s)\n", value.c_str());
}

} // namespace print
} // namespace core
} // namespace cppmodules

