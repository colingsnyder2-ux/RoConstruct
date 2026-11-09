// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_abstract_family_7e2b1c67744266cc.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/JointInstance.h"
#include "tool/DragUtilities.h"
#include "v8xml/SerializerV2.h"
#include "Network/Players.h"

namespace RBX
{
	static Reflection::PropDescriptor<Accoutrement, G3D::CoordinateFrame> prop_AttachmentPoint("AttachmentPoint", "Appearance", &Accoutrement::getAttachmentPoint, &Accoutrement::setAttachmentPoint, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentPos("AttachmentPos", "Appearance", &Accoutrement::getAttachmentPos, &Accoutrement::setAttachmentPos, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentForward("AttachmentForward", "Appearance", &Accoutrement::getAttachmentForward, &Accoutrement::setAttachmentForward, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentUp("AttachmentUp", "Appearance", &Accoutrement::getAttachmentUp, &Accoutrement::setAttachmentUp, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentRight("AttachmentRight", "Appearance", &Accoutrement::getAttachmentRight, &Accoutrement::setAttachmentRight, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState("BackendAccoutrementState", "Appearance", &Accoutrement::getBackendAccoutrementState, &Accoutrement::setBackendAccoutrementState, Reflection::PropertyDescriptor::STREAMING);

	Accoutrement::Accoutrement()
		: backendAccoutrementState(NOTHING)
	{
		setName("Accoutrement");
	}

	Accoutrement::~Accoutrement()
	{
		RBXASSERT(!weld);
		RBXASSERT(!handleTouched.connected());
		RBXASSERT(!characterChildAdded.connected());
		RBXASSERT(!characterChildRemoved.connected());
	}

	//99.29% match
	//see Tool::readProperty
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

	PartInstance* Accoutrement::getHandle()
	{
		return const_cast<PartInstance*>(getHandleConst());
	}

	const G3D::CoordinateFrame Accoutrement::getLocation() const
	{
		const PartInstance* handle = getHandleConst();
		return handle ? handle->getCoordinateFrame() : G3D::CoordinateFrame();
	}

	Accoutrement::AccoutrementState Accoutrement::computeDesiredState()
	{
		RBXASSERT(Network::Players::backendProcessing(this, true));

		if (!getHandleConst())
			return NOTHING;

		if (!Workspace::contextInWorkspace(this))
			return HAS_HANDLE;

		return computeDesiredState(getParent());
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

	void Accoutrement::onCameraNear(float distance)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (ICameraSubject* subject = queryTypedChild<ICameraSubject>((int)i))
				subject->onCameraNear(distance);
		}
	}

	void Accoutrement::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (IRenderable* renderable = queryTypedChild<IRenderable>((int)i))
				renderable->render3dSelect(adorn, selectState);
		}
	}

	void Accoutrement::onEvent_AddedBackend(boost::shared_ptr<Instance> child)
	{
		if (child.get() != this)
		{
			RBXASSERT(ServiceProvider::findServiceProvider(this));
			RBXASSERT(Network::Players::backendProcessing(this, true));

			AccoutrementState state = computeDesiredState();
			const ServiceProvider* serviceProvider = ServiceProvider::findServiceProvider(this);

			RBXASSERT(serviceProvider);

			setDesiredState(state, serviceProvider);
		}
	}

	void Accoutrement::onEvent_RemovedBackend(boost::shared_ptr<Instance> child)
	{
		if (child.get() != this)
		{
			RBXASSERT(ServiceProvider::findServiceProvider(this));
			RBXASSERT(Network::Players::backendProcessing(this, true));

			if (child.get() == (Instance*)this->weld.get())
			{
				RBXASSERT(Accoutrement::drawSelected());
				setDesiredState(NOTHING, ServiceProvider::findServiceProvider(this));
			}

			AccoutrementState state = computeDesiredState();
			const ServiceProvider* serviceProvider = ServiceProvider::findServiceProvider(this);

			RBXASSERT(serviceProvider);

			setDesiredState(state, serviceProvider);
		}
	}

	void Accoutrement::onEvent_HandleTouched(boost::shared_ptr<Instance> other)
	{
		RBXASSERT(Network::Players::backendProcessing(this, true));

		if (backendAccoutrementState == IN_WORKSPACE)
		{
			Instance* otherParent = other->getParent();
			Humanoid* humanoid = Humanoid::modelIsCharacter(otherParent);

			if (humanoid && humanoid->getTorso() && !otherParent->findFirstChildOfType<Accoutrement>())
			{
				setParent(otherParent);
			}
		}
	}

	XmlElement* Accoutrement::write()
	{
		if (!writeUnlocked)
			return new XmlElement(tag_External, InstanceHandle(this));
		else
			return Instance::write();
	}

	void Accoutrement::upTo_Equipped()
	{
		handleTouched.disconnect();

		std::vector<boost::weak_ptr<PartInstance>> parts;
		PartInstance::findParts(this, parts);
		DragUtilities::unJoinFromOutsiders(parts);

		Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
		RBXASSERT(humanoid);

		PartInstance* head = humanoid->getHead();
		RBXASSERT(head);

		PartInstance* handle = getHandle();
		RBXASSERT(handle);

		buildWeld(head, handle, humanoid->getTopOfHead(), attachmentPoint, "HeadWeld");
	}

	void Accoutrement::upTo_InCharacter()
	{
		RBXASSERT(Humanoid::modelIsCharacter(getParent()));

		characterChildAdded = Instance::event_childAdded.connect(getParent(), boost::bind(&Accoutrement::onEvent_AddedBackend, this, _1));
		characterChildRemoved = Instance::event_childRemoved.connect(getParent(), boost::bind(&Accoutrement::onEvent_RemovedBackend, this, _1));
	}

	void Accoutrement::connectTouchEvent()
	{
		if (PartInstance* handle = getHandle())
		{
			handleTouched = PartInstance::event_Touched.connect(handle, boost::bind(&Accoutrement::onEvent_HandleTouched, this, _1));
		}
		else
		{
			handleTouched.disconnect();
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

	void Accoutrement::setAttachmentPoint(const G3D::CoordinateFrame& value)
	{
		if (value != attachmentPoint)
		{
			attachmentPoint = value;

			if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
				workspace->raiseDrawChanged();

			raisePropertyChanged(prop_AttachmentPoint);

			if (weld)
			{
				RBXASSERT(Network::Players::backendProcessing(this, true));
				weld->setC1(attachmentPoint);
			}
		}
	}

	void Accoutrement::setAttachmentPos(const G3D::Vector3& v)
	{
		setAttachmentPoint(G3D::CoordinateFrame(attachmentPoint.rotation, v));
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

	const PartInstance* Accoutrement::getHandleConst() const
	{
		return dynamic_cast<PartInstance*>(findFirstChildByName("Handle"));
	}

	void Accoutrement::upTo_InWorkspace()
	{
		RBXASSERT(ServiceProvider::findServiceProvider(this));
		RBXASSERT(Network::Players::backendProcessing(this, true));
	}

	void Accoutrement::downFrom_HasHandle()
	{
		handleTouched.disconnect();
	}

	void Accoutrement::setDesiredState(AccoutrementState desiredState, const ServiceProvider* serviceProvider)
	{
		do
		{
			RBXASSERT(Network::Players::backendProcessing(serviceProvider, true));

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
					RBXASSERT(false);
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
					break;
				case HAS_HANDLE:
					downFrom_HasHandle();
					break;
				default:
					RBXASSERT(false);
					break;
				}

				setBackendAccoutrementState(backendAccoutrementState - HAS_HANDLE);
			} 
		} while (desiredState != backendAccoutrementState);
	}

	Hat::Hat()
	{
		setName("Hat");
	}
}
