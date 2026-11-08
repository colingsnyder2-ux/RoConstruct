#include "reflection/property.h"
namespace RBX { namespace Reflection {
template bool TypedPropertyDescriptor<bool>::isReadOnly() const;
template bool TypedPropertyDescriptor<bool>::isWriteOnly() const;
}}
