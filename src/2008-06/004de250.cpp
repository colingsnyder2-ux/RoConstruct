// from server: 100% by auto
// roc 2008-06 004de250  unit: RBX::RenderBase::Mesh::Level  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004de250
//
// 004de250  83ec08               sub esp, 8
// 004de253  53                   push ebx
// 004de254  56                   push esi
// 004de255  8bf1                 mov esi, ecx
// 004de257  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004de25a  57                   push edi
// 004de25b  85db                 test ebx, ebx
// 004de25d  7504                 jne 0x4de263
// 004de25f  33c9                 xor ecx, ecx
// 004de261  eb15                 jmp 0x4de278
// 004de263  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004de266  2bcb                 sub ecx, ebx
// 004de268  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004de26d  f7e9                 imul ecx
// 004de26f  d1fa                 sar edx, 1
// 004de271  8bca                 mov ecx, edx
// 004de273  c1e91f               shr ecx, 0x1f
// 004de276  03ca                 add ecx, edx
// 004de278  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004de27b  8bd7                 mov edx, edi
// 004de27d  2bd3                 sub edx, ebx
// 004de27f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004de284  f7ea                 imul edx
// 004de286  d1fa                 sar edx, 1
// 004de288  8bc2                 mov eax, edx
// 004de28a  c1e81f               shr eax, 0x1f
// 004de28d  03c2                 add eax, edx
// 004de28f  3bc1                 cmp eax, ecx
// 004de291  7332                 jae 0x4de2c5
// 004de293  8b542418             mov edx, dword ptr [esp + 0x18]
// 004de297  c644240c00           mov byte ptr [esp + 0xc], 0
// 004de29c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004de2a0  51                   push ecx
// 004de2a1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004de2a5  52                   push edx
// 004de2a6  8d4608               lea eax, [esi + 8]
// 004de2a9  50                   push eax
// 004de2aa  51                   push ecx
// 004de2ab  6a01                 push 1
// 004de2ad  57                   push edi
// 004de2ae  e8bde7ffff           call 0x4dca70
// 004de2b3  83c418               add esp, 0x18
// 004de2b6  83c70c               add edi, 0xc
// 004de2b9  897e10               mov dword ptr [esi + 0x10], edi
// 004de2bc  5f                   pop edi
// 004de2bd  5e                   pop esi
// 004de2be  5b                   pop ebx
// 004de2bf  83c408               add esp, 8
// 004de2c2  c20400               ret 4
// 004de2c5  3bdf                 cmp ebx, edi
// 004de2c7  7606                 jbe 0x4de2cf
// 004de2c9  ff1590288000         call dword ptr [0x802890]
// 004de2cf  8b542418             mov edx, dword ptr [esp + 0x18]
// 004de2d3  8b06                 mov eax, dword ptr [esi]
// 004de2d5  52                   push edx
// 004de2d6  57                   push edi
// 004de2d7  50                   push eax
// 004de2d8  8d442418             lea eax, [esp + 0x18]
// 004de2dc  50                   push eax
// 004de2dd  8bce                 mov ecx, esi
// 004de2df  e81cfeffff           call 0x4de100
// 004de2e4  5f                   pop edi
// 004de2e5  5e                   pop esi
// 004de2e6  5b                   pop ebx
// 004de2e7  83c408               add esp, 8
// 004de2ea  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
