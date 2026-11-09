// from server: 100% by colin
// from server: 95% by colin
// roc 2008-06 004159e0  unit: CopyVerb  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004159e0
//
// 004159e0  56                   push esi
// 004159e1  8b742408             mov esi, dword ptr [esp + 8]
// 004159e5  57                   push edi
// 004159e6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004159ea  57                   push edi
// 004159eb  56                   push esi
// 004159ec  ff1524298000         call dword ptr [0x802924]
// 004159f2  85c0                 test eax, eax
// 004159f4  7c27                 jl 0x415a1d
// 004159f6  85ff                 test edi, edi
// 004159f8  7423                 je 0x415a1d
// 004159fa  66833f0d             cmp word ptr [edi], 0xd
// 004159fe  751d                 jne 0x415a1d
// 00415a00  85f6                 test esi, esi
// 00415a02  7419                 je 0x415a1d
// 00415a04  0fb74e02             movzx ecx, word ptr [esi + 2]
// 00415a08  f6c140               test cl, 0x40
// 00415a0b  7410                 je 0x415a1d
// 00415a0d  f7c100040000         test ecx, 0x400
// 00415a13  7408                 je 0x415a1d
// 00415a15  b909000000           mov ecx, 9
// 00415a1a  66890f               mov word ptr [edi], cx
// 00415a1d  5f                   pop edi
// 00415a1e  5e                   pop esi
// 00415a1f  c3                   ret 

struct SafeArray {
    unsigned short dimensions;
    unsigned short flags;
};

extern "C" {
    long (__stdcall *SafeArrayGetVartype)(SafeArray*, unsigned short*);
}

long __cdecl f(SafeArray* array, unsigned short* type)
{
    long result = SafeArrayGetVartype(array, type);
    if (result < 0)
        return result;
    if (type != 0 && *type == 13 && array != 0) {
        unsigned short flags = array->flags;
        if ((flags & 0x40) != 0 && (flags & 0x400) != 0)
            *type = 9;
    }
    return result;
}
