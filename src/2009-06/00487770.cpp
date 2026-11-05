// from server: 100% by auto
// roc 2009-06 00487770  unit: Ogre::RbxMeshPartAdapter  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00487770
//
// 00487770  83ec08               sub esp, 8
// 00487773  56                   push esi
// 00487774  8bf1                 mov esi, ecx
// 00487776  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00487779  57                   push edi
// 0048777a  85c9                 test ecx, ecx
// 0048777c  7504                 jne 0x487782
// 0048777e  33c0                 xor eax, eax
// 00487780  eb08                 jmp 0x48778a
// 00487782  8b4614               mov eax, dword ptr [esi + 0x14]
// 00487785  2bc1                 sub eax, ecx
// 00487787  c1f803               sar eax, 3
// 0048778a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048778d  8bd7                 mov edx, edi
// 0048778f  2bd1                 sub edx, ecx
// 00487791  c1fa03               sar edx, 3
// 00487794  3bd0                 cmp edx, eax
// 00487796  7331                 jae 0x4877c9
// 00487798  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048779c  c644240800           mov byte ptr [esp + 8], 0
// 004877a1  8b442408             mov eax, dword ptr [esp + 8]
// 004877a5  50                   push eax
// 004877a6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004877aa  51                   push ecx
// 004877ab  8d5608               lea edx, [esi + 8]
// 004877ae  52                   push edx
// 004877af  50                   push eax
// 004877b0  6a01                 push 1
// 004877b2  57                   push edi
// 004877b3  e878ecffff           call 0x486430
// 004877b8  83c418               add esp, 0x18
// 004877bb  83c708               add edi, 8
// 004877be  897e10               mov dword ptr [esi + 0x10], edi
// 004877c1  5f                   pop edi
// 004877c2  5e                   pop esi
// 004877c3  83c408               add esp, 8
// 004877c6  c20400               ret 4
// 004877c9  3bcf                 cmp ecx, edi
// 004877cb  7606                 jbe 0x4877d3
// 004877cd  ff15ace98900         call dword ptr [0x89e9ac]
// 004877d3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004877d7  8b06                 mov eax, dword ptr [esi]
// 004877d9  51                   push ecx
// 004877da  57                   push edi
// 004877db  50                   push eax
// 004877dc  8d542414             lea edx, [esp + 0x14]
// 004877e0  52                   push edx
// 004877e1  8bce                 mov ecx, esi
// 004877e3  e878fcffff           call 0x487460
// 004877e8  5f                   pop edi
// 004877e9  5e                   pop esi
// 004877ea  83c408               add esp, 8
// 004877ed  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
