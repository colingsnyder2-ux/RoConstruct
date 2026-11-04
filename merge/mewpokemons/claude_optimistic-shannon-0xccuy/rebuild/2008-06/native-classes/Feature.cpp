// 2008-06 native RBX::Feature, RBX::Hole, RBX::MotorFeature (inactive); evidence in
// native-headers/v8datamodel/Feature.h. Verified by tests/record_native_feature.py.
// The VelocityMotor half of the original unit (00609af0, 0060a020..0060a260, 0060a650, 0060bbb0, 0060c400..,
// initializers 007f7ac0..007f7b80) is not recovered here.
#include "v8datamodel/Feature.h"
#include "v8datamodel/PartInstance.h"
#include "reflection/enumconverter.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#ifdef NATIVE_FEATURE_PENDING
#include "v8datamodel/VelocityMotor.h"
#endif

namespace RBX
{
	const char sFeature[] = "Feature";           // 00842998 (doDeclare<sFeature> 00609c60)
	const char sHole[] = "Hole";                 // 008429a0 (doDeclare<sHole> 0057d6e0)
	const char sMotorFeature[] = "MotorFeature"; // 008429a8 (doDeclare<sMotorFeature> 0057d670)

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

#ifdef NATIVE_FEATURE_PENDING
	// Needs a VelocityMotor declaration (Creatable<Instance>::create<VelocityMotor> 005804a0,
	// VelocityMotor::setHole 0060c400); the recorder supplies a declaration-only overlay.
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
#endif
}
