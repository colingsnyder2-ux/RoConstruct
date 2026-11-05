// roc 2009-12 0088b200  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088b200
//
// 0088b200  f644240410           test byte ptr [esp + 4], 0x10
// 0088b205  7417                 je 0x88b21e
// 0088b207  8b91d0000000         mov edx, dword ptr [ecx + 0xd0]
// 0088b20d  8b01                 mov eax, dword ptr [ecx]
// 0088b20f  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 0088b215  83ca04               or edx, 4
// 0088b218  89542404             mov dword ptr [esp + 4], edx
// 0088b21c  ffe0                 jmp eax
// 0088b21e  8b81d0000000         mov eax, dword ptr [ecx + 0xd0]
// 0088b224  8b11                 mov edx, dword ptr [ecx]
// 0088b226  8b9294000000         mov edx, dword ptr [edx + 0x94]
// 0088b22c  83e0fb               and eax, 0xfffffffb
// 0088b22f  89442404             mov dword ptr [esp + 4], eax
// 0088b233  ffe2                 jmp edx
// copied from an identical function in another client (function ?SetStyle@CXTPCustomizeSheet_CCustomizeEdit@ns_ROCX000008@@QAEXI@Z)

namespace ns_ROCX000008 {
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
