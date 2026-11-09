// from server: 100% by auto
// roc 2008-06 00697c10  unit: Ogre::RbxSceneManager  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00697c10
//
// 00697c10  53                   push ebx
// 00697c11  55                   push ebp
// 00697c12  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00697c18  56                   push esi
// 00697c19  57                   push edi
// 00697c1a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00697c1e  8bf1                 mov esi, ecx
// 00697c20  c70700000000         mov dword ptr [edi], 0
// 00697c26  85f6                 test esi, esi
// 00697c28  740e                 je 0x697c38
// 00697c2a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00697c2e  39460c               cmp dword ptr [esi + 0xc], eax
// 00697c31  7705                 ja 0x697c38
// 00697c33  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00697c36  7606                 jbe 0x697c3e
// 00697c38  ffd5                 call ebp
// 00697c3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00697c3e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00697c42  8b0e                 mov ecx, dword ptr [esi]
// 00697c44  890f                 mov dword ptr [edi], ecx
// 00697c46  894704               mov dword ptr [edi + 4], eax
// 00697c49  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00697c4c  7705                 ja 0x697c53
// 00697c4e  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00697c51  7606                 jbe 0x697c59
// 00697c53  ffd5                 call ebp
// 00697c55  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00697c59  8b07                 mov eax, dword ptr [edi]
// 00697c5b  8b0e                 mov ecx, dword ptr [esi]
// 00697c5d  85c0                 test eax, eax
// 00697c5f  7404                 je 0x697c65
// 00697c61  3bc1                 cmp eax, ecx
// 00697c63  7402                 je 0x697c67
// 00697c65  ffd5                 call ebp
// 00697c67  8b4f04               mov ecx, dword ptr [edi + 4]
// 00697c6a  3bcb                 cmp ecx, ebx
// 00697c6c  7425                 je 0x697c93
// 00697c6e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00697c71  c644241400           mov byte ptr [esp + 0x14], 0
// 00697c76  8b542414             mov edx, dword ptr [esp + 0x14]
// 00697c7a  52                   push edx
// 00697c7b  8b542418             mov edx, dword ptr [esp + 0x18]
// 00697c7f  52                   push edx
// 00697c80  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00697c84  52                   push edx
// 00697c85  51                   push ecx
// 00697c86  50                   push eax
// 00697c87  53                   push ebx
// 00697c88  e8c364ffff           call 0x68e150
// 00697c8d  83c418               add esp, 0x18
// 00697c90  894610               mov dword ptr [esi + 0x10], eax
// 00697c93  8bc7                 mov eax, edi
// 00697c95  5f                   pop edi
// 00697c96  5e                   pop esi
// 00697c97  5d                   pop ebp
// 00697c98  5b                   pop ebx
// 00697c99  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
