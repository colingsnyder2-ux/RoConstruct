// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// BoundProp<T,1>::BoundPropGetSet<C> constructors the converted static initializers (007f.. range) call out of line.
// Their analog headers took `BoundProp*` (mangled PAV123@), ours `BoundProp&` (AAV123@): same ABI, so quicktest aliases
// the pointer spelling to these instantiations. Unlinked, they were `return 0` stubs: the GetSet object kept a null
// vtable -> CPropGrid::addProperty -> isReadOnly crashed on Sky::prop_SkyRt (File->New).
#include "util/Object.h"
#include "v8datamodel/Sky.h"
#include "spawn-touched/v8datamodel/SpawnLocation.h"
#include "v8datamodel/Team.h"
#include "v8datamodel/Tool.h"

template class RBX::Reflection::BoundProp<int, 1>::BoundPropGetSet<RBX::Sky>;
template class RBX::Reflection::BoundProp<RBX::TextureId, 1>::BoundPropGetSet<RBX::Sky>;
template class RBX::Reflection::BoundProp<bool, 1>::BoundPropGetSet<RBX::Sky>;
template class RBX::Reflection::BoundProp<int, 1>::BoundPropGetSet<RBX::SpawnLocation>;
template class RBX::Reflection::BoundProp<bool, 1>::BoundPropGetSet<RBX::SpawnLocation>;
template class RBX::Reflection::BoundProp<bool, 1>::BoundPropGetSet<RBX::Team>;
template class RBX::Reflection::BoundProp<bool, 1>::BoundPropGetSet<RBX::Tool>;
