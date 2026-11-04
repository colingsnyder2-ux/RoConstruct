#include "v8datamodel/ToolsPart.h"
namespace RBX {
const std::string FillTool::getCursorName() const { return "FillCursor"; }
MouseCommand* FillTool::isSticky() const { return new FillTool(workspace); }
const std::string DropperTool::getCursorName() const { return "DropperCursor"; }
}
