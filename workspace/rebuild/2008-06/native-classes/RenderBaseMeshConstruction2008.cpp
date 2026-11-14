// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Donor constructor plus original Ogre fields, matched against 00548570.
#include "ViewNew/RenderBaseMesh.h"
namespace RBX { namespace RenderBase {
static bool init; // Original 00973980; donor file-static flag.
Mesh::Mesh()
{
	if (!init) {
		initStatics();
		init = true;
	}
	debugBoundingRadius = 0.0f;
	subMesh = NULL;
	meshKind = 0;
}
} }
