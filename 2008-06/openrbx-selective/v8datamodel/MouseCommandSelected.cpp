#include "v8datamodel/MouseCommand.h"

#include "humanoid/Humanoid.h"
#include "util/ContentProvider.h"
#include "util/ISelectable3d.h"
#include "util/UIEvent.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Filters.h"
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/SpatialHash.h"
#include "v8world/World.h"
// PORT: 2008 World only forward-declares ContactManager.
#include "v8world/ContactManager.h"

#include <G3D/GCamera.h>
#include <G3D/Rect2D.h>

namespace RBX {

// PORT: selective unit; remaining functions use the 2008 object.

void MouseCommand::capture()
{
	capturedMouse = true;
}

} // namespace RBX
