#include "v8datamodel/MouseCommand.h"
namespace RBX {
typedef char MouseCommandSize[sizeof(MouseCommand) == 0x1c ? 1 : -1];
MouseCommand::MouseCommand(Workspace* value) : workspace(value), capturedMouse(false) {}
MouseCommand::~MouseCommand() {}
}
