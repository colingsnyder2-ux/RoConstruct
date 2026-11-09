// from server: 100% by auto
// roc 2009-12 0047c3c0  unit: RBX::LDraw2Lua::LDraw2RobloxPartMap  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047c3c0
//
// 0047c3c0  83ec08               sub esp, 8
// 0047c3c3  56                   push esi
// 0047c3c4  8bf1                 mov esi, ecx
// 0047c3c6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0047c3c9  57                   push edi
// 0047c3ca  85c9                 test ecx, ecx
// 0047c3cc  7504                 jne 0x47c3d2
// 0047c3ce  33c0                 xor eax, eax
// 0047c3d0  eb08                 jmp 0x47c3da
// 0047c3d2  8b4614               mov eax, dword ptr [esi + 0x14]
// 0047c3d5  2bc1                 sub eax, ecx
// 0047c3d7  c1f806               sar eax, 6
// 0047c3da  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0047c3dd  8bd7                 mov edx, edi
// 0047c3df  2bd1                 sub edx, ecx
// 0047c3e1  c1fa06               sar edx, 6
// 0047c3e4  3bd0                 cmp edx, eax
// 0047c3e6  7331                 jae 0x47c419
// 0047c3e8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047c3ec  c644240800           mov byte ptr [esp + 8], 0
// 0047c3f1  8b442408             mov eax, dword ptr [esp + 8]
// 0047c3f5  50                   push eax
// 0047c3f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0047c3fa  51                   push ecx
// 0047c3fb  8d5608               lea edx, [esi + 8]
// 0047c3fe  52                   push edx
// 0047c3ff  50                   push eax
// 0047c400  6a01                 push 1
// 0047c402  57                   push edi
// 0047c403  e808f8ffff           call 0x47bc10
// 0047c408  83c418               add esp, 0x18
// 0047c40b  83c740               add edi, 0x40
// 0047c40e  897e10               mov dword ptr [esi + 0x10], edi
// 0047c411  5f                   pop edi
// 0047c412  5e                   pop esi
// 0047c413  83c408               add esp, 8
// 0047c416  c20400               ret 4
// 0047c419  3bcf                 cmp ecx, edi
// 0047c41b  7606                 jbe 0x47c423
// 0047c41d  ff1560b79800         call dword ptr [0x98b760]
// 0047c423  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047c427  8b06                 mov eax, dword ptr [esi]
// 0047c429  51                   push ecx
// 0047c42a  57                   push edi
// 0047c42b  50                   push eax
// 0047c42c  8d542414             lea edx, [esp + 0x14]
// 0047c430  52                   push edx
// 0047c431  8bce                 mov ecx, esi
// 0047c433  e8a8feffff           call 0x47c2e0
// 0047c438  5f                   pop edi
// 0047c439  5e                   pop esi
// 0047c43a  83c408               add esp, 8
// 0047c43d  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
