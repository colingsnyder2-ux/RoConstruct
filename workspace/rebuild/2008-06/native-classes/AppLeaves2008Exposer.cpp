// Inactive native 2008-06 Exposer (native-headers/AppLeaves2008/Exposer2008.h).
// >>> native-status (generated) -- do not edit >>>
// AppLeaves2008Exposer | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c0b02cc7 | roc native-status --write
#include "AppLeaves2008/Exposer2008.h"

const char* Exposer::IDTOString(int id)
{
    Exposer exposer;
    return exposer.PacketLogger::IDTOString((unsigned char)id);
}
