
#ifndef CPP_MODULES_USER_DEPS_H
#define CPP_MODULES_USER_DEPS_H

#include "core/print.h"

#include <cstdio>

//#define USE_ALTERNATIVE

namespace cppmodules {
namespace userdeps {

class UserDeps
{
    public:
        void printDeinit()
        {
            core::print::printFancyInt(44);
#ifdef USE_ALTERNATIVE
            printf("UserDeps.printDeinit. ALTERNATIVE\n");
#else
            printf("UserDeps.printDeinit.\n");
#endif
        }
        void printInit()
        {
            core::print::printFancyInt(24);
#ifdef USE_ALTERNATIVE
            printf("UserDeps.printInit. ALTERNATIVE\n");
#else
            printf("UserDeps.printInit.\n");
#endif
        }

};

} // namespace userdeps
} // namespace cppmodules

#endif // CPP_MODULES_USER_DEPS_H

