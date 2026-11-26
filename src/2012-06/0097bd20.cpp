// from server: 100% by Xemicl
// roc 2012-06 0097bd20  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097bd20
//
// 0097bd20  83ec28               sub esp, 0x28
// 0097bd23  ff15bc21b200         call dword ptr [0xb221bc]
// 0097bd29  85c0                 test eax, eax
// 0097bd2b  7e0a                 jle 0x97bd37
// 0097bd2d  25ffff0000           and eax, 0xffff
// 0097bd32  0d00000780           or eax, 0x80070000
// 0097bd37  50                   push eax
// 0097bd38  8d442404             lea eax, [esp + 4]
// 0097bd3c  682cb9c000           push 0xc0b92c
// 0097bd41  50                   push eax
// 0097bd42  e82970ffff           call 0x972d70
// 0097bd47  83c40c               add esp, 0xc
// 0097bd4a  686c80cd00           push 0xcd806c
// 0097bd4f  8d4c2404             lea ecx, [esp + 4]
// 0097bd53  51                   push ecx
// 0097bd54  e8eb730000           call 0x983144
// copied from an identical function in another client (function ?throwLastError@@YAXXZ)

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