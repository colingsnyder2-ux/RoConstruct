// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 005df140: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "G3D/Matrix3.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "util/Name.h"

struct Matrix3;

void __cdecl rotate(::Matrix3& matrix, float angle)
{
	G3D::Matrix3& m = reinterpret_cast<G3D::Matrix3&>(matrix);
	G3D::Matrix3 r = G3D::Matrix3::fromAxisAngle(G3D::Vector3::unitY(), angle);
	m = r * m;
}
