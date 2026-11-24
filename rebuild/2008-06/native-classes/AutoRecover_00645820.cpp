// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8kernel/IPipelined2008.h"

namespace RBX {
// 00645820
void IPipelined::removeFromPipeline(IStage*) { currentStage = NULL; }
}
