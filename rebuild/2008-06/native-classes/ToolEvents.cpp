// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Tool (inactive): event, state and grip members of the original Tool unit 005fd3a0..006004d0
// (the rest is native-classes/Tool.cpp, read-only). Flags copied from Tool.cpp. Shape after the donor
// tools/rbxgs v8datamodel/Tool.cpp, changed where the 2008 bytes differ (no Handle CanCollide toggle in
// setBackendToolStateNoReplicate). Evidence for the layout in native-headers/v8datamodel/Tool.h.
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
	// Defined in native-classes/Tool.cpp. Proposal: drop `static` there so this unit can link to them.
	extern Reflection::PropDescriptor<Tool, G3D::CoordinateFrame> prop_Grip;            // 0097b7a8
	extern Reflection::SignalDesc<Tool, void(boost::shared_ptr<Instance>)> event_Equipped; // 0097b758
	extern Reflection::SignalDesc<Tool, void(void)> event_Unequipped;                    // 0097b708
	extern Reflection::SignalDesc<Tool, void(void)> event_Activated;                     // 0097b818
	extern Reflection::SignalDesc<Tool, void(void)> event_Deactivated;                   // 0097b6d4

	// Inlined into onLocalClicked 005fe140 / onLocalOtherClicked 005fe1d0: Humanoid::modelIsCharacter 005d9a20,
	// findFirstChildOfType<Tool> 005fdf00, canUnequip (vtable slot 0x8c).
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

	// 005fdaf0 (ISelectable3d this): children loop, __RTDynamicCast to IRenderable, render3dSelect (slot 0x10)
	void Tool::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (IRenderable* renderable = dynamic_cast<IRenderable*>(getChild(i)))
				renderable->render3dSelect(adorn, selectState);
		}
	}

	// 005fe140: findLocalPlayer 0049ac80, getPlayerBackpack 0048c470, moveAllToolsToBackpack 005fdfe0,
	// setParent 0055a8f0
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

	// 005fe1d0
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

	// 005ff750: onEquipping 005ff1a0, getMouse 005ff680, SignalDesc fire 0049d200 / 0056b620 + 004b5950,
	// Workspace::setDefaultMouseCommand 005a2730. The 2008 body has no Handle CanCollide toggle.
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

	// 005ffa10: findServiceProvider 004898d0 (old / new parent), backendProcessing 00495eb0, setDesiredState 005ff900,
	// Instance::onAncestorChanged 0055acc0, rebuildBackendState 005fdb70, findLocalCharacter 0049aca0. The frontend
	// branch for the old provider is setBackendToolStateNoReplicate(NOTHING) inlined.
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

	// 005ffb70: CoordinateFrame != 004765e0, find<Workspace> 00491e50, raiseDrawChanged (Notifier raise 00576940 at
	// Workspace +0x344), raisePropertyChanged 0040db00 (prop_Grip 0097b7a8), weld (+0x1a4) setC1 005e44c0
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
}
