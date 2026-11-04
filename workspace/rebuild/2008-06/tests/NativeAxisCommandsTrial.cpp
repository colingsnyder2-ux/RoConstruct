#include "StandardVerbs.h"
namespace RBX {
RotateSelectionVerb::RotateSelectionVerb(DataModel* model) : RotateAxisCommand("SelectionRotate", model) {}
TiltSelectionVerb::TiltSelectionVerb(DataModel* model) : RotateAxisCommand("SelectionTilt", model) {}
PrimaryControllerCommand::PrimaryControllerCommand(DataModel* model) : ControllerCommand("Controller1", model) {}
SecondaryControllerCommand::SecondaryControllerCommand(DataModel* model) : ControllerCommand("Controller2", model) {}
}
