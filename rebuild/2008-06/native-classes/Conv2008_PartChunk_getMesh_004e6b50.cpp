// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// ?getMesh@PartChunk@ViewNew@RBX@@UAE?AV?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@XZ (PartChunk::getMesh) converted from the exact server analog src/2008-06/004e6b50.cpp; byte-exact vs 2008.
#include "RenderLib/Material2008.h"
#include "ViewNew/RenderBaseMesh.h"
#include "ViewNew/PartChunk.h"

// DUPLICATE: PartChunk::getMesh 004e6b50 is already byte-exact in native-classes/ViewNewPartChunk.cpp (the class's own
// unit). This conversion copy is kept out of the build and reported for retirement; the Ogre include path above
// (as ViewNewPartChunk.cpp uses) fixes the C1083 OgreMaterial.h failure of RenderLib/Material2008.h.
#if defined(PARTCHUNK_CONVERSION_COPY_ENABLED)
// 004e6b50

G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> RBX::ViewNew::PartChunk::getMesh()
{
	if (mesh.isNull())
		updateMesh();

	return mesh;
}
#endif
