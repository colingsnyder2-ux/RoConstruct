// from server: 100% by EspClaude
// roc 2009-06 005ab9b0  unit: RBX::Mesh  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ab9b0
//
// 005ab9b0  55                   push ebp
// 005ab9b1  8bec                 mov ebp, esp
// 005ab9b3  83ec08               sub esp, 8
// 005ab9b6  894df8               mov dword ptr [ebp - 8], ecx
// 005ab9b9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005ab9c0  eb09                 jmp 0x5ab9cb
// 005ab9c2  8b45fc               mov eax, dword ptr [ebp - 4]
// 005ab9c5  83c001               add eax, 1
// 005ab9c8  8945fc               mov dword ptr [ebp - 4], eax
// 005ab9cb  8b4df8               mov ecx, dword ptr [ebp - 8]
// 005ab9ce  8b55fc               mov edx, dword ptr [ebp - 4]
// 005ab9d1  3b5104               cmp edx, dword ptr [ecx + 4]
// 005ab9d4  7d14                 jge 0x5ab9ea
// 005ab9d6  6a00                 push 0
// 005ab9d8  8b45f8               mov eax, dword ptr [ebp - 8]
// 005ab9db  8b08                 mov ecx, dword ptr [eax]
// 005ab9dd  8b55fc               mov edx, dword ptr [ebp - 4]
// 005ab9e0  8d0c91               lea ecx, [ecx + edx*4]
// 005ab9e3  e8d851fbff           call 0x560bc0
// 005ab9e8  ebd8                 jmp 0x5ab9c2
// 005ab9ea  8b45f8               mov eax, dword ptr [ebp - 8]
// 005ab9ed  8b08                 mov ecx, dword ptr [eax]
// 005ab9ef  51                   push ecx
// 005ab9f0  e89bf8fbff           call 0x56b290
// 005ab9f5  83c404               add esp, 4
// 005ab9f8  8b55f8               mov edx, dword ptr [ebp - 8]
// 005ab9fb  c70200000000         mov dword ptr [edx], 0
// 005aba01  8b45f8               mov eax, dword ptr [ebp - 8]
// 005aba04  c7400400000000       mov dword ptr [eax + 4], 0
// 005aba0b  8b4df8               mov ecx, dword ptr [ebp - 8]
// 005aba0e  c7410800000000       mov dword ptr [ecx + 8], 0
// 005aba15  8be5                 mov esp, ebp
// 005aba17  5d                   pop ebp
// 005aba18  c3                   ret 
// copied from an identical function in another client (function ?clear@S@ns_ROCX00000b@@QAEXXZ)

namespace ns_ROCX00000b {
struct Entry {
    void* value;
    void reset(void* value);
};

extern "C" void __cdecl alignedFree(void* memory);

struct S {
    Entry* entries;
    int count;
    int capacity;
    void clear();
};

#pragma optimize("", off)
void S::clear()
{
    for (int i = 0; i < count; i++)
        entries[i].reset(0);

    alignedFree(entries);
    entries = 0;
    count = 0;
    capacity = 0;
}
}
