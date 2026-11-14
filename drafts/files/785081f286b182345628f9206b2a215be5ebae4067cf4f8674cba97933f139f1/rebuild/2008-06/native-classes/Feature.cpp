// 2008-06 native RBX::Feature, RBX::Hole, RBX::MotorFeature and RBX::VelocityMotor (inactive); evidence in
// native-headers/v8datamodel/Feature.h. Verified by tests/record_native_feature.py.
// NATIVE_FEATURE_PENDING bodies need declarations the shared headers do not have yet (2008 SignalDesc::connect
// with a group argument, JointInstance::onAncestorChanged, Workspace::getWorldIfInWorkspace); the recorder builds
// them against generated copies under out/native-feature-pending/. The unguarded VelocityMotor bodies that read
// JointInstance/MotorJoint fields are exact only against the 2008 layouts of those generated copies.
// Unit profile: document-swap flags plus /fp:fast (float setters 0060c580..0060c600) and /U_RELEASEASSERT
// (rbx_static_cast without the debug dynamic_cast, so IPipelined::getWorld inlines in 0060a0f0).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// Feature | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/16 mapped addresses byte-exact | 14 unproved | 1 referenced strings (not rechecked) | by king_originala (+4) (mixed 5)
// <<< native-status | src 0d38d2b5 | roc native-status --write
#include "v8datamodel/Feature.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/MotorJoint.h"
#include "reflection/enumconverter.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#include <boost/bind.hpp>
#ifdef NATIVE_FEATURE_PENDING
#include "v8datamodel/Workspace.h"
#endif

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

	template<class C, class D, const char* N>
	template<typename Arg0Type>
	DescribedCreatable<C, D, N>::DescribedCreatable(Arg0Type arg0)   // VelocityMotor: 0060bab0
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}

	// Dynamic initializers 007f7ac0, 007f7b00, 007f7b40, 007f7b80 (before the Feature ones; Functionality 5).
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

	// Dynamic initializers 007f7bc0, 007f7c00, 007f7c40, 007f7c80 (in this order; Functionality 5 = STANDARD).
	// The EnumPropDescriptor constructors they call (0060bd80, 0060c040, 0060c180, 0060c260) follow the 2008
	// reflection.h shape (call_once singleton, EnumDesc member at +0x20), not the shared native header.
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

	// 0060a490: not exact (same instructions, the original allocates ecx/edx/eax for the temporaries).
	// computeLocalCoordinateFrame 00609da0 is not recovered: it reads PartInstance's embedded Primitive (+0x228)
	// geometry, a layout the shared PartInstance.h/Primitive.h do not have.
	// Parked (hard-leftover batch 8, 2026-11-13). Rejected variants, each recompiled and diffed against 0060a490:
	//   1. c = part->getCoordinateFrame() * computeLocalCoordinateFrame(); -- worse: eax reused for the call
	//      result as the operator* argument (no re-lea of the temporary).
	//   2. const G3D::CoordinateFrame& local = computeLocalCoordinateFrame(); -- identical to this body
	//      (lea eax / lea ecx / lea edx; the original uses lea ecx / lea edx / lea eax).
	//   3. if (PartInstance* part = dynamic_cast<PartInstance*>(getParent())) -- identical to this body.
	//   Remaining difference is register naming only; no further source-shape evidence.
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

#ifdef NATIVE_FEATURE_PENDING
	// Needs JointInstance::onAncestorChanged (005e3a80) and Workspace::getWorldIfInWorkspace (005a3390).
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
#endif

	void VelocityMotor::onEvent_HoleAncestorChanged()
	{
		setPart(1, hole.get());
	}

#ifdef NATIVE_FEATURE_PENDING
	// Needs the 2008 SignalDesc::connect(source, slot, int group) (004a3340, group 10).
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
#endif

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

// VelocityMotor::setHole 0060c400 stays pending (2008 SignalDesc::connect with a group argument). The slot it builds
// from boost::bind(&VelocityMotor::onEvent_HoleAncestorChanged, this) (0060b650) is instantiated here explicitly, so
// this unit emits its boost::function manager / invoker rows (0060a300, 0060aac0, 0060abe0) against the current
// headers too.
typedef boost::_bi::bind_t<void, boost::_mfi::mf0<void, RBX::VelocityMotor>, boost::_bi::list1<boost::_bi::value<RBX::VelocityMotor*> > > VelocityMotorHoleBinder;
template boost::slot<boost::function<void(boost::shared_ptr<RBX::Instance>)> >::slot(const VelocityMotorHoleBinder&);

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
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

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sVelocityMotor>();
template void RBX::Name::callDoDeclare<RBX::sFeature>();
