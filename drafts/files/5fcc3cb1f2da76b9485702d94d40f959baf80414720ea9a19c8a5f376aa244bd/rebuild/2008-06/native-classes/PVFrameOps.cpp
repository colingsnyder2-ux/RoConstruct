#pragma float_control(precise, off)
#include "PVFrameOps.h"

// 00598a60 ?velocityAtPoint@PV@RBX@@QBE?AVVelocity@2@ABVVector3@G3D@@@Z is out of line in the client (005991c0 calls it),
// but core util/PV.h defines PV::velocityAtPoint inline in the class, so a second body here is C2084.
// GUARDED: remaining blocker is the core header; proposal: util/PV.h declares
// `Velocity velocityAtPoint(const G3D::Vector3& worldPos) const;` and this unit keeps the body below.
#if defined(PV_HEADER_DECLARES_VELOCITYATPOINT_OUT_OF_LINE)
// 00598a60
RBX::Velocity RBX::PV::velocityAtPoint(const G3D::Vector3& worldPos) const
	{
		G3D::Vector3 v1 = worldPos - this->position.translation;
		G3D::Vector3 v2 = this->velocity.rotational.cross(v1);
		return Velocity(this->velocity.linear + v2, this->velocity.rotational);
	}
#endif

// 005991c0: recoveredFrameMultiply 005989d0 then PV::velocityAtPoint 00598a60 (both calls).

void RBX::recoveredPVLocalFrame(const PV& source, const G3D::CoordinateFrame& local, PV& result)
{
    recoveredFrameMultiply(source.position, local, result.position);
    result.velocity = source.velocityAtPoint(result.position.translation);
}
