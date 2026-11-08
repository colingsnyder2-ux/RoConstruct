#pragma once
// >>> native-status (generated) -- do not edit >>>
// HumanoidFloorFields | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src bd1a681b | roc native-status --write
#include <boost/shared_ptr.hpp>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>

namespace RBX {
class PartInstance;
namespace HUMAN {
// Inactive relative layout of HumanoidState +0x20 through +0x9f.
// PartInstance identity and float semantics need independent native proof.
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
