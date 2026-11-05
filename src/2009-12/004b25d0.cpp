// from server: 100% by auto
// roc 2009-12 004b25d0  unit: Ogre::TextureCompositor  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b25d0
//
// 004b25d0  83ec08               sub esp, 8
// 004b25d3  56                   push esi
// 004b25d4  8bf1                 mov esi, ecx
// 004b25d6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004b25d9  57                   push edi
// 004b25da  85c9                 test ecx, ecx
// 004b25dc  7504                 jne 0x4b25e2
// 004b25de  33c0                 xor eax, eax
// 004b25e0  eb08                 jmp 0x4b25ea
// 004b25e2  8b4614               mov eax, dword ptr [esi + 0x14]
// 004b25e5  2bc1                 sub eax, ecx
// 004b25e7  c1f806               sar eax, 6
// 004b25ea  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004b25ed  8bd7                 mov edx, edi
// 004b25ef  2bd1                 sub edx, ecx
// 004b25f1  c1fa06               sar edx, 6
// 004b25f4  3bd0                 cmp edx, eax
// 004b25f6  7331                 jae 0x4b2629
// 004b25f8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b25fc  c644240800           mov byte ptr [esp + 8], 0
// 004b2601  8b442408             mov eax, dword ptr [esp + 8]
// 004b2605  50                   push eax
// 004b2606  8b442418             mov eax, dword ptr [esp + 0x18]
// 004b260a  51                   push ecx
// 004b260b  8d5608               lea edx, [esi + 8]
// 004b260e  52                   push edx
// 004b260f  50                   push eax
// 004b2610  6a01                 push 1
// 004b2612  57                   push edi
// 004b2613  e858e1ffff           call 0x4b0770
// 004b2618  83c418               add esp, 0x18
// 004b261b  83c740               add edi, 0x40
// 004b261e  897e10               mov dword ptr [esi + 0x10], edi
// 004b2621  5f                   pop edi
// 004b2622  5e                   pop esi
// 004b2623  83c408               add esp, 8
// 004b2626  c20400               ret 4
// 004b2629  3bcf                 cmp ecx, edi
// 004b262b  7606                 jbe 0x4b2633
// 004b262d  ff1560b79800         call dword ptr [0x98b760]
// 004b2633  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b2637  8b06                 mov eax, dword ptr [esi]
// 004b2639  51                   push ecx
// 004b263a  57                   push edi
// 004b263b  50                   push eax
// 004b263c  8d542414             lea edx, [esp + 0x14]
// 004b2640  52                   push edx
// 004b2641  8bce                 mov ecx, esi
// 004b2643  e8c8fdffff           call 0x4b2410
// 004b2648  5f                   pop edi
// 004b2649  5e                   pop esi
// 004b264a  83c408               add esp, 8
// 004b264d  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
