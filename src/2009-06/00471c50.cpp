// from server: 100% by auto
// roc 2009-06 00471c50  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00471c50
//
// 00471c50  83ec08               sub esp, 8
// 00471c53  53                   push ebx
// 00471c54  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00471c58  56                   push esi
// 00471c59  8bf1                 mov esi, ecx
// 00471c5b  8b4610               mov eax, dword ptr [esi + 0x10]
// 00471c5e  57                   push edi
// 00471c5f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00471c62  8bc8                 mov ecx, eax
// 00471c64  2bcf                 sub ecx, edi
// 00471c66  c1f906               sar ecx, 6
// 00471c69  3bcb                 cmp ecx, ebx
// 00471c6b  7705                 ja 0x471c72
// 00471c6d  e8ae022700           call 0x6e1f20
// 00471c72  3bf8                 cmp edi, eax
// 00471c74  7606                 jbe 0x471c7c
// 00471c76  ff15ace98900         call dword ptr [0x89e9ac]
// 00471c7c  8b36                 mov esi, dword ptr [esi]
// 00471c7e  55                   push ebp
// 00471c7f  8bee                 mov ebp, esi
// 00471c81  897c2414             mov dword ptr [esp + 0x14], edi
// 00471c85  85f6                 test esi, esi
// 00471c87  751a                 jne 0x471ca3
// 00471c89  ff15ace98900         call dword ptr [0x89e9ac]
// 00471c8f  33c0                 xor eax, eax
// 00471c91  c1e306               shl ebx, 6
// 00471c94  03fb                 add edi, ebx
// 00471c96  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00471c99  7713                 ja 0x471cae
// 00471c9b  85f6                 test esi, esi
// 00471c9d  7408                 je 0x471ca7
// 00471c9f  8b36                 mov esi, dword ptr [esi]
// 00471ca1  eb06                 jmp 0x471ca9
// 00471ca3  8b06                 mov eax, dword ptr [esi]
// 00471ca5  ebea                 jmp 0x471c91
// 00471ca7  33f6                 xor esi, esi
// 00471ca9  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00471cac  730a                 jae 0x471cb8
// 00471cae  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 00471cb4  ffd6                 call esi
// 00471cb6  eb06                 jmp 0x471cbe
// 00471cb8  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 00471cbe  85ed                 test ebp, ebp
// 00471cc0  7517                 jne 0x471cd9
// 00471cc2  ffd6                 call esi
// 00471cc4  33c0                 xor eax, eax
// 00471cc6  5d                   pop ebp
// 00471cc7  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00471cca  7202                 jb 0x471cce
// 00471ccc  ffd6                 call esi
// 00471cce  8bc7                 mov eax, edi
// 00471cd0  5f                   pop edi
// 00471cd1  5e                   pop esi
// 00471cd2  5b                   pop ebx
// 00471cd3  83c408               add esp, 8
// 00471cd6  c20400               ret 4
// 00471cd9  8b4500               mov eax, dword ptr [ebp]
// 00471cdc  ebe8                 jmp 0x471cc6
// standard library vector<pod64> (function ?at@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
