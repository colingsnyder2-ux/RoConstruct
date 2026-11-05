// from server: 100% by auto
// roc 2008-06 00621440  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621440
//
// 00621440  83ec08               sub esp, 8
// 00621443  53                   push ebx
// 00621444  56                   push esi
// 00621445  8bf1                 mov esi, ecx
// 00621447  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0062144a  57                   push edi
// 0062144b  85db                 test ebx, ebx
// 0062144d  7504                 jne 0x621453
// 0062144f  33c9                 xor ecx, ecx
// 00621451  eb16                 jmp 0x621469
// 00621453  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00621456  2bcb                 sub ecx, ebx
// 00621458  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0062145d  f7e9                 imul ecx
// 0062145f  c1fa02               sar edx, 2
// 00621462  8bca                 mov ecx, edx
// 00621464  c1e91f               shr ecx, 0x1f
// 00621467  03ca                 add ecx, edx
// 00621469  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0062146c  8bd7                 mov edx, edi
// 0062146e  2bd3                 sub edx, ebx
// 00621470  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00621475  f7ea                 imul edx
// 00621477  c1fa02               sar edx, 2
// 0062147a  8bc2                 mov eax, edx
// 0062147c  c1e81f               shr eax, 0x1f
// 0062147f  03c2                 add eax, edx
// 00621481  3bc1                 cmp eax, ecx
// 00621483  7332                 jae 0x6214b7
// 00621485  8b542418             mov edx, dword ptr [esp + 0x18]
// 00621489  c644240c00           mov byte ptr [esp + 0xc], 0
// 0062148e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00621492  51                   push ecx
// 00621493  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00621497  52                   push edx
// 00621498  8d4608               lea eax, [esi + 8]
// 0062149b  50                   push eax
// 0062149c  51                   push ecx
// 0062149d  6a01                 push 1
// 0062149f  57                   push edi
// 006214a0  e81bf9ffff           call 0x620dc0
// 006214a5  83c418               add esp, 0x18
// 006214a8  83c718               add edi, 0x18
// 006214ab  897e10               mov dword ptr [esi + 0x10], edi
// 006214ae  5f                   pop edi
// 006214af  5e                   pop esi
// 006214b0  5b                   pop ebx
// 006214b1  83c408               add esp, 8
// 006214b4  c20400               ret 4
// 006214b7  3bdf                 cmp ebx, edi
// 006214b9  7606                 jbe 0x6214c1
// 006214bb  ff1590288000         call dword ptr [0x802890]
// 006214c1  8b542418             mov edx, dword ptr [esp + 0x18]
// 006214c5  8b06                 mov eax, dword ptr [esi]
// 006214c7  52                   push edx
// 006214c8  57                   push edi
// 006214c9  50                   push eax
// 006214ca  8d442418             lea eax, [esp + 0x18]
// 006214ce  50                   push eax
// 006214cf  8bce                 mov ecx, esi
// 006214d1  e8bafeffff           call 0x621390
// 006214d6  5f                   pop edi
// 006214d7  5e                   pop esi
// 006214d8  5b                   pop ebx
// 006214d9  83c408               add esp, 8
// 006214dc  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
