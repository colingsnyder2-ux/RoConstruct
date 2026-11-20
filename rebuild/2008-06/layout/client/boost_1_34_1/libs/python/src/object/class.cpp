#include "reflection/Metadata.h"
#include <algorithm>

namespace RBX {
namespace Reflection {
namespace Metadata {

int Class::getImageIndex() const {
    if (unknown_154 == -1)
        return dynamic_cast<const Class*>(getParent()) && dynamic_cast<const Class*>(getParent())->getImageIndex();
    return (std::max)(unknown_154, 0);
}

} // namespace Metadata
} // namespace Reflection
} // namespace RBX

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

int RBX::Reflection::Metadata::Class::explorerOrder() const
{
    if (unknown_150)
        return unknown_150;
    if (dynamic_cast<Class*>(getParent())) {
        if (dynamic_cast<Class*>(getParent())->explorerOrder())
            return 1;
    }
    return 0;
}
