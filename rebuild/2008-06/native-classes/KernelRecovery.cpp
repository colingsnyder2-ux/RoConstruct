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
