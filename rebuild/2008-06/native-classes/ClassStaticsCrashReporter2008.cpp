// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native CrashReporter::singleton (inactive): pointer at 009706c0 (.bss, null; the CrashReporter base ctor
// 00427a20 stores this). Header: native-headers/Network/CrashReporter.h.
#include "Network/CrashReporter.h"

CrashReporter* CrashReporter::singleton = 0;
