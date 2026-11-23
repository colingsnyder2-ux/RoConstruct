// =============================================================================
// ReflectionMetadata.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/ReflectionMetadata.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "reflection/Metadata.h"
namespace RBX
{
template<typename Class, typename DerivedClass, const char* ClassName>
FactoryProduct<Class, DerivedClass, ClassName>::FactoryProduct() {}
template<typename Class, typename DerivedClass, const char* ClassName>
DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable() {}
template<> const Name& FactoryProduct<Metadata::Reflection, Instance, Metadata::sReflection>::getClassName() const
{
    return Name::declare<Metadata::sReflection>();
}
namespace Metadata
{
char sReflection[] = "ReflectionMetadata";
Reflection::Reflection() : classes(NULL) {}
Reflection::~Reflection() {}
bool Reflection::askAddChild(const Instance* child) const
{
    return dynamic_cast<const RBX::Reflection::Metadata::Classes*>(child) != NULL;
}
}}

template void RBX::Name::callDoDeclare<RBX::Metadata::sReflection>();
