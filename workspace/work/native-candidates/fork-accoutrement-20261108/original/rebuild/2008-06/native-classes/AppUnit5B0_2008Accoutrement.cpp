// 2008-06 native RBX::Accoutrement members (inactive), original unit v8datamodel/Accoutrement.cpp, 005b0820..005b2ebf in
// the application range 005b0000..005bc000. Built against the committed native v8datamodel/Accoutrement.h (read-only).
// Verified by tests/record_native_app_unit5b0_2008.py (receipt app-unit5b0-2008-working.json).
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#ifdef NATIVE_APPUNIT5B0_PENDING
#include "humanoid/Humanoid.h"
#include "Network/Players.h"
#endif

namespace RBX
{
	// Property descriptors of the unit (static initializers 007f4fb0..007f5190, counted by appearance-working.json);
	// defined here because setAttachmentPoint raises prop_AttachmentPoint (00976d20).
	static Reflection::PropDescriptor<Accoutrement, G3D::CoordinateFrame> prop_AttachmentPoint("AttachmentPoint", "Appearance", &Accoutrement::getAttachmentPoint, &Accoutrement::setAttachmentPoint, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentPos("AttachmentPos", "Appearance", &Accoutrement::getAttachmentPos, &Accoutrement::setAttachmentPos, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentForward("AttachmentForward", "Appearance", &Accoutrement::getAttachmentForward, &Accoutrement::setAttachmentForward, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentUp("AttachmentUp", "Appearance", &Accoutrement::getAttachmentUp, &Accoutrement::setAttachmentUp, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentRight("AttachmentRight", "Appearance", &Accoutrement::getAttachmentRight, &Accoutrement::setAttachmentRight, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState("BackendAccoutrementState", "Appearance", &Accoutrement::getBackendAccoutrementState, &Accoutrement::setBackendAccoutrementState, Reflection::PropertyDescriptor::STREAMING);

	// @005b0840: name_name 00975338, findAttribute 0057c2b0, getValue 0057c360, "BackendAccoutrementState" 00834a0c,
	// Instance::readProperty 00559170
	void Accoutrement::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
	{
		const Name* name = NULL;
		if (const XmlAttribute* attrib = propertyElement->findAttribute(name_name))
		{
			if (attrib->getValue(name))
			{
				if (name->toString() == "BackendAccoutrementState")
					return;
			}
		}
		Instance::readProperty(propertyElement, binder);
	}

	// @005b08a0: findFirstChildByName 00557950 ("Handle" 00834a28), dynamic_cast Instance -> PartInstance
	const PartInstance* Accoutrement::getHandleConst() const
	{
		return dynamic_cast<PartInstance*>(findFirstChildByName("Handle"));
	}

	// @005b0b70 (ILocation this): PartInstance::getCoordinateFrame 00598cb0, CoordinateFrame() 004782d0
	const G3D::CoordinateFrame Accoutrement::getLocation() const
	{
		const PartInstance* handle = getHandleConst();
		return handle ? handle->getCoordinateFrame() : G3D::CoordinateFrame();
	}

	// @005b2670: CoordinateFrame != 004765e0, find<Workspace> 00491e50, raiseDrawChanged (Notifier raise 00576940
	// at Workspace +0x344), raisePropertyChanged 0040db00 (prop_AttachmentPoint 00976d20), weld (+0x134) setC1 005e44c0
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

	// @005b2750
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

	// @005b28d0 (copies as in setAttachmentRight; the x87 order needs both copies of the first cross product)
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

	// @005b2a40 (copies of the direction and the old column are needed for the x87 order the bytes show)
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

#ifdef NATIVE_APPUNIT5B0_PENDING
	// The bodies below need Accoutrement members the committed native header does not declare (proposal: the
	// static writeUnlocked 00976cad and the state-machine members). Built only against a generated header copy under
	// out/app-unit5b0-2008/pending/ and recorded exact=false (pending-build-only).

	// @005b1480: writeUnlocked 00976cad; new(0x28) XmlElement(tag_External 00975358, InstanceHandle(this) 00594e00)
	// 00417510; Instance::write 00558c50
	XmlElement* Accoutrement::write()
	{
		if (!writeUnlocked)
			return new XmlElement(tag_External, InstanceHandle(this));
		else
			return Instance::write();
	}

	// @005b10a0: getHandleConst, Workspace::contextInWorkspace 005a33d0, Humanoid::modelIsCharacter 005d9a20,
	// Humanoid::getTorso 005d8b10, findServiceProvider 004898d0, setDesiredState 005b2510
	void Accoutrement::updateDesiredState()
	{
		setDesiredState(computeDesiredState(), ServiceProvider::findServiceProvider(this));
	}

	// @005b25f0: findServiceProvider(oldParent / newParent), backendProcessing 00495eb0, Instance::onAncestorChanged 0055acc0
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
#endif
}
