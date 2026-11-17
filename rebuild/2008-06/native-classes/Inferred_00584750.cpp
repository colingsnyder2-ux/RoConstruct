// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: RBX::Reflection::Value::sub_00584750 (placeholder name for 00584750 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <G3D/CoordinateFrame.h>
#include "reflection/type.h"
#include "AppUnit49C_2008/Streaming2008.h"

RBX::Reflection::Value& RBX::Reflection::Value::sub_00584750(const G3D::CoordinateFrame& cf)
{
	_type = &Type::singleton<G3D::CoordinateFrame>();
	value = cf;
	return *this;
}
