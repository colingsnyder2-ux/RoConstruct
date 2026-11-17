// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_00659460 (placeholder name for 00659460 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "util/Vector3int32.h"
#include "v8world/SpatialHash2008.h"
#include "util/Name.h"

namespace RBX {

RBX::Vector3int32 sub_00659460(int shift, const G3D::Vector3& value)
{
	double scale = 1.0 / (double)(SpatialHash::gridSize << shift);
	G3D::Vector3 scaled;
	scaled.x = (float)(value.x * scale);
	scaled.y = (float)(value.y * scale);
	scaled.z = (float)(value.z * scale);
	return RBX::Vector3int32::floor(scaled);
}

}
