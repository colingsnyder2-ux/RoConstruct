// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_ecf56b79f3744b71.cpp

// Candidate translation unit (score above; library headers required).
#include "util/PV.h"
#include "util/Units.h"
#include "v8kernel/Constants.h"
namespace RBX {
struct UIEvent;struct HitTestFilter;struct PartInstance;
struct MouseCommand {PartInstance*getPart(const UIEvent&,const HitTestFilter*,G3D::Vector3&);};
float __cdecl ballisticAngle(float,float,float,float);
struct SlingshotTool:MouseCommand {PV launch(const UIEvent&,const G3D::CoordinateFrame&);};
PV SlingshotTool::launch(const UIEvent&event,const G3D::CoordinateFrame&frame){ float roc_dd1 = 0; float roc_dd2 = 0;
 G3D::Vector3 hit;
 PartInstance*part=getPart(event,0,hit);
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
}
