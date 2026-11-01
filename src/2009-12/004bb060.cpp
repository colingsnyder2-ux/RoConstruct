// from server: 100% by auto
// roc 2009-12 004bb060  unit: Ogre::RbxCullableSceneNode  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bb060
//
// 004bb060  53                   push ebx
// 004bb061  55                   push ebp
// 004bb062  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004bb068  56                   push esi
// 004bb069  57                   push edi
// 004bb06a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004bb06e  8bf1                 mov esi, ecx
// 004bb070  c70700000000         mov dword ptr [edi], 0
// 004bb076  85f6                 test esi, esi
// 004bb078  740e                 je 0x4bb088
// 004bb07a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004bb07e  39460c               cmp dword ptr [esi + 0xc], eax
// 004bb081  7705                 ja 0x4bb088
// 004bb083  3b4610               cmp eax, dword ptr [esi + 0x10]
// 004bb086  7606                 jbe 0x4bb08e
// 004bb088  ffd5                 call ebp
// 004bb08a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004bb08e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004bb092  8b0e                 mov ecx, dword ptr [esi]
// 004bb094  890f                 mov dword ptr [edi], ecx
// 004bb096  894704               mov dword ptr [edi + 4], eax
// 004bb099  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004bb09c  7705                 ja 0x4bb0a3
// 004bb09e  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004bb0a1  7606                 jbe 0x4bb0a9
// 004bb0a3  ffd5                 call ebp
// 004bb0a5  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004bb0a9  8b07                 mov eax, dword ptr [edi]
// 004bb0ab  8b0e                 mov ecx, dword ptr [esi]
// 004bb0ad  85c0                 test eax, eax
// 004bb0af  7404                 je 0x4bb0b5
// 004bb0b1  3bc1                 cmp eax, ecx
// 004bb0b3  7402                 je 0x4bb0b7
// 004bb0b5  ffd5                 call ebp
// 004bb0b7  8b4f04               mov ecx, dword ptr [edi + 4]
// 004bb0ba  3bcb                 cmp ecx, ebx
// 004bb0bc  7425                 je 0x4bb0e3
// 004bb0be  8b4610               mov eax, dword ptr [esi + 0x10]
// 004bb0c1  c644241400           mov byte ptr [esp + 0x14], 0
// 004bb0c6  8b542414             mov edx, dword ptr [esp + 0x14]
// 004bb0ca  52                   push edx
// 004bb0cb  8b542418             mov edx, dword ptr [esp + 0x18]
// 004bb0cf  52                   push edx
// 004bb0d0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004bb0d4  52                   push edx
// 004bb0d5  51                   push ecx
// 004bb0d6  50                   push eax
// 004bb0d7  53                   push ebx
// 004bb0d8  e853ecffff           call 0x4b9d30
// 004bb0dd  83c418               add esp, 0x18
// 004bb0e0  894610               mov dword ptr [esi + 0x10], eax
// 004bb0e3  8bc7                 mov eax, edi
// 004bb0e5  5f                   pop edi
// 004bb0e6  5e                   pop esi
// 004bb0e7  5d                   pop ebp
// 004bb0e8  5b                   pop ebx
// 004bb0e9  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
