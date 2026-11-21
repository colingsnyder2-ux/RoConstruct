// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004d6ff0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Lighting2008.h"
#include "util/Name.h"

namespace RBX {

G3D::Color3 Lighting::getAmbient() const
{
	return ambient;
}

}
