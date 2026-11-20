#include "reflection/Metadata.h"
namespace RBX { namespace Metadata {
RBX::Reflection::Metadata::Class* Reflection::lookup(const RBX::Reflection::ClassDescriptor& descriptor, bool recursive) const
{
    return classes ? classes->lookup(descriptor, recursive) : NULL;
}

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::PropertyDescriptor& descriptor) const
{
    Instance* item = classes ? classes->findFirstChildByName(descriptor.owner.name.toString()) : NULL;
    if (item) {
        RBX::Reflection::Metadata::Properties* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Properties>();
        if (members) return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.toString()));
    }
    return NULL;
}

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::FunctionDescriptor& descriptor) const
{
    Instance* item = classes ? classes->findFirstChildByName(descriptor.owner.name.toString()) : NULL;
    if (item) {
        RBX::Reflection::Metadata::Functions* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Functions>();
        if (members) return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.toString()));
    }
    return NULL;
}

RBX::Reflection::Metadata::Member* Reflection::lookup(const RBX::Reflection::SignalDescriptor& descriptor) const
{
    Instance* item = classes ? classes->findFirstChildByName(descriptor.owner.name.toString()) : NULL;
    if (item) {
        RBX::Reflection::Metadata::Events* members = item->findFirstChildOfType<RBX::Reflection::Metadata::Events>();
        if (members) return static_cast<RBX::Reflection::Metadata::Member*>(members->findFirstChildByName(descriptor.name.toString()));
    }
    return NULL;
}
}}
