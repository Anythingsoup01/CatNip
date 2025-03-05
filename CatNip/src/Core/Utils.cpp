#include "Utils.h"
#include <stdio.h>

namespace CatNip::Utils
{
    void PrintError(const char* msg)
    {
        printf("ERROR: %s\n", msg);
    }

    void PrintWarning(const char* msg)
    {
        printf("WARNING: %s\n", msg);
    }
}
