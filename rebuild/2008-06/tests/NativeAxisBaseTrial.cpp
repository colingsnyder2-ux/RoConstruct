#include "StandardVerbs.h"
namespace RBX {
RotateAxisCommand::RotateAxisCommand(std::string name, DataModel* model) : EditSelectionVerb(name, model) {}
ControllerCommand::ControllerCommand(std::string name, DataModel* model) : EditSelectionVerb(name, model) {}
}
