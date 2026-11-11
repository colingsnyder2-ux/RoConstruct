// Internal descriptive helper names; original symbol names are unknown.
// ABI evidence: complete005991c0, accepted005989d0, and verified SDK00598a60.
#pragma once
// >>> native-status (generated) -- do not edit >>>
// PVFrameOps | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8a4c075c | roc native-status --write
#include "util/PV.h"
namespace RBX {
void recoveredFrameMultiply(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&, G3D::CoordinateFrame&);
void recoveredPVLocalFrame(const PV&, const G3D::CoordinateFrame&, PV&);
}
