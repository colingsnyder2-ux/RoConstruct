// >>> native-status (generated) -- do not edit >>>
// MegaDragger | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
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
