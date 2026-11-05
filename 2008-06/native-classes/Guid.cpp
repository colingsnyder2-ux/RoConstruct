// Inactive: globals and initializer require original data/link proof.
#include "util/Guid.h"
#include <windows.h>
#include <objbase.h>
#include <boost/thread/once.hpp>
const RBX::Name* localScope = NULL;
LONG nextIndex = 0;
void initLocalScope()
{
    std::string guid;
    RBX::Guid::generateGUID(guid);
    localScope = &RBX::Name::declare(guid.c_str(), -1);
}
namespace RBX {
Guid::Guid()
{
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(initLocalScope, flag);
    data.scope = localScope;
    data.index = InterlockedIncrement(&nextIndex);
}
}
