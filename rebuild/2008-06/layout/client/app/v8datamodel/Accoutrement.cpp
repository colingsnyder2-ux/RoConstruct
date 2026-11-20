#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#include "humanoid/Humanoid.h"
#include "Network/Players.h"

namespace RBX
{
	static Reflection::PropDescriptor<Accoutrement, G3D::CoordinateFrame> prop_AttachmentPoint("AttachmentPoint", "Appearance", &Accoutrement::getAttachmentPoint, &Accoutrement::setAttachmentPoint, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentPos("AttachmentPos", "Appearance", &Accoutrement::getAttachmentPos, &Accoutrement::setAttachmentPos, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentForward("AttachmentForward", "Appearance", &Accoutrement::getAttachmentForward, &Accoutrement::setAttachmentForward, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentUp("AttachmentUp", "Appearance", &Accoutrement::getAttachmentUp, &Accoutrement::setAttachmentUp, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentRight("AttachmentRight", "Appearance", &Accoutrement::getAttachmentRight, &Accoutrement::setAttachmentRight, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState("BackendAccoutrementState", "Appearance", &Accoutrement::getBackendAccoutrementState, &Accoutrement::setBackendAccoutrementState, Reflection::PropertyDescriptor::STREAMING);

	void Accoutrement::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
	{
		const Name* name = NULL;
		if (const XmlAttribute* attrib = propertyElement->findAttribute(name_name))
		{
			if (attrib->getValue(name))
			{
				if (name->name == "BackendAccoutrementState")
					return;
			}
		}
		Instance::readProperty(propertyElement, binder);
	}

	const PartInstance* Accoutrement::getHandleConst() const
	{
		return dynamic_cast<PartInstance*>(findFirstChildByName("Handle"));
	}

	const G3D::CoordinateFrame Accoutrement::getLocation() const
	{
		const PartInstance* handle = getHandleConst();
		return handle ? handle->getCoordinateFrame() : G3D::CoordinateFrame();
	}

	void Accoutrement::setAttachmentPoint(const G3D::CoordinateFrame& value)
	{
		if (value != attachmentPoint)
		{
			attachmentPoint = value;
			if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
				workspace->raiseDrawChanged();
			raisePropertyChanged(prop_AttachmentPoint);
			if (weld)
				weld->setC1(attachmentPoint);
		}
	}

	void Accoutrement::setAttachmentForward(const G3D::Vector3& v)
	{
		G3D::CoordinateFrame c = attachmentPoint;
		G3D::Vector3 oldX = c.rotation.getColumn(0);
		G3D::Vector3 oldY = c.rotation.getColumn(1);
		G3D::Vector3 z = -v.direction();
		G3D::Vector3 x = oldY.cross(z);
		x.unitize();
		G3D::Vector3 y = z.cross(x);
		y.unitize();
		c.rotation.setColumn(0, x);
		c.rotation.setColumn(1, y);
		c.rotation.setColumn(2, z);
		setAttachmentPoint(c);
	}

	void Accoutrement::setAttachmentUp(const G3D::Vector3& v)
	{
		G3D::CoordinateFrame c = attachmentPoint;
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
		setAttachmentPoint(c);
	}

	void Accoutrement::setAttachmentRight(const G3D::Vector3& v)
	{
		G3D::CoordinateFrame c = attachmentPoint;
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
		setAttachmentPoint(c);
	}

	XmlElement* Accoutrement::write()
	{
		if (!writeUnlocked)
			return new XmlElement(tag_External, InstanceHandle(this));
		else
			return Instance::write();
	}

	Accoutrement::AccoutrementState Accoutrement::computeDesiredState(Instance* testParent)
	{
		Humanoid* humanoid = Humanoid::modelIsCharacter(testParent);
		if (!humanoid)
			return IN_WORKSPACE;
		if (!humanoid->getTorso())
			return NOTHING;
		return EQUIPPED;
	}

	Accoutrement::AccoutrementState Accoutrement::computeDesiredState()
	{
		if (!getHandleConst())
			return NOTHING;
		if (!Workspace::contextInWorkspace(this))
			return HAS_HANDLE;
		return computeDesiredState(getParent());
	}

	void Accoutrement::updateDesiredState()
	{
		setDesiredState(computeDesiredState(), ServiceProvider::findServiceProvider(this));
	}

	void Accoutrement::onAncestorChanged(const AncestorChanged& event)
	{
		const ServiceProvider* oldProvider = ServiceProvider::findServiceProvider(event.oldParent);
		const ServiceProvider* newProvider = ServiceProvider::findServiceProvider(event.newParent);
		if (oldProvider)
		{
			if (Network::Players::backendProcessing(oldProvider, true))
				setDesiredState(NOTHING, oldProvider);
			else
				backendAccoutrementState = NOTHING;
		}
		Instance::onAncestorChanged(event);
		if (newProvider && Network::Players::backendProcessing(newProvider, true))
			updateDesiredState();
	}
}

template class RBX::Notifier<RBX::Workspace,RBX::DrawChanged>;
template class boost::shared_ptr<RBX::Weld>;
template class std::vector<RBX::Listener<RBX::Workspace,RBX::DrawChanged> *,std::allocator<RBX::Listener<RBX::Workspace,RBX::DrawChanged> *> >;

#include "util/Name.h"

namespace RBX {

void Accoutrement::upTo_InCharacter()
{
	characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Accoutrement::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Accoutrement::onEvent_RemovedBackend, this, _1), 10);
}

}
