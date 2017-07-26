
#ifndef CPP_MODULES_USER_DEPS_H
#define CPP_MODULES_USER_DEPS_H

#include <cstdio>

//#define USE_ALTERNATIVE

namespace cppmodules {
namespace userdeps {

class UserDeps
{
    public:
        void printDeinit()
        {
#ifdef USE_ALTERNATIVE
            printf("UserDeps.printDeinit. ALTERNATIVE\n");
#else
            printf("UserDeps.printDeinit.\n");
#endif
        }
        void printInit()
        {
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

