// roc 2012-06 00a13de0  unit: CXTPControlEdit  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a13de0
//
// 00a13de0  f644240410           test byte ptr [esp + 4], 0x10
// 00a13de5  7417                 je 0xa13dfe
// 00a13de7  8b91d0000000         mov edx, dword ptr [ecx + 0xd0]
// 00a13ded  8b01                 mov eax, dword ptr [ecx]
// 00a13def  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00a13df5  83ca04               or edx, 4
// 00a13df8  89542404             mov dword ptr [esp + 4], edx
// 00a13dfc  ffe0                 jmp eax
// 00a13dfe  8b81d0000000         mov eax, dword ptr [ecx + 0xd0]
// 00a13e04  8b11                 mov edx, dword ptr [ecx]
// 00a13e06  8b9294000000         mov edx, dword ptr [edx + 0x94]
// 00a13e0c  83e0fb               and eax, 0xfffffffb
// 00a13e0f  89442404             mov dword ptr [esp + 4], eax
// 00a13e13  ffe2                 jmp edx
// copied from an identical function in another client (function ?SetStyle@CXTPCustomizeSheet_CCustomizeEdit@ns_ROCX00000b@@QAEXI@Z)

namespace ns_ROCX00000b {
struct CXTPCustomizeSheet_CCustomizeEdit {
    void SetStyle(unsigned int flags);
};

void CXTPCustomizeSheet_CCustomizeEdit::SetStyle(unsigned int flags) {
    if (flags & 0x10) {
        unsigned int v = *(unsigned int*)((char*)this + 0xd0);
        void (__thiscall *fn)(void*, unsigned int) = *(void (__thiscall **)(void*, unsigned int))((*(char**)this) + 0x94);
        v |= 4;
        fn(this, v);
    } else {
        unsigned int v = *(unsigned int*)((char*)this + 0xd0);
        void (__thiscall *fn)(void*, unsigned int) = *(void (__thiscall **)(void*, unsigned int))((*(char**)this) + 0x94);
        v &= ~4u;
        fn(this, v);
    }
}
}
