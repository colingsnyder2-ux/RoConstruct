// from server: 100% by auto
// roc 2009-06 006c26b0  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c26b0
//
// 006c26b0  83ec08               sub esp, 8
// 006c26b3  53                   push ebx
// 006c26b4  56                   push esi
// 006c26b5  8bf1                 mov esi, ecx
// 006c26b7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006c26ba  57                   push edi
// 006c26bb  85db                 test ebx, ebx
// 006c26bd  7504                 jne 0x6c26c3
// 006c26bf  33c9                 xor ecx, ecx
// 006c26c1  eb16                 jmp 0x6c26d9
// 006c26c3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006c26c6  2bcb                 sub ecx, ebx
// 006c26c8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006c26cd  f7e9                 imul ecx
// 006c26cf  c1fa02               sar edx, 2
// 006c26d2  8bca                 mov ecx, edx
// 006c26d4  c1e91f               shr ecx, 0x1f
// 006c26d7  03ca                 add ecx, edx
// 006c26d9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006c26dc  8bd7                 mov edx, edi
// 006c26de  2bd3                 sub edx, ebx
// 006c26e0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006c26e5  f7ea                 imul edx
// 006c26e7  c1fa02               sar edx, 2
// 006c26ea  8bc2                 mov eax, edx
// 006c26ec  c1e81f               shr eax, 0x1f
// 006c26ef  03c2                 add eax, edx
// 006c26f1  3bc1                 cmp eax, ecx
// 006c26f3  7332                 jae 0x6c2727
// 006c26f5  8b542418             mov edx, dword ptr [esp + 0x18]
// 006c26f9  c644240c00           mov byte ptr [esp + 0xc], 0
// 006c26fe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006c2702  51                   push ecx
// 006c2703  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006c2707  52                   push edx
// 006c2708  8d4608               lea eax, [esi + 8]
// 006c270b  50                   push eax
// 006c270c  51                   push ecx
// 006c270d  6a01                 push 1
// 006c270f  57                   push edi
// 006c2710  e89bf8ffff           call 0x6c1fb0
// 006c2715  83c418               add esp, 0x18
// 006c2718  83c718               add edi, 0x18
// 006c271b  897e10               mov dword ptr [esi + 0x10], edi
// 006c271e  5f                   pop edi
// 006c271f  5e                   pop esi
// 006c2720  5b                   pop ebx
// 006c2721  83c408               add esp, 8
// 006c2724  c20400               ret 4
// 006c2727  3bdf                 cmp ebx, edi
// 006c2729  7606                 jbe 0x6c2731
// 006c272b  ff15ace98900         call dword ptr [0x89e9ac]
// 006c2731  8b542418             mov edx, dword ptr [esp + 0x18]
// 006c2735  8b06                 mov eax, dword ptr [esi]
// 006c2737  52                   push edx
// 006c2738  57                   push edi
// 006c2739  50                   push eax
// 006c273a  8d442418             lea eax, [esp + 0x18]
// 006c273e  50                   push eax
// 006c273f  8bce                 mov ecx, esi
// 006c2741  e8bafeffff           call 0x6c2600
// 006c2746  5f                   pop edi
// 006c2747  5e                   pop esi
// 006c2748  5b                   pop ebx
// 006c2749  83c408               add esp, 8
// 006c274c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
