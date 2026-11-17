// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native Reflection::BoundFuncDesc explicit instances for the RunService void(void) 0-argument descriptor
// (ctors 0041c3e0, 0058b020, 005c4f80).
// Explicit class instantiation emits the constructor, execute and call members; no hand-written bodies.
#include "util/RunStateOwner.h"
#include "reflection/reflection.h"

using namespace RBX;
using namespace RBX::Reflection;

template class BoundFuncDesc<RunService, void(void), 0>;
