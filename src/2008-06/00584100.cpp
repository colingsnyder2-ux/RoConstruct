// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_07090bbce10d86b5.cpp

// Candidate translation unit (score above; library headers required).
#ifndef V8DATAMODEL_MODELINSTANCE_H
#define V8DATAMODEL_MODELINSTANCE_H

#include "decomp.h"
#include "util/ComputeProp.h"
#include "util/Extents.h"
#include "util/ICameraSubject.h"
#include "util/IRenderable.h"
#include "util/ISelectable3d.h"
#include "v8datamodel/IPrimaryPart.h"
#include "v8datamodel/PVInstance.h"

#include <G3D/CoordinateFrame.h>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace RBX {

class PartInstance;

extern char sModel[];

// SIZE 0x254
class ModelInstance : public PVInstance,
					  public IRenderable,
					  public virtual IPrimaryPart,
					  public virtual ICameraSubject,
					  public virtual ISelectable3d
{
public:
	static bool showModelCoord;

private:
	mutable CoordinateFrame modelInPrimary;               // 0x178
	mutable PartInstance* primaryPart;                    // 0x1a8
	boost::shared_ptr<PartInstance> candidatePrimaryPart; // 0x1ac

	void updatePrimaryPart(PartInstance* part) const;

	// Binary has a native vector at +0x1ec, before the remaining cached properties.
	std::vector<void*> cachedItems;
	ComputeProp<float, ModelInstance> FlagHeight;         // 0x1b8
	ComputeProp<Extents, ModelInstance> LocalGridExtents; // 0x1d8
	ComputeProp<Extents, ModelInstance> WorldGridExtents; // 0x208

	float computeFlagHeight() const;
	Extents computeLocalGridExtents() const;
	Extents computeWorldGridExtents() const;
	void dirtyAll() const;

	virtual bool shouldRender3dAdorn() const;
	virtual void render3dAdorn(Adorn* adorn);
	virtual void render3dSelect(Adorn* adorn, SelectState selectState);

protected:
	virtual void onDescendentAdded(Instance* instance);
	virtual void onDescendentRemoving(const shared_ptr<Instance>& instance);
	virtual bool askSetParent(const Instance* instance) const;

private:
	virtual void onLastChildRemoved();

public:
	ModelInstance();
	virtual ~ModelInstance();

	PartInstance* getPrimaryPartInternal() const;
	void setPrimaryPart(PartInstance* value);

	const CoordinateFrame& getModelInPrimary() const;
	void setModelInPrimary(const CoordinateFrame& value);

	virtual void onExtentsChanged() const;

	virtual const Primitive* getBiggestPrimitive() const;
	virtual bool hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint);

	virtual Extents getExtentsWorld() const;
	virtual Extents getExtentsLocal() const;

	virtual const CoordinateFrame getLocation() const;

	virtual void onCameraNear(float distance);
	virtual void getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives);

	virtual PartInstance* getPrimaryPart();
	virtual const PartInstance* getPrimaryPartConst() const;

protected:
	virtual void legacyTraverseState(const CoordinateFrame& parentState);

public:
};

DECOMP_SIZE_ASSERT(ModelInstance, 0x254)

} // namespace RBX

#endif // V8DATAMODEL_MODELINSTANCE_H


#include "v8datamodel/PartInstance.h"
namespace RBX {
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


}
namespace RBX {
inline float Extents::areaXZ() const
{
	G3D::Vector3 delta = this->high - this->low;
	return delta.x * delta.z;
}
}
