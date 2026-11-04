#include "reflection/Metadata.h"
namespace RBX { namespace Reflection { namespace Metadata {
Item::Item() : unknown_130(true), unknown_131(false), unknown_132(false) {}

Member::Member() {}
Member::~Member() {}
Properties::Properties() {}
Properties::~Properties() {}
bool Properties::askAddChild(const Instance* child) const
{
    return dynamic_cast<const Member*>(child) != NULL;
}
Functions::Functions() {}
Functions::~Functions() {}
bool Functions::askAddChild(const Instance* child) const
{
    return dynamic_cast<const Member*>(child) != NULL;
}
Events::Events() {}
Events::~Events() {}
bool Events::askAddChild(const Instance* child) const
{
    return dynamic_cast<const Member*>(child) != NULL;
}
typedef char ItemSize[sizeof(Item) == 0x150 ? 1 : -1];
typedef char MemberSize[sizeof(Member) == 0x150 ? 1 : -1];
typedef char PropertiesSize[sizeof(Properties) == 0x130 ? 1 : -1];
typedef char FunctionsSize[sizeof(Functions) == 0x130 ? 1 : -1];
typedef char EventsSize[sizeof(Events) == 0x130 ? 1 : -1];
}}}
