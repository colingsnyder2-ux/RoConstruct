// =============================================================================
// tool.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/tool.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Tool.h"

namespace RBX
{
	// 005fd3d0: single-instruction tail call. INFERRED: fn_00642fc0 is the unresolved target of the
	extern void fn_00642fc0();
	void Tool::sub_005fd3d0()
	{
		fn_00642fc0();
	}

	extern "C" { extern Reflection::PropDescriptor<Tool, int> prop_BackendToolState; }

	namespace { inline void emptyUpToWorkspace() {} inline void emptyUpToActivated() {}
	           inline void emptyDownFromWorkspace() {} }

	void Tool::setDesiredState(ToolState desiredState, const ServiceProvider* serviceProvider)
	{
		do
		{
			int next;

			if ((int)desiredState > (int)backendToolState)
			{
				switch (backendToolState)
				{
				case HAS_TORSO:    upTo_Equipped();     break;
				case IN_CHARACTER: upTo_HasTorso();     break;
				case IN_WORKSPACE: upTo_InCharacter();  break;
				case HAS_HANDLE:   emptyUpToWorkspace();   break;
				case NOTHING:      connectTouchEvent();    break;
				case EQUIPPED:     emptyUpToActivated();    break;
				case ACTIVATED:    emptyUpToActivated();    break;
				}
				next = (int)backendToolState + 1;
			}
			else if ((int)desiredState < (int)backendToolState)
			{
				switch (backendToolState)
				{
				case EQUIPPED:     downFrom_Equipped();    break;
				case HAS_TORSO:    downFrom_HasTorso();    break;
				case IN_CHARACTER: downFrom_InCharacter(); break;
				case IN_WORKSPACE: emptyDownFromWorkspace();  break;
				case HAS_HANDLE:   handleTouched.disconnect(); break; // downFrom_HasHandle() inlined
				case NOTHING:      emptyDownFromWorkspace(); break;
				}
				next = (int)backendToolState - 1;
			}
			else
			{
				continue;
			}

			// inlined setBackendToolState(next)
			if (next != (int)backendToolState)
			{
				setBackendToolStateNoReplicate(next);
				raisePropertyChanged(prop_BackendToolState);
			}
		}
		while ((int)desiredState != (int)backendToolState);
	}
}

#include "util/Name.h"

namespace RBX
{

void Tool::onEvent_AddedBackend(boost::shared_ptr<Instance> instance)
{
	if (instance.get() != this)
		rebuildBackendState();
}

}

namespace RBX
{

void Tool::upTo_InCharacter()
{
	characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}

#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"

namespace RBX
{

void Tool::upTo_HasTorso()
{
	Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
	PartInstance* torso = humanoid->getTorso();

	torsoChildAdded = Instance::event_childAdded.connect(torso, boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	torsoChildRemoved = Instance::event_childRemoved.connect(torso, boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}

#include "v8datamodel/Workspace.h"

namespace RBX
{
void Tool::setGripUp(const G3D::Vector3& v)
{
	G3D::CoordinateFrame c = grip;
	G3D::Vector3 col0 = c.rotation.getColumn(0);
	G3D::Vector3 oldZ = c.rotation.getColumn(2);

	G3D::Vector3 y = v.direction();
	G3D::Vector3 yc = y;
	G3D::Vector3 oldX = col0;

	G3D::Vector3 z = oldX.cross(yc);
	z.unitize();

	G3D::Vector3 yy = y;
	G3D::Vector3 zc = z;
	G3D::Vector3 x = yy.cross(zc);
	x.unitize();

	c.rotation.setColumn(0, x);
	c.rotation.setColumn(1, y);
	c.rotation.setColumn(2, z);

	setGrip(c);
}
}

namespace RBX
{
void Tool::setGripRight(const G3D::Vector3& v)
{
	G3D::CoordinateFrame c = grip;
	G3D::Vector3 col1 = c.rotation.getColumn(1);
	G3D::Vector3 oldZ = c.rotation.getColumn(2);

	G3D::Vector3 x = v.direction();
	G3D::Vector3 xc = x;
	G3D::Vector3 oldY = col1;

	G3D::Vector3 z = xc.cross(oldY);
	z.unitize();

	G3D::Vector3 xx = x;
	G3D::Vector3 zc = z;
	G3D::Vector3 y = zc.cross(xx);
	y.unitize();

	c.rotation.setColumn(0, x);
	c.rotation.setColumn(1, y);
	c.rotation.setColumn(2, z);

	setGrip(c);
}
}

namespace RBX
{
void Tool::dropAll(ModelInstance* character)
{
	Workspace* workspace = Workspace::findWorkspace(character);
	if (workspace) {
		Tool* tool = character->findFirstChildOfType<Tool>();
		while (tool) {
			tool->setParent(workspace);
			tool = character->findFirstChildOfType<Tool>();
		}
	}
}
}
