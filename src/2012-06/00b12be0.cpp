// roc 2012-06 00b12be0  unit: seg_00b10000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12be0
//
// 00b12be0  a174d4e100           mov eax, dword ptr [0xe1d474]
// 00b12be5  85c0                 test eax, eax
// 00b12be7  7408                 je 0xb12bf1
// 00b12be9  50                   push eax
// 00b12bea  ff15042eb200         call dword ptr [0xb22e04]
// 00b12bf0  59                   pop ecx
// 00b12bf1  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000016_0097ee50@ns_ROCX000016@@YAXXZ)

namespace ns_ROCX000016 {
extern void (__cdecl *deallocBytes)(void*);

extern void* g_00b7cd28;

void fn_ROCX000016_0097ee50()
{
    if (g_00b7cd28)
        deallocBytes(g_00b7cd28);
}
}
