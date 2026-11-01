// from server: 100% by colin
// roc 2007-03 0040cc90  unit: seg_00400000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040cc90
//
// 0040cc90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040cc94  834118ff             add dword ptr [ecx + 0x18], -1
// 0040cc98  56                   push esi
// 0040cc99  8b7118               mov esi, dword ptr [ecx + 0x18]
// 0040cc9c  750d                 jne 0x40ccab
// 0040cc9e  85c9                 test ecx, ecx
// 0040cca0  7409                 je 0x40ccab
// 0040cca2  8b01                 mov eax, dword ptr [ecx]
// 0040cca4  8b5010               mov edx, dword ptr [eax + 0x10]
// 0040cca7  6a01                 push 1
// 0040cca9  ffd2                 call edx
// 0040ccab  8bc6                 mov eax, esi
// 0040ccad  5e                   pop esi
// 0040ccae  c20400               ret 4
// copied from an identical function in another client (function ?release@@YGKPAUS@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~S();
};

unsigned long __stdcall release(S* object)
{
    unsigned long* refs = reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(object) + 0x18);
    unsigned long remaining = --*refs;
    if (remaining == 0)
        delete object;
    return remaining;
}