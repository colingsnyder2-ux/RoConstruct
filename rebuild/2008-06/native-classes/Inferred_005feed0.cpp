// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005feed0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Tool.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "util/Name.h"

namespace RBX {

void Tool::upTo_HasTorso()
{
	Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
	PartInstance* torso = humanoid->getTorso();

	torsoChildAdded = Instance::event_childAdded.connect(torso, boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	torsoChildRemoved = Instance::event_childRemoved.connect(torso, boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}
