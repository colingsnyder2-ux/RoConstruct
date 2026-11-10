// Inactive native 2008-06 recovery: the RBX::ModelInstance unit (v8datamodel/ModelInstance.cpp) of the application
// range 0057c000..00588000, 005834b0..00585c56 (after Verb.cpp's VerbContainer rows, before the Script unit that starts
// with ~FactoryProduct<Script> 00585c60). Verified by tests/record_native_app_unit57c_2008.py.
// Layout: the committed native v8datamodel/ModelInstance.h (read-only here). Its constructor 00585630 and destructor
// 00584790 are already counted by model-vector-lifetime-trial.json; they are compiled here (same bodies) only because
// the unit emits the FactoryProduct / DescribedCreatable / ComputeProp instantiations they call.
//   RTTI     vtable 00830dc4 .?AVModelInstance@RBX@@: FactoryProduct<ModelInstance, PVInstance, sModel> with sModel a
//            non-const char array (mangled $1?sModel@2@3PADA); IRenderable +0x1a0; virtual bases through the vbptr
//            at +0x134 (vtables of the IPrimaryPart / ILocation / ICameraSubject subobjects at +0x28c / +0x294 /
//            +0x29c: getPrimaryPart thunk 00584b20, getLocation thunk 00584af0, ??_E vtordisp thunk 005849f0).
//   size     0x2a4: Creatable<Instance>::create<ModelInstance> 00414960 mallocs 0x2a4 and calls 00585630.
//   fields   modelInPrimary +0x1b0 (getModelInPrimary 005834b0), primaryPart +0x1e0 (updatePrimaryPart 00583a40),
//            candidatePrimaryPart +0x1e4 (onDescendentAdded 00584620), modifiers +0x1ec (00585050 / 00584fc0),
//            LocalGridExtents +0x228 (computeWorldGridExtents 00583c90); the ComputeProp dirty flags that
//            onExtentsChanged 00583a20 sets are +0x240 (LocalGridExtents), +0x270 (WorldGridExtents) and +0x20c
//            (FlagHeight).
// Unit profile: document-swap flags, /fp:fast (x87 order of updatePrimaryPart / getPrimaryPartInternal) and
// /U_RELEASEASSERT (rbx_static_cast and RBXASSERT compile to nothing, as in Feature.cpp).
// NATIVE_APPUNIT57C_PENDING bodies need declarations the shared headers do not have yet (the ModelInstance
// onChildAdded / onChildRemoving overrides, vtable slots 7 / 8); the recorder builds them against generated header
// copies under out/native-layouts/app-unit57c-2008/pending/ (proposals in the receipt).
// Codegen analog: bodies follow the donor tools/rbxgs v8datamodel/ModelInstance.cpp shape; the recorder proves each
// against the bytes and every call / data target.
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "tool/DragUtilities.h"
#include "AppDraw/Draw.h"
#ifdef NATIVE_APPUNIT57C_PENDING
#include "v8datamodel/Clothing.h"           // IModelModifier (defined there)
#include <algorithm>
#endif

static bool physicalCharacterHacked = false;

namespace RBX
{
	char sModel[] = "Model";

	// Template members the shared headers only declare (same definitions as Feature.cpp / Hopper.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }   // 00584c10

	template<class C, class D, const char* N>
	template<typename Arg0Type>
	DescribedCreatable<C, D, N>::DescribedCreatable(Arg0Type arg0)   // 00585520
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}

	static const Name& partName = Name::declare(sModel, 2000);

	// PropDescriptor ctor 00585170 (getModelInPrimary 005834b0 / setModelInPrimary 005834c0 out of line),
	// RefPropDescriptor ctor 00585240 (primaryPartProp is the raisePropertyChanged argument of setPrimaryPart).
	static Reflection::PropDescriptor<ModelInstance, G3D::CoordinateFrame> desc_ModelInPrimary("ModelInPrimary", "Data", &ModelInstance::getModelInPrimary, &ModelInstance::setModelInPrimary, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::RefPropDescriptor<ModelInstance, PartInstance> primaryPartProp("PrimaryPart", "Data", &ModelInstance::getPrimaryPartInternal, &ModelInstance::setPrimaryPart, Reflection::PropertyDescriptor::STANDARD);
	// BoundFuncDesc<void()> ctor 00585890 / execute 00585910; BoundFuncDesc<void(Vector3)> ctor 00585980 / execute 00585a30.
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_breakJoints(&ModelInstance::breakJoints, "BreakJoints", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_makeJoints(&ModelInstance::makeJoints, "MakeJoints", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunctionOld(&PVInstance::moveToPoint, "move", "location", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunction(&PVInstance::moveToPoint, "MoveTo", "location", Reflection::FunctionDescriptor::AnyCaller);

	bool ModelInstance::showModelCoord = false;

#pragma warning (push)
#pragma warning (disable : 4355) // 'this' : used in base member initializer list
	ModelInstance::ModelInstance()   // 00585630 (counted by model-vector-lifetime-trial.json)
		: Base("Model"),
		  modelInPrimary(),
		  primaryPart(NULL),
		  FlagHeight(this, &ModelInstance::computeFlagHeight),
		  LocalGridExtents(this, &ModelInstance::computeLocalGridExtents),
		  WorldGridExtents(this, &ModelInstance::computeWorldGridExtents)
	{
		if (!physicalCharacterHacked)
		{
			const Name& name = Name::declare("PhysicalCharacter", -1);
			AbstractFactoryProduct<Instance>::getCreators()[&name] = &getCreator();
			physicalCharacterHacked = true;
		}
	}
#pragma warning (pop)

	ModelInstance::~ModelInstance()   // 00584790 (counted by model-vector-lifetime-trial.json)
	{
	}

	void ModelInstance::dirtyAll() const
	{
		LocalGridExtents.setDirty();
		WorldGridExtents.setDirty();
		FlagHeight.setDirty();
	}

	void ModelInstance::onExtentsChanged() const   // 00583a20
	{
		dirtyAll();
		PVInstance::onExtentsChanged();
	}

	void ModelInstance::onDescendentAdded(Instance* instance)   // 00584620
	{
		PVInstance::onDescendentAdded(instance);
		dirtyAll();

		if (instance == candidatePrimaryPart.get())
		{
			candidatePrimaryPart.reset();
			updatePrimaryPart(static_cast<PartInstance*>(instance));
		}

		shouldRenderSetDirty();
	}

	void ModelInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)   // 00584670
	{
		if (primaryPart == instance.get())
			primaryPart = NULL;

		if (candidatePrimaryPart == instance)
			candidatePrimaryPart.reset();

		dirtyAll();
		shouldRenderSetDirty();
		PVInstance::onDescendentRemoving(instance);
	}

#ifdef NATIVE_APPUNIT57C_PENDING
	// 00585050 / 00584fc0: vtable slots 7 / 8 of 00830dc4 (dynamic_cast to IModelModifier 00936908, modifiers +0x1ec,
	// push_back 004213a0 / erase 00459830). The native ModelInstance.h does not declare these overrides (proposal).
	void ModelInstance::onChildAdded(Instance* child)
	{
		if (IModelModifier* modifier = dynamic_cast<IModelModifier*>(child))
			modifiers.push_back(modifier);
	}

	void ModelInstance::onChildRemoving(Instance* child)
	{
		if (IModelModifier* modifier = dynamic_cast<IModelModifier*>(child))
			modifiers.erase(std::find(modifiers.begin(), modifiers.end(), modifier));
	}
#endif

	// 005834f0: exact only with the 2008 PartInstance (embedded Primitive at +0x228, native-headers/part-embedded).
	const Primitive* ModelInstance::getBiggestPrimitive() const
	{
		const PartInstance* primaryPart = getPrimaryPartConst();
		if (primaryPart)
			return primaryPart->getPrimitive();

		return NULL;
	}

	void ModelInstance::updatePrimaryPart(PartInstance* set) const   // 00583a40
	{
		if (primaryPart == set)
		{
		}
		else if (set)
		{
			if (primaryPart)
			{
				G3D::Matrix3 oldMe = getLocation().rotation;
				modelInPrimary = G3D::CoordinateFrame(primaryPart->getCoordinateFrame().rotation.transpose() * oldMe, G3D::Vector3::zero());
				primaryPart = set;
			}
			else
			{
				modelInPrimary = G3D::CoordinateFrame();
				primaryPart = set;
			}
		}
		else
		{
			modelInPrimary = G3D::CoordinateFrame();
			primaryPart = NULL;
		}
	}

	// 00585b30: NOT exact (278 B against 294 B; with the pending inline isDescendentOf 294 B, but the original keeps
	// `this` in ebp and that build in ebx).
	void ModelInstance::setPrimaryPart(PartInstance* set)
	{
		if (!set || set->isDescendentOf(this))
		{
			candidatePrimaryPart.reset();
			updatePrimaryPart(set);
		}
		else
		{
			candidatePrimaryPart = shared_from(set);

			if (primaryPart)
			{
				modelInPrimary = G3D::CoordinateFrame();
				primaryPart = NULL;
			}
		}

		raisePropertyChanged(primaryPartProp);
	}

	static void makeJ(Instance* instance)   // 00584b30
	{
		PartInstance* partInstance = dynamic_cast<PartInstance*>(instance);
		if (partInstance)
		{
			partInstance->join();
		}
		else
		{
			ModelInstance* modelInstance = dynamic_cast<ModelInstance*>(instance);
			if (modelInstance)
				modelInstance->for_eachChild(makeJ);
		}
	}

	void ModelInstance::makeJoints()   // 00584b90
	{
		for_eachChild(makeJ);
	}

	static void breakJ(Instance* instance)   // 00584ba0
	{
		PartInstance* partInstance = dynamic_cast<PartInstance*>(instance);
		if (partInstance)
		{
			partInstance->destroyJoints();
		}
		else
		{
			ModelInstance* modelInstance = dynamic_cast<ModelInstance*>(instance);
			if (modelInstance)
				modelInstance->for_eachChild(breakJ);
		}
	}

	void ModelInstance::breakJoints()   // 00584c00
	{
		for_eachChild(breakJ);
	}

	// 00584100: exact only with an inline Extents::areaXZ (generated util/Extents.h copy; proposal).
	PartInstance* ModelInstance::getPrimaryPartInternal() const
	{
		if (primaryPart)
			return primaryPart;

		float biggest = -1.0f;
		PartInstance* biggestPart = NULL;
		for (size_t i = 0; i < numChildren(); ++i)
		{
			const Instance* child = getChild(i);
			const PVInstance* pvChild = dynamic_cast<const PVInstance*>(child);
			if (pvChild)
			{
				const Primitive* primitive = pvChild->getBiggestPrimitive();
				if (primitive)
				{
					PartInstance* part = PartInstance::fromPrimitive(const_cast<Primitive*>(primitive));
					float area = part->getExtentsWorld().areaXZ();
					if (area > biggest)
					{
						biggest = area;
						biggestPart = part;
					}
				}
			}
		}

		updatePrimaryPart(biggestPart);
		return biggestPart;
	}

	// 00584d80: exact only with the 2008 Primitive (geometry +0x9c, native-headers/part-embedded) and inline
	// Extents::zero / negativeInfiniteExtents (00583860 / 00583920 are their COMDAT bodies; proposal).
	Extents ModelInstance::computeLocalGridExtents() const
	{
		std::vector<const Primitive*> primitives;
		DragUtilities::getPrimitivesConst(this, primitives);

		Extents answer = Extents::negativeInfiniteExtents();

		for (size_t i = 0; i < primitives.size(); i++)
		{
			const Primitive* primitive = primitives[i];
			Extents localExtents = primitive->getExtentsLocal();
			Extents childExtentsInMe = localExtents.express(primitive->getCoordinateFrame(), getLocation());
			answer.unionWith(childExtentsInMe);
		}

		return primitives.size() > 0 ? answer : Extents::zero();
	}

	Extents ModelInstance::computeWorldGridExtents() const   // 00583c90
	{
		return LocalGridExtents.getValue().express(getLocation(), G3D::CoordinateFrame());
	}

	void ModelInstance::legacyTraverseState(const G3D::CoordinateFrame& parentState)   // 005841e0
	{
		if (children)
		{
			int count = (int)children->size();
			if (count > 0)
			{
				G3D::CoordinateFrame myState = parentState * (*legacyOffset);
				for (int i = 0; i < count; ++i)
				{
					Instance* child = getChild(i);
					PVInstance* pvChild = dynamic_cast<PVInstance*>(child);
					if (pvChild)
						pvChild->legacyTraverseState(myState);
				}
			}
		}
	}

	const G3D::CoordinateFrame ModelInstance::getLocation() const   // 00583cf0
	{
		if (getPrimaryPartConst())
		{
			G3D::CoordinateFrame cf = primaryPart->getCoordinateFrame();
			return G3D::CoordinateFrame(cf.rotation * modelInPrimary.rotation, cf.translation);
		}

		return G3D::CoordinateFrame();
	}

	bool ModelInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)   // 00584280
	{
		for (size_t i = 0; i < numChildren(); ++i)
		{
			Instance* child = getChild(i);
			PVInstance* pvChild = dynamic_cast<PVInstance*>(child);
			if (pvChild)
			{
				if (pvChild->hitTest(worldRay, worldHitPoint))
					return true;
			}
		}

		return false;
	}

	// 00584310 / 00584360: exact only with the 2008 isTopLevelPVInstance inlined (an iterative getTypedRoot<PVInstance>,
	// out of line at 005836d0; isTopLevelPVInstance itself out of line at 005840a0): generated v8tree/Instance.h copy.
	bool ModelInstance::shouldRender3dAdorn() const
	{
		return isTopLevelPVInstance() && showModelCoord;
	}

	void ModelInstance::render3dAdorn(Adorn* adorn)
	{
		if (isTopLevelPVInstance())
		{
			if (showModelCoord)
				renderCoordinateFrame(adorn);
		}
	}

	void ModelInstance::render3dSelect(Adorn* adorn, SelectState selectState)   // 00583da0 (Part ctor 00583980)
	{
		Extents localExtents = getExtentsLocal();
		G3D::CoordinateFrame location = getLocation();
		location.translation = location.pointToWorldSpace(localExtents.center());

		Part part(Part::BLOCK_PART, localExtents.size(), G3D::Color3::white(), location);
		Draw::selectionBox(part, adorn, selectState);
	}

	void ModelInstance::onCameraNear(float distance)   // 005843c0
	{
		for (size_t i = 0; i < numChildren(); ++i)
		{
			Instance* child = getChild(i);
			ICameraSubject* cameraSubject = dynamic_cast<ICameraSubject*>(child);
			if (cameraSubject)
				cameraSubject->onCameraNear(distance);
		}
	}
}
