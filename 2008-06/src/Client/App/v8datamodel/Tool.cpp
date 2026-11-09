#pragma float_control(precise, off)
#include "v8datamodel/Tool.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/ToolMouseCommand.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/Backpack.h"
#include "tool/DragUtilities.h"
#include "humanoid/Humanoid.h"
#include "Network/Players.h"
#include "v8xml/SerializerV2.h"

namespace RBX
{
	const char* const sTool = "Tool";

	static Reflection::PropDescriptor<Tool, G3D::CoordinateFrame> prop_Grip("Grip", "Appearance", &Tool::getGrip, &Tool::setGrip, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripPos("GripPos", "Appearance", &Tool::getGripPos, &Tool::setGripPos, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripForward("GripForward", "Appearance", &Tool::getGripForward, &Tool::setGripForward, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripUp("GripUp", "Appearance", &Tool::getGripUp, &Tool::setGripUp, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripRight("GripRight", "Appearance", &Tool::getGripRight, &Tool::setGripRight, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Tool, int> prop_BackendToolState("BackendToolState", "Appearance", &Tool::getBackendToolState, &Tool::setBackendToolState, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Tool, int> prop_FrontendActivationState("ActivationState", "Appearance", &Tool::getFrontendActivationState, &Tool::setFrontendActivationState, Reflection::PropertyDescriptor::STREAMING);

	static Reflection::SignalDesc<Tool, void(boost::shared_ptr<Instance>)> event_Equipped("Equipped", "mouse");
	static Reflection::SignalDesc<Tool, void(void)> event_Unequipped("Unequipped");
	static Reflection::SignalDesc<Tool, void(void)> event_Activated("Activated");
	static Reflection::SignalDesc<Tool, void(void)> event_Deactivated("Deactivated");

	Reflection::BoundProp<bool, 1> Tool::prop_Enabled("Enabled", "State", &Tool::enabled, Reflection::PropertyDescriptor::STANDARD);

	Tool::Tool()
		: backendToolState(NOTHING),
		  frontendActivationState(0),
		  toolMouseCommand(NULL),
		  enabled(true)
	{
		setName("Tool");
	}

	Tool::~Tool()
	{
		RBXASSERT(!handleTouched.connected());
		RBXASSERT(!characterChildAdded.connected());
		RBXASSERT(!characterChildRemoved.connected());
		RBXASSERT(!torsoChildAdded.connected());
		RBXASSERT(!torsoChildRemoved.connected());
	}

	//99.46% match
	//different register allocation
	void Tool::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
	{
		const Name* name = NULL;

		if (propertyElement->findAttributeValue(name_name, name))
		{
			if (name->toString() == "BackendToolState" || name->toString() == "ActivationState")
				return;
		}

		Instance::readProperty(propertyElement, binder);
	}

	Tool::ToolState Tool::computeDesiredState()
	{
		if (!getHandleConst())
			return NOTHING;

		if (!Workspace::contextInWorkspace(this))
			return HAS_HANDLE;

		return computeDesiredState(getParent());
	}

	Tool::ToolState Tool::computeDesiredState(Instance* testParent)
	{
		Humanoid* humanoid = Humanoid::modelIsCharacter(testParent);
		if (!humanoid)
			return IN_WORKSPACE;

		if (!humanoid->getTorso())
			return IN_CHARACTER;

		if (!humanoid->findRightArm() || !humanoid->findRightShoulder())
			return HAS_TORSO;

		return EQUIPPED;
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

	void Tool::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (IRenderable* renderable = queryTypedChild<IRenderable>((int)i))
				renderable->render3dSelect(adorn, selectState);
		}
	}

	void Tool::rebuildBackendState()
	{
		ToolState state = computeDesiredState();
		setDesiredState(state, ServiceProvider::findServiceProvider(this));
	}

	void Tool::onEvent_AddedBackend(boost::shared_ptr<Instance> child)
	{
		if (child.get() != this)
		{
			rebuildBackendState();
		}
	}

	void Tool::onEvent_RemovedBackend(boost::shared_ptr<Instance> child)
	{
		if (ServiceProvider::findServiceProvider(this) && child.get() != this)
		{
			if (child.get() == (Instance*)this->weld.get())
			{
				setDesiredState(HAS_TORSO, ServiceProvider::findServiceProvider(this));
			}

			rebuildBackendState();
		}
	}

	int Tool::getNumToolsInCharacter()
	{
		int total = 0;

		if (Humanoid::modelIsCharacter(getParent()))
		{
			Instance* parent = getParent();

			for (size_t i = 0; i < parent->numChildren(); i++)
			{
				if (dynamic_cast<Tool*>(parent->getChild(i)))
					total++;
			}
		}

		return total;
	}

	void Tool::moveAllToolsToBackpack(Network::Player* player)
	{
		if (player)
		{
			if (ModelInstance* character = player->getCharacter())
			{
				while (Tool* tool = character->findFirstChildOfType<Tool>())
				{
					tool->setParent(player->getPlayerBackpack());
				}
			}
		}
	}

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

	void Tool::onEvent_HandleTouched(boost::shared_ptr<Instance> other)
	{
		                                                          ;

		if (backendToolState == IN_WORKSPACE)
		{
			Instance* otherParent = other->getParent();
			if (computeDesiredState(otherParent) == EQUIPPED && characterCanUnequipTool(dynamic_cast<ModelInstance*>(otherParent)))
			{
				Network::Player* player = Network::Players::getPlayerFromCharacter(otherParent);
				if (player && canBePickedUpByPlayer(player))
				{
					moveAllToolsToBackpack(player);
					setParent(otherParent);
					                                       ;
				}
			}
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

	void Tool::upTo_Equipped()
	{
		handleTouched.disconnect();

		std::vector<boost::weak_ptr<PartInstance>> parts;
		PartInstance::findParts(this, parts);
		DragUtilities::unJoinFromOutsiders(parts);

		Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
		PartInstance* rightArm = humanoid->getRightArm();

		PartInstance* handle = getHandle();
		if (handle)
			handle->setCanCollide(false);

		buildWeld(rightArm, handle, humanoid->getRightArmGrip(), grip, "RightGrip");
	}

	void Tool::connectTouchEvent()
	{
		if (PartInstance* handle = getHandle())
		{
			handleTouched = PartInstance::event_Touched.connect(handle, boost::bind(&Tool::onEvent_HandleTouched, this, _1), 10);
		}
		else
		{
			handleTouched.disconnect();
		}
	}

	void Tool::upTo_InCharacter()
	{
		characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
		characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
	}

	void Tool::upTo_HasTorso()
	{
		Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
		PartInstance* torso = humanoid->getTorso();

		torsoChildAdded = Instance::event_childAdded.connect(torso, boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
		torsoChildRemoved = Instance::event_childRemoved.connect(torso, boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
	}

	void Tool::onEquipping()
	{
		Instance* parent = getParent();
		if (parent && parent == Network::Players::findLocalCharacter(this))
		{
			                                                           ;

			workspace = ServiceProvider::find<Workspace>(this);
			toolMouseCommand = new ToolMouseCommand(workspace, this);

			workspace->setMouseCommand(toolMouseCommand);
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

	void Tool::setBackendToolState(int value)
	{
		if (value != backendToolState)
		{
			setBackendToolStateNoReplicate(value);
			raisePropertyChanged(prop_BackendToolState);
		}
	}

	void Tool::setGrip(const G3D::CoordinateFrame& value)
	{
		if (value != grip)
		{
			grip = value;

			if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
				workspace->raiseDrawChanged();

			raisePropertyChanged(prop_Grip);

			if (weld)
			{
				                                                          ;
				weld->setC1(grip);
			}
		}
	}

	void Tool::setGripPos(const G3D::Vector3& v)
	{
		setGrip(G3D::CoordinateFrame(grip.rotation, v));
	}

	void Tool::setGripForward(const G3D::Vector3& v)
	{
		G3D::CoordinateFrame c = grip;
		G3D::Vector3 oldX = c.rightVector();
		G3D::Vector3 oldY = c.upVector();

		G3D::Vector3 z = -v.direction();

		G3D::Vector3 x = oldY.cross(z);
		x.unitize();

		G3D::Vector3 y = z.cross(x);
		y.unitize();
		
		c.rotation.setColumn(0, x);
		c.rotation.setColumn(1, y);
		c.rotation.setColumn(2, z);

		setGrip(c);
	}

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

	const PartInstance* Tool::getHandleConst() const
	{
		return dynamic_cast<PartInstance*>(findFirstChildByName("Handle"));
	}

	boost::shared_ptr<Mouse> Tool::getMouse()
	{
		boost::shared_ptr<Mouse> mouse;

		if (toolMouseCommand)
			mouse = toolMouseCommand->getMouse();
		else
			mouse = Creatable::create<Mouse>();

		return mouse;
	}

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

	void Tool::upTo_Activated() // guess based on setDesiredState
	{
		return;
	}

	void Tool::upTo_HasHandle() // guess based on setDesiredState
	{
		connectTouchEvent();
	}

	void Tool::downFrom_InWorkspace() // guess based on setDesiredState
	{
		return;
	}

	void Tool::downFrom_HasHandle() // guess based on setDesiredState
	{
		handleTouched.disconnect();
	}

	void Tool::upTo_InWorkspace()
	{
		RBXASSERT(ServiceProvider::findServiceProvider(this));
		RBXASSERT(Network::Players::backendProcessing(this, true));
	}

	void Tool::downFrom_Equipped()
	{
		ModelInstance* character = NULL;

		if (weld)
		{
			PartInstance* part = weld->getPart0();
			if (part)
				character = dynamic_cast<ModelInstance*>(part->getParent());

			weld->setParent(NULL);
			weld.reset();
		}

		if (Humanoid::modelIsCharacter(character))
		{
			G3D::CoordinateFrame cf = character->getLocation();
			G3D::Vector3 pos = cf.translation;
			pos.y += 4.0f;
			pos += cf.lookVector() * 8.0f;

			PartInstance* handle = getHandle();
			if (handle)
			{
				handle->moveToPoint(pos);
				handle->setRotationalVelocity(G3D::Vector3(1.0f, 1.0f, 1.0f));
			}
		}

		connectTouchEvent();
	}

	void Tool::setDesiredState(ToolState desiredState, const ServiceProvider* serviceProvider)
	{
		int numToolsInCharacter;
		RBXASSERT((numToolsInCharacter = getNumToolsInCharacter(), true)); // what
		RBXASSERT(Network::Players::backendProcessing(serviceProvider, true));

		if (backendToolState < desiredState)
		{
			switch (backendToolState)
			{
			case ACTIVATED:
				RBXASSERT(false);
				break;
			case EQUIPPED:
				upTo_Activated();
				break;
			case HAS_TORSO:
				upTo_Equipped();
				break;
			case IN_CHARACTER:
				upTo_HasTorso();
				break;
			case IN_WORKSPACE:
				upTo_InCharacter();
				break;
			case HAS_HANDLE:
				upTo_InWorkspace();
				break;
			case NOTHING:
				upTo_HasHandle();
				break;
			}

			setBackendToolState(backendToolState + 1);
		}
		else if (desiredState < backendToolState)
		{
			switch (backendToolState)
			{
			case EQUIPPED:
				downFrom_Equipped();
				break;
			case HAS_TORSO:
				downFrom_HasTorso();
				break;
			case IN_CHARACTER:
				downFrom_InCharacter();
				break;
			case IN_WORKSPACE:
				downFrom_InWorkspace();
				break;
			case HAS_HANDLE:
				downFrom_HasHandle();
				break;
			case NOTHING:
				RBXASSERT(false);
				break;
			}

			setBackendToolState(backendToolState - 1);
		}

		if (desiredState != backendToolState)
			setDesiredState(desiredState, serviceProvider);

		RBXASSERT(numToolsInCharacter == getNumToolsInCharacter());
	}

	void Tool::onAncestorChanged(const AncestorChanged& event)
	{
		int numToolsInCharacter;
		RBXASSERT((numToolsInCharacter = getNumToolsInCharacter(), true)); // what

		const ServiceProvider* oldProvider = ServiceProvider::findServiceProvider(event.oldParent);
		const ServiceProvider* newProvider = ServiceProvider::findServiceProvider(event.newParent);

		if (oldProvider)
		{
			if (Network::Players::backendProcessing(oldProvider, true))
			{
				setDesiredState(NOTHING, oldProvider);
			}
			else
			{
				setBackendToolStateNoReplicate(NOTHING);
			}
		}

		Instance::onAncestorChanged(event);

		if (newProvider)
		{
			if (Network::Players::backendProcessing(newProvider, true))
			{
				ToolState state = computeDesiredState();
				const ServiceProvider* thisProvider = ServiceProvider::findServiceProvider(this);
				RBXASSERT(thisProvider);

				setDesiredState(state, thisProvider);
			}
		}

		RBXASSERT(numToolsInCharacter == getNumToolsInCharacter());
	}

	void Tool::activate()
	{
		                                                           ;
		setFrontendActivationState(frontendActivationState + (frontendActivationState % 2) + 1);
	}

	void Tool::deactivate()
	{
		                                                           ;
		setFrontendActivationState(frontendActivationState + ((frontendActivationState + 1) % 2) + 1);
	}
}
