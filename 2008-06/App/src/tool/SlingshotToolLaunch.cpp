// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// SlingshotToolLaunch | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 64790694 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
#include "util/Units.h"
#include "v8kernel/Constants.h"
#include <math.h>
namespace RBX {
float __cdecl ballisticAngle(float,float,float,float);
PV SlingshotTool::launch(const UIEvent& event,const G3D::CoordinateFrame& frame) {
 float unused1=0,unused2=0;
 G3D::Vector3 hit;
 PartInstance* part=getPart(event,0,hit);
 G3D::Vector3 direction=part?(hit-frame.translation).direction():frame.lookVector();
 G3D::Vector3 position=frame.translation+direction*3.0f;
 if(!part){
  G3D::CoordinateFrame launchFrame(position);
  return PV(launchFrame,Velocity(direction*85.0f,G3D::Vector3::zero()));
 } else {
  G3D::Vector3 delta=hit;delta-=position;
  float height=delta.y;delta.y=0;
  float distance=delta.unitize(0.000001f);
  float angle=ballisticAngle(85.0f,distance,height,Units::kmsAccelerationToRbx(Constants::getKmsGravity()).y);
  delta.y=sinf(angle);
  float c=cosf(angle);
  delta.x*=c;delta.z*=c;
  G3D::CoordinateFrame launchFrame(position);
  return PV(launchFrame,Velocity(delta*85.0f,G3D::Vector3::zero()));
 }
}
int SlingshotTool::getShootSound() { return 6; }
}
