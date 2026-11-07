// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ControllerActions | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 29817612 | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);

void PrimaryControllerCommand::doIt(IDataState* state)
{
    applyController(1);
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}

void SecondaryControllerCommand::doIt(IDataState* state)
{
    applyController(2);
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}
}
