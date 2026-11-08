// >>> native-status (generated) -- do not edit >>>
// MetadataClassesRegister | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 4bfa3926 | roc native-status --write
#include "reflection/Metadata.h"
namespace RBX {
template<typename C, typename B, const char* N>
FactoryProduct<C, B, N>::FactoryProduct() {}
template<typename C, typename B, const char* N>
DescribedCreatable<C, B, N>::DescribedCreatable() {}
template<> const Name& FactoryProduct<Reflection::Metadata::Class, Reflection::Metadata::Item, Reflection::Metadata::sClass>::getClassName() const
{
    return Name::declare<Reflection::Metadata::sClass>();
}
namespace Reflection { namespace Metadata {
Class::Class() : unknown_150(-1), unknown_154(0) {}
bool Class::askAddChild(const Instance* child) const
{
    return dynamic_cast<const Members*>(child) != NULL;
}
void Classes::addClass(const ClassDescriptor& descriptor)
{
    Class* found = static_cast<Class*>(findFirstChildByName(descriptor.name.toString()));
    if (found) {
        found->unknown_130 = false;
        return;
    }
    boost::shared_ptr<Class> item = Creatable<Instance>::create<Class>();
    item->setName(descriptor.name.toString());
    item->unknown_130 = false;
    item->setParent(this);
}
}}}
