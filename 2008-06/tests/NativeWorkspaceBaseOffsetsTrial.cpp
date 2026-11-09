#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"

using namespace RBX;
typedef Notifier<Workspace, DrawChanged> DrawNotifier;
typedef Notifier<Workspace, ToolChanged> ToolNotifier;
typedef Listener<RunService, Heartbeat> HeartbeatListener;
typedef Notifier<Instance, ChildAdded> ChildNotifier;
#define OFFSET(name, type) int name() { return (char*)static_cast<type*>((Workspace*)0x10000) - (char*)0x10000; }
OFFSET(guiOffset, GuiTarget)
OFFSET(verbOffset, VerbContainer)
OFFSET(movingOffset, IMovingManager)
OFFSET(scriptOffset, IScriptOwner)
OFFSET(drawOffset, DrawNotifier)
OFFSET(toolOffset, ToolNotifier)
OFFSET(heartbeatOffset, HeartbeatListener)
OFFSET(cameraOffset, ICameraOwner)
OFFSET(renderOffset, IRenderable)
OFFSET(controllableOffset, IControllable)
OFFSET(childNotifierOffset, ChildNotifier)
