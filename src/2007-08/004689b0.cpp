// from server: 51% by colin
// roc 2007-08 004689b0  unit: VCWorkspace::?$CComObject  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004689b0
//
// 004689b0  894804               mov dword ptr [eax + 4], ecx
// 004689b3  837dd800             cmp dword ptr [ebp - 0x28], 0
// 004689b7  740b                 je 0x4689c4
// 004689b9  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 004689bc  52                   push edx
// 004689bd  6a00                 push 0
// 004689bf  e874751c00           call 0x62ff38
// 004689c4  33c0                 xor eax, eax
// 004689c6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004689c9  64890d00000000       mov dword ptr fs:[0], ecx
// 004689d0  59                   pop ecx
// 004689d1  5f                   pop edi
// 004689d2  5e                   pop esi
// 004689d3  5b                   pop ebx
// 004689d4  8be5                 mov esp, ebp
// 004689d6  5d                   pop ebp
// 004689d7  c20800               ret 8
// 004689da  6848010000           push 0x148
// 004689df  6858607900           push 0x796058
// 004689e4  6803400080           push 0x80004003
// 004689e9  6a01                 push 1
// 004689eb  e8c0f3fbff           call 0x427db0
// 004689f0  83c410               add esp, 0x10
// 004689f3  6870027900           push 0x790270
// 004689f8  6803400080           push 0x80004003
// 004689fd  e80ee6ffff           call 0x467010

struct VCWorkspaceCComObject
{
    void __stdcall sub_4689B0(int, int);
};

extern "C" void __stdcall sub_62FF38(int, int);
extern "C" void __stdcall sub_427DB0(int, int, int, int);
extern "C" void __stdcall sub_467010(int, int);

void VCWorkspaceCComObject::sub_4689B0(int a2, int a3)
{
    *(int*)(a2 + 4) = (int)this;
    if (a3 != 0)
    {
        sub_62FF38(0, a3);
    }
    sub_427DB0(1, 0x80004003, 0x796058, 0x148);
    sub_467010(0x80004003, 0x790270);
}
