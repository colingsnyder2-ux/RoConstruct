// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdio.h>
#include "Replicator.h"

// INFERRED: FILE* at +0x20c (from server analog); the base destructor (func_004baa40) runs implicitly
FilePacketLogger::~FilePacketLogger()
{
    FILE* f = *reinterpret_cast<FILE**>(reinterpret_cast<char*>(this) + 0x20c);
    if (f)
        fclose(f);
}
