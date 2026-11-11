// >>> native-status (generated) -- do not edit >>>
// MetadataReflectionLifetime | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by atomic.potato (+1) (ntech:glm-4.5-air)
// <<< native-status | src aa7612a4 | roc native-status --write
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

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::Metadata::sReflection>();
