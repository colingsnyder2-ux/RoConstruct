// >>> native-status (generated) -- do not edit >>>
// GuidRegistryCriticalSection | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 2faec000 | roc native-status --write
#include <windows.h>
#include <boost/thread/exceptions.hpp>

namespace RBX {
void* newGuidRegistryCriticalSection()
{
    try {
        CRITICAL_SECTION* section = new CRITICAL_SECTION;
        if (section == 0) throw boost::thread_resource_error();
        InitializeCriticalSection(section);
        return section;
    } catch (...) {
        throw boost::thread_resource_error();
    }
}
}
