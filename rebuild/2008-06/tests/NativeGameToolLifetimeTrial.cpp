#include "NativeGameToolTrial.h"
namespace RBX {
GameTool::GameTool(Workspace* workspace) : Named<MouseCommand, &sGameTool>(workspace) {}
GameTool::~GameTool() {}
MouseCommand* GameTool::isSticky() const { return new GameTool(workspace); }
}
