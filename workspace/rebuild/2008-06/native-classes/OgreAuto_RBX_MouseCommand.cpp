// native-flags: /O2 /GS- /EHsc /MD /fp:fast /D_AFXDLL /GS-
#include "../native-headers/v8datamodel/MouseCommand.h"
#include "../../../tools/rbxgs/Client/Rendering/g3d/include/G3D/Ray.h"
#include "../native-headers/v8datamodel/PartInstance.h"

namespace RBX {
RBX::Surface* MouseCommand::getSurface(const RBX::UIEvent& uiEvent, RBX::PartInstance*& part, int& surfaceId)
{
	part = getPart(uiEvent, 0);
	if (part) {
		G3D::Ray ray = getUnitMouseRay(uiEvent);
		RBX::Surface* surface = part->getSurface(ray, surfaceId);
		if (surface)
			return surface;
	}
	return 0;
}
}
