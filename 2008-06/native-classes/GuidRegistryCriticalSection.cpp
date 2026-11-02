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
