// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 2008-06 native RBX::Reflection::EnumDescriptor members of the reflection type unit (0056bf90..0056c520 lies
// between the signal unit 0056a590..0056bd8f and the TypedPropertyDescriptor/Value rows of Inferred_0056f0b0.cpp).
// reflection/enumconverter.h (core, read-only) declares ~EnumDescriptor out of line; allEnums() 0056bf90 is the
// out-of-line private static accessor it calls three times.
#include "reflection/enumconverter.h"
#include <algorithm>

namespace RBX
{
	namespace Reflection
	{
		// 0056c080 ??1EnumDescriptor@Reflection@RBX@@MAE@XZ: vtable 0082f648 stored first; the descriptor removes
		// itself from allEnums() (std::find then vector::erase 00459830), then allItems and the Type base are
		// destroyed (Type vtable 0080b730 restored last).
		EnumDescriptor::~EnumDescriptor()
		{
			allEnums().erase(std::find(allEnums().begin(), allEnums().end(), this));
		}
	}
}
