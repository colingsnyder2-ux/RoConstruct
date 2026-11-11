// Rebuild glue: the run loop and data-model members rbxgs declares but never defines. Behavioural
// reconstructions built from the rbxgs code around them (RunService::start, DataModel::createDataModel,
// Workspace::step, Surface getters); not byte-verified.
#include <RakPeer.h>  // first, as rbxgs Players.cpp: RakNet needs winsock2 before windows.h
#include "Network/Players.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/factoryregistration.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/GameSettings.h"
#include "NetworkSettings.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/JointsService.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/Surfaces.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Lighting.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/TimeState.h"
#include "v8datamodel/Stats.h"
#include "v8world/Primitive.h"
#include "util/RunStateOwner.h"
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "gui/GuiEvent.h"
#include <G3D/System.h>

namespace RBX
{
	// the services every place starts with (DataModel::clearContents empties the same set)


	float DataModel::getSimTime() const
	{
		return getTimeState()->totalVirtualTime;
	}

	// run a chunk with no arguments and discard its results (the other overloads push and read values)
	namespace
	{
		size_t pushNothing(lua_State*) { return 0; }
		void readNothing(lua_State*, size_t) {}
	}

	// the context's global Lua state, opened on first use as executeInNewThread does
	lua_State* ScriptContext::state()
	{
		openState();
		return globalState;
	}

	void ScriptContext::executeInNewThread(Security::Identities identity, const char* script, const char* name)
	{
		executeInNewThread(identity, script, name, &pushNothing, &readNothing);
	}

	// the shell closes a place by emptying it under the lock; the run thread is the shell's own
	// (RunService::runProc returns once the services are gone), so there is nothing else to join here

	// one simulation step per frame period while running; views redraw after each step

	// the current mouse command handles input; a handler may hand over to another command



	// scripts anywhere in the workspace run unless disabled

	// a backpack runs its local scripts only for the local player

	// surface inputs and parameters live in the primitive's surface data, as the getters read them



	namespace Stats
	{
		// plain items hold whatever was last set; typed items override this
	}
}
