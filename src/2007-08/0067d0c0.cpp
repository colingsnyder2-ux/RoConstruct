// from server: 100% by EspClaude
// from server: 73% by colin
// roc 2007-08 0067d0c0  unit: CXTPControls  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0067d0c0
//
// 0067d0c0  53                   push ebx
// 0067d0c1  55                   push ebp
// 0067d0c2  56                   push esi
// 0067d0c3  57                   push edi
// 0067d0c4  8bf9                 mov edi, ecx
// 0067d0c6  8b07                 mov eax, dword ptr [edi]
// 0067d0c8  8b10                 mov edx, dword ptr [eax]
// 0067d0ca  ffd2                 call edx
// 0067d0cc  8bc8                 mov ecx, eax
// 0067d0ce  e85934fbff           call 0x63052c
// 0067d0d3  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0067d0d7  8bd8                 mov ebx, eax
// 0067d0d9  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0067d0dc  33f6                 xor esi, esi
// 0067d0de  85c0                 test eax, eax
// 0067d0e0  7e4c                 jle 0x67d12e
// 0067d0e2  85f6                 test esi, esi
// 0067d0e4  7c11                 jl 0x67d0f7
// 0067d0e6  3bf0                 cmp esi, eax
// 0067d0e8  7d0d                 jge 0x67d0f7
// 0067d0ea  3b772c               cmp esi, dword ptr [edi + 0x2c]
// 0067d0ed  7d58                 jge 0x67d147
// 0067d0ef  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 0067d0f2  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0067d0f5  eb02                 jmp 0x67d0f9
// 0067d0f7  33c9                 xor ecx, ecx
// 0067d0f9  83b9ac00000000       cmp dword ptr [ecx + 0xac], 0
// 0067d100  7522                 jne 0x67d124
// 0067d102  85f6                 test esi, esi
// 0067d104  7c11                 jl 0x67d117
// 0067d106  3bf0                 cmp esi, eax
// 0067d108  7d0d                 jge 0x67d117
// 0067d10a  3b772c               cmp esi, dword ptr [edi + 0x2c]
// 0067d10d  7d38                 jge 0x67d147
// 0067d10f  8b5728               mov edx, dword ptr [edi + 0x28]
// 0067d112  8b04b2               mov eax, dword ptr [edx + esi*4]
// 0067d115  eb02                 jmp 0x67d119
// 0067d117  33c0                 xor eax, eax
// 0067d119  55                   push ebp
// 0067d11a  6aff                 push -1
// 0067d11c  50                   push eax
// 0067d11d  8bcb                 mov ecx, ebx
// 0067d11f  e88cf4ffff           call 0x67c5b0
// 0067d124  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0067d127  83c601               add esi, 1
// 0067d12a  3bf0                 cmp esi, eax
// 0067d12c  7cb4                 jl 0x67d0e2
// 0067d12e  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 0067d131  85c9                 test ecx, ecx
// 0067d133  7409                 je 0x67d13e
// 0067d135  55                   push ebp
// 0067d136  e885ffffff           call 0x67d0c0
// 0067d13b  89433c               mov dword ptr [ebx + 0x3c], eax
// 0067d13e  5f                   pop edi
// 0067d13f  5e                   pop esi

__declspec(noreturn) void __stdcall sub_62ff20();

struct Inner {
    char pad[0xac];
    int field_ac;
};

struct Outer;

struct RtClass {
    Outer* sub_63052c();
};

struct Arr {
    Inner** m_pData;
    int m_nSize;
    Inner* GetAt(int n) const {
        if (n >= 0 && n < m_nSize)
            return m_pData[n];
        sub_62ff20();
    }
};

struct Outer {
    virtual RtClass* GetRuntimeClass();
    char pad0[0x24];
    Arr items;
    char pad1[0xc];
    Outer* child;
    int GetCount() const { return items.m_nSize; }
    Inner* GetAt(int i) const { return (i >= 0 && i < GetCount()) ? items.GetAt(i) : 0; }
    void sub_67c5b0(Inner*, int, int);
    Outer* method(int);
};

Outer* Outer::method(int arg) {
    Outer* v = GetRuntimeClass()->sub_63052c();
    for (int i = 0; i < GetCount(); i++) {
        if (GetAt(i)->field_ac == 0)
            v->sub_67c5b0(GetAt(i), -1, arg);
    }
    if (child != 0)
        v->child = child->method(arg);
    return v;
}
