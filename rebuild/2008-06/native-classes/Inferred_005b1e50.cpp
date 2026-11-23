// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005b1e50: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Accoutrement.h"
#include "util/Name.h"

namespace RBX {

// INFERRED: noinline like downFrom_InCharacter in Accoutrement.cpp; the exe calls 005b1e50 from setDesiredState, joined into one TU MSVC inlines it.
__declspec(noinline) void Accoutrement::upTo_InCharacter()
{
	characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Accoutrement::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Accoutrement::onEvent_RemovedBackend, this, _1), 10);
}

}
