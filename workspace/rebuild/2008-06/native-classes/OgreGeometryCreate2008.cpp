// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreGeometryCreate2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src fa6bcefa | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#include <OgrePrerequisites.h>
// INFERRED: target inlines explicit math methods but imports AxisAlignedBox destructor; test historical inline policy.
#pragma push_macro("inline")
#define inline __forceinline
#include <OgreAxisAlignedBox.h>
#pragma pop_macro("inline")
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreMeshManager.h>
#include <cmath>
#include "OgreRbx/RbxSubMesh2008.h"
#include <OgreHardwareBufferManager.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>
namespace Ogre {
// INFERRED: create identity from server-exact analog 0067bcc0; real Ogre classes replace analog views.
MeshPtr GeometryBuilder::create(const char*name,const char*group,const float*vertices,unsigned vertexCount,const float*normals,const float*colours,const float*texCoords,const Vector3*minimum,const Vector3*maximum){
 boost::call_once(initializeGeometryContext,geometryOnce);
 boost::recursive_mutex::scoped_lock lock(geometryContext->mutex);
 MeshPtr mesh=MeshManager::getSingleton().createManual(name,group,0);
 update(mesh,vertices,vertexCount,normals,colours,texCoords,minimum,maximum);
 float radius;
 if(minimum&&maximum){
  mesh->_setBounds(AxisAlignedBox(minimum->x,minimum->y,minimum->z,maximum->x,maximum->y,maximum->z),true);
  // INFERRED: target evaluates subtraction z/y/x (0067be44); analog operator- stores in this order.
  Vector3 difference;
  difference.z=maximum->z-minimum->z;
  difference.y=maximum->y-minimum->y;
  difference.x=maximum->x-minimum->x;
  double r=sqrt(static_cast<double>(difference.squaredLength()));
  radius=static_cast<float>(r);
 }else{
  Vector3 low(1.0e9f,1.0e9f,1.0e9f),high(-1.0e9f,-1.0e9f,-1.0e9f);
  for(unsigned i=0;i<3*vertexCount;i+=3){
   if(low.x>vertices[i])low.x=vertices[i];if(low.y>vertices[i+1])low.y=vertices[i+1];if(low.z>vertices[i+2])low.z=vertices[i+2];
   if(high.x<vertices[i])high.x=vertices[i];if(high.y<vertices[i+1])high.y=vertices[i+1];if(high.z<vertices[i+2])high.z=vertices[i+2];
  }
  mesh->_setBounds(AxisAlignedBox(low.x,low.y,low.z,high.x,high.y,high.z),true);
  Vector3 difference;
  difference.z=high.z-low.z;
  difference.y=high.y-low.y;
  difference.x=high.x-low.x;
  radius=difference.length();
 }
 mesh->_setBoundingSphereRadius(radius*0.5f);
 mesh->load(false);
 return mesh;
}
}
