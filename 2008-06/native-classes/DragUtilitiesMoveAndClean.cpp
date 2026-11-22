// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// DragUtilities::moveAndClean (2008-06), between MegaDragger::finishDragging 0060e780 and DragUtilities::pvsToParts
// 0060e920. Identity: work/2008-06/identity-registry.json ?moveAndClean@DragUtilities@RBX@@SAXPAVPartInstance@2@ABVVector3@G3D@@@Z;
// the only caller is Dragger::movePrimitives 0060fef0 (via PartInstance::fromPrimitive 00599f80). The inactive
// lifetime trial (work/2008-06/shared-layouts/axis-move-tool-lifetime-trial.json) recorded this body exact as movePart.
// Callees: PartInstance::getCoordinateFrame 00598cb0, CoordinateFrame copy 00513220, PartInstance::aligned 005994c0,
// Math::snapToGrid(CoordinateFrame, float) 005deed0 with 0.1f (0081e704), PartInstance::setCoordinateFrame 0059d8a0.
#include "tool/DragUtilities.h"
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"

namespace RBX
{
	// 0060e840
	void DragUtilities::moveAndClean(PartInstance* part, const G3D::Vector3& pos)
	{
		G3D::CoordinateFrame frame = part->getCoordinateFrame();
		frame.translation += pos;
		if (part->aligned())
		{
			frame = Math::snapToGrid(frame, 0.1f);
		}
		part->setCoordinateFrame(frame);
	}
}
