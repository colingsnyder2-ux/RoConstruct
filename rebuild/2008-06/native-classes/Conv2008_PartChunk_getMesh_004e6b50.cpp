// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// ?getMesh@PartChunk@ViewNew@RBX@@UAE?AV?$ReferenceCountedPointer@VMesh@RenderBase@RBX@@@G3D@@XZ (PartChunk::getMesh) converted from the exact server analog src/2008-06/004e6b50.cpp; byte-exact vs 2008.
#include "RenderLib/Material2008.h"
#include "ViewNew/RenderBaseMesh.h"
#include "ViewNew/PartChunk.h"

G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> RBX::ViewNew::PartChunk::getMesh()
{
	if (mesh.isNull())
		updateMesh();

	return mesh;
}
