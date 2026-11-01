// from server: 100% by auto
// roc 2009-12 004bf520  unit: Ogre::RbxSpatialHashedSceneNode  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bf520
//
// 004bf520  83ec08               sub esp, 8
// 004bf523  56                   push esi
// 004bf524  8bf1                 mov esi, ecx
// 004bf526  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004bf529  57                   push edi
// 004bf52a  85c9                 test ecx, ecx
// 004bf52c  7504                 jne 0x4bf532
// 004bf52e  33c0                 xor eax, eax
// 004bf530  eb08                 jmp 0x4bf53a
// 004bf532  8b4614               mov eax, dword ptr [esi + 0x14]
// 004bf535  2bc1                 sub eax, ecx
// 004bf537  c1f804               sar eax, 4
// 004bf53a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004bf53d  8bd7                 mov edx, edi
// 004bf53f  2bd1                 sub edx, ecx
// 004bf541  c1fa04               sar edx, 4
// 004bf544  3bd0                 cmp edx, eax
// 004bf546  7331                 jae 0x4bf579
// 004bf548  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004bf54c  c644240800           mov byte ptr [esp + 8], 0
// 004bf551  8b442408             mov eax, dword ptr [esp + 8]
// 004bf555  50                   push eax
// 004bf556  8b442418             mov eax, dword ptr [esp + 0x18]
// 004bf55a  51                   push ecx
// 004bf55b  8d5608               lea edx, [esi + 8]
// 004bf55e  52                   push edx
// 004bf55f  50                   push eax
// 004bf560  6a01                 push 1
// 004bf562  57                   push edi
// 004bf563  e8e8e9ffff           call 0x4bdf50
// 004bf568  83c418               add esp, 0x18
// 004bf56b  83c710               add edi, 0x10
// 004bf56e  897e10               mov dword ptr [esi + 0x10], edi
// 004bf571  5f                   pop edi
// 004bf572  5e                   pop esi
// 004bf573  83c408               add esp, 8
// 004bf576  c20400               ret 4
// 004bf579  3bcf                 cmp ecx, edi
// 004bf57b  7606                 jbe 0x4bf583
// 004bf57d  ff1560b79800         call dword ptr [0x98b760]
// 004bf583  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004bf587  8b06                 mov eax, dword ptr [esi]
// 004bf589  51                   push ecx
// 004bf58a  57                   push edi
// 004bf58b  50                   push eax
// 004bf58c  8d542414             lea edx, [esp + 0x14]
// 004bf590  52                   push edx
// 004bf591  8bce                 mov ecx, esi
// 004bf593  e8d8fbffff           call 0x4bf170
// 004bf598  5f                   pop edi
// 004bf599  5e                   pop esi
// 004bf59a  83c408               add esp, 8
// 004bf59d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
