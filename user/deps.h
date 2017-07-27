
#ifndef CPP_MODULES_USER_DEPS_H
#define CPP_MODULES_USER_DEPS_H

#include "core/print.h"

#include <cstdio>

//#define USE_ALTERNATIVE

namespace cppmodules {
namespace user {
namespace deps {

class Deps
{
    public:
        void printDeinit()
        {
            core::print::printFancyInt(44);
#ifdef USE_ALTERNATIVE
            printf("Deps.printDeinit. ALTERNATIVE\n");
#else
            printf("Deps.printDeinit.\n");
#endif
        }
        void printInit()
        {
            core::print::printFancyInt(24);
#ifdef USE_ALTERNATIVE
            printf("Deps.printInit. ALTERNATIVE\n");
#else
            printf("Deps.printInit.\n");
#endif
        }

};

} // namespace deps
} // namespace user
} // namespace cppmodules

#endif // CPP_MODULES_USER_DEPS_H

