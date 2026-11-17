// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 004d8c90: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Sky.h"
#include "util/Name.h"

namespace RBX {

template boost::shared_ptr<Sky> Creatable<Instance>::create<Sky>();

}
