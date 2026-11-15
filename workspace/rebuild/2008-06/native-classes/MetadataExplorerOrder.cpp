// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "reflection/Metadata.h"

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

namespace RBX {
namespace Reflection {
namespace Metadata {
Class::Class()
    : unknown_150(-1)
    , unknown_154(0)
{
}
}
}
}

