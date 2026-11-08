// Internal descriptive helper names; original symbol names are unknown.
// ABI evidence: complete005991c0, accepted005989d0, and verified SDK00598a60.
#pragma once
#include "util/PV.h"
namespace RBX {
void recoveredFrameMultiply(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&, G3D::CoordinateFrame&);
void recoveredPVLocalFrame(const PV&, const G3D::CoordinateFrame&, PV&);
}
