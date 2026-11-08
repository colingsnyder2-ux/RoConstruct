#include "reflection/Metadata.h"
namespace RBX { namespace Reflection { namespace Metadata {
Classes::Classes() {}
Classes::~Classes() {}
bool Classes::askAddChild(const Instance* child) const
{
    return dynamic_cast<const Class*>(child) != NULL;
}
}}}
