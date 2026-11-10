#include "v8datamodel/Hopper.h"
namespace RBX {
// 005cf900: RelativePanel ctor 005cf770; yLocation store +0x160 = 1.
Hopper::Hopper() { yLocation = Rect::BOTTOM; }
// 005cf1c0: __RTDynamicCast Instance -> BackpackItem.
bool Hopper::askAddChild(const Instance* instance) const { return dynamic_cast<const BackpackItem*>(instance) != NULL; }
}
