// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreGeometryIndexed2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d4546f20 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#include <OgrePrerequisites.h>
#include <OgreVector3.h>
// INFERRED: 0067c130 inlines box construction but imports Vector3::length (unlike 0067bcc0).
#pragma push_macro("inline")
#define inline __forceinline
#include <OgreAxisAlignedBox.h>
#pragma pop_macro("inline")
#include "OgreRbx/GeometryCreate2008.h"
#include "OgreRbx/RbxSubMesh2008.h"
#include <OgreHardwareBufferManager.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace Ogre {
// INFERRED: method/signature from 0067c130 analog; fields from original allocation and stores.
RbxSubMesh* GeometryBuilder::createIndexed(const float*vertices,unsigned vertexCount,const float*normals,const float*colours,const float*texCoords,const unsigned short*indices16,const unsigned*indices32,unsigned triangleCount,Vector3*minimum,Vector3*maximum){
 boost::call_once(initializeGeometryContext,geometryOnce);
 GeometryContext*context=geometryContext;
 boost::recursive_mutex::scoped_lock lock(context->mutex);
 RbxSubMesh*result=new RbxSubMesh;
 result->parent=0;
 result->vertexData=createVertexData(vertices,vertexCount,normals,colours,texCoords);
 result->useSharedVertices=false;
 unsigned indexCount=3*triangleCount;
 HardwareIndexBufferSharedPtr buffer=HardwareBufferManager::getSingleton().createIndexBuffer(indices16?HardwareIndexBuffer::IT_16BIT:HardwareIndexBuffer::IT_32BIT,indexCount,HardwareBuffer::HBU_STATIC_WRITE_ONLY,false);
 buffer->writeData(0,buffer->getSizeInBytes(),indices16?static_cast<const void*>(indices16):indices32,true);
 result->indexData->indexBuffer=buffer;
 result->indexData->indexCount=indexCount;
 result->indexData->indexStart=0;
 {
  Vector3 low(1.0e9f,1.0e9f,1.0e9f),high(-1.0e9f,-1.0e9f,-1.0e9f);
  for(unsigned i=0;i<3*vertexCount;i+=3){
   if(low.x>vertices[i])low.x=vertices[i];if(low.y>vertices[i+1])low.y=vertices[i+1];if(low.z>vertices[i+2])low.z=vertices[i+2];
   if(high.x<vertices[i])high.x=vertices[i];if(high.y<vertices[i+1])high.y=vertices[i+1];if(high.z<vertices[i+2])high.z=vertices[i+2];
  }
  *minimum=low;*maximum=high;
  AxisAlignedBox bounds(low.x,low.y,low.z,high.x,high.y,high.z);
  result->bounds=bounds;
  result->radius=bounds.getHalfSize().length();
 }
 std::string name="sms"+StringConverter::toString(context->counter++);
 context->names[result]=name;
 LogManager::getSingleton().logMessage("RBX cr "+name,LML_NORMAL,false);
 return result;
}
}
