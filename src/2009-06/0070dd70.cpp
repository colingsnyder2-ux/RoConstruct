// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _DLL
#include <stdexcept>
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
std::runtime_error runtime_error(const char* fmt, ...);
void throwLastError()
{
    long x = (long)GetLastError();
    long hr = x <= 0 ? x : (long)((x & 0xffff) | 0x80070000);
    throw runtime_error("HRESULT = 0x%.8X", hr);
}
