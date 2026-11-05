#include "reflection/Metadata.h"
#include "reflection/object.h"
#include "reflection/property.h"
#include "reflection/function.h"
#include "reflection/signal.h"

namespace RBX { namespace Metadata {

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::PropertyDescriptor& descriptor) const
{
    Instance* item = classes ? classes->findFirstChildByName(descriptor.owner.name.name) : NULL;
    if (item) {
        RBX::Reflection::Metadata::Properties* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Properties>();
        if (members) return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.name));
    }
    return NULL;
}

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::FunctionDescriptor& descriptor) const
{
    Instance* item = classes ? classes->findFirstChildByName(descriptor.owner.name.name) : NULL;
    if (item) {
        RBX::Reflection::Metadata::Functions* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Functions>();
        if (members) return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.name));
    }
    return NULL;
}

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::SignalDescriptor& descriptor) const
{
    Instance* item = classes ? classes->findFirstChildByName(descriptor.owner.name.name) : NULL;
    if (item) {
        RBX::Reflection::Metadata::Events* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Events>();
        if (members) return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.name));
    }
    return NULL;
}

}}
