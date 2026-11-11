// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native CylinderTransform (inactive): bodies of the server-exact analogs 004fdbd0.
// >>> native-status (generated) -- do not edit >>>
// OgreAutoCylinderTransform | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 4cbe93b8 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#include "OgreAuto/CylinderTransform2008.h"
#include <OgreVector2.h>
#include <OgreVector3.h>
#include "G3D/Vector2.h"
#include "G3D/Vector2int16.h"
#include "G3D/Vector3.h"
#include <stddef.h>
#include <cmath>



void CylinderTransform::operator()(G3D::Vector3& vertex,G3D::Vector3& normal,G3D::Vector2& tex,const G3D::Vector3& radius,const G3D::Vector2int16& index)const{
 float angleX=vertex.x/radius.x*0.7853981852531433f;
 float angleY=float(index.y-steps+1)*1.5707963705062866f/float(steps-1);
 vertex.x=(radius.x-(1-cosf(angleY))*bevel)*sinf(angleX);
 if(index.y>=steps)vertex.y=radius.y-(1-sinf(angleY))*bevel;
 else vertex.y=(sinf(angleY)+1)*bevel-radius.y;
 vertex.z=(radius.z-(1-cosf(angleY))*bevel)*cosf(angleX);
 normal.x=cosf(angleY)*sinf(angleX);
 normal.y=sinf(angleY);
 normal.z=cosf(angleY)*cosf(angleX);
 float arc=1.5707963705062866f*bevel;float factor=arc/(radius.y+arc-bevel);
 if(index.y>=steps)tex.y*=factor;
 else tex.y=2*radius.y-(1-(tex.y-radius.y)/radius.y)*radius.y*factor;
}


