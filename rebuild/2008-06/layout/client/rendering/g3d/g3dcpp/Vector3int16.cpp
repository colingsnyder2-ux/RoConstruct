// =============================================================================
// Vector3int16.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/g3dcpp/Vector3int16.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\G3Dcpp\\Vector3int16.cpp"
/**
 @file Vector3int16.cpp

 @author Morgan McGuire, matrix@graphics3d.com

 @created 2003-04-07
 @edited  2006-01-17
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3int16.h"
#include "G3D/Vector3.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D
{

Vector3int16::Vector3int16(const class Vector3& v) {
    x = (int16)iFloor(v.x + 0.5);
    y = (int16)iFloor(v.y + 0.5);
    z = (int16)iFloor(v.z + 0.5);
}

Vector3int16::Vector3int16(class BinaryInput& bi) {
    deserialize(bi);
}

void Vector3int16::serialize(class BinaryOutput& bo) const {
    bo.writeInt16(x);
    bo.writeInt16(y);
    bo.writeInt16(z);
}

void Vector3int16::deserialize(class BinaryInput& bi) {
    x = bi.readInt16();
    y = bi.readInt16();
    z = bi.readInt16();
}

}
