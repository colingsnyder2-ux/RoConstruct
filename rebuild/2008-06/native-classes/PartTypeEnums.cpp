// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /U_RELEASEASSERT
// 2008-06 native v8datamodel/Enums.cpp (inactive): Reflection::EnumDesc<Part::PartType>::EnumDesc() 00614e00
// (registry placeholder func_00614e00), between the IMoving unit (00614be0..00614dfa) and Controller 00614f80.
// Identity: the stored vftable 00832dc4 is RTTI .?AV?$EnumDesc@W4PartType@Part@RBX@@@Reflection@RBX@@, the
// EnumDescriptor(name, type_info) ctor 0056c590 gets "PartType" 008438d8 and the PartType type_info 0095a8a4, and the
// three addPair 0064d530 calls pass 0 "Ball" 008438d0, 1 "Block" 00832dcc, 2 "Cylinder" 00833370 (openrbx
// Client/App/v8datamodel/Enums.cpp; flags line copied from the sibling EnumDesc unit Camera.cpp).
#include "AppDraw/Part.h"
#include "reflection/enumconverter.h"

namespace RBX {
namespace Reflection {

// 00614e00
template <>
EnumDesc<Part::PartType>::EnumDesc() : EnumDescriptor("PartType", typeid(Part::PartType))
{
	addPair(Part::BALL_PART, "Ball");
	addPair(Part::BLOCK_PART, "Block");
	addPair(Part::CYLINDER_PART, "Cylinder");
}

} // namespace Reflection
} // namespace RBX
