// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/reflection/Metadata.h"

namespace RBX {
namespace Metadata {
RBX::Reflection::Metadata::Class* Reflection::lookup(const RBX::Reflection::ClassDescriptor& descriptor, bool flag) const
{
    if (classes)
        return classes->lookup(descriptor, flag);
    return 0;
}
}
}
