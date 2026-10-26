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
	DataModel::Lock::Lock(const DataModel* dataModel)
		: lock(NULL)
	{
		doLock(dataModel);
	}

	DataModel::Lock::Lock(boost::shared_ptr<const DataModel> dataModel)
		: lock(NULL)
	{
		doLock(dataModel.get());
	}

	// the services every place starts with (DataModel::clearContents empties the same set)
	void DataModel::initializeContents()
	{
		// the factory knows no classes until a FactoryRegistrator runs (the app shell owns one; rbxgs has no
		// shell): construct it once, before the first service is created by name
		static FactoryRegistrator factoryRegistrator;
		// the global settings items are created by name on first use (GlobalSettingsItem::singleton); naming
		// getCreator instantiates their factory creators here, which register them at startup
		(void)&DebugSettings::getCreator;
		(void)&GameSettings::getCreator;
		(void)&NetworkSettings::getCreator;
		workspace->setParent(this);
		runService = shared_from(ServiceProvider::create<RunService>(this));
		Notifier<RunService, RunTransition>::connect(runService.get(), this);
		starterPackService = shared_from(ServiceProvider::create<StarterPackService>(this));
		localBackpack = shared_from(ServiceProvider::create<LocalBackpack>(this));
		ServiceProvider::create<Lighting>(this);
		ServiceProvider::create<Teams>(this);
		ServiceProvider::create<ScriptContext>(this);
	}

	float DataModel::step(float interval)
	{
		float stepped = workspace->step(interval);
		getTimeState()->totalVirtualTime += stepped;
		return stepped;
	}

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
	void DataModel::closeDataModel(boost::shared_ptr<DataModel> dataModel, bool)
	{
		if (!dataModel)
			return;
		Lock lock(dataModel);
		dataModel->clearContents();
	}

	// one simulation step per frame period while running; views redraw after each step
	void RunService::runProc(boost::shared_ptr<DataModel> dataModel)
	{
		G3D::RealTime last = G3D::System::time();
		while (!stopRequested)
		{
			if (runState != RS_RUNNING)
			{
				boost::mutex::scoped_lock lock(runMutex);
				while (runState != RS_RUNNING && !stopRequested)
					stateChangedCondition.wait(lock);
				last = G3D::System::time();
				continue;
			}

			G3D::RealTime frameStart = G3D::System::time();
			{
				DataModel::Lock lock(dataModel.get());
				float stepped = dataModel->step(framePeriod);
				raiseStepped(dataModel->getSimTime(), stepped);
				raiseHeartbeat(dataModel->getSimTime(), (float)(frameStart - last));
			}
			last = frameStart;
			invalidateRunViews();

			double spare = framePeriod - (G3D::System::time() - frameStart);
			if (spare > 0)
				G3D::System::sleep(spare);
		}
	}

	// the current mouse command handles input; a handler may hand over to another command
	GuiResponse Workspace::process(const GuiEvent& event)
	{
		MouseCommand* command = currentCommand.get();
		if (!command)
			return GuiResponse::notUsed();

		MouseCommand* next = NULL;
		switch (event.eventType)
		{
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN: next = command->onMouseDown(event); break;
		case UIEvent::MOUSE_LEFT_BUTTON_UP: next = command->onMouseUp(event); break;
		case UIEvent::MOUSE_MOVE: command->onMouseMove(event); break;
		case UIEvent::MOUSE_DELTA: command->onMouseDelta(event); break;
		case UIEvent::MOUSE_IDLE: command->onMouseIdle(event); break;
		case UIEvent::KEY_DOWN: next = command->onKeyDown(event); break;
		default: return GuiResponse::notUsed();
		}
		if (next && next != command)
			setMouseCommand(next);
		return GuiResponse::used();
	}

	void Workspace::onEvent(const RunService*, Heartbeat)
	{
		if (Camera* camera = getCamera())
			camera->onHeartbeat();
	}

	bool Workspace::showWorldCoord = false;
	bool Workspace::showHashGrid = false;

	// scripts anywhere in the workspace run unless disabled
	IScriptOwner* Workspace::scriptShouldRun(Script* script)
	{
		return script->isDisabled() ? NULL : this;
	}

	// a backpack runs its local scripts only for the local player
	IScriptOwner* Backpack::scriptShouldRun(Script* script)
	{
		if (script->isDisabled() || !dynamic_cast<LocalScript*>(script))
			return NULL;
		return getParent() && getParent() == Network::Players::findLocalPlayer(this) ? this : NULL;
	}

	void IScriptOwner::runScript(Script* script, ScriptContext* context)
	{
		context->addScript(script);
	}

	void IScriptOwner::releaseScript(Script* script)
	{
		if (ScriptContext* context = ServiceProvider::find<ScriptContext>(script))
			context->removeScript(script);
	}

	bool Script::askSetParent(const Instance*) const
	{
		return true;
	}

	// surface inputs and parameters live in the primitive's surface data, as the getters read them
	void Surface::setSurfaceInput(Controller::InputType value)
	{
		SurfaceData data = partInstance->getPrimitive()->getSurfaceData(surfId);
		if (data.inputType != value)
		{
			data.inputType = value;
			partInstance->getPrimitive()->setSurfaceData(surfId, data);
			partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceInput(surfId));
		}
	}

	void Surface::setParamA(float value)
	{
		SurfaceData data = partInstance->getPrimitive()->getSurfaceData(surfId);
		if (data.paramA != value)
		{
			data.paramA = value;
			partInstance->getPrimitive()->setSurfaceData(surfId, data);
			partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamA(surfId));
		}
	}

	void Surface::setParamB(float value)
	{
		SurfaceData data = partInstance->getPrimitive()->getSurfaceData(surfId);
		if (data.paramB != value)
		{
			data.paramB = value;
			partInstance->getPrimitive()->setSurfaceData(surfId, data);
			partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamB(surfId));
		}
	}

	namespace Stats
	{
		void Item::setValue(double value, const std::string& text)
		{
			val = value;
			sValue = text;
		}

		// plain items hold whatever was last set; typed items override this
		void Item::update()
		{
		}
	}
}
