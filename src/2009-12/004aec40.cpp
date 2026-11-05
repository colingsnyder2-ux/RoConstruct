// from server: 100% by auto
// roc 2009-12 004aec40  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aec40
//
// 004aec40  53                   push ebx
// 004aec41  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004aec45  55                   push ebp
// 004aec46  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004aec4c  56                   push esi
// 004aec4d  8bf1                 mov esi, ecx
// 004aec4f  57                   push edi
// 004aec50  c70300000000         mov dword ptr [ebx], 0
// 004aec56  85f6                 test esi, esi
// 004aec58  740e                 je 0x4aec68
// 004aec5a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aec5e  39460c               cmp dword ptr [esi + 0xc], eax
// 004aec61  7705                 ja 0x4aec68
// 004aec63  3b4610               cmp eax, dword ptr [esi + 0x10]
// 004aec66  7606                 jbe 0x4aec6e
// 004aec68  ffd5                 call ebp
// 004aec6a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aec6e  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004aec72  8b0e                 mov ecx, dword ptr [esi]
// 004aec74  890b                 mov dword ptr [ebx], ecx
// 004aec76  894304               mov dword ptr [ebx + 4], eax
// 004aec79  397e0c               cmp dword ptr [esi + 0xc], edi
// 004aec7c  7705                 ja 0x4aec83
// 004aec7e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004aec81  7606                 jbe 0x4aec89
// 004aec83  ffd5                 call ebp
// 004aec85  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004aec89  8b03                 mov eax, dword ptr [ebx]
// 004aec8b  8b0e                 mov ecx, dword ptr [esi]
// 004aec8d  85c0                 test eax, eax
// 004aec8f  7404                 je 0x4aec95
// 004aec91  3bc1                 cmp eax, ecx
// 004aec93  7402                 je 0x4aec97
// 004aec95  ffd5                 call ebp
// 004aec97  8b5304               mov edx, dword ptr [ebx + 4]
// 004aec9a  3bd7                 cmp edx, edi
// 004aec9c  7426                 je 0x4aecc4
// 004aec9e  8b4610               mov eax, dword ptr [esi + 0x10]
// 004aeca1  2bc7                 sub eax, edi
// 004aeca3  c1f802               sar eax, 2
// 004aeca6  8d0c8500000000       lea ecx, [eax*4]
// 004aecad  8d2c11               lea ebp, [ecx + edx]
// 004aecb0  85c0                 test eax, eax
// 004aecb2  7e0d                 jle 0x4aecc1
// 004aecb4  51                   push ecx
// 004aecb5  57                   push edi
// 004aecb6  51                   push ecx
// 004aecb7  52                   push edx
// 004aecb8  ff15c0b79800         call dword ptr [0x98b7c0]
// 004aecbe  83c410               add esp, 0x10
// 004aecc1  896e10               mov dword ptr [esi + 0x10], ebp
// 004aecc4  5f                   pop edi
// 004aecc5  5e                   pop esi
// 004aecc6  5d                   pop ebp
// 004aecc7  8bc3                 mov eax, ebx
// 004aecc9  5b                   pop ebx
// 004aecca  c21400               ret 0x14
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
