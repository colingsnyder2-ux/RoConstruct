#include "v8datamodel/Feature.h"
#include "v8datamodel/PartInstance.h"

#define NATIVE_MOTOR_JOINT_DONOR_BASE
#include "v8world/Joints2008.h"
#include "reflection/enumconverter.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#include <boost/bind.hpp>
#include "v8datamodel/Workspace.h"   // Workspace::getWorldIfInWorkspace 005a3390 (onAncestorChanged 0060a0f0)
#include "util/NormalId.h"           // objectToUvw / uvwToObject / intToNormalId / normalIdToMatrix3 (00609da0)
#include "util/Math.h"               // Math::vector3Abs 005de630, Math::sign (00609da0)

namespace RBX
{
	const char sFeature[] = "Feature";           // 00842998 (doDeclare<sFeature> 00609c60)
	const char sHole[] = "Hole";                 // 008429a0 (doDeclare<sHole> 0057d6e0)
	const char sMotorFeature[] = "MotorFeature"; // 008429a8 (doDeclare<sMotorFeature> 0057d670)
	const char sVelocityMotor[] = "VelocityMotor"; // 008429b8 (doDeclare<sVelocityMotor> 0057d750)

	// Template members the shared headers only declare (same definitions as Team.cpp / ServiceChangeHistory.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	static Reflection::RefPropDescriptor<VelocityMotor, Hole> prop_Hole("Hole", "Data", &VelocityMotor::getHole, &VelocityMotor::setHole, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<VelocityMotor, float> prop_MaxVelocity("MaxVelocity", "Data", &VelocityMotor::getMaxVelocity, &VelocityMotor::setMaxVelocity, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<VelocityMotor, float> prop_DesiredAngle("DesiredAngle", "Data", &VelocityMotor::getDesiredAngle, &VelocityMotor::setDesiredAngle, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<VelocityMotor, float> prop_CurrentAngle("CurrentAngle", "Data", &VelocityMotor::getCurrentAngle, &VelocityMotor::setCurrentAngle, Reflection::PropertyDescriptor::STANDARD);

	Reflection::EnumDesc<Feature::TopBottom>::EnumDesc()   // 0060b1d0
		: EnumDescriptor("TopBottom", typeid(Feature::TopBottom))
	{
		addPair(Feature::TOP, "Top");
		addPair(Feature::CENTER_TB, "Center");
		addPair(Feature::BOTTOM, "Bottom");
	}

	Reflection::EnumDesc<Feature::LeftRight>::EnumDesc()   // 0060b350
		: EnumDescriptor("LeftRight", typeid(Feature::LeftRight))
	{
		addPair(Feature::LEFT, "Left");
		addPair(Feature::CENTER_LR, "Center");
		addPair(Feature::RIGHT, "Right");
	}

	Reflection::EnumDesc<Feature::InOut>::EnumDesc()       // 0060b4d0
		: EnumDescriptor("InOut", typeid(Feature::InOut))
	{
		addPair(Feature::EDGE, "Edge");
		addPair(Feature::INSET, "Inset");
		addPair(Feature::CENTER_IO, "Center");
	}

	static Reflection::EnumPropDescriptor<Feature, NormalId> prop_FaceId("FaceId", "Data", &Feature::getFaceId, &Feature::setFaceId, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<Feature, Feature::TopBottom> prop_TopBottom("TopBottom", "Data", &Feature::getTopBottom, &Feature::setTopBottom, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<Feature, Feature::LeftRight> prop_LeftRight("LeftRight", "Data", &Feature::getLeftRight, &Feature::setLeftRight, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<Feature, Feature::InOut> prop_InOut("InOut", "Data", &Feature::getInOut, &Feature::setInOut, Reflection::PropertyDescriptor::STANDARD);

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

	bool Feature::getRenderCoord(G3D::CoordinateFrame& c) const
	{
		PartInstance* part = dynamic_cast<PartInstance*>(getParent());
		if (part)
		{
			G3D::CoordinateFrame local = computeLocalCoordinateFrame();
			c = part->getCoordinateFrame() * local;
			return true;
		}
		return false;
	}

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
				uv.x = Math::sign(uv.x) * std::max(0.0f, std::abs(uv.x) - 1.0f);
				uv.y = Math::sign(uv.y) * std::max(0.0f, std::abs(uv.y) - 1.0f);
				break;

			case CENTER_IO:
				uv.x = 0.0f;
				uv.y = 0.0f;
				break;
		}

		G3D::Vector3 uvInObject = RBX::uvwToObject(uv, faceId);
		G3D::Vector3 ptInObject = extents.faceCenter(faceId) + uvInObject;

		NormalId face = getCoordOrientation() == Z_OUT
			? faceId
			: intToNormalId((faceId + NORM_X_NEG) % NORM_UNDEFINED);

		return G3D::CoordinateFrame(normalIdToMatrix3(face), ptInObject);
	}

	void Feature::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		G3D::CoordinateFrame worldCoord;
		if (getRenderCoord(worldCoord))
			DrawAdorn::cylinder(adorn, worldCoord, 2, 0.3f, 0.6f, Draw::selectColor());
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

	Hole::Hole()
	{
		setName("Hole");
	}

	void Hole::render3dAdorn(Adorn* adorn)
	{
		G3D::CoordinateFrame worldCoord;
		if (getRenderCoord(worldCoord))
			DrawAdorn::cylinder(adorn, worldCoord, 2, 0.2f, 0.3f, G3D::Color3::black());
	}

	MotorFeature::MotorFeature()
	{
		setName("MotorFeature");
	}

	void MotorFeature::render3dAdorn(Adorn* adorn)
	{
		G3D::CoordinateFrame worldCoord;
		if (getRenderCoord(worldCoord))
			DrawAdorn::cylinder(adorn, worldCoord, 2, 1.0f, 0.3f, G3D::Color3::yellow());
	}

	bool MotorFeature::canJoin(Instance* a, Instance* b)
	{
		return (dynamic_cast<Hole*>(a) && dynamic_cast<MotorFeature*>(b))
			|| (dynamic_cast<Hole*>(b) && dynamic_cast<MotorFeature*>(a));
	}

	void MotorFeature::join(Instance* a, Instance* b)
	{
		if (canJoin(a, b))
		{
			Instance* hole = dynamic_cast<Hole*>(a) ? a : b;
			Instance* other = (hole == a) ? b : a;
			boost::shared_ptr<VelocityMotor> motor = Creatable<Instance>::create<VelocityMotor>();
			motor->setHole(static_cast<Hole*>(hole));
			motor->setParent(other);
		}
	}

	inline const MotorJoint* VelocityMotor::motorJoint() const
	{
		return static_cast<MotorJoint*>(joint);
	}

	inline MotorJoint* VelocityMotor::motorJoint()
	{
		return static_cast<MotorJoint*>(joint);
	}

	VelocityMotor::VelocityMotor()
		: DescribedCreatable(new MotorJoint())
	{
		setName("VelocityMotor");
	}

	VelocityMotor::~VelocityMotor()
	{
	}

	static Primitive* getParentPrimitive(Instance* instance)
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
		Primitive* prim = getParentPrimitive(feature);

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
		JointInstance::onAncestorChanged(event);

		setPart(0, dynamic_cast<Feature*>(getParent()));

		World* oldWorld = motorJoint()->getWorld();
		World* wsWorld = Workspace::getWorldIfInWorkspace(this);

		if (oldWorld != wsWorld)
		{
			if (oldWorld)
			{
				oldWorld->removeJoint(motorJoint());
				setPart(0, NULL);
				setPart(1, NULL);
			}

			if (wsWorld)
				wsWorld->insertJoint(motorJoint());
		}
	}

	void VelocityMotor::onEvent_HoleAncestorChanged()
	{
		setPart(1, hole.get());
	}

	void VelocityMotor::setHole(Hole* value)
	{
		if (value != getHole())
		{
			hole = shared_from(value);
			raisePropertyChanged(prop_Hole);

			setPart(1, getHole());

			if (getHole())
				holeAncestorChanged = event_ancestryChanged.connect(hole.get(), boost::bind(&VelocityMotor::onEvent_HoleAncestorChanged, this), 10);
			else
				holeAncestorChanged.disconnect();
		}
	}

	float VelocityMotor::getMaxVelocity() const
	{
		return motorJoint()->maxVelocity;
	}

	void VelocityMotor::setMaxVelocity(float value)
	{
		if (value != motorJoint()->maxVelocity)
		{
			motorJoint()->maxVelocity = value;
			raisePropertyChanged(prop_MaxVelocity);
		}
	}

	float VelocityMotor::getDesiredAngle() const
	{
		return motorJoint()->desiredAngle;
	}

	void VelocityMotor::setDesiredAngle(float value)
	{
		if (value != motorJoint()->desiredAngle)
		{
			motorJoint()->desiredAngle = value;
			raisePropertyChanged(prop_DesiredAngle);
		}
	}

	float VelocityMotor::getCurrentAngle() const
	{
		return motorJoint()->getCurrentAngle();
	}

	void VelocityMotor::setCurrentAngle(float value)
	{
		if (value != motorJoint()->getCurrentAngle())
		{
			motorJoint()->setCurrentAngle(value);
			raisePropertyChanged(prop_CurrentAngle);
		}
	}
}

typedef boost::_bi::bind_t<void, boost::_mfi::mf0<void, RBX::VelocityMotor>, boost::_bi::list1<boost::_bi::value<RBX::VelocityMotor*> > > VelocityMotorHoleBinder;
template boost::slot<boost::function<void(boost::shared_ptr<RBX::Instance>)> >::slot(const VelocityMotorHoleBinder&);

template class RBX::Reflection::TypedPropertyDescriptor<RBX::Hole *>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::Feature::InOut>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::Feature::LeftRight>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::Feature::TopBottom>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::NormalId>;
template class boost::_bi::list1<boost::_bi::value<RBX::VelocityMotor *> >;
template class boost::_bi::storage1<boost::_bi::value<RBX::VelocityMotor *> >;
template class boost::_bi::value<RBX::VelocityMotor *>;
template class boost::_mfi::mf0<void,RBX::VelocityMotor>;
template class boost::shared_ptr<RBX::Hole>;
template class boost::shared_ptr<RBX::VelocityMotor>;
template class boost::shared_ptr<boost::signals::detail::slot_base::data_t>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::Feature::InOut> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::Feature::LeftRight> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::Feature::TopBottom> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::NormalId> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::InOut> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::LeftRight> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::TopBottom> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::NormalId> > >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::InOut,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::InOut> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::LeftRight,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::LeftRight> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::TopBottom,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::TopBottom> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::NormalId,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NormalId> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::InOut,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::InOut> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::LeftRight,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::LeftRight> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::TopBottom,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::TopBottom> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NormalId,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NormalId> >,0> >;
template class std::_Vector_const_iterator<enum RBX::Feature::InOut,std::allocator<enum RBX::Feature::InOut> >;
template class std::_Vector_const_iterator<enum RBX::Feature::LeftRight,std::allocator<enum RBX::Feature::LeftRight> >;
template class std::_Vector_const_iterator<enum RBX::Feature::TopBottom,std::allocator<enum RBX::Feature::TopBottom> >;
template class std::_Vector_iterator<enum RBX::Feature::InOut,std::allocator<enum RBX::Feature::InOut> >;
template class std::_Vector_iterator<enum RBX::Feature::LeftRight,std::allocator<enum RBX::Feature::LeftRight> >;
template class std::_Vector_iterator<enum RBX::Feature::TopBottom,std::allocator<enum RBX::Feature::TopBottom> >;
template class std::_Vector_val<enum RBX::NormalId,std::allocator<enum RBX::NormalId> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::InOut,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::InOut> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::LeftRight,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::LeftRight> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::Feature::TopBottom,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::TopBottom> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::NormalId,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NormalId> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::InOut> >;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::LeftRight> >;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::Feature::TopBottom> >;
template class std::map<RBX::Name const *,enum RBX::NormalId,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NormalId> > >;
template class std::vector<enum RBX::Feature::InOut,std::allocator<enum RBX::Feature::InOut> >;
template class std::vector<enum RBX::Feature::LeftRight,std::allocator<enum RBX::Feature::LeftRight> >;
template class std::vector<enum RBX::Feature::TopBottom,std::allocator<enum RBX::Feature::TopBottom> >;
template class std::vector<enum RBX::NormalId,std::allocator<enum RBX::NormalId> >;

template void RBX::Name::callDoDeclare<RBX::sVelocityMotor>();
template void RBX::Name::callDoDeclare<RBX::sFeature>();
