// =============================================================================
// HumanoidFloorFields.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/humanoid/HumanoidFloorFields.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <boost/shared_ptr.hpp>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>

namespace RBX
{
class PartInstance;
namespace HUMAN
{
struct HumanoidFloorFields {
    bool active;
    boost::shared_ptr<PartInstance> floorPart;
    G3D::Vector3 floorTouchInWorld;
    float value38;
    float value3c;
    G3D::CoordinateFrame previous;
    G3D::CoordinateFrame current;
};
}
}
