// >>> native-status (generated) -- do not edit >>>
// WorkspaceClassName | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 5b77c4ee | roc native-status --write
#include "v8datamodel/Workspace.h"
namespace RBX {
template<class DerivedClass, const char* ClassName>
const Name& NonFactoryProduct<DerivedClass, ClassName>::className() { return Name::declare<ClassName>(); }
template<> const Name& NonFactoryProduct<RootInstance,sWorkspace>::getClassName() const { return className(); }
template const Name& NonFactoryProduct<RootInstance,sWorkspace>::className();
}
