// from server: 100% by EspClaude
// roc 2009-06 0046d720  unit: CWebToolbox  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d720
//
// 0046d720  56                   push esi
// 0046d721  8b742408             mov esi, dword ptr [esp + 8]
// 0046d725  56                   push esi
// 0046d726  e8bbb62a00           call 0x718de6
// 0046d72b  85c0                 test eax, eax
// 0046d72d  7507                 jne 0x46d736
// 0046d72f  814e0417408401       or dword ptr [esi + 4], 0x1844017
// 0046d736  5e                   pop esi
// 0046d737  c20400               ret 4
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
