// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /U_RELEASEASSERT
// 2008-06 native Reflection::EnumDesc<NormalId>::EnumDesc() (registry placeholder func_0056fac0, 416 B), inactive.
// Identity: EnumDescriptor(name, type_info) ctor 0056c590 with "NormalId" 0082f7a4, then addPair 0064d530 with
// 1 "Top" 0081e504, 4 "Bottom", 2 "Back", 5 "Front", 0 "Right", 3 "Left" (0082f778..0082f790, 0081e4fc); the only
// direct caller is the doSingleton at 005ef4c0. Order and names of the 2007 analog (v8tree/enumproperty.cpp). Flags line
// copied from the sibling EnumDesc unit PartTypeEnums.cpp.
#include "util/NormalId.h"
#include "reflection/enumconverter.h"

namespace RBX {
namespace Reflection {

// 0056fac0
template <>
EnumDesc<NormalId>::EnumDesc() : EnumDescriptor("NormalId", typeid(NormalId))
{
	addPair(NORM_Y, "Top");
	addPair(NORM_Y_NEG, "Bottom");
	addPair(NORM_Z, "Back");
	addPair(NORM_Z_NEG, "Front");
	addPair(NORM_X, "Right");
	addPair(NORM_X_NEG, "Left");
}

}
}
