// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// Inactive native 2008-06 Exposer (native-headers/AppLeaves2008/Exposer2008.h).
#include "AppLeaves2008/Exposer2008.h"

const char* Exposer::IDTOString(int id)
{
    Exposer exposer;
    return exposer.PacketLogger::IDTOString((unsigned char)id);
}
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
