// from server: 41% by TrollStein
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/ModelInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/ModelInstance.h"

#include "humanoid/Humanoid.h"
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

char sModel[] = "Model";

bool ModelInstance::showModelCoord;

bool ModelInstance::askSetParent(const Instance* instance) const
{
	STUB(0x10059c10);
	return false;
}

// FUNCTION: WEBSERVICE 0x10059c40
float ModelInstance::computeFlagHeight() const
{
	float height = 6.0f;

	if (primaryPart != NULL) {
		float partTop = primaryPart->getExtentsWorld().max().y;

		height = getExtentsWorld().max().y - partTop + 6.0f;
	}

	return height;
}

// FUNCTION: WEBSERVICE 0x1005a1a0
void ModelInstance::onExtentsChanged() const
{
	LocalGridExtents.setDirty();
	WorldGridExtents.setDirty();
	FlagHeight.setDirty();

	PVInstance::onExtentsChanged();
}

// FUNCTION: WEBSERVICE 0x1005a1c0
const Primitive* ModelInstance::getBiggestPrimitive() const
{
	const PartInstance* part = getPrimaryPartConst();

	if (part != NULL) {
		return part->getPrimitive();
	}

	return NULL;
}

// STUB: WEBSERVICE 0x1005a1f0
void ModelInstance::updatePrimaryPart(PartInstance* part) const
{
	if (primaryPart == part) {
		return;
	}

	if (part != NULL && primaryPart != NULL) {
		Matrix3 rotation = getLocation().rotation;

		modelInPrimary =
			CoordinateFrame(primaryPart->getCoordinateFrame().rotation.transpose() * rotation, Vector3::zero());
	}
	else {
		modelInPrimary = CoordinateFrame();
	}

	primaryPart = part;
}

// FUNCTION: WEBSERVICE 0x1005a350
Extents ModelInstance::computeWorldGridExtents() const
{
	return LocalGridExtents.getValue().express(getLocation(), CoordinateFrame());
}

// STUB: WEBSERVICE 0x1005a3b0
const CoordinateFrame ModelInstance::getLocation() const
{
	STUB(0x1005a3b0);
	return CoordinateFrame();
}

// STUB: WEBSERVICE 0x1005a460
void ModelInstance::render3dSelect(Adorn* adorn, SelectState selectState)
{
	STUB(0x1005a460);
}

// STUB: WEBSERVICE 0x1005a890
ModelInstance::~ModelInstance()
{
}

// STUB: WEBSERVICE 0x1005ab00
Extents ModelInstance::getExtentsWorld() const
{
	return WorldGridExtents.getValue();
}

// STUB: WEBSERVICE 0x1005ab50
Extents ModelInstance::getExtentsLocal() const
{
	return LocalGridExtents.getValue();
}

// FUNCTION: WEBSERVICE 0x1005abb0
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

// FUNCTION: WEBSERVICE 0x1005ac90
void ModelInstance::legacyTraverseState(const CoordinateFrame& parentState)
{
	int count = numChildren();

	if (count > 0) {
		CoordinateFrame state = parentState * *legacyOffset;

		for (int i = 0; i < count; i++) {
			PVInstance* pv = dynamic_cast<PVInstance*>(getChild(i));

			if (pv != NULL) {
				pv->legacyTraverseState(state);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x1005ad40
bool ModelInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
{
	for (unsigned int i = 0; i < numChildren(); i++) {
		PVInstance* pv = dynamic_cast<PVInstance*>(getChild(i));

		if (pv != NULL && pv->hitTest(worldRay, worldHitPoint)) {
			return true;
		}
	}

	return false;
}

// STUB: WEBSERVICE 0x1005add0
bool ModelInstance::shouldRender3dAdorn() const
{
	const PVInstance* pv = dynamic_cast<const PVInstance*>(getParent());

	if (pv == NULL || getTypedRoot<PVInstance>() == getParent()) {
		return showModelCoord;
	}

	return false;
}

// STUB: WEBSERVICE 0x1005ae20
void ModelInstance::render3dAdorn(Adorn* adorn)
{
	if (ModelInstance::shouldRender3dAdorn()) {
		renderCoordinateFrame(adorn);
	}
}

// FUNCTION: WEBSERVICE 0x1005ae80
void ModelInstance::onCameraNear(float distance)
{
	for (unsigned int i = 0; i < numChildren(); i++) {
		ICameraSubject* subject = dynamic_cast<ICameraSubject*>(getChild(i));

		if (subject != NULL) {
			subject->onCameraNear(distance);
		}
	}
}

// FUNCTION: WEBSERVICE 0x1005b220
PartInstance* ModelInstance::getPrimaryPart()
{
	return getPrimaryPartInternal();
}

const PartInstance* ModelInstance::getPrimaryPartConst() const
{
	STUB(0x1005b221);
	return NULL;
}

// FUNCTION: WEBSERVICE 0x1005b230
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

// FUNCTION: WEBSERVICE 0x1005b2c0
void ModelInstance::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	if (primaryPart == instance.get()) {
		primaryPart = NULL;
	}

	if (candidatePrimaryPart.get() == instance.get()) {
		candidatePrimaryPart.reset();
	}

	LocalGridExtents.setDirty();
	WorldGridExtents.setDirty();
	FlagHeight.setDirty();

	shouldRenderSetDirty();

	PVInstance::onDescendentRemoving(instance);
}

// STUB: WEBSERVICE 0x1005b440
void ModelInstance::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
{
	STUB(0x1005b440);
}

// STUB: WEBSERVICE 0x1005b560
Extents ModelInstance::computeLocalGridExtents() const
{
	STUB(0x1005b560);
	return Extents();
}

// STUB: WEBSERVICE 0x1005c000
ModelInstance::ModelInstance()
	: PVInstance(sModel), primaryPart(NULL), FlagHeight(this, &ModelInstance::computeFlagHeight),
	  LocalGridExtents(this, &ModelInstance::computeLocalGridExtents),
	  WorldGridExtents(this, &ModelInstance::computeWorldGridExtents)
{
	STUB(0x1005c000);
}

void ModelInstance::onLastChildRemoved()
{
	STUB(0x1015b611);
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sPart>();
template const RBX::Name& RBX::Name::doDeclare<RBX::sHumanoid>();
template void RBX::Name::callDoDeclare<RBX::sPart>();
template void RBX::Name::callDoDeclare<RBX::sHumanoid>();
