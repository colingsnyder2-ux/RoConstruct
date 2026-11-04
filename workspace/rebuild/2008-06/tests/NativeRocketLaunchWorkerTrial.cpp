#include "NativeRocketWorkerTrial.h"
#pragma float_control(precise,off)
namespace RBX {
PV RocketTool::launch(const UIEvent& event,const G3D::CoordinateFrame& frame) {
 G3D::Vector3 hit;
 G3D::Vector3 forward=getPart(event,0,hit)?(hit-frame.translation).direction():frame.lookVector();
 G3D::CoordinateFrame result; result.lookAt(forward); G3D::Vector3 position; position=forward; position*=5.0f; position+=frame.translation; result.translation=position;
 return PV(result,Velocity::zero());
}
}
