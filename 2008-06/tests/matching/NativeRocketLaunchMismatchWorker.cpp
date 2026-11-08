#include "NativeRocketWorkerTrial.h"
#pragma float_control(precise,off)
namespace RBX {
PV RocketTool::launch(const UIEvent& event,const G3D::CoordinateFrame& frame) {
 G3D::Vector3 hit;
 G3D::Vector3 forward=getPart(event,0,hit)?(hit-frame.translation).direction():frame.lookVector();
 G3D::CoordinateFrame result; result.lookAt(forward); result.translation=forward*5.0f+frame.translation;
 return PV(result,Velocity::zero());
}
}
