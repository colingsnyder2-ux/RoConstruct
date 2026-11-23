// =============================================================================
// Color3uint8.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/g3dcpp/Color3uint8.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\G3Dcpp\\Color3uint8.cpp"
/**
 @file Color3uint8.cpp

 @author Morgan McGuire, matrix@graphics3d.com

 @created 2003-04-07
 @edited  2006-01-07
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Color3uint8.h"
#include "G3D/Color3.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D
{

Color3uint8::Color3uint8(const class Color3& c) {
    r = iMin(255, iRound(c.r * 256));
    g = iMin(255, iRound(c.g * 256));
    b = iMin(255, iRound(c.b * 256));
}

Color3uint8::Color3uint8(class BinaryInput& bi) {
    deserialize(bi);
}

void Color3uint8::serialize(class BinaryOutput& bo) const {
    bo.writeUInt8(r);
    bo.writeUInt8(g);
    bo.writeUInt8(b);
}

void Color3uint8::deserialize(class BinaryInput& bi) {
    r = bi.readUInt8();
    g = bi.readUInt8();
    b = bi.readUInt8();
}

}
