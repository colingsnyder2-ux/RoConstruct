#include "NativeCloneToolInlineTrial.h"
namespace RBX {
MouseCommand* CloneTool::isSticky() const { return new CloneTool(workspace); }
}
