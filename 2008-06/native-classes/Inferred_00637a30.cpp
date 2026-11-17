// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_00637a30 (placeholder name for 00637a30 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "G3D/Vector3.h"
#include "reflection/signal.h"

void sub_00637a30(RBX::Reflection::SignalDescImpl<1, void(G3D::Vector3)>::GenericSlotAdapter* self, G3D::Vector3 v)
{
	(*self)(v);
}
