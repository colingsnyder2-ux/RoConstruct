// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Authentic Mesh declarations and donor access/lifetime methods, checked against 2008 originals.
#include "ViewNew/RenderBaseMesh.h"
namespace RBX { namespace RenderBase {
Mesh::ShadowSurface::ShadowSurface() {}
Mesh::ShadowSurface::~ShadowSurface() {}
const G3D::ReferenceCountedPointer<Mesh::Level> Mesh::detailLevel(float detail) const
{
	int index = detailIndex(detail);
	return levels[index].getPointer();
}
} }
