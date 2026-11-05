// from server: 100% by auto
// roc 2009-12 00490f20  unit: Ogre::RbxEntity  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00490f20
//
// 00490f20  53                   push ebx
// 00490f21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00490f25  55                   push ebp
// 00490f26  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00490f2c  56                   push esi
// 00490f2d  8bf1                 mov esi, ecx
// 00490f2f  57                   push edi
// 00490f30  c70300000000         mov dword ptr [ebx], 0
// 00490f36  85f6                 test esi, esi
// 00490f38  740e                 je 0x490f48
// 00490f3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00490f3e  39460c               cmp dword ptr [esi + 0xc], eax
// 00490f41  7705                 ja 0x490f48
// 00490f43  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00490f46  7606                 jbe 0x490f4e
// 00490f48  ffd5                 call ebp
// 00490f4a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00490f4e  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00490f52  8b0e                 mov ecx, dword ptr [esi]
// 00490f54  890b                 mov dword ptr [ebx], ecx
// 00490f56  894304               mov dword ptr [ebx + 4], eax
// 00490f59  397e0c               cmp dword ptr [esi + 0xc], edi
// 00490f5c  7705                 ja 0x490f63
// 00490f5e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00490f61  7606                 jbe 0x490f69
// 00490f63  ffd5                 call ebp
// 00490f65  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00490f69  8b03                 mov eax, dword ptr [ebx]
// 00490f6b  8b0e                 mov ecx, dword ptr [esi]
// 00490f6d  85c0                 test eax, eax
// 00490f6f  7404                 je 0x490f75
// 00490f71  3bc1                 cmp eax, ecx
// 00490f73  7402                 je 0x490f77
// 00490f75  ffd5                 call ebp
// 00490f77  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00490f7a  3bcf                 cmp ecx, edi
// 00490f7c  741c                 je 0x490f9a
// 00490f7e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00490f81  2bc7                 sub eax, edi
// 00490f83  8d2c08               lea ebp, [eax + ecx]
// 00490f86  85c0                 test eax, eax
// 00490f88  7e0d                 jle 0x490f97
// 00490f8a  50                   push eax
// 00490f8b  57                   push edi
// 00490f8c  50                   push eax
// 00490f8d  51                   push ecx
// 00490f8e  ff15c0b79800         call dword ptr [0x98b7c0]
// 00490f94  83c410               add esp, 0x10
// 00490f97  896e10               mov dword ptr [esi + 0x10], ebp
// 00490f9a  5f                   pop edi
// 00490f9b  5e                   pop esi
// 00490f9c  5d                   pop ebp
// 00490f9d  8bc3                 mov eax, ebx
// 00490f9f  5b                   pop ebx
// 00490fa0  c21400               ret 0x14
// standard library vector<char> (function ?erase@?$vector@DV?$allocator@D@std@@@std@@QAE?AV?$_Vector_iterator@DV?$allocator@D@std@@@2@V?$_Vector_const_iterator@DV?$allocator@D@std@@@2@0@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
