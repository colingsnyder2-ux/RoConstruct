// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /GS- /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\App\v8datamodel
#include "../native-headers/v8datamodel/Camera.h"
#include "../native-headers/v8datamodel/Workspace.h"
#include "../native-headers/v8datamodel/ICharacterSubject.h"

namespace RBX {
ICameraOwner* Camera::getCameraOwner()
	{
		for (Instance* instance = getParent(); instance != NULL; instance = instance->getParent())
		{
			ICameraOwner* cameraOwner = dynamic_cast<ICameraOwner*>(instance);
			if (cameraOwner)
				return cameraOwner;
		}

		return NULL;
	}

bool Camera::zoomExtents(const G3D::Rect2D& viewPort)
	{
		if (ICameraOwner* owner = getCameraOwner())
		{
			zoomExtents(owner->computeCameraOwnerExtents(), viewPort, ZOOM_IN_OR_OUT);
			return true;
		}
		return false;
	}
}
