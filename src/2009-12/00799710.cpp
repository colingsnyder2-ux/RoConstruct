// from server: 100% by auto
// roc 2009-12 00799710  unit: lua_exception  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00799710
//
// 00799710  83ec08               sub esp, 8
// 00799713  53                   push ebx
// 00799714  56                   push esi
// 00799715  8bf1                 mov esi, ecx
// 00799717  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0079971a  57                   push edi
// 0079971b  85db                 test ebx, ebx
// 0079971d  7504                 jne 0x799723
// 0079971f  33c9                 xor ecx, ecx
// 00799721  eb16                 jmp 0x799739
// 00799723  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00799726  2bcb                 sub ecx, ebx
// 00799728  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0079972d  f7e9                 imul ecx
// 0079972f  c1fa02               sar edx, 2
// 00799732  8bca                 mov ecx, edx
// 00799734  c1e91f               shr ecx, 0x1f
// 00799737  03ca                 add ecx, edx
// 00799739  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0079973c  8bd7                 mov edx, edi
// 0079973e  2bd3                 sub edx, ebx
// 00799740  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00799745  f7ea                 imul edx
// 00799747  c1fa02               sar edx, 2
// 0079974a  8bc2                 mov eax, edx
// 0079974c  c1e81f               shr eax, 0x1f
// 0079974f  03c2                 add eax, edx
// 00799751  3bc1                 cmp eax, ecx
// 00799753  7332                 jae 0x799787
// 00799755  8b542418             mov edx, dword ptr [esp + 0x18]
// 00799759  c644240c00           mov byte ptr [esp + 0xc], 0
// 0079975e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00799762  51                   push ecx
// 00799763  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00799767  52                   push edx
// 00799768  8d4608               lea eax, [esi + 8]
// 0079976b  50                   push eax
// 0079976c  51                   push ecx
// 0079976d  6a01                 push 1
// 0079976f  57                   push edi
// 00799770  e88bf1ffff           call 0x798900
// 00799775  83c418               add esp, 0x18
// 00799778  83c718               add edi, 0x18
// 0079977b  897e10               mov dword ptr [esi + 0x10], edi
// 0079977e  5f                   pop edi
// 0079977f  5e                   pop esi
// 00799780  5b                   pop ebx
// 00799781  83c408               add esp, 8
// 00799784  c20400               ret 4
// 00799787  3bdf                 cmp ebx, edi
// 00799789  7606                 jbe 0x799791
// 0079978b  ff1560b79800         call dword ptr [0x98b760]
// 00799791  8b542418             mov edx, dword ptr [esp + 0x18]
// 00799795  8b06                 mov eax, dword ptr [esi]
// 00799797  52                   push edx
// 00799798  57                   push edi
// 00799799  50                   push eax
// 0079979a  8d442418             lea eax, [esp + 0x18]
// 0079979e  50                   push eax
// 0079979f  8bce                 mov ecx, esi
// 007997a1  e80afeffff           call 0x7995b0
// 007997a6  5f                   pop edi
// 007997a7  5e                   pop esi
// 007997a8  5b                   pop ebx
// 007997a9  83c408               add esp, 8
// 007997ac  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
