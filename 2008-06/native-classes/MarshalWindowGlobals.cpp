#include "util/MarshaledListener.h"
#include <map>

namespace RBX {
std::map<DWORD, CMarshalWindow*> marshalWindows;
ATL::CCriticalSection marshalRegistryLock;
}
