// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 Reflection::BoundFuncDesc<Class, void(int), 1> ctor #2 bodies at 004a06b0
// (RBX::Network::Client) and 004a4760 (DHTMLWindow). Byte-identical disassembly; same body,
// different class/reloc targets. Ctor body is the // INFERRED: definition in reflection/BoundFuncDesc.h.
// Explicit class instantiation emits the constructor; no hand-written bodies here.
// MFC/ATL must be included before anything that pulls in windows.h.
#include "AppLeaves2008/DHTMLWindow2008.h"
#include "util/RunStateOwner.h"
#include "Network/Client2008.h"
#include "reflection/reflection.h"
#include "reflection/BoundFuncDesc.h"

namespace RBX
{
	namespace Reflection
	{

template class BoundFuncDesc<RBX::Network::Client, void(int), 1>;
template class BoundFuncDesc<::DHTMLWindow, void(int), 1>;

	}
}
