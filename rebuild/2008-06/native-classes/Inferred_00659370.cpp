// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00659370 (placeholder name for 00659370 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <v8world/SpatialHash.h>
#include <utility>
#include "util/Name.h"

namespace RBX {

std::pair<Vector3int32, Vector3int32> __cdecl sub_00659370(int fromLevel, int toLevel, const std::pair<Vector3int32, Vector3int32>& source)
{
	int shift = toLevel - fromLevel;

	Vector3int32 second;
	second.x = source.second.x >> shift;
	second.y = source.second.y >> shift;
	second.z = source.second.z >> shift;

	Vector3int32 first;
	first.x = source.first.x >> shift;
	first.y = source.first.y >> shift;
	first.z = source.first.z >> shift;

	return std::pair<Vector3int32, Vector3int32>(first, second);
}

}
