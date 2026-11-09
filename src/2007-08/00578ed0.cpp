// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_part_flags_d9c3a93f48e031eb.cpp

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
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
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
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/Assembly.h"
#include "v8world/Controller.h"
#include "v8world/World.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#include "AppDraw/HitTest.h"
#include "tool/Dragger.h"
#include <G3D/CoordinateFrame.h>
#include "reflection/type.h"

namespace RBX
{
const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_CastsShadows("CastsShadows", "Appearance", &PartInstance::getCastsShadows, &PartInstance::setCastsShadows, Reflection::PropertyDescriptor::STANDARD);
const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Cullable("Cullable", "Appearance", &PartInstance::getCullable, &PartInstance::setCullable, Reflection::PropertyDescriptor::STANDARD);
	const char* category_Part = "Part";

	static Reflection::BoundFuncDesc<PartInstance, void(void), 0> desc_unjoin(&PartInstance::destroyJoints, "BreakJoints", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<PartInstance, void(void), 0> desc_join(&PartInstance::join, "MakeJoints", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<PartInstance, float(void), 0> desc_getMass(&PartInstance::getMass, "GetMass", Reflection::FunctionDescriptor::AnyCaller);

	static Reflection::EnumPropDescriptor<PartInstance, Part::PartType> prop_shapeUi("Shape", category_Part, &PartInstance::getPartType, &PartInstance::setPartTypeUi, Reflection::PropertyDescriptor::UI);

	static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_PositionUi("Position", "Data", &PartInstance::getTranslationUi, &PartInstance::setTranslationUi, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_Velocity("Velocity", "Data", &PartInstance::getLinearVelocity, &PartInstance::setLinearVelocity, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_RotVelocity("RotVelocity", "Data", &PartInstance::getRotationalVelocity, &PartInstance::setRotationalVelocity, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_SizeUi("Size", category_Part, &PartInstance::getPartSizeUi, &PartInstance::setPartSizeUi, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<PartInstance, bool> prop_Dragging("DraggingV1", "Behavior", &PartInstance::getDragging, &PartInstance::setDragging, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<PartInstance, PartInstance::FormFactor> prop_formFactorUi("formFactor", category_Part, &PartInstance::getFormFactor, &PartInstance::setFormFactorUi, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<PartInstance, PartInstance::FormFactor> prop_formFactor("FormFactor", category_Part, &PartInstance::getFormFactor, &PartInstance::setFormFactorXml, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<PartInstance, float> prop_Friction("Friction", category_Part, &PartInstance::getFriction, &PartInstance::setFriction, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<PartInstance, float> prop_Elasticity("Elasticity", category_Part, &PartInstance::getElasticity, &PartInstance::setElasticity, Reflection::PropertyDescriptor::STANDARD);

	namespace Reflection
	{
		// TODO: check if type singletons are matching
		template<>
		const Type& Type::singleton<G3D::CoordinateFrame>()
		{
			static Type type("CoordinateFrame", typeid(G3D::CoordinateFrame));
			return type;
		}
	}

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	PartInstance::PartInstance()
		: Base("Part"),
		  partType(Part::BLOCK_PART),
		  formFactor(BRICK),
		  color(BrickColor::defaultColor()),
		  transparency(0.0f),
		  reflectance(0.0f),
		  locked(false),
		  surfaces(this),
		  castsShadows(true),
		  cullable(true),
		  primitive(new Primitive(Geometry::GEOMETRY_BLOCK)),
		  alphaModifier(1.0f),
		  myWorld(NULL),
		  PersistentPart(this, &PartInstance::computePersistentPart),
		  SurfacesNeedAdorn(this, &PartInstance::computeSurfacesNeedAdorn)
	{
		primitive->setSurfaceType(NORM_Y, STUDS);
		primitive->setSurfaceType(NORM_Y_NEG, INLET);
		primitive->setGridSize(G3D::Vector3(4.0f, 1.2f, 2.0f));
		primitive->setFriction(0.3f);
		primitive->setElasticity(0.5f);
		primitive->setAnchor(false);
		primitive->setCanCollide(true);
		primitive->setOwner(this);

	}
#pragma warning (pop)

	PartInstance::~PartInstance()
	{
		RBXASSERT(!primitive->getClump());
		RBXASSERT(!myWorld);
	}

	Surfaces& PartInstance::getSurfaces()
	{
		return surfaces;
	}

	const Surfaces& PartInstance::getSurfaces() const
	{
		return surfaces;
	}

// Later GUID hook omitted; historical Instance and Primitive have no GUID fields.
	bool PartInstance::nonNullInWorkspace(boost::shared_ptr<PartInstance> part)
	{
		bool null = part.get() && part->myWorld;
		RBXASSERT(!null || part->primitive->inPipeline());
		return null;
	}

	void PartInstance::destroyJoints()
	{
		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world)
			world->destroyJoints(primitive.get());
	}

	void PartInstance::join()
	{
		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world)
			world->createJoints(primitive.get());
	}

	bool PartInstance::computeSurfacesNeedAdorn() const
	{
		for (int i = 0; i < 6; i++)
		{
			Surface& current = surfaces[(NormalId)i];
			if (current.getSurfaceType() == ROTATE || current.getSurfaceType() == ROTATE_P || current.getSurfaceType() == ROTATE_V)
				return true;
		}
		return false;
	}

	void PartInstance::legacyTraverseState(const G3D::CoordinateFrame& parentState)
	{
		RBXASSERT(legacyOffset.get());

		G3D::CoordinateFrame myState = parentState * *legacyOffset;
		primitive->setGridCorner(myState);
	}

	bool PartInstance::isControllable() const
	{
		for (int i = 0; i < 6; i++)
		{
			Surface& current = surfaces[(NormalId)i];
			if ((current.getSurfaceType() == ROTATE_P || current.getSurfaceType() == ROTATE_V) && current.isControllable())
				return true;
		}
		return false;
	}

	void PartInstance::onSurfaceChanged(RBX::NormalId surfId)
	{
		PersistentPart.setDirty();
		IsControllable.setDirty();
		SurfacesNeedAdorn.setDirty();
		shouldRenderSetDirty();
	}

	void PartInstance::setPhysics(const G3D::CoordinateFrame& value)
	{
		if (value != getCoordinateFrame())
		{
			RBXASSERT(Math::isOrthonormal(value.rotation));
			primitive->setCoordinateFrame(value);
			PersistentPart.setDirty();
			onExtentsChanged();
		}
	}

	void PartInstance::setPhysics(const G3D::CoordinateFrame& cf, const Velocity& vel)
	{
		primitive->getBody()->setVelocity(vel);
		setPhysics(cf);
	}

	const G3D::CoordinateFrame& PartInstance::getCoordinateFrame() const
	{
		return primitive->getCoordinateFrame();
	}

	const G3D::Vector3& PartInstance::getTranslationUi() const
	{
		return primitive->getBody()->getCoordinateFrame().translation;
	}

	float PartInstance::getMass()
	{
		return primitive->getBody()->getMass();
	}

	const Velocity& PartInstance::getVelocity() const
	{
		return primitive->getBody()->getVelocity();
	}

	const G3D::Vector3& PartInstance::getLinearVelocity() const
	{
		return getVelocity().linear;
	}

	const G3D::Vector3& PartInstance::getRotationalVelocity() const
	{
		return getVelocity().rotational;
	}

	const G3D::Vector3& PartInstance::getPartSizeXml() const
	{
		return primitive->getGeometry()->getGridSize();
	}

	G3D::Vector3 PartInstance::getPartSizeUi() const
	{
		return getPartSizeXml();
	}

	bool PartInstance::getDragging() const
	{
		return primitive->getDragging();
	}

	bool PartInstance::getCanCollide() const
	{
		return !primitive->getDragging() && primitive->getCanCollide() ? true : false;
	}

	bool PartInstance::getAnchored() const
	{
		return primitive->getAnchor();
	}

	float PartInstance::getFriction() const
	{
		return primitive->getFriction();
	}

	float PartInstance::getElasticity() const
	{
		return primitive->getElasticity();
	}

	Extents PartInstance::getExtentsWorld() const
	{
		return primitive->getExtentsWorld();
	}

	Extents PartInstance::getExtentsLocal() const
	{
		return primitive->getExtentsLocal();
	}

	G3D::CoordinateFrame PartInstance::worldSnapLocation() const
	{
		G3D::Vector3 halfSize = getPartSizeXml() * 0.5f;

		G3D::Vector3 snapInPart;
		snapInPart.y = -halfSize.y;
		snapInPart.x = halfSize.x - G3D::iRound(floorf(halfSize.x));
		snapInPart.z = halfSize.z - G3D::iRound(floorf(halfSize.z));

		G3D::CoordinateFrame localSnapLocation(snapInPart);
		return primitive->getCoordinateFrame() * localSnapLocation;
	}

	bool PartInstance::aligned() const
	{
		G3D::CoordinateFrame myCoord = worldSnapLocation();
		G3D::CoordinateFrame myCoordSnapped = Math::snapToGrid(myCoord, Dragger::dragSnap());

		return Math::fuzzyEq(myCoord, myCoordSnapped, 0.00001, 0.00001);
	}


	G3D::Vector3 PartInstance::uiToXmlSize(const G3D::Vector3& uiSize) const
	{
		G3D::Vector3 gridUiSize = Math::iRoundVector3(uiSize.max(G3D::Vector3(1.0f, 1.0f, 1.0f)));
		G3D::Vector3 xmlSize = gridUiSize;
		
		switch (formFactor)
		{
		case BRICK:
			xmlSize.y *= 1.2f;
			break;
		case PLATE:
			xmlSize.y *= 0.4f;
			break;
		}

		return xmlSize;
	}

	const Part& PartInstance::getPart() const
	{
		const Part& part = PersistentPart.getValueRef();
		part.coordinateFrame = primitive->getCoordinateFrame();
		return part;
	}

	Part PartInstance::computePersistentPart() const
	{
		const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame();
		float transparency = 1.0f - alpha();

		return Part(partType, getPartSizeXml(), G3D::Color4(getColor3(), transparency), surfaces.surf6(), cframe);
	}

	const RBX::PartInstance* PartInstance::fromPrimitiveConst(const Primitive* p)
	{
		RBXASSERT(!p || dynamic_cast<PartInstance*>(p->getOwner()));

		if (p)
			return rbx_static_cast<PartInstance*>(p->getOwner());
		else
			return NULL;
	}

	PartInstance* PartInstance::fromPrimitive(Primitive* p)
	{
		return const_cast<PartInstance*>(fromPrimitiveConst(p));
	}

	bool PartInstance::shouldRender3dAdorn() const
	{
		return partType == Part::CYLINDER_PART ||
			   SurfacesNeedAdorn || 
			   highlightSleepParts || 
			   highlightAwakeParts || 
			   showPartCoord || 
			   showAnchoredParts ||
			   showUnalignedParts ||
			   showSpanningTree;
	}

	bool PartInstance::getLocked(Instance* instance)
	{
		PartInstance* thisPart = dynamic_cast<PartInstance*>(instance);

		if (thisPart)
		{
			return thisPart->locked;
		}
		else
		{
			for (size_t i = 0; i < instance->numChildren(); i++)
			{
				if (getLocked(instance->getChild(i)))
					return true;
			}
			return false;
		}
	}

	void PartInstance::onParentControllerChanged()
	{
		PVInstance::onParentControllerChanged();
		PersistentPart.setDirty();
		primitive->setController(getTopPVController());
	}

	void PartInstance::onCanAggregateChanged(bool canAggregate)
	{
		RBXASSERT(canAggregate == getCanAggregate());
		Notifier<PartInstance, CanAggregateChanged>::raise(canAggregate);
		shouldRenderSetDirty();
	}

	void PartInstance::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);
		RBXASSERT(primitive.get());

		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world != myWorld)
		{
			RBXASSERT(myWorld || !primitive->getClump());

			if (myWorld)
			{
				setMovingManager(NULL);
				myWorld->removePrimitive(primitive.get());
			}

			myWorld = world;

			if (world)
			{
				world->insertPrimitive(primitive.get());
				setMovingManager(Workspace::getMyWorkspaceFast(this));
				primitive->setController(getTopPVController());
			}
		}
	}

	void PartInstance::onTouchThisStep(boost::shared_ptr<PartInstance> other)
	{
		event_Touched.fire(this, other);
	}

	void PartInstance::onChildAdded(Instance* child)
	{
		PVInstance::onChildAdded(child);
	}

	void PartInstance::onCameraNear(float distance)
	{
		if (distance < 3.0f)
			setAlphaModifier(0.0f);
		else if (distance < 6.0f)
			setAlphaModifier(0.5f);
		else
			setAlphaModifier(1.0f);
	}

	void PartInstance::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		Draw::selectionBox(getPart(), adorn, selectState);
	}

	void PartInstance::render3dAdorn(Adorn* adorn)
	{
		if (partType == Part::CYLINDER_PART || SurfacesNeedAdorn)
			Draw::partAdorn(getPart(), adorn, Controller::controllerTypeToColor(getTopPVController()->getControllerType()));

		if (highlightSleepParts && primitive->getAssembly())
		{
			Sim::AssemblyState sleepStatus = primitive->getAssembly()->getRootClump()->getSleepStatus();

			if (sleepStatus != Sim::ANCHORED && sleepStatus != Sim::AWAKE)
			{
				G3D::Color3 sleepColor;

				switch (sleepStatus)
				{
				case Sim::RECURSIVE_WAKE_PENDING:
				case Sim::WAKE_PENDING:
					sleepColor = G3D::Color3::purple();
					break;
				case Sim::SLEEPING_CHECKING:
					sleepColor = G3D::Color3::orange();
					break;
				case Sim::SLEEPING_DEEPLY:
					sleepColor = G3D::Color3::yellow();
					break;
				default:
					RBXASSERT(0);
					sleepColor = sleepColor;
					break;
				}
				
				Draw::selectionBox(getPart(), adorn, sleepColor);
			}
		}

		if (highlightAwakeParts && primitive->getAssembly())
		{
			Sim::AssemblyState sleepStatus = primitive->getAssembly()->getRootClump()->getSleepStatus();

			if (sleepStatus != Sim::ANCHORED && sleepStatus != Sim::SLEEPING_DEEPLY)
			{
				G3D::Color3 wakeColor;

				switch (sleepStatus)
				{
				case Sim::SLEEPING_CHECKING:
					wakeColor = G3D::Color3::red();
					break;
				case Sim::AWAKE:
					wakeColor = G3D::Color3::orange();
					break;					
				case Sim::RECURSIVE_WAKE_PENDING:
				case Sim::WAKE_PENDING:
					wakeColor = G3D::Color3::purple();
					break;
				default:
					RBXASSERT(0);
					wakeColor = wakeColor;
					break;
				}
				
				Draw::selectionBox(getPart(), adorn, wakeColor);
			}
		}

		if (showPartCoord)
			renderCoordinateFrame(adorn);

		if (showAnchoredParts && primitive->getAnchor())
		{
			float transparency = 1.0f - alpha();
			G3D::Color4 color(G3D::Color3::gray(), transparency);
			const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame();

			DrawAdorn::partSurface(getPart(), Math::getClosestObjectNormalId(G3D::Vector3(0.0f, -1.0f, 0.0f), cframe.rotation), adorn, color);
		}

		if (showUnalignedParts && !aligned())
			Draw::selectionBox(getPart(), adorn, G3D::Color3::yellow());

		if (showSpanningTree)
		{
			setAlphaModifier(0.3f);

			Assembly* assembly = primitive->getAssembly();
			if (assembly && primitive.get() == assembly->getMainPrimitive())
			{
				adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(primitive->getCoordinateFrame().translation));

				if (primitive->getAnchor())
				{
					adorn->sphere(G3D::Sphere(G3D::Vector3::zero(), 0.5f), G3D::Color3::green(), G3D::Color4::clear());
				}
				else
				{
					G3D::Vector3 boxSize = G3D::Vector3::one() * 0.25f;
					adorn->box(G3D::AABox(-boxSize, boxSize), G3D::Color3::green(), G3D::Color4::clear());
				}
			}
		}
	}

	bool PartInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
	{
		const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame();
		G3D::Ray rayInPartCoords = cframe.toObjectSpace(worldRay);
		G3D::Vector3 hitPointInPartCoords;

		if (HitTest::hitTest(getPart(), rayInPartCoords, hitPointInPartCoords, 1.0f))
		{
			const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame(); // roblox be like: lets do it again why not
			worldHitPoint = cframe.pointToWorldSpace(hitPointInPartCoords);
			return true;
		}
		else
		{
			return false;
		}
	}

	void PartInstance::safeMove()
	{
		RBXASSERT(primitive.get());

		if (World* world = Workspace::getWorldIfInWorkspace(this))
		{
			G3D::Array<Primitive*> temp;
			temp.append(primitive.get());
			
			Dragger::safeMoveNoDrop(temp, G3D::Vector3::zero(), world->getContactManager());
		}
	}

	void PartInstance::primitivesToParts(const G3D::Array<Primitive*>& primitives, G3D::Array<boost::shared_ptr<PartInstance>>& parts)
	{
		for (int i = 0; i < primitives.size(); i++)
		{
			PartInstance* part = fromPrimitive(primitives[i]);
			parts.push_back(shared_from(part));
		}
	}

	void PartInstance::findParts(Instance* instance, std::vector<boost::weak_ptr<RBX::PartInstance>>& parts)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
			parts.push_back(shared_from(part));

		for (size_t i = 0; i < instance->numChildren(); i++)
		{
			findParts(instance->getChild(i), parts);
		}
	}

	void PartInstance::setCoordinateFrame(const G3D::CoordinateFrame& value)
	{
		if (value != getCoordinateFrame())
		{
			G3D::CoordinateFrame newValue = value;
			Math::orthonormalizeIfNecessary(newValue.rotation);
			setPhysics(newValue);

			raisePropertyChanged(prop_CFrame);
			raisePropertyChanged(prop_PositionUi);
		}
	}

	void PartInstance::setPartSizeXml(const G3D::Vector3& rbxSize)
	{
		if (rbxSize != getPartSizeXml())
		{
			G3D::Vector3 newRbxSize = partType == Part::BLOCK_PART ? rbxSize : rbxSize.xxx();
			RBXASSERT(newRbxSize.max(G3D::Vector3(1.0f, 0.4f, 1.0f)) == newRbxSize);

			if (legacyOffset.get())
			{
				G3D::CoordinateFrame oldCorner = primitive->getGridCorner();
				primitive->setGridSize(newRbxSize);
				primitive->setGridCorner(oldCorner);
			}
			else
			{
				primitive->setGridSize(newRbxSize);
			}

			raisePropertyChanged(prop_Size);
			raisePropertyChanged(prop_SizeUi);
			PersistentPart.setDirty();
			onExtentsChanged();
		}
	}

	//93.96% match
	//not matching for the same reason as PartInstance::setFormFactorUi
	void PartInstance::setPartSizeUi(const G3D::Vector3& uiSize)
	{
		destroyJoints();

		G3D::Vector3 adjustedUiSize = uiSize;

		switch (formFactor)
		{
		case BRICK:
			adjustedUiSize.y = uiSize.y * 5.0f/6.0f;
			break;
		case PLATE:
			adjustedUiSize.y = uiSize.y * 2.5f;
			break;
		}

		setPartSizeXml(uiToXmlSize(adjustedUiSize));
		safeMove();
		join();
	}

	void PartInstance::setTranslationUi(const G3D::Vector3& set)
	{
		G3D::CoordinateFrame current = primitive->getCoordinateFrame();

		if (current.translation != set)
		{
			current.translation = set;

			destroyJoints();
			
			setCoordinateFrame(current);
			safeMove();
			join();
		}
	}

	void PartInstance::setDragging(bool value)
	{
		if (value != getDragging())
		{
			primitive->setDragging(value);
			raisePropertyChanged(prop_Dragging);
		}
	}

	void PartInstance::setCastsShadows(bool value)
	{
		if (value != getCastsShadows())
		{
			castsShadows = value;
			raisePropertyChanged(prop_CastsShadows);
		}
	}
	void PartInstance::setCullable(bool value)
	{
		if (value != getCullable())
		{
			cullable = value;
			raisePropertyChanged(prop_Cullable);
		}
	}

	void PartInstance::setCanCollide(bool value)
	{
		if (value != getCanCollide())
		{
			primitive->setCanCollide(value);
			raisePropertyChanged(prop_CanCollide);
		}
	}

	void PartInstance::setAnchored(bool value)
	{
		if (value != getAnchored())
		{
			primitive->setAnchor(value);
			raisePropertyChanged(prop_Anchored);
		}
	}

	void PartInstance::setPartLocked(bool value)
	{
		if (value != getPartLocked())
		{
			locked = value;
			raisePropertyChanged(prop_Locked);
		}
	}

	void PartInstance::setTransparency(float value)
	{
		if (value != getTransparencyXml())
		{
			transparency = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	void PartInstance::setAlphaModifier(float value)
	{
		if (value != alphaModifier)
		{
			alphaModifier = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	void PartInstance::setReflectance(float value)
	{
		if (value != getReflectance())
		{
			reflectance = value;
			raisePropertyChanged(prop_Reflectance);
		}
	}

	void PartInstance::setColor(BrickColor value)
	{
		if (value != color)
		{
			color = value;
			raisePropertyChanged(prop_BrickColor);
			raisePropertyChanged(prop_Color);
		}
	}

	void PartInstance::setFormFactorXml(FormFactor value)
	{
		if (value != getFormFactor())
		{
			formFactor = value;
			raisePropertyChanged(prop_formFactor);
		}
	}

	//94.32% match
	//there is a way to match it 100% but it is Not Clean. try to find a cleaner way.
	void PartInstance::setFormFactorUi(FormFactor value)
	{
		if (partType != Part::BLOCK_PART)
			value = SYMETRIC;

		if (value != getFormFactor())
		{
			destroyJoints();

			setFormFactorXml(value);

			G3D::Vector3 uiSize = getPartSizeUi();
			uiSize.y = G3D::max<float>(1.0, G3D::iRound(uiSize.y));

			G3D::Vector3 xmlSize = uiToXmlSize(uiSize);
			setPartSizeXml(xmlSize);
			safeMove();
			join();
		}
	}

	void PartInstance::setFriction(float friction)
	{
		float newFriction = G3D::clamp(friction, 0.0f, 2.0f);
		if (newFriction != getFriction())
		{
			primitive->setFriction(newFriction);
			raisePropertyChanged(prop_Friction);
		}
	}

	void PartInstance::setElasticity(float elasticity)
	{
		float newElasticity = G3D::clamp(elasticity, 0.0f, 1.0f);
		if (newElasticity != getElasticity())
		{
			primitive->setElasticity(newElasticity);
			raisePropertyChanged(prop_Elasticity);
		}
	}

	void PartInstance::setPartTypeXml(Part::PartType _type)
	{
		if (getPartType() != _type)
		{
			partType = _type;
			primitive->setPrimitiveType(_type == Part::BLOCK_PART ? Geometry::GEOMETRY_BLOCK : Geometry::GEOMETRY_BALL);

			if (partType != Part::BLOCK_PART)
				setFormFactorXml(SYMETRIC);

			raisePropertyChanged(prop_shapeXml);
			raisePropertyChanged(prop_shapeUi);

			PersistentPart.setDirty();
			shouldRenderSetDirty();
			onExtentsChanged();
		}
	}

	void PartInstance::setPartTypeUi(Part::PartType _type)
	{
		if (partType != Part::BLOCK_PART)
			RBXASSERT(formFactor == SYMETRIC);

		if (getPartType() != _type)
		{
			destroyJoints();

			setPartTypeXml(_type);

			if (_type != Part::BLOCK_PART)
			{
				G3D::Vector3 xmlSize = uiToXmlSize(getPartSizeUi());
				setPartSizeXml(xmlSize);
				safeMove();
			}

			safeMove();
			join();
		}
	}

	void PartInstance::setLinearVelocity(const G3D::Vector3& set)
	{
		Velocity vel = getVelocity();
		if (vel.linear != set)
		{
			vel.linear = set;
			primitive->getBody()->setVelocity(vel);
			raisePropertyChanged(prop_RotVelocity);
		}
	}

	void PartInstance::setRotationalVelocity(const G3D::Vector3& set)
	{
		Velocity vel = getVelocity();
		if (vel.rotational != set)
		{
			vel.rotational = set;
			primitive->getBody()->setVelocity(vel);
			raisePropertyChanged(prop_RotVelocity);
		}
	}

	bool PartInstance::reportTouches() const
	{
		return !event_Touched.empty(this);
	}
}
