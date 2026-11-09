// from server: 100% by sophus
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_12e000dc97c65257.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"
#include <G3D/Vector2int16.h>

namespace RBX {
namespace Reflection {
template<>
const Type& Type::singleton<G3D::Vector2int16>()
{
    static Type type("Vector2int16", typeid(G3D::Vector2int16));
    return type;
}
}
}
