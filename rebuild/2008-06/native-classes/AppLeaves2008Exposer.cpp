// Inactive native 2008-06 Exposer (native-headers/AppLeaves2008/Exposer2008.h).
#include "AppLeaves2008/Exposer2008.h"

const char* Exposer::IDTOString(int id)
{
    Exposer exposer;
    return exposer.PacketLogger::IDTOString((unsigned char)id);
}
