// from server: 100% by auto
// roc 2010-06 008d2ea0  unit: Ogre::VisualEngine  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d2ea0
//
// 008d2ea0  53                   push ebx
// 008d2ea1  55                   push ebp
// 008d2ea2  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008d2ea8  56                   push esi
// 008d2ea9  57                   push edi
// 008d2eaa  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008d2eae  8bf1                 mov esi, ecx
// 008d2eb0  c70700000000         mov dword ptr [edi], 0
// 008d2eb6  85f6                 test esi, esi
// 008d2eb8  740e                 je 0x8d2ec8
// 008d2eba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d2ebe  39460c               cmp dword ptr [esi + 0xc], eax
// 008d2ec1  7705                 ja 0x8d2ec8
// 008d2ec3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 008d2ec6  7606                 jbe 0x8d2ece
// 008d2ec8  ffd5                 call ebp
// 008d2eca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d2ece  8b0e                 mov ecx, dword ptr [esi]
// 008d2ed0  894704               mov dword ptr [edi + 4], eax
// 008d2ed3  8b442424             mov eax, dword ptr [esp + 0x24]
// 008d2ed7  890f                 mov dword ptr [edi], ecx
// 008d2ed9  39460c               cmp dword ptr [esi + 0xc], eax
// 008d2edc  7705                 ja 0x8d2ee3
// 008d2ede  3b4610               cmp eax, dword ptr [esi + 0x10]
// 008d2ee1  7606                 jbe 0x8d2ee9
// 008d2ee3  ffd5                 call ebp
// 008d2ee5  8b442424             mov eax, dword ptr [esp + 0x24]
// 008d2ee9  8b0e                 mov ecx, dword ptr [esi]
// 008d2eeb  8bd8                 mov ebx, eax
// 008d2eed  8b07                 mov eax, dword ptr [edi]
// 008d2eef  85c0                 test eax, eax
// 008d2ef1  7404                 je 0x8d2ef7
// 008d2ef3  3bc1                 cmp eax, ecx
// 008d2ef5  7402                 je 0x8d2ef9
// 008d2ef7  ffd5                 call ebp
// 008d2ef9  8b4704               mov eax, dword ptr [edi + 4]
// 008d2efc  3bc3                 cmp eax, ebx
// 008d2efe  7411                 je 0x8d2f11
// 008d2f00  8b5610               mov edx, dword ptr [esi + 0x10]
// 008d2f03  50                   push eax
// 008d2f04  52                   push edx
// 008d2f05  53                   push ebx
// 008d2f06  e8a5fdffff           call 0x8d2cb0
// 008d2f0b  83c40c               add esp, 0xc
// 008d2f0e  894610               mov dword ptr [esi + 0x10], eax
// 008d2f11  8bc7                 mov eax, edi
// 008d2f13  5f                   pop edi
// 008d2f14  5e                   pop esi
// 008d2f15  5d                   pop ebp
// 008d2f16  5b                   pop ebx
// 008d2f17  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
