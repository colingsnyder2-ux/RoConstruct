#include "v8datamodel/Tool.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Mouse.h"
#include "humanoid/Humanoid.h"
#include "Network/Players.h"
#include "Network/Player.h"
#include "v8datamodel/Backpack.h"

namespace RBX
{
	extern Reflection::PropDescriptor<Tool, G3D::CoordinateFrame> prop_Grip;            // 0097b7a8
	extern Reflection::SignalDesc<Tool, void(boost::shared_ptr<Instance>)> event_Equipped; // 0097b758
	extern Reflection::SignalDesc<Tool, void(void)> event_Unequipped;                    // 0097b708
	extern Reflection::SignalDesc<Tool, void(void)> event_Activated;                     // 0097b818
	extern Reflection::SignalDesc<Tool, void(void)> event_Deactivated;                   // 0097b6d4

	bool Tool::characterCanUnequipTool(ModelInstance* character)
	{
		if (character && Humanoid::modelIsCharacter(character))
		{
			Tool* tool = character->findFirstChildOfType<Tool>();
			if (tool)
				return tool->canUnequip();
		}

		return true;
	}

	void Tool::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (IRenderable* renderable = dynamic_cast<IRenderable*>(getChild(i)))
				renderable->render3dSelect(adorn, selectState);
		}
	}

	void Tool::onLocalClicked()
	{
		Network::Player* localPlayer = Network::Players::findLocalPlayer(this);
		if (localPlayer && characterCanUnequipTool(localPlayer->getCharacter()))
		{
			if (getParent() == localPlayer->getPlayerBackpack())
			{
				moveAllToolsToBackpack(localPlayer);
				setParent(localPlayer->getCharacter());
			}
			else
			{
				setParent(localPlayer->getPlayerBackpack());
			}
		}
	}

	void Tool::onLocalOtherClicked()
	{
		Network::Player* localPlayer = Network::Players::findLocalPlayer(this);
		if (localPlayer && characterCanUnequipTool(localPlayer->getCharacter()))
		{
			if (getParent() != localPlayer->getPlayerBackpack())
			{
				setParent(localPlayer->getPlayerBackpack());
			}
		}
	}

	void Tool::setBackendToolStateNoReplicate(int value)
	{
		ToolState state = (ToolState)value;

		if (backendToolState < EQUIPPED && state >= EQUIPPED)
		{
			onEquipping();
			event_Equipped.fire(this, getMouse());
		}

		if (state == ACTIVATED)
			event_Activated.fire(this);

		if (backendToolState == ACTIVATED)
			event_Deactivated.fire(this);

		if (backendToolState >= EQUIPPED && state < EQUIPPED)
		{
			event_Unequipped.fire(this);

			if (toolMouseCommand)
			{
				toolMouseCommand = NULL;
				workspace->setDefaultMouseCommand();
				workspace = NULL;
			}
		}

		backendToolState = state;
	}

	void Tool::onAncestorChanged(const AncestorChanged& event)
	{
		ToolState oldState = backendToolState;

		const ServiceProvider* oldProvider = ServiceProvider::findServiceProvider(event.oldParent);
		const ServiceProvider* newProvider = ServiceProvider::findServiceProvider(event.newParent);

		if (oldProvider)
		{
			if (Network::Players::backendProcessing(oldProvider, true))
				setDesiredState(NOTHING, oldProvider);
			else
				setBackendToolStateNoReplicate(NOTHING);
		}

		Instance::onAncestorChanged(event);

		if (newProvider)
		{
			if (Network::Players::backendProcessing(newProvider, true))
			{
				rebuildBackendState();
			}
			else if (getParent() == Network::Players::findLocalCharacter(this))
			{
				if (oldState >= EQUIPPED)
					setBackendToolStateNoReplicate(HAS_TORSO);

				setBackendToolStateNoReplicate(EQUIPPED);
			}
		}
	}

#if 0 // BLOCKED (batch 25): v8datamodel/JointInstance.h declares Weld : DescribedCreatable<Weld, JointInstance, sWeld>
	void Tool::setGrip(const G3D::CoordinateFrame& value)
	{
		if (value != grip)
		{
			grip = value;

			if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
				workspace->raiseDrawChanged();

			raisePropertyChanged(prop_Grip);

			if (weld)
				weld->setC1(grip);
		}
	}
#endif
}

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

namespace RBX {

void Tool::upTo_InCharacter()
{
	characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}

namespace RBX {

void Tool::upTo_HasTorso()
{
	Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
	PartInstance* torso = humanoid->getTorso();

	torsoChildAdded = Instance::event_childAdded.connect(torso, boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	torsoChildRemoved = Instance::event_childRemoved.connect(torso, boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}

namespace RBX {
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

namespace RBX {
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

namespace RBX {
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
