// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005dd820 (placeholder name for 005dd820 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "../../../tools/rbxgs/Client/App/include/util/Math.h"

namespace RBX {

inline bool sub_isDenormal(float value)
{
	unsigned int bits = *reinterpret_cast<unsigned int*>(&value);
	return (bits & 0x7f800000u) == 0 &&
	       (bits & 0x007fffffu) != 0;
}

#pragma float_control(precise, off, push)

int __cdecl sub_005dd820(float value)
{
	if (Math::isNanInfDenorm(value) || sub_isDenormal(value))
		return 1;
	return 0;
}

#pragma float_control(pop)

}
