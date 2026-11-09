// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-string-calls roc_espclaude_3b1ba1467e3c49e0.cpp

// Candidate translation unit (score above; library headers required).
// Replay genuine MBCS library prelude before every vendor/MFC header.
#define _MBCS 1
#define _LIB 1
#pragma include_alias("atlsimpstr.h", "roc_xtp_native_length_boundary_header_2162f6784fec3fbf.cpp")
#pragma include_alias(<atlsimpstr.h>, <roc_xtp_native_length_boundary_header_2162f6784fec3fbf.cpp>)
#include "Source/Common/XTPDLLExports.h"
#include "Source/XTToolkitPro.h"
#include "Source/CommandBars/XTPControlExt.cpp"
