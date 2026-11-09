// from server: 100% by auto
// roc 2010-06 008d2f20  unit: Ogre::VisualEngine  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d2f20
//
// 008d2f20  53                   push ebx
// 008d2f21  55                   push ebp
// 008d2f22  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008d2f28  56                   push esi
// 008d2f29  57                   push edi
// 008d2f2a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008d2f2e  8bf1                 mov esi, ecx
// 008d2f30  c70700000000         mov dword ptr [edi], 0
// 008d2f36  85f6                 test esi, esi
// 008d2f38  740e                 je 0x8d2f48
// 008d2f3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d2f3e  39460c               cmp dword ptr [esi + 0xc], eax
// 008d2f41  7705                 ja 0x8d2f48
// 008d2f43  3b4610               cmp eax, dword ptr [esi + 0x10]
// 008d2f46  7606                 jbe 0x8d2f4e
// 008d2f48  ffd5                 call ebp
// 008d2f4a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d2f4e  8b0e                 mov ecx, dword ptr [esi]
// 008d2f50  894704               mov dword ptr [edi + 4], eax
// 008d2f53  8b442424             mov eax, dword ptr [esp + 0x24]
// 008d2f57  890f                 mov dword ptr [edi], ecx
// 008d2f59  39460c               cmp dword ptr [esi + 0xc], eax
// 008d2f5c  7705                 ja 0x8d2f63
// 008d2f5e  3b4610               cmp eax, dword ptr [esi + 0x10]
// 008d2f61  7606                 jbe 0x8d2f69
// 008d2f63  ffd5                 call ebp
// 008d2f65  8b442424             mov eax, dword ptr [esp + 0x24]
// 008d2f69  8b0e                 mov ecx, dword ptr [esi]
// 008d2f6b  8bd8                 mov ebx, eax
// 008d2f6d  8b07                 mov eax, dword ptr [edi]
// 008d2f6f  85c0                 test eax, eax
// 008d2f71  7404                 je 0x8d2f77
// 008d2f73  3bc1                 cmp eax, ecx
// 008d2f75  7402                 je 0x8d2f79
// 008d2f77  ffd5                 call ebp
// 008d2f79  8b4704               mov eax, dword ptr [edi + 4]
// 008d2f7c  3bc3                 cmp eax, ebx
// 008d2f7e  7411                 je 0x8d2f91
// 008d2f80  8b5610               mov edx, dword ptr [esi + 0x10]
// 008d2f83  50                   push eax
// 008d2f84  52                   push edx
// 008d2f85  53                   push ebx
// 008d2f86  e875fdffff           call 0x8d2d00
// 008d2f8b  83c40c               add esp, 0xc
// 008d2f8e  894610               mov dword ptr [esi + 0x10], eax
// 008d2f91  8bc7                 mov eax, edi
// 008d2f93  5f                   pop edi
// 008d2f94  5e                   pop esi
// 008d2f95  5d                   pop ebp
// 008d2f96  5b                   pop ebx
// 008d2f97  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
