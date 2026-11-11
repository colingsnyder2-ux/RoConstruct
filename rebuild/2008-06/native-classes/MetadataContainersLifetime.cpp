// >>> native-status (generated) -- do not edit >>>
// MetadataContainersLifetime | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8fdc5bc9 | roc native-status --write
#include "reflection/Metadata.h"
namespace RBX { namespace Reflection { namespace Metadata {


Members::Members() {}
bool Members::askAddChild(const Instance* child) const
{
    return dynamic_cast<const Member*>(child) != NULL;
}
Member::Member() {}
Member::~Member() {}
Properties::Properties() {}
Properties::~Properties() {}
Functions::Functions() {}
Functions::~Functions() {}
Events::Events() {}
Events::~Events() {}
typedef char ItemSize[sizeof(Item) == 0x150 ? 1 : -1];
typedef char MemberSize[sizeof(Member) == 0x150 ? 1 : -1];
typedef char PropertiesSize[sizeof(Properties) == 0x130 ? 1 : -1];
typedef char FunctionsSize[sizeof(Functions) == 0x130 ? 1 : -1];
typedef char EventsSize[sizeof(Events) == 0x130 ? 1 : -1];
}}}
