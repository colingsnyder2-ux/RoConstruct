// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 RBX::JointInstance IRenderable rows of the v8datamodel/JointInstance.cpp unit (inactive), built against the
// committed native v8datamodel/JointInstance.h (read-only; the getset factories of the same unit are in
// AppUnit5E0JointReflection.cpp): shouldRender3dAdorn 005e27a0.
//
// Not built here (see the header proposal in the batch result): render3dAdorn 005e2af0 and askSetParent 005e3790.
// The 2008 JointInstance is the donor JointInstance + AutoJoint merged into one class: askSetParent is decorated
// ?askSetParent@JointInstance@RBX@@MBE_NPBVInstance@2@@Z, render3dAdorn calls the out-of-line part getters 005e2a10 /
// 005e2a70 on JointInstance (boost::weak_ptr<PartInstance> at +0x140 / +0x148, lock 005cab00) and reads joint at
// +0x150 (IRenderable +0x130, IJointOwner +0x140, JointsService::onEvent 005e5500). native JointInstance.h declares
// askSetParent / the parts on AutoJoint and places joint directly after the bases, so neither body can be expressed
// against it.
#include "v8datamodel/JointInstance.h"

namespace RBX
{
	// 005e27a0: reads PartInstance::showSpanningTree (00975f8f).
	bool JointInstance::shouldRender3dAdorn() const
	{
		return PartInstance::showSpanningTree;
	}
}
