// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_3ec6397cb9dfa2ae.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8datamodel/MouseCommand.h", "roc_unit_9958a7131e20354c.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "roc_unit_ea83e629b1338927.cpp")
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "roc_unit_a21bf1eef16ceba3.cpp"
#include "v8datamodel/Selection.h"
namespace RBX {
class HandleHitTest { public: static bool hitTestHandleLocal(const Extents&,const G3D::CoordinateFrame&,const G3D::Ray&,G3D::Vector3&,NormalId&); };
std::vector<boost::shared_ptr<Instance> >::const_iterator Selection::begin() const { return selection->begin(); }
std::vector<boost::shared_ptr<Instance> >::const_iterator Selection::end() const { return selection->end(); }
void ResizeTool::findTargetPV(const UIEvent& inputObject)
{
	ServiceClient< Selection > selection(reinterpret_cast<Instance*>(this->workspace));

	Instances::const_iterator it;

	for (it = selection->begin(); it != selection->end(); ++it) {
		if (PartInstance* part = dynamic_cast<PartInstance*>(it->get())) {

			G3D::Ray gridRay(getUnitMouseRay(inputObject));
			if (HandleHitTest::hitTestHandleLocal(	part->getExtentsLocal(),
													part->getLocation(),
													gridRay, 
													hitPointGrid, 
													localNormalId))
			{
				targetPV = shared_from(part);
				return;
			}
		}
	}
	targetPV.reset();
}
}
