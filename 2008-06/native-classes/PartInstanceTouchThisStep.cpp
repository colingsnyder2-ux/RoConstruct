// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// RBX::PartInstance::onTouchThisStep (placeholder func_0059d7f0, 171 B) of the PartInstance unit 00598000..005a0000.
// Identity: the only caller is Workspace::step 005a2580 (005a26a2), which walks the touch / touch-other part Arrays
// and passes touchOtherParts[i] by value to touchParts[i]; the body fires PartInstance::event_Touched (00976164)
// through SignalDesc fire 0049d200 on the SignalSource subobject (+0x14) with the part converted to
// shared_ptr<Instance>. Statement shape from the 2007 analog (tools/openrbx v8datamodel/PartInstance.cpp).
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0059d7f0
	void PartInstance::onTouchThisStep(boost::shared_ptr<PartInstance> other)
	{
		event_Touched.fire(this, other);
	}
}
