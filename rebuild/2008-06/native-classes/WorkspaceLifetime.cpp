// >>> native-status (generated) -- do not edit >>>
// WorkspaceLifetime | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8baffef7 | roc native-status --write
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/MouseCommand.h"
#include "v8world/World.h"
namespace RBX {
	Workspace::Workspace(IDataState* dataState)
		: VerbContainer(NULL),
		  dataState(dataState),
		  unknown0x3cc(NULL),
		  cameraTemplate(Creatable::create<Camera>()),
          unknown0x410(0.0), unknown0x418(0.0), unknown0x420(0.0),
		  profileWorkspaceStep(new Profiling::CodeProfiler("DataModel Step")),
		  profileWorkspaceStepInner(new Profiling::CodeProfiler("Workspace Step")),
		  profileWorkspaceAssemble(new Profiling::CodeProfiler("Workspace Assemble")),
		  profileRunServiceStepped(new Profiling::CodeProfiler("RunService Stepped")),
		  profileRunServiceHeartbeat(new Profiling::CodeProfiler("RunService Heartbeat")),
		  arrowCameraControls(false),
		  inMouselookMode(false),
		  isSimulating(false),
		  scriptContext(NULL),
		  imageServerViewHack(0)
	{
		RBXASSERT(dataState);
		
		setName("Workspace");

		profileWorkspaceStepInner->parent = profileWorkspaceStep.get();
        world->getProfileWorldStep().parent = profileWorkspaceStepInner.get();
        profileWorkspaceAssemble->parent = profileWorkspaceStep.get();
		profileRunServiceStepped->parent = profileWorkspaceStep.get();
		profileRunServiceHeartbeat->parent = profileWorkspaceStep.get();
	}

	Workspace::~Workspace() {}
}
