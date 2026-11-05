#include "RakPeer.h"
struct RemoteSystemSizeProbe : RakPeer
{
    typedef char Size[sizeof(RemoteSystemStruct) == 0x850 ? 1 : -1];
};
