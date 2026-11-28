// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x0078c560 (single tail jump to USER32 GetSysColor, stdcall one int argument).
#include <windows.h>
extern "C" DWORD __stdcall fn_0078c560(int index)
{
    return GetSysColor(index);
}
