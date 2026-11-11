// from server: 99% by EspClaude
// from server: 97% by EspClaude
// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /QIfist
// roc-lib: rbxgs-dll roc_claude_7a3d4fc1a38fdc06.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/g3dmath.h>
#pragma include_alias("v8tree/Instance.h", "roc_espeon_nativeinstanceguidportablea1682bda32c99cd2.cpp")
#include "util/NormalId.h"
#include "util/ICameraSubject.h"
#include "v8datamodel/IPrimaryPart.h"
#include "util/Math.h"
#include <boost/weak_ptr.hpp>
#include <cmath>
namespace RBX {
// 2007-08 0x5fcaf3: the part's vbptr sits at +0xec (2008 header: +0x134); ILocation is vbtable entry +8.
struct PartInstanceNonVirtual2007 { char data[0xec]; };
class PartInstance : public PartInstanceNonVirtual2007, public virtual IPrimaryPart, public virtual ICameraSubject {};
static inline G3D::Vector3 directNormal(NormalId id,const G3D::CoordinateFrame&f){const G3D::Matrix3&m=f.rotation;int c=id%3;int s=1-(id/3)*2;return s*G3D::Vector3(m[0][c],m[1][c],m[2][c]);}
// Offsets proven in 0063ee20: weak20, face2c, origin30, accumulated40.
// 00518830 is verified G3D Ray::fromOriginAndDirection, cdecl value return.
G3D::Ray makeResizeAxis(const G3D::Vector3&,const G3D::Vector3&);
class ResizeToolRecovery {
 char prefix[0x24]; boost::weak_ptr<PartInstance> part;
 int reserved28; int face; G3D::Vector3 start; int reserved3c; int accumulated;
 G3D::Ray getUnitMouseRay(const void*) const;
 void capturedDrag(int);
public: void drag(const void*);
};
void ResizeToolRecovery::drag(const void* event){
 if(part.expired()) return;
 G3D::Vector3 direction=directNormal((NormalId)face,part.lock()->getLocation());
 G3D::Ray axis=makeResizeAxis(start,direction);
 G3D::Ray mouse=getUnitMouseRay(event);
 G3D::Vector3 hit=Math::closestPointOnRay(axis,mouse);
 float dot=(hit-start).dot(axis.direction);float delta=dot-accumulated;
 if(delta>1.0f){int steps=G3D::iRound((float)std::floor(delta));accumulated+=steps;capturedDrag(steps);}
 if(delta<-1.0f){int steps=-G3D::iRound((float)std::floor(-delta));accumulated+=steps;capturedDrag(steps);}
}
}
