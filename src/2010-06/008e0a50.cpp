// from server: 100% by auto
// roc 2010-06 008e0a50  unit: Ogre::RbxMaterialAdapter  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e0a50
//
// 008e0a50  53                   push ebx
// 008e0a51  55                   push ebp
// 008e0a52  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008e0a58  56                   push esi
// 008e0a59  57                   push edi
// 008e0a5a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008e0a5e  8bf1                 mov esi, ecx
// 008e0a60  c70700000000         mov dword ptr [edi], 0
// 008e0a66  85f6                 test esi, esi
// 008e0a68  740e                 je 0x8e0a78
// 008e0a6a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e0a6e  39460c               cmp dword ptr [esi + 0xc], eax
// 008e0a71  7705                 ja 0x8e0a78
// 008e0a73  3b4610               cmp eax, dword ptr [esi + 0x10]
// 008e0a76  7606                 jbe 0x8e0a7e
// 008e0a78  ffd5                 call ebp
// 008e0a7a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e0a7e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008e0a82  8b0e                 mov ecx, dword ptr [esi]
// 008e0a84  890f                 mov dword ptr [edi], ecx
// 008e0a86  894704               mov dword ptr [edi + 4], eax
// 008e0a89  395e0c               cmp dword ptr [esi + 0xc], ebx
// 008e0a8c  7705                 ja 0x8e0a93
// 008e0a8e  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008e0a91  7606                 jbe 0x8e0a99
// 008e0a93  ffd5                 call ebp
// 008e0a95  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008e0a99  8b07                 mov eax, dword ptr [edi]
// 008e0a9b  8b0e                 mov ecx, dword ptr [esi]
// 008e0a9d  85c0                 test eax, eax
// 008e0a9f  7404                 je 0x8e0aa5
// 008e0aa1  3bc1                 cmp eax, ecx
// 008e0aa3  7402                 je 0x8e0aa7
// 008e0aa5  ffd5                 call ebp
// 008e0aa7  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e0aaa  3bcb                 cmp ecx, ebx
// 008e0aac  7425                 je 0x8e0ad3
// 008e0aae  8b4610               mov eax, dword ptr [esi + 0x10]
// 008e0ab1  c644241400           mov byte ptr [esp + 0x14], 0
// 008e0ab6  8b542414             mov edx, dword ptr [esp + 0x14]
// 008e0aba  52                   push edx
// 008e0abb  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e0abf  52                   push edx
// 008e0ac0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008e0ac4  52                   push edx
// 008e0ac5  51                   push ecx
// 008e0ac6  50                   push eax
// 008e0ac7  53                   push ebx
// 008e0ac8  e823ebffff           call 0x8df5f0
// 008e0acd  83c418               add esp, 0x18
// 008e0ad0  894610               mov dword ptr [esi + 0x10], eax
// 008e0ad3  8bc7                 mov eax, edi
// 008e0ad5  5f                   pop edi
// 008e0ad6  5e                   pop esi
// 008e0ad7  5d                   pop ebp
// 008e0ad8  5b                   pop ebx
// 008e0ad9  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
