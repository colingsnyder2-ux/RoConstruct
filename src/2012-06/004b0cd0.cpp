// from server: 100% by Xemicl
// roc 2012-06 004b0cd0  unit: CWebToolbox  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0cd0
//
// 004b0cd0  56                   push esi
// 004b0cd1  8b742408             mov esi, dword ptr [esp + 8]
// 004b0cd5  56                   push esi
// 004b0cd6  e8db174d00           call 0x9824b6
// 004b0cdb  85c0                 test eax, eax
// 004b0cdd  7507                 jne 0x4b0ce6
// 004b0cdf  814e0417408401       or dword ptr [esi + 4], 0x1844017
// 004b0ce6  5e                   pop esi
// 004b0ce7  c20400               ret 4
// copied from an identical function in another client (function ?f@CWebToolbox@ns_ROCX000025@@QAEXPAX@Z)

namespace ns_ROCX000025 {
struct CWebToolbox
{
    void f(void *);
};

extern "C" int __stdcall fn_ROCX000025_006a0a34(void *);

void CWebToolbox::f(void *p)
{
    if (!fn_ROCX000025_006a0a34(p))
        *(int *)((char *)p + 4) |= 0x1844017;
}
}