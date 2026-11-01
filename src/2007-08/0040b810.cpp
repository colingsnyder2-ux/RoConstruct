// from server: 100% by colin
// roc 2007-08 0040b810  unit: VCBrowserViewExternal::?$CComObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b810
//
// 0040b810  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040b814  834118ff             add dword ptr [ecx + 0x18], -1
// 0040b818  56                   push esi
// 0040b819  8b7118               mov esi, dword ptr [ecx + 0x18]
// 0040b81c  750d                 jne 0x40b82b
// 0040b81e  85c9                 test ecx, ecx
// 0040b820  7409                 je 0x40b82b
// 0040b822  8b01                 mov eax, dword ptr [ecx]
// 0040b824  8b5010               mov edx, dword ptr [eax + 0x10]
// 0040b827  6a01                 push 1
// 0040b829  ffd2                 call edx
// 0040b82b  8bc6                 mov eax, esi
// 0040b82d  5e                   pop esi
// 0040b82e  c20400               ret 4
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