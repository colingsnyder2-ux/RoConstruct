// from server: 100% by auto
// roc 2009-06 0083a9b0  unit: Ogre::RbxEntity  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0083a9b0
//
// 0083a9b0  83ec08               sub esp, 8
// 0083a9b3  53                   push ebx
// 0083a9b4  56                   push esi
// 0083a9b5  8bf1                 mov esi, ecx
// 0083a9b7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0083a9ba  57                   push edi
// 0083a9bb  85db                 test ebx, ebx
// 0083a9bd  7504                 jne 0x83a9c3
// 0083a9bf  33c9                 xor ecx, ecx
// 0083a9c1  eb15                 jmp 0x83a9d8
// 0083a9c3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0083a9c6  2bcb                 sub ecx, ebx
// 0083a9c8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0083a9cd  f7e9                 imul ecx
// 0083a9cf  d1fa                 sar edx, 1
// 0083a9d1  8bca                 mov ecx, edx
// 0083a9d3  c1e91f               shr ecx, 0x1f
// 0083a9d6  03ca                 add ecx, edx
// 0083a9d8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0083a9db  8bd7                 mov edx, edi
// 0083a9dd  2bd3                 sub edx, ebx
// 0083a9df  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0083a9e4  f7ea                 imul edx
// 0083a9e6  d1fa                 sar edx, 1
// 0083a9e8  8bc2                 mov eax, edx
// 0083a9ea  c1e81f               shr eax, 0x1f
// 0083a9ed  03c2                 add eax, edx
// 0083a9ef  3bc1                 cmp eax, ecx
// 0083a9f1  7332                 jae 0x83aa25
// 0083a9f3  8b542418             mov edx, dword ptr [esp + 0x18]
// 0083a9f7  c644240c00           mov byte ptr [esp + 0xc], 0
// 0083a9fc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0083aa00  51                   push ecx
// 0083aa01  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0083aa05  52                   push edx
// 0083aa06  8d4608               lea eax, [esi + 8]
// 0083aa09  50                   push eax
// 0083aa0a  51                   push ecx
// 0083aa0b  6a01                 push 1
// 0083aa0d  57                   push edi
// 0083aa0e  e83d0cc4ff           call 0x47b650
// 0083aa13  83c418               add esp, 0x18
// 0083aa16  83c70c               add edi, 0xc
// 0083aa19  897e10               mov dword ptr [esi + 0x10], edi
// 0083aa1c  5f                   pop edi
// 0083aa1d  5e                   pop esi
// 0083aa1e  5b                   pop ebx
// 0083aa1f  83c408               add esp, 8
// 0083aa22  c20400               ret 4
// 0083aa25  3bdf                 cmp ebx, edi
// 0083aa27  7606                 jbe 0x83aa2f
// 0083aa29  ff15ace98900         call dword ptr [0x89e9ac]
// 0083aa2f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0083aa33  8b06                 mov eax, dword ptr [esi]
// 0083aa35  52                   push edx
// 0083aa36  57                   push edi
// 0083aa37  50                   push eax
// 0083aa38  8d442418             lea eax, [esp + 0x18]
// 0083aa3c  50                   push eax
// 0083aa3d  8bce                 mov ecx, esi
// 0083aa3f  e89cfeffff           call 0x83a8e0
// 0083aa44  5f                   pop edi
// 0083aa45  5e                   pop esi
// 0083aa46  5b                   pop ebx
// 0083aa47  83c408               add esp, 8
// 0083aa4a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
