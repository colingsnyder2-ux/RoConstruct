// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_abstract_family_d41596b0c632e733.cpp

// Candidate translation unit (score above; library headers required).
#define _RELEASEASSERT 1
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
#include "v8datamodel/Feature.h"
#include "v8datamodel/Workspace.h"
#include "v8world/MotorJoint.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"

namespace RBX 
{
	static Reflection::RefPropDescriptor<VelocityMotor, Hole> prop_Hole ("Hole", "Data", &VelocityMotor::getHole, &VelocityMotor::setHole, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<VelocityMotor, float> prop_MaxVelocity ("MaxVelocity", "Data", &VelocityMotor::getMaxVelocity, &VelocityMotor::setMaxVelocity, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<VelocityMotor, float> prop_DesiredAngle ("DesiredAngle", "Data", &VelocityMotor::getDesiredAngle, &VelocityMotor::setDesiredAngle, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<VelocityMotor, float> prop_CurrentAngle ("CurrentAngle", "Data", &VelocityMotor::getCurrentAngle, &VelocityMotor::setCurrentAngle, Reflection::PropertyDescriptor::LEGACY);

	Reflection::EnumDesc<Feature::TopBottom>::EnumDesc()
		: EnumDescriptor("TopBottom", typeid(Feature::TopBottom))
	{
		addPair(Feature::TOP, "Top");
		addPair(Feature::CENTER_TB, "Center");
		addPair(Feature::BOTTOM, "Bottom");
	}

	Reflection::EnumDesc<Feature::LeftRight>::EnumDesc()
		: EnumDescriptor("LeftRight", typeid(Feature::LeftRight))
	{
		addPair(Feature::LEFT, "Left");
		addPair(Feature::CENTER_LR, "Center");
		addPair(Feature::RIGHT, "Right");
	}

	Reflection::EnumDesc<Feature::InOut>::EnumDesc()
		: EnumDescriptor("InOut", typeid(Feature::InOut))
	{
		addPair(Feature::EDGE, "Edge");
		addPair(Feature::INSET, "Inset");
		addPair(Feature::CENTER_IO, "Center");
	}

	static Reflection::EnumPropDescriptor<Feature, NormalId> prop_FaceId ("FaceId", "Data", &Feature::getFaceId, &Feature::setFaceId, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::EnumPropDescriptor<Feature, Feature::TopBottom> prop_TopBottom ("TopBottom", "Data", &Feature::getTopBottom, &Feature::setTopBottom, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::EnumPropDescriptor<Feature, Feature::LeftRight> prop_LeftRight ("LeftRight", "Data", &Feature::getLeftRight, &Feature::setLeftRight, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::EnumPropDescriptor<Feature, Feature::InOut> prop_InOut ("InOut", "Data", &Feature::getInOut, &Feature::setInOut, Reflection::PropertyDescriptor::LEGACY);

    const char* sFeature = "Feature";

	Feature::Feature()
		: faceId(NORM_X),
		  topBottom(CENTER_TB),
		  leftRight(CENTER_LR),
		  inOut(CENTER_IO)
	{
		setName("Feature");
	}

	Feature::~Feature()
	{
	}

	// TODO: 98.92% match
	bool Feature::getRenderCoord(G3D::CoordinateFrame& c) const
	{
		PartInstance* part = dynamic_cast<PartInstance*>(getParent());

		if (part)
		{
			// for some reason local is being taken as operator*'s LHS
			// and not part->getCoordinateFrame()
			G3D::CoordinateFrame local = computeLocalCoordinateFrame();
			c = part->getCoordinateFrame()*local;

			return true;
		}
		else
		{
			return false;
		}
	}

	void Feature::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		G3D::CoordinateFrame worldCoord;

		if (getRenderCoord(worldCoord))
			DrawAdorn::cylinder(adorn, worldCoord, 2, 0.3, 0.6, Draw::selectColor());
	}

	// TODO: 98.55% match
	G3D::CoordinateFrame Feature::computeLocalCoordinateFrame() const
	{
		PartInstance* part = dynamic_cast<PartInstance*>(getParent());

		if (!part)
			return G3D::CoordinateFrame();

		Extents extents = part->getPrimitive()->getExtentsLocal();

		G3D::Vector3 corner = extents.max();
		G3D::Vector3 uv = Math::vector3Abs(RBX::objectToUvw(corner, faceId));

		uv.z = 0.0f;

		switch (leftRight)
		{
			case LEFT:
				uv.x = -uv.x;
				break;

			case CENTER_LR:
				uv.x = 0.0f;
				break;
		}

		switch (topBottom)
		{
			case CENTER_TB:
				uv.y = 0.0f;
				break;

			case BOTTOM:
				uv.y = -uv.y;
				break;
		}

		switch (inOut)
		{
		case INSET:
			uv.x = RBX::Math::sign(uv.x) * std::max(0.0f, std::abs(uv.x) - 1.0f);
			uv.y = RBX::Math::sign(uv.y) * std::max(0.0f, std::abs(uv.y) - 1.0f);
			break;

		case CENTER_IO:
			uv.x = 0.0f;
			uv.y = 0.0f;
			break;
		}

		G3D::Vector3 uvInObject = RBX::uvwToObject(uv, faceId);
		G3D::Vector3 ptInObject = extents.faceCenter(faceId) + uvInObject;

		RBX::NormalId face = getCoordOrientation() == Z_OUT
							     ? faceId
							     : RBX::intToNormalId((faceId + NORM_X_NEG) % NORM_UNDEFINED);

		return G3D::CoordinateFrame(RBX::normalIdToMatrix3(face), ptInObject);
	}

	void Feature::setFaceId(NormalId value)
	{
		if (faceId != value)
		{
			faceId = value;
			raisePropertyChanged(prop_FaceId);
		}
	}

	void Feature::setTopBottom(TopBottom value)
	{
		if (topBottom != value)
		{
			topBottom = value;
			raisePropertyChanged(prop_TopBottom);
		}
	}

	void Feature::setLeftRight(LeftRight value)
	{
		if (leftRight != value)
		{
			leftRight = value;
			raisePropertyChanged(prop_LeftRight);
		}
	}

	void Feature::setInOut(InOut value)
	{
		if (inOut != value)
		{
			inOut = value;
			raisePropertyChanged(prop_InOut);
		}
	}

    const char* sHole = "Hole";

	Hole::Hole()
	{
		setName("Hole");
	}

	void Hole::render3dAdorn(Adorn* adorn)
	{
		G3D::CoordinateFrame worldCoord;

		if (getRenderCoord(worldCoord))
			DrawAdorn::cylinder(adorn, worldCoord, 2, 0.2, 0.3, G3D::Color3::black());
	}

    const char* sMotorFeature = "MotorFeature";

	MotorFeature::MotorFeature()
	{
		setName("MotorFeature");
	}

	void MotorFeature::render3dAdorn(Adorn* adorn)
	{
		G3D::CoordinateFrame worldCoord;

		if (getRenderCoord(worldCoord))
			DrawAdorn::cylinder(adorn, worldCoord, 2, 1.0, 0.3, G3D::Color3::yellow());
	}

    const char* sVelocityMotor = "VelocityMotor";

	VelocityMotor::VelocityMotor()
		: DescribedCreatable(new MotorJoint())
	{
		setName("VelocityMotor");
	}

	VelocityMotor::~VelocityMotor()
	{
	}

	// TODO: figure out where this can go, maybe it's not an inline? it's the
	// only way i can make this work sensibly though
	static inline Primitive* _getParentPrimitive(Instance* instance)
	{
		if (instance)
		{
			PartInstance* part = dynamic_cast<PartInstance*>(instance->getParent());

			if (part)
				return part->getPrimitive();
		}

		return NULL;
	}

	void VelocityMotor::setPart(int i, Feature* feature)
	{
		Primitive* prim = _getParentPrimitive(feature);

		G3D::CoordinateFrame c = feature ? feature->computeLocalCoordinateFrame() : G3D::CoordinateFrame();

		if (motorJoint()->getPrimitive(i) != prim)
		{
			motorJoint()->setPrimitive(i, prim);

			if (prim)
				motorJoint()->setJointCoord(i, c);
		}
	}

	void VelocityMotor::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);

		setPart(0, dynamic_cast<Feature*>(this->getParent()));

		World* oldWorld = motorJoint()->getWorld();
		World* wsWorld = Workspace::getWorldIfInWorkspace(this);

		if (oldWorld != wsWorld)
		{
			if (oldWorld)
			{
				oldWorld->removeJoint(motorJoint());
				setPart(0, NULL);
				setPart(1, NULL);
				RBXASSERT(!motorJoint()->getWorld());
			}

			if (wsWorld)
			{
				wsWorld->insertJoint(motorJoint());
				RBXASSERT(motorJoint()->getWorld());
			}
		}
	}

	void VelocityMotor::onEvent_HoleAncestorChanged()
	{
		RBXASSERT(hole.get());
		setPart(1, hole.get());
	}

	void VelocityMotor::setHole(Hole* value)
	{
		if (value != getHole())
		{
			hole = RBX::shared_from(value);
			raisePropertyChanged(prop_Hole);

			setPart(1, getHole());

			if (getHole())
				holeAncestorChanged = event_ancestryChanged.connect(hole.get(), boost::bind(&VelocityMotor::onEvent_HoleAncestorChanged, this));
			else
				holeAncestorChanged.disconnect();
		}
	}

	float VelocityMotor::getMaxVelocity() const
	{
		return rbx_static_cast<MotorJoint*>(joint)->maxVelocity;
	}

	void VelocityMotor::setMaxVelocity(float value)
	{
		if (value != getMaxVelocity())
		{
			rbx_static_cast<MotorJoint*>(joint)->maxVelocity = value;
			raisePropertyChanged(prop_MaxVelocity);
		}
	}

	float VelocityMotor::getDesiredAngle() const
	{
		return rbx_static_cast<MotorJoint*>(joint)->desiredAngle;
	}

	void VelocityMotor::setDesiredAngle(float value)
	{
		if (value != getDesiredAngle())
		{
			rbx_static_cast<MotorJoint*>(joint)->desiredAngle = value;
			raisePropertyChanged(prop_DesiredAngle);
		}
	}

	float VelocityMotor::getCurrentAngle() const
	{
		return rbx_static_cast<MotorJoint*>(joint)->getCurrentAngle();
	}

	void VelocityMotor::setCurrentAngle(float value)
	{
		if (value != getCurrentAngle())
		{
			rbx_static_cast<MotorJoint*>(joint)->setCurrentAngle(value);
			raisePropertyChanged(prop_CurrentAngle);
		}
	}
}
