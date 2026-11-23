// =============================================================================
// Accoutrement.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Accoutrement.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "tool/DragUtilities.h"
#include <boost/bind.hpp>

namespace RBX
{
	const char sAccoutrement[] = "Accoutrement";
	const char sHat[] = "Hat";

	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<> Reflection::ClassDescriptor& Reflection::Described<Accoutrement, sAccoutrement,
		FactoryProduct<Accoutrement, Instance, sAccoutrement> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), sAccoutrement);
		return descriptor;
	}
	template<> Reflection::ClassDescriptor& Reflection::Described<Hat, sHat,
		FactoryProduct<Hat, Accoutrement, sHat> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Accoutrement::classDescriptor(), sHat);
		return descriptor;
	}

	template class FactoryProduct<Accoutrement, Instance, sAccoutrement>;
	template class FactoryProduct<Hat, Accoutrement, sHat>;
	template DescribedCreatable<Accoutrement, Instance, sAccoutrement>::DescribedCreatable();
	template DescribedCreatable<Hat, Accoutrement, sHat>::DescribedCreatable();

	Reflection::PropDescriptor<Accoutrement, G3D::CoordinateFrame> prop_AttachmentPoint(
		"AttachmentPoint",
		"Appearance",
		&Accoutrement::getAttachmentPoint,
		&Accoutrement::setAttachmentPoint,
		Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentPos(
		"AttachmentPos",
		"Appearance",
		&Accoutrement::getAttachmentPos,
		&Accoutrement::setAttachmentPos,
		Reflection::PropertyDescriptor::UI);
	Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentForward(
		"AttachmentForward",
		"Appearance",
		&Accoutrement::getAttachmentForward,
		&Accoutrement::setAttachmentForward,
		Reflection::PropertyDescriptor::UI);
	Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentUp(
		"AttachmentUp",
		"Appearance",
		&Accoutrement::getAttachmentUp,
		&Accoutrement::setAttachmentUp,
		Reflection::PropertyDescriptor::UI);
	Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentRight(
		"AttachmentRight",
		"Appearance",
		&Accoutrement::getAttachmentRight,
		&Accoutrement::setAttachmentRight,
		Reflection::PropertyDescriptor::UI);
	Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState(
		"BackendAccoutrementState",
		"Appearance",
		&Accoutrement::getBackendAccoutrementState,
		&Accoutrement::setBackendAccoutrementState,
		Reflection::PropertyDescriptor::STREAMING);

	Accoutrement::Accoutrement()
		: backendAccoutrementState(NOTHING)
	{
		setName("Accoutrement");
	}

	Accoutrement::~Accoutrement()
	{
	}

	const G3D::CoordinateFrame& Accoutrement::getAttachmentPoint() const
	{
		return attachmentPoint;
	}

	// it __declspec(noinline) for the same reason. INFERRED: the attribute is not proven to be original source.
	__declspec(noinline) void Accoutrement::downFrom_InCharacter()
	{
		characterChildAdded.disconnect();
		characterChildRemoved.disconnect();
	}

	const G3D::Vector3 Accoutrement::getAttachmentPos() const
	{
		return attachmentPoint.translation;
	}

	const G3D::Vector3 Accoutrement::getAttachmentForward() const
	{
		return attachmentPoint.lookVector();
	}

	const G3D::Vector3 Accoutrement::getAttachmentUp() const
	{
		return attachmentPoint.upVector();
	}

	const G3D::Vector3 Accoutrement::getAttachmentRight() const
	{
		return attachmentPoint.rightVector();
	}

	void Accoutrement::onCameraNear(float distance)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (ICameraSubject* subject = dynamic_cast<ICameraSubject*>(getChild(i)))
				subject->onCameraNear(distance);
		}
	}

	void Accoutrement::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (IRenderable* renderable = dynamic_cast<IRenderable*>(getChild(i)))
				renderable->render3dSelect(adorn, selectState);
		}
	}

	void Accoutrement::setBackendAccoutrementState(int value)
	{
		if (value != backendAccoutrementState)
		{
			backendAccoutrementState = (AccoutrementState)value;
			raisePropertyChanged(prop_BackendAccoutrementState);
		}
	}

	void Accoutrement::setDesiredState(AccoutrementState desiredState, const ServiceProvider* serviceProvider)
	{
		do
		{
			if (backendAccoutrementState < desiredState)
			{
				switch (backendAccoutrementState)
				{
				case IN_CHARACTER:
					upTo_Equipped();
					break;
				case IN_WORKSPACE:
					upTo_InCharacter();
					break;
				case HAS_HANDLE:
					upTo_InWorkspace();
					break;
				case NOTHING:
					connectTouchEvent();
					break;
				default:
					break;
				}
				setBackendAccoutrementState(backendAccoutrementState + HAS_HANDLE);
			}
			else if (desiredState < backendAccoutrementState)
			{
				switch (backendAccoutrementState)
				{
				case EQUIPPED:
					downFrom_Equipped();
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
				default:
					break;
				}
				setBackendAccoutrementState(backendAccoutrementState - HAS_HANDLE);
			}
		} while (desiredState != backendAccoutrementState);
	}

	void Accoutrement::upTo_Equipped()
	{
		handleTouched.disconnect();

		std::vector<boost::weak_ptr<PartInstance> > parts;
		PartInstance::findParts(this, parts);
		DragUtilities::unJoinFromOutsiders(parts);

		Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
		PartInstance* head = humanoid->getHead();
		PartInstance* handle = getHandle();
		if (handle)
			handle->setCanCollide(false);   // 0059dd80, 2008 addition to the donor body

		buildWeld(head, handle, humanoid->getTopOfHead(), attachmentPoint, "HeadWeld");
	}

	void Accoutrement::downFrom_Equipped()
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
				handle->setCanCollide(true);   // 0059dd80, 2008 addition to the donor body
				handle->moveToPoint(pos);
				handle->setRotationalVelocity(G3D::Vector3(1.0f, 1.0f, 1.0f));
			}
		}

		onCameraNear(999.0f);
		connectTouchEvent();
	}

	void Accoutrement::connectTouchEvent()
	{
		if (PartInstance* handle = getHandle())
			handleTouched = PartInstance::event_Touched.connect(handle, boost::bind(&Accoutrement::onEvent_HandleTouched, this, _1), 10);
		else
			handleTouched.disconnect();
	}

	void Accoutrement::onEvent_HandleTouched(boost::shared_ptr<Instance> other)
	{
		if (backendAccoutrementState == IN_WORKSPACE)
		{
			Instance* character = other->getParent();

			if (Humanoid* humanoid = Humanoid::modelIsCharacter(character))
			{
				if (humanoid->getTorso() && !character->findFirstChildOfType<Accoutrement>())
					setParent(character);
			}
		}
	}

	void Accoutrement::onEvent_AddedBackend(boost::shared_ptr<Instance> child)
	{
		if (child.get() != this)
			updateDesiredState();
	}

	void Accoutrement::onEvent_RemovedBackend(boost::shared_ptr<Instance> child)
	{
		if (child.get() != this)
		{
			if (child.get() == weld.get())
				setDesiredState(NOTHING, ServiceProvider::findServiceProvider(this));
			updateDesiredState();
		}
	}

	void Accoutrement::dropAllOthers(ModelInstance* model, Accoutrement* accoutrement)
	{
		Workspace* workspace = Workspace::findWorkspace(model);
		if (workspace)
		{
			while (Accoutrement* other = model->findFirstChildOfType<Accoutrement>())
			{
				if (other != accoutrement)
					other->setParent(workspace);
			}
		}
	}

	void Accoutrement::setAttachmentPos(const G3D::Vector3& v)
	{
		setAttachmentPoint(G3D::CoordinateFrame(attachmentPoint.rotation, v));
	}

	Hat::Hat()
	{
		setName("Hat");
	}
}

template void RBX::Name::callDoDeclare<RBX::sAccoutrement>();
template void RBX::Name::callDoDeclare<RBX::sHat>();

#include "v8xml/XmlElement.h"
#include "Network/Players.h"

namespace RBX
{
	// INFERRED: the one definition lives in Accoutrement.cpp (same original unit, external linkage); these are references.
	extern Reflection::PropDescriptor<Accoutrement, G3D::CoordinateFrame> prop_AttachmentPoint;
	extern Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentPos;
	extern Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentForward;
	extern Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentUp;
	extern Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentRight;
	extern Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState;

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

namespace RBX
{

// INFERRED: noinline like downFrom_InCharacter in Accoutrement.cpp; the exe calls 005b1e50 from setDesiredState, joined into one TU MSVC inlines it.
__declspec(noinline) void Accoutrement::upTo_InCharacter()
{
	characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Accoutrement::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(
		getParent(),
		boost::bind(&Accoutrement::onEvent_RemovedBackend, this, _1),
		10);
}

}
