// >>> native-status (generated) -- do not edit >>>
// MarshalWindowGlobals | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 9bd4837f | roc native-status --write
#include "util/MarshaledListener.h"
#include <map>

namespace RBX {
std::map<DWORD, CMarshalWindow*> marshalWindows;
ATL::CCriticalSection marshalRegistryLock;
}
