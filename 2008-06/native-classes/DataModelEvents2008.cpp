// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native DataModel::onChildAdded 00575750 and DataModel::onEvent(RunService, RunTransition) 00575840 (inactive).
// Same logic as the 2007 donor DataModel.cpp:82/96 (read for evidence): a NetworkClient child locks play mode and nulls the
// workspace mouse command; run-state transitions drive the workspace (RS_RUNNING -> start, RS_PAUSED -> stop, back to
// RS_NORMAL from running -> reset). The 2008 onEvent first tests the flag at +0x259 (renderEnabled) and has no TimeState.
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	void DataModel::onChildAdded(Instance* child)
	{
		ServiceProvider::onChildAdded(child);

		if (child->getClassName() == "NetworkClient")
		{
			Verb* lockPlayMode = getVerb("LockPlayMode");
			if (lockPlayMode)
				lockPlayMode->doIt(NULL);

			workspace->setNullMouseCommand();
		}
	}

	void DataModel::onEvent(const RunService* source, RunTransition event)
	{
		if (!renderEnabled)
			return;

		switch (event.newState)
		{
		case RS_NORMAL:
			if (event.oldState == RS_RUNNING)
				workspace->reset();
			break;
		case RS_RUNNING:
			workspace->start();
			break;
		case RS_PAUSED:
			workspace->stop();
			break;
		}
	}
}
