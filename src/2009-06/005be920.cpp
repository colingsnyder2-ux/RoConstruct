// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0053f9e0  unit: RBX::RenderBase::AggregatingSceneManager  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0053f9e0
//
// 0053f9e0  55                   push ebp
// 0053f9e1  8bec                 mov ebp, esp
// 0053f9e3  51                   push ecx
// 0053f9e4  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f9e7  e8f45ff6ff           call 0x4a59e0
// 0053f9ec  0fb6c0               movzx eax, al
// 0053f9ef  85c0                 test eax, eax
// 0053f9f1  7504                 jne 0x53f9f7
// 0053f9f3  32c0                 xor al, al
// 0053f9f5  eb49                 jmp 0x53fa40
// 0053f9f7  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053f9fe  eb09                 jmp 0x53fa09
// 0053fa00  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053fa03  83c101               add ecx, 1
// 0053fa06  894dfc               mov dword ptr [ebp - 4], ecx
// 0053fa09  837dfc03             cmp dword ptr [ebp - 4], 3
// 0053fa0d  7d2f                 jge 0x53fa3e
// 0053fa0f  8b55fc               mov edx, dword ptr [ebp - 4]
// 0053fa12  52                   push edx
// 0053fa13  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053fa16  e865deefff           call 0x43d880
// 0053fa1b  d900                 fld dword ptr [eax]
// 0053fa1d  83ec08               sub esp, 8
// 0053fa20  dd1c24               fstp qword ptr [esp]
// 0053fa23  e8b822fdff           call 0x511ce0
// 0053fa28  83c408               add esp, 8
// 0053fa2b  dc1df8ce8200         fcomp qword ptr [0x82cef8]
// 0053fa31  dfe0                 fnstsw ax
// 0053fa33  f6c441               test ah, 0x41
// 0053fa36  7504                 jne 0x53fa3c
// 0053fa38  32c0                 xor al, al
// 0053fa3a  eb04                 jmp 0x53fa40
// 0053fa3c  ebc2                 jmp 0x53fa00
// 0053fa3e  b001                 mov al, 1
// 0053fa40  8be5                 mov esp, ebp
// 0053fa42  5d                   pop ebp
// 0053fa43  c3                   ret 

struct Vector3
{
    bool isFinite() const;
    const float& operator[](int index) const;
};

extern double __cdecl absoluteValue(double value);
extern const double limit;

#pragma optimize("", off)

bool __cdecl checkVector(const Vector3& value)
{
    if (!value.isFinite())
        return false;

    for (int i = 0; i < 3; ++i)
    {
        if (absoluteValue(value[i]) > limit)
            return false;
    }

    return true;
}
