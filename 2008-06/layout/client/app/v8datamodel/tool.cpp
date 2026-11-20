#include "v8datamodel/Tool.h"

#include "v8datamodel/Workspace.h"

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

// 005feed0: real name from the identity registry; body byte-proved against the native headers (named lane)
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

// 005fed60: real name from the identity registry; body byte-proved against the native headers (named lane)

namespace RBX {

void Tool::upTo_InCharacter()
{
	characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}

// 2008-06 native RBX::Tool (inactive): state-walk members of the original Tool unit 005fd3a0..006004d0.
// Statement order from donor tools/rbxgs v8datamodel/Tool.cpp (roc_espclaude_cc7153d713b9aac6.cpp.i).

namespace RBX
{
	// 005fd3d0: single-instruction tail call. INFERRED: fn_00642fc0 is the unresolved target of the
	// original 5-byte jmp; the name is not in the identity registry, so the member is kept as sub_005fd3d0.
	extern void fn_00642fc0();
	void Tool::sub_005fd3d0()
	{
		fn_00642fc0();
	}

	// 0097b7e0 is the C-linkage data symbol _prop_BackendToolState (identity registry), defined static in
	// native-classes/Tool.cpp. extern "C" reproduces that reference name.
	extern "C" { extern Reflection::PropDescriptor<Tool, int> prop_BackendToolState; }

	// The original unit defines these three helpers with empty bodies (donor 139563-139565). Local
	// inline empty stand-ins reproduce the inlined-to-nothing switch cases and the original 7/6-entry
	// jump tables without redefining Tool members from the separate Tool.cpp unit.
	namespace { inline void emptyUpToWorkspace() {} inline void emptyUpToActivated() {}
	           inline void emptyDownFromWorkspace() {} }

	// 005ff900: walk backendToolState one step at a time toward the desired state.
	// setBackendToolState is inlined here (it lives in the separate Tool.cpp unit); the donor body is
	// switch-on-backendToolState with all 7 up / 6 down enum cases.
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

// 2008-06 native RBX::Tool (inactive): the Tool part of the original Tool unit 005fd3a0..006004d0 (dynamic
// initializers 007f7640..007f7990, atexit functions 007fffc0..00800110). Evidence in native-headers/v8datamodel/Tool.h.
#include "Network/Players.h"
#include "v8xml/XmlElement.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/ToolMouseCommand.h"

namespace RBX
{
	const char sTool[] = "Tool"; // 008416d0 (classDescriptor 005c3810, constructor setName)

	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	// Dynamic initializers 007f7640, 007f76a0, 007f7700, 007f7760, 007f77c0, 007f7820, 007f7880, 007f78e0, 007f7910,
	// 007f7930, 007f7960, 007f7990 (in this order). Grip / BackendToolState / ActivationState push STREAMING (4),
	// GripPos / GripForward / GripUp / GripRight push UI (1).
	static Reflection::PropDescriptor<Tool, G3D::CoordinateFrame> prop_Grip("Grip", "Appearance", &Tool::getGrip, &Tool::setGrip, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripPos("GripPos", "Appearance", &Tool::getGripPos, &Tool::setGripPos, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripForward("GripForward", "Appearance", &Tool::getGripForward, &Tool::setGripForward, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripUp("GripUp", "Appearance", &Tool::getGripUp, &Tool::setGripUp, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripRight("GripRight", "Appearance", &Tool::getGripRight, &Tool::setGripRight, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, int> prop_BackendToolState("BackendToolState", "Appearance", &Tool::getBackendToolState, &Tool::setBackendToolState, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Tool, int> prop_FrontendActivationState("ActivationState", "Appearance", &Tool::getFrontendActivationState, &Tool::setFrontendActivationState, Reflection::PropertyDescriptor::STREAMING);
	Reflection::BoundProp<bool, 1> Tool::prop_Enabled("Enabled", "State", &Tool::enabled, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::SignalDesc<Tool, void(boost::shared_ptr<Instance>)> event_Equipped("Equipped", "mouse");
	static Reflection::SignalDesc<Tool, void(void)> event_Unequipped("Unequipped");
	static Reflection::SignalDesc<Tool, void(void)> event_Activated("Activated");
	static Reflection::SignalDesc<Tool, void(void)> event_Deactivated("Deactivated");

	// 005fd3e0: name_name 00975338, findAttribute 0057c2b0, getValue 0057c360, "BackendToolState" 008416e8,
	// "ActivationState" 008416d8, Instance::readProperty 00559170. Reads the public Name::name member directly, as the
	// exact sibling Accoutrement::readProperty 005b0840 does. Rejected: donor name->toString() (inline accessor marked
	// "guess" in util/Name.h): string pointer in eax and binder in edx where the original has edx / ecx.
	void Tool::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
	{
		const Name* name = NULL;
		if (const XmlAttribute* attrib = propertyElement->findAttribute(name_name))
		{
			if (attrib->getValue(name))
			{
				if (name->name == "BackendToolState" || name->name == "ActivationState")
					return;
			}
		}

		Instance::readProperty(propertyElement, binder);
	}

	void Tool::downFrom_InCharacter()
	{
		characterChildAdded.disconnect();
		characterChildRemoved.disconnect();
	}

	void Tool::downFrom_HasTorso()
	{
		torsoChildAdded.disconnect();
		torsoChildRemoved.disconnect();
	}

	const G3D::Vector3 Tool::getGripPos() const
	{
		return grip.translation;
	}

	const G3D::Vector3 Tool::getGripForward() const
	{
		return grip.lookVector();
	}

	const G3D::Vector3 Tool::getGripUp() const
	{
		return grip.upVector();
	}

	const G3D::Vector3 Tool::getGripRight() const
	{
		return grip.rightVector();
	}

	PartInstance* Tool::getHandle()
	{
		return const_cast<PartInstance*>(getHandleConst());
	}

	const G3D::CoordinateFrame Tool::getLocation() const
	{
		const PartInstance* handle = getHandleConst();
		return handle ? handle->getCoordinateFrame() : G3D::CoordinateFrame();
	}

	Tool::~Tool()
	{
	}

	void Tool::setBackendToolState(int value)
	{
		if (value != backendToolState)
		{
			setBackendToolStateNoReplicate(value);
			raisePropertyChanged(prop_BackendToolState);
		}
	}

	void Tool::setGripPos(const G3D::Vector3& v)
	{
		setGrip(G3D::CoordinateFrame(grip.rotation, v));
	}

	Tool::Tool()
		: backendToolState(NOTHING),
		  frontendActivationState(0),
		  toolMouseCommand(NULL),
		  enabled(true)
	{
		setName(sTool);
	}

	// 00600420: drawSelected inlines as backendToolState >= EQUIPPED (+0x1c4 >= 5).
	void Tool::setFrontendActivationState(int value)
	{
		int prevState = frontendActivationState;

		if (value > frontendActivationState)
		{
			frontendActivationState = value;
			raisePropertyChanged(prop_FrontendActivationState);

			if (ServiceProvider::findServiceProvider(this) && Network::Players::backendProcessing(this, true) && Tool::drawSelected())
			{
				if (value - 1 > prevState)
					setBackendToolState((value - 1) % 2 == 0 ? EQUIPPED : ACTIVATED);

				setBackendToolState(value % 2 == 0 ? EQUIPPED : ACTIVATED);
			}
		}
	}

	// 005ff680: toolMouseCommand +0x200 -> the inherited non-virtual ScriptMouseCommand::getMouse 005cf8d0 (direct call
	// 005ff6c7); otherwise Creatable<Instance>::create<Mouse> 005ff600.
	boost::shared_ptr<Mouse> Tool::getMouse()
	{
		boost::shared_ptr<Mouse> mouse;

		if (toolMouseCommand)
			mouse = toolMouseCommand->getMouse();
		else
			mouse = Creatable<Instance>::create<Mouse>();

		return mouse;
	}

	void Tool::activate()
	{
		setFrontendActivationState(frontendActivationState + (frontendActivationState % 2) + 1);
	}

	void Tool::deactivate()
	{
		setFrontendActivationState(frontendActivationState + ((frontendActivationState + 1) % 2) + 1);
	}
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sTool>();

// 2008-06 native RBX::Tool (inactive): event, state and grip members of the original Tool unit 005fd3a0..006004d0
// (the rest is native-classes/Tool.cpp, read-only). Flags copied from Tool.cpp. Shape after the donor
// tools/rbxgs v8datamodel/Tool.cpp, changed where the 2008 bytes differ (no Handle CanCollide toggle in
// setBackendToolStateNoReplicate). Evidence for the layout in native-headers/v8datamodel/Tool.h.
#include "v8datamodel/JointInstance.h"
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

#if 0 // BLOCKED (batch 25): v8datamodel/JointInstance.h declares Weld : DescribedCreatable<Weld, JointInstance, sWeld>
	// with no setC1; the original calls AutoJoint::setC1 005e44c0 on the weld (identity registry
	// ?setC1@AutoJoint@RBX@@QAEXABVCoordinateFrame@G3D@@@Z). Needs a JointInstance.h owner decision (setC0/setC1 reachable
	// from Weld); proposal in the batch 25 result. Guarded so the rest of this unit compiles.
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
#endif
}
