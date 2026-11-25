// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll util/PV.cpp

// Candidate translation unit (score above; library headers required).
#include "util/PV.h"

// PV members became inline in util/PV.h upstream (RBXGSdecomp 6fcc4b0); anchor their bodies here so the
// 2008-06 analogs (velocityAtPoint, pvAtLocalOffset, PV ctor) still have an out-of-line copy.
namespace RBX
{
	typedef Velocity (PV::*VelocityAtPoint)(const G3D::Vector3&) const;
	typedef PV (PV::*PvAtLocalOffset)(const G3D::Vector3&) const;
	typedef PV (PV::*PvAtLocalCoord)(const G3D::CoordinateFrame&) const;
	VelocityAtPoint keepVelocityAtPoint = &PV::velocityAtPoint;
	PvAtLocalOffset keepPvAtLocalOffset = &PV::pvAtLocalOffset;
	PvAtLocalCoord keepPvAtLocalCoord = &PV::pvAtLocalCoord;
	PV* keepPvCtor(void* where, const G3D::CoordinateFrame& cf, const Velocity& v) { return new (where) PV(cf, v); }
}
