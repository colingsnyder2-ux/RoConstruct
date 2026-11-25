// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"

namespace RBX { class RunService; }

// INFERRED: the target is a single tail jmp to 0x0044f3c0, a void(void) cdecl function.
extern "C" void fn_0044f3c0();

// INFERRED: DataModel.h pulls in ServiceProvider.h (v8datamodel/ServiceProvider.h does not exist
// as a standalone path), which declares this static member template.
template<>
void RBX::ServiceProvider::callDoGetClassIndex<RBX::RunService>()
{
    fn_0044f3c0();
}
