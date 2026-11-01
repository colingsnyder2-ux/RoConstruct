// from server: 100% by auto
// roc 2009-12 004834c0  unit: RBX::AdornRbxGfx  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004834c0
//
// 004834c0  83ec08               sub esp, 8
// 004834c3  56                   push esi
// 004834c4  8bf1                 mov esi, ecx
// 004834c6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004834c9  57                   push edi
// 004834ca  85c9                 test ecx, ecx
// 004834cc  7504                 jne 0x4834d2
// 004834ce  33c0                 xor eax, eax
// 004834d0  eb08                 jmp 0x4834da
// 004834d2  8b4614               mov eax, dword ptr [esi + 0x14]
// 004834d5  2bc1                 sub eax, ecx
// 004834d7  c1f803               sar eax, 3
// 004834da  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004834dd  8bd7                 mov edx, edi
// 004834df  2bd1                 sub edx, ecx
// 004834e1  c1fa03               sar edx, 3
// 004834e4  3bd0                 cmp edx, eax
// 004834e6  7331                 jae 0x483519
// 004834e8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004834ec  c644240800           mov byte ptr [esp + 8], 0
// 004834f1  8b442408             mov eax, dword ptr [esp + 8]
// 004834f5  50                   push eax
// 004834f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004834fa  51                   push ecx
// 004834fb  8d5608               lea edx, [esi + 8]
// 004834fe  52                   push edx
// 004834ff  50                   push eax
// 00483500  6a01                 push 1
// 00483502  57                   push edi
// 00483503  e8f8c0ffff           call 0x47f600
// 00483508  83c418               add esp, 0x18
// 0048350b  83c708               add edi, 8
// 0048350e  897e10               mov dword ptr [esi + 0x10], edi
// 00483511  5f                   pop edi
// 00483512  5e                   pop esi
// 00483513  83c408               add esp, 8
// 00483516  c20400               ret 4
// 00483519  3bcf                 cmp ecx, edi
// 0048351b  7606                 jbe 0x483523
// 0048351d  ff1560b79800         call dword ptr [0x98b760]
// 00483523  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00483527  8b06                 mov eax, dword ptr [esi]
// 00483529  51                   push ecx
// 0048352a  57                   push edi
// 0048352b  50                   push eax
// 0048352c  8d542414             lea edx, [esp + 0x14]
// 00483530  52                   push edx
// 00483531  8bce                 mov ecx, esi
// 00483533  e888dcffff           call 0x4811c0
// 00483538  5f                   pop edi
// 00483539  5e                   pop esi
// 0048353a  83c408               add esp, 8
// 0048353d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
