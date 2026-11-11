// >>> native-status (generated) -- do not edit >>>
// MegaDragger | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 6dd2f4e1 | roc native-status --write
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/MouseCommand.h"

namespace RBX {
bool MegaDragger::mousePartAlive()
	{
		return PartInstance::nonNullInWorkspace(mousePart.lock());
	}
}
