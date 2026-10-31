// from server: 100% by EspClaude
// roc 2009-06 0040f690  unit: CChatPrompt  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040f690
//
// 0040f690  56                   push esi
// 0040f691  8b742408             mov esi, dword ptr [esp + 8]
// 0040f695  56                   push esi
// 0040f696  e879993000           call 0x719014
// 0040f69b  85c0                 test eax, eax
// 0040f69d  7504                 jne 0x40f6a3
// 0040f69f  5e                   pop esi
// 0040f6a0  c20400               ret 4
// 0040f6a3  8b4620               mov eax, dword ptr [esi + 0x20]
// 0040f6a6  257fffcfff           and eax, 0xffcfff7f
// 0040f6ab  0d00000008           or eax, 0x8000000
// 0040f6b0  894620               mov dword ptr [esi + 0x20], eax
// 0040f6b3  b801000000           mov eax, 1
// 0040f6b8  5e                   pop esi
// 0040f6b9  c20400               ret 4
// copied from an identical function in another client (function ?f@ns_ROCX000016@@YGHPAUS@1@@Z)

namespace ns_ROCX000016 {
struct S {
    unsigned char padding[0x20];
    unsigned long flags;
};

extern "C" int __stdcall check(S* p);

int __stdcall f(S* p)
{
    if (!check(p))
        return 0;

    p->flags = (p->flags & 0xFFCFFF7FUL) | 0x08000000UL;
    return 1;
}
}
