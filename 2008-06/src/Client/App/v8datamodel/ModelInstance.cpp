#pragma float_control(precise, off)
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
namespace RBX { template Humanoid* Instance::findFirstChildOfType<Humanoid>() const; }
#include "v8world/Primitive.h"
#include "tool/DragUtilities.h"
#include "AppDraw/Draw.h"

static bool physicalCharacterHacked = false;

namespace RBX
{
	const char* sModel = "Model";

	static const Name& partName = Name::declare(sModel, 2000);

	static Reflection::PropDescriptor<ModelInstance, G3D::CoordinateFrame> desc_ModelInPrimary("ModelInPrimary", "Data", &ModelInstance::getModelInPrimary, &ModelInstance::setModelInPrimary, Reflection::PropertyDescriptor::STREAMING); // L25
	static Reflection::RefPropDescriptor<ModelInstance, PartInstance> primaryPartProp("PrimaryPart", "Data", &ModelInstance::getPrimaryPartInternal, &ModelInstance::setPrimaryPart, Reflection::PropertyDescriptor::STANDARD); // L26
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_breakJoints(&ModelInstance::breakJoints, "BreakJoints", Reflection::FunctionDescriptor::AnyCaller); // L27
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_makeJoints(&ModelInstance::makeJoints, "MakeJoints", Reflection::FunctionDescriptor::AnyCaller); // L28

	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunctionOld(&PVInstance::moveToPoint, "move", "location", Reflection::FunctionDescriptor::AnyCaller); // L30
	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunction(&PVInstance::moveToPoint, "MoveTo", "location", Reflection::FunctionDescriptor::AnyCaller); // L31

	bool ModelInstance::showModelCoord = false;

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	ModelInstance::ModelInstance()
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

	ModelInstance::~ModelInstance()
	{
		RBXASSERT(!primaryPart);
	}

	void ModelInstance::dirtyAll() const
	{
		LocalGridExtents.setDirty();
		WorldGridExtents.setDirty();
		FlagHeight.setDirty();
	}

	bool ModelInstance::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const ModelInstance*>(instance) != NULL;
	}

	void ModelInstance::onExtentsChanged() const
	{
	LocalGridExtents.setDirty();
	WorldGridExtents.setDirty();
	FlagHeight.setDirty();

	PVInstance::onExtentsChanged();
}

	void ModelInstance::onChildAdded(Instance* child)
	{
		IModelModifier* modifier = dynamic_cast<IModelModifier*>(child);
		if (modifier)
			modifiers.push_back(modifier);
	}

	void ModelInstance::onChildRemoving(Instance* child)
	{
		IModelModifier* modifier = dynamic_cast<IModelModifier*>(child);
		if (modifier)
			modifiers.erase(std::find(modifiers.begin(), modifiers.end(), modifier));
	}

	void ModelInstance::onDescendentAdded(Instance* instance)
	{
	PVInstance::onDescendentAdded(instance);

	LocalGridExtents.setDirty();
	WorldGridExtents.setDirty();
	FlagHeight.setDirty();

	if (instance == candidatePrimaryPart.get()) {
		candidatePrimaryPart.reset();

		updatePrimaryPart(static_cast<PartInstance*>(instance));
	}

	shouldRenderSetDirty();
}

	void ModelInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		if (primaryPart == instance.get())
			primaryPart = NULL;

		if (candidatePrimaryPart == instance)
		{
			candidatePrimaryPart.reset();
		}

		dirtyAll();
		shouldRenderSetDirty();
		PVInstance::onDescendentRemoving(instance);
	}

	const Primitive* ModelInstance::getBiggestPrimitive() const
	{
	const PartInstance* part = getPrimaryPartConst();

	if (part != NULL) {
		return part->getPrimitive();
	}

	return NULL;
}

	void ModelInstance::updatePrimaryPart(PartInstance* set) const
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

	void ModelInstance::setFrontAndTop(const G3D::Vector3& front)
	{
		if (primaryPart)
		{
			G3D::CoordinateFrame cf;
			cf.lookAt(front);
			modelInPrimary = G3D::CoordinateFrame(primaryPart->getCoordinateFrame().rotation.transpose() * cf.rotation, G3D::Vector3::zero());
			dirtyAll();
		}
	}

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

	static void makeJ(Instance* instance)
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

	void ModelInstance::makeJoints()
	{
		for_eachChild(makeJ);
	}

	static void breakJ(Instance* instance)
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

	void ModelInstance::breakJoints()
	{
		for_eachChild(breakJ);
	}

	float ModelInstance::computeFlagHeight() const
	{
	float height = 6.0f;

	if (primaryPart != NULL) {
		float partTop = primaryPart->getExtentsWorld().max().y;

		height = getExtentsWorld().max().y - partTop + 6.0f;
	}

	return height;
}

	PartInstance* ModelInstance::getPrimaryPartInternal() const
	{
	if (primaryPart != NULL) {
		return primaryPart;
	}

	float bestArea = -1.0f;
	PartInstance* best = NULL;

	for (unsigned int i = 0; i < numChildren(); i++) {
		const PVInstance* pv = dynamic_cast<const PVInstance*>(getChild(i));

		if (pv != NULL) {
			const Primitive* primitive = pv->getBiggestPrimitive();

			if (primitive != NULL) {
				PartInstance* part = PartInstance::fromPrimitive(const_cast<Primitive*>(primitive));

				float area = part->getExtentsWorld().areaXZ();

				if (area > bestArea) {
					bestArea = area;
					best = part;
				}
			}
		}
	}

	updatePrimaryPart(best);

	return best;
}

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

		return primitives.size() != 0 ? answer : Extents::zero();
	}

	Extents ModelInstance::computeWorldGridExtents() const
	{
		return LocalGridExtents.getValue().express(getLocation(), G3D::CoordinateFrame());
	}

	void ModelInstance::legacyTraverseState(const G3D::CoordinateFrame& parentState)
	{

		if (getChildren())
		{
			int count = (int)getChildren()->size();
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

	const G3D::CoordinateFrame ModelInstance::getLocation() const
	{
		if (getPrimaryPartConst())
		{
			G3D::CoordinateFrame cf = primaryPart->getCoordinateFrame();
			return G3D::CoordinateFrame(cf.rotation * modelInPrimary.rotation, cf.translation);
		}

		return G3D::CoordinateFrame();
	}

	bool ModelInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
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

	void ModelInstance::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		Extents localExtents = getExtentsLocal();
		G3D::CoordinateFrame location = getLocation();
		location.translation = location.pointToWorldSpace(localExtents.center());

		Part part(Part::BLOCK_PART, localExtents.size(), G3D::Color3::white(), location);
		Draw::selectionBox(part, adorn, selectState);
	}

	void ModelInstance::onCameraNear(float distance)
	{
		for (size_t i = 0; i < numChildren(); ++i)
		{
			Instance* child = getChild(i);
			ICameraSubject* cameraSubject = dynamic_cast<ICameraSubject*>(child);
			if (cameraSubject)
				cameraSubject->onCameraNear(distance);
		}
	}

	void ModelInstance::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
	{
		DragUtilities::getPrimitivesConst(this, primitives);

		Humanoid* humanoid = Humanoid::modelIsCharacter(this);
		if (humanoid)
			humanoid->getIgnorePrims(primitives);
	}
}
