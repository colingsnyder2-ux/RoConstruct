// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// >>> native-status (generated) -- do not edit >>>
// WorldLifetime | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 48058515 | roc native-status --write
#undef _RELEASEASSERT
#include "v8world/World.h"
#include "v8world/JointStage.h"
#include "v8world/Contact.h"
#include "util/Debug.h"
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash.h"
#include "v8world/IWorldStage.h"
#include "v8world/Assembly.h"
#include "v8world/CollisionStage.h"
#include "v8world/SleepStage.h"
#include "v8world/ClumpStage.h"
#include "v8world/SimJobStage.h"
#include "v8world/JointBuilder.h"

namespace RBX {
World::World() : 
		throttlePercentage(100.0f),
        contactManager(new ContactManager(this)),
		jointStage(new JointStage(NULL, this)),
		inStepCode(false),
		inJointNotification(false),
		worldStepId(0),
		numJoints(0),
		numContacts(0),
		numLinkCalls(0),
		profilingWorldStep(new Profiling::CodeProfiler("World Step")),
		profilingPreStep(new Profiling::CodeProfiler("Pre Step")),
        profilingAssemblyStep(new Profiling::CodeProfiler("Assembly Step")),
        profilingUiStep(new Profiling::CodeProfiler("UI Step")),
        profilingPreStepInner(new Profiling::CodeProfiler("Pre Step 8 Inner")),
		profilingBroadphase(new Profiling::CodeProfiler("Broadphase"))
		{
            profilingAssemblyStep->parent = profilingWorldStep.get();
            profilingUiStep->parent = profilingWorldStep.get();
            profilingPreStep->parent = profilingWorldStep.get();
            profilingPreStepInner->parent = profilingWorldStep.get();
            profilingBroadphase->parent = profilingWorldStep.get();
            getCollisionStage()->profilingCollision->parent = profilingWorldStep.get();
            getSleepStage()->profilingSleep->parent = profilingWorldStep.get();
            jointStage->getKernel()->profilingKernel->parent = profilingWorldStep.get();
        }

World::~World()
	{
		RBXASSERT(numJoints == 0);
		RBXASSERT(numContacts == 0);
		RBXASSERT(primitives.size() == 0);
		RBXASSERT(breakableJoints.size() == 0);
		
		delete jointStage;
		delete contactManager;
	}

}
