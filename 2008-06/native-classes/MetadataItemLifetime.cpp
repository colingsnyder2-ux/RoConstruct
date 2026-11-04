#include "reflection/Metadata.h"
namespace RBX {
template<> const Name& NonFactoryProduct<Instance, Reflection::Metadata::sItem>::getClassName() const
{
    return Name::declare<Reflection::Metadata::sItem>();
}
namespace Reflection { namespace Metadata {
Item::Item() : unknown_130(true), unknown_131(false), unknown_132(false) {}
}}}
