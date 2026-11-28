// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: v8tree/ServiceProvider.h and v8datamodel/ServiceProvider.h are both missing,
// so ServiceProvider is reached through DataModel.h, which should pull it in.
#include "v8datamodel/DataModel.h"

namespace RBX {

// RunService is only used as a template argument, so a forward declaration is enough.
class RunService;

// INFERRED: explicit specialization of the static member template, with a function-local static caching newIndex()
template<>
unsigned int ServiceProvider::doGetClassIndex<RunService>()
{
    static unsigned int index = ServiceProvider::newIndex();
    return index;
}

}
