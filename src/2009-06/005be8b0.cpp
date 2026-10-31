// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0053f970  unit: RBX::RenderBase::AggregatingSceneManager  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0053f970
//
// 0053f970  55                   push ebp
// 0053f971  8bec                 mov ebp, esp
// 0053f973  83ec08               sub esp, 8
// 0053f976  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053f97d  eb09                 jmp 0x53f988
// 0053f97f  8b45fc               mov eax, dword ptr [ebp - 4]
// 0053f982  83c001               add eax, 1
// 0053f985  8945fc               mov dword ptr [ebp - 4], eax
// 0053f988  837dfc03             cmp dword ptr [ebp - 4], 3
// 0053f98c  7d47                 jge 0x53f9d5
// 0053f98e  c745f800000000       mov dword ptr [ebp - 8], 0
// 0053f995  eb09                 jmp 0x53f9a0
// 0053f997  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0053f99a  83c101               add ecx, 1
// 0053f99d  894df8               mov dword ptr [ebp - 8], ecx
// 0053f9a0  837df803             cmp dword ptr [ebp - 8], 3
// 0053f9a4  7d2d                 jge 0x53f9d3
// 0053f9a6  8b55fc               mov edx, dword ptr [ebp - 4]
// 0053f9a9  52                   push edx
// 0053f9aa  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f9ad  e8be6bf3ff           call 0x476570
// 0053f9b2  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0053f9b5  d90488               fld dword ptr [eax + ecx*4]
// 0053f9b8  83ec08               sub esp, 8
// 0053f9bb  dd1c24               fstp qword ptr [esp]
// 0053f9be  e87d5ff6ff           call 0x4a5940
// 0053f9c3  83c408               add esp, 8
// 0053f9c6  0fb6d0               movzx edx, al
// 0053f9c9  85d2                 test edx, edx
// 0053f9cb  7504                 jne 0x53f9d1
// 0053f9cd  32c0                 xor al, al
// 0053f9cf  eb06                 jmp 0x53f9d7
// 0053f9d1  ebc4                 jmp 0x53f997
// 0053f9d3  ebaa                 jmp 0x53f97f
// 0053f9d5  b001                 mov al, 1
// 0053f9d7  8be5                 mov esp, ebp
// 0053f9d9  5d                   pop ebp
// 0053f9da  c3                   ret 

#pragma optimize("", off)

struct Matrix3 {
    const float* operator[](int index) const;
};

extern bool __cdecl validValue(double value);

bool __cdecl f(const Matrix3& matrix)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!validValue(matrix[i][j]))
                return false;
        }
    }
    return true;
}
