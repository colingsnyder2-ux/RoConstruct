// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Team.h"

// INFERRED: the disassembly names GameSettings::GameSettings and shared_ptr<Script>
// constructors, which look like identical-code-folded twins of the Team ones.
// The real vendor body is the Creatable<Instance>::create<T>() template:
//     return boost::shared_ptr<T>(new T(), Deleter());
// I assume Team.h declares Creatable<Instance> with that template body, so an
// explicit instantiation produces this function.
// The headers were not visible, so this was not compiled or checked against the bytes.
template boost::shared_ptr<RBX::Team> RBX::Creatable<RBX::Instance>::create<RBX::Team>();
