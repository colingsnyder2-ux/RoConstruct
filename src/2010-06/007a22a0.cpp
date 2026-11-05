// from server: 60% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Enums.cpp

// Candidate translation unit (score above; library headers required).
#include "appdraw/Part.h"
#include "reflection/enumconverter.h"

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x10105f50
template <>
EnumDesc<Part::PartType>::EnumDesc() : EnumDescriptor("PartType", typeid(Part::PartType))
{
	addPair(Part::BALL_PART, "Ball");
	addPair(Part::BLOCK_PART, "Block");
	addPair(Part::CYLINDER_PART, "Cylinder");
}

} // namespace Reflection
} // namespace RBX
