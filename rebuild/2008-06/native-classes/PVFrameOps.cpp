#pragma float_control(precise, off)
#include "PVFrameOps.h"

// 00598a60 ?velocityAtPoint@PV@RBX@@QBE?AVVelocity@2@ABVVector3@G3D@@@Z: core util/PV.h defines PV::velocityAtPoint
// inline in the class, so a second body here was C2084. The compiler keeps the call below out of line and emits the
// header body as a COMDAT, which is byte-exact against 00598a60 (005991c0 calls it), so no body is written here.

// 005991c0: recoveredFrameMultiply 005989d0 then PV::velocityAtPoint 00598a60 (both calls).

void RBX::recoveredPVLocalFrame(const PV& source, const G3D::CoordinateFrame& local, PV& result)
{
    recoveredFrameMultiply(source.position, local, result.position);
    result.velocity = source.velocityAtPoint(result.position.translation);
}
