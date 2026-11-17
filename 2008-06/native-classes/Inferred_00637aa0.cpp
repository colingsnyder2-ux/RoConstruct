// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_00637aa0 (placeholder name for 00637aa0 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "util/Name.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "G3D/Color3.h"
#include "reflection/signal.h"

namespace RBX {
void sub_00637aa0(void* function_obj_ptr, G3D::Color3 a0)
{
	typedef Reflection::SignalDescImpl<1, void(G3D::Color3)>::GenericSlotAdapter FunctionObj;
	FunctionObj* f = reinterpret_cast<FunctionObj*>(function_obj_ptr);
	(*f)(a0);
}
}
