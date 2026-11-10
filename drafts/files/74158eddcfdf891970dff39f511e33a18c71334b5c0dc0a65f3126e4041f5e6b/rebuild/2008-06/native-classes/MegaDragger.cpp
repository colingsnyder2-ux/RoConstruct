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
