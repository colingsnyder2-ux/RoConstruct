// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /U_RELEASEASSERT
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <G3D/Array.h>
#include "v8kernel/Connector2008.h"
#include "v8kernel/Kernel2008.h"
#include "v8kernel/KernelData2008.h"

void RBX::Kernel::removeConnector2ndPass(Connector* connector)
{
    kernelData->connectors2ndPass.fastRemove(connector);
}

// 005fa620 (registry placeholder func_005fa620; declared with its INFERRED name in v8kernel/Kernel2008.h):
// `mov eax, [ecx + 0x10]; mov eax, [eax + 0x28]; ret` = kernelData (+0x10) connectors IndexArray (+0x24) num.
// WorkspaceStatsItem 005a5c90 binds it (data ref 005a63fa) and DataModel 00575d90 calls it (005762a6) for the
// "numConstraints" stat (DataModelEvaluate.cpp notes).
int RBX::Kernel::getUnknownKernelData0x28() const
{
    return kernelData->connectors.size();
}
