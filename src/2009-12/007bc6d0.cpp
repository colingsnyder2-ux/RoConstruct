// from server: 100% by auto
// roc 2009-12 007bc6d0  unit: RBX::SpatialFilter  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bc6d0
//
// 007bc6d0  83ec08               sub esp, 8
// 007bc6d3  56                   push esi
// 007bc6d4  8bf1                 mov esi, ecx
// 007bc6d6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007bc6d9  57                   push edi
// 007bc6da  85c9                 test ecx, ecx
// 007bc6dc  7504                 jne 0x7bc6e2
// 007bc6de  33c0                 xor eax, eax
// 007bc6e0  eb08                 jmp 0x7bc6ea
// 007bc6e2  8b4614               mov eax, dword ptr [esi + 0x14]
// 007bc6e5  2bc1                 sub eax, ecx
// 007bc6e7  c1f803               sar eax, 3
// 007bc6ea  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007bc6ed  8bd7                 mov edx, edi
// 007bc6ef  2bd1                 sub edx, ecx
// 007bc6f1  c1fa03               sar edx, 3
// 007bc6f4  3bd0                 cmp edx, eax
// 007bc6f6  7331                 jae 0x7bc729
// 007bc6f8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007bc6fc  c644240800           mov byte ptr [esp + 8], 0
// 007bc701  8b442408             mov eax, dword ptr [esp + 8]
// 007bc705  50                   push eax
// 007bc706  8b442418             mov eax, dword ptr [esp + 0x18]
// 007bc70a  51                   push ecx
// 007bc70b  8d5608               lea edx, [esi + 8]
// 007bc70e  52                   push edx
// 007bc70f  50                   push eax
// 007bc710  6a01                 push 1
// 007bc712  57                   push edi
// 007bc713  e8480ef1ff           call 0x6cd560
// 007bc718  83c418               add esp, 0x18
// 007bc71b  83c708               add edi, 8
// 007bc71e  897e10               mov dword ptr [esi + 0x10], edi
// 007bc721  5f                   pop edi
// 007bc722  5e                   pop esi
// 007bc723  83c408               add esp, 8
// 007bc726  c20400               ret 4
// 007bc729  3bcf                 cmp ecx, edi
// 007bc72b  7606                 jbe 0x7bc733
// 007bc72d  ff1560b79800         call dword ptr [0x98b760]
// 007bc733  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007bc737  8b06                 mov eax, dword ptr [esi]
// 007bc739  51                   push ecx
// 007bc73a  57                   push edi
// 007bc73b  50                   push eax
// 007bc73c  8d542414             lea edx, [esp + 0x14]
// 007bc740  52                   push edx
// 007bc741  8bce                 mov ecx, esi
// 007bc743  e8c8feffff           call 0x7bc610
// 007bc748  5f                   pop edi
// 007bc749  5e                   pop esi
// 007bc74a  83c408               add esp, 8
// 007bc74d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
