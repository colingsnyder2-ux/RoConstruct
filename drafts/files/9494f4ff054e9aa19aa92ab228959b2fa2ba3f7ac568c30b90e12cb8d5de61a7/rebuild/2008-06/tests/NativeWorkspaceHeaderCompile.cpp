#include "v8datamodel/Workspace.h"
const RBX::Workspace* workspaceHeaderCast(const RBX::Instance* instance)
{
    return dynamic_cast<const RBX::Workspace*>(instance);
}
