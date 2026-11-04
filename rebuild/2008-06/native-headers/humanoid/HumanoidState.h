#pragma once
#include "util/Name.h"
#include "util/HitTestFilter.h"

namespace RBX {
class Humanoid;
namespace HUMAN {
// Incomplete native prefix only: constructor 00643e00 and RTTI establish bases
// and these initial offsets. Remaining members, virtuals and lifetime are open.
// Do not instantiate or use in the running player.
class HumanoidState : public INamed, public HitTestFilter {
public:
    Humanoid* humanoid;
    float value0c;
    bool flag10;
    bool flag11;
};
}
}
