// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreSubMesh.h>
#include <OgreHardwareBufferManager.h>
namespace Ogre {
// INFERRED: helper name and pointer types from original 0067c020 and indexed geometry donor.
SubMesh* __stdcall createIndices(const MeshPtr& mesh, const unsigned short* indices16, const unsigned* indices32, unsigned triangles) {
 boost::call_once(initializeGeometryContext, geometryOnce);
 boost::recursive_mutex::scoped_lock lock(geometryContext->mutex);
 SubMesh* submesh = mesh->createSubMesh();
 size_t count = triangles * 3;
 HardwareIndexBufferSharedPtr buffer = HardwareBufferManager::getSingleton().createIndexBuffer(indices16 ? HardwareIndexBuffer::IT_16BIT : HardwareIndexBuffer::IT_32BIT, count, HardwareBuffer::HBU_STATIC_WRITE_ONLY);
 buffer->writeData(0, buffer->getSizeInBytes(), indices16 ? static_cast<const void*>(indices16) : static_cast<const void*>(indices32), true);
 submesh->useSharedVertices = true;
 submesh->indexData->indexBuffer = buffer;
 submesh->indexData->indexCount = count;
 submesh->indexData->indexStart = 0;
 return submesh;
}
}
