#include "v8datamodel/Tool.h"
#include "v8datamodel/PartInstance.h"
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

template void RBX::Name::callDoDeclare<RBX::sTool>();

#include "util/Name.h"

namespace RBX {

void Tool::onEvent_AddedBackend(boost::shared_ptr<Instance> instance)
{
	if (instance.get() != this)
		rebuildBackendState();
}

}

namespace RBX {

void Tool::upTo_InCharacter()
{
	characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}

#include "humanoid/Humanoid.h"

namespace RBX {

void Tool::upTo_HasTorso()
{
	Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
	PartInstance* torso = humanoid->getTorso();

	torsoChildAdded = Instance::event_childAdded.connect(torso, boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	torsoChildRemoved = Instance::event_childRemoved.connect(torso, boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

}

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
