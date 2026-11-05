// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_73850220e0cd261c.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/KernelIndex.h"
#define SimBody SimBodyHeader
#include "v8kernel/SimBody.h"
#undef SimBody
namespace RBX {
class SimBody
{
public:
	Body* body;
	int exePad;
	bool dirty;
	void makeDirty() { dirty = true; }
	const G3D::Vector3& getForce() const;
	const G3D::Vector3& getTorque() const;
	void accumulateForceCofm(const G3D::Vector3&);
	void accumulateForce(const G3D::Vector3&, const G3D::Vector3&);
	void accumulateTorque(const G3D::Vector3&);
	void resetAccumulators();
};
struct ExeKernelIndex : KernelIndex { int exePad[3]; };
}
#define KernelIndex ExeKernelIndex
#include "v8kernel/Body.h"
#undef KernelIndex
#include "decomp.h"
#include "util/Math.h"
#include "v8kernel/Link.h"
#include "v8kernel/SimBody.h"
#include <cstddef>
namespace RBX {
void Body::makeCofmDirty()
{
	if (cofm == NULL || !cofm->getIsDirty()) {
		if (parent != NULL) {
			parent->makeCofmDirty();
		}
		else {
			if (simBody != NULL) {
				simBody->makeDirty();
			}
		}
		if (cofm != NULL) {
			cofm->makeDirty();
		}
	}
}
void Body::onChildAdded(Body* child)
{
	makeCofmDirty();
	children.fastAppend(child);
	if (cofm == NULL) {
		cofm = new Cofm(this);
	}
}
}
