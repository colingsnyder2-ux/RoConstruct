// >>> native-status (generated) -- do not edit >>>
// MetadataReflectionLifetime | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src e667c795 | roc native-status --write
#include "reflection/Metadata.h"
namespace RBX {
template<typename Class, typename DerivedClass, const char* ClassName>
FactoryProduct<Class, DerivedClass, ClassName>::FactoryProduct() {}
template<typename Class, typename DerivedClass, const char* ClassName>
DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable() {}
template<> const Name& FactoryProduct<Metadata::Reflection, Instance, Metadata::sReflection>::getClassName() const
{
    return Name::declare<Metadata::sReflection>();
}
namespace Metadata {
char sReflection[] = "ReflectionMetadata";
Reflection::Reflection() : classes(NULL) {}
Reflection::~Reflection() {}
bool Reflection::askAddChild(const Instance* child) const
{
    return dynamic_cast<const RBX::Reflection::Metadata::Classes*>(child) != NULL;
}
}}
