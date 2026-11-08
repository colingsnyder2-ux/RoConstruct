// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// AxisVerbConstructors | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0b0b1f02 | roc native-status --write
#include "StandardVerbs.h"
#include "util/Math.h"

namespace RBX {
RotateAxisCommand::RotateAxisCommand(std::string name, DataModel* model) : EditSelectionVerb(name, model) {}
ControllerCommand::ControllerCommand(std::string name, DataModel* model) : EditSelectionVerb(name, model) {}
RotateSelectionVerb::RotateSelectionVerb(DataModel* model) : RotateAxisCommand("SelectionRotate", model) {}
TiltSelectionVerb::TiltSelectionVerb(DataModel* model) : RotateAxisCommand("SelectionTilt", model) {}
PrimaryControllerCommand::PrimaryControllerCommand(DataModel* model) : ControllerCommand("Controller1", model) {}
SecondaryControllerCommand::SecondaryControllerCommand(DataModel* model) : ControllerCommand("Controller2", model) {}
G3D::Matrix3 RotateSelectionVerb::getRotationAxis() { return Math::matrixRotateY(); }
}
