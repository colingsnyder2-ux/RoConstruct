// from server: 100% by auto
// roc 2009-06 00473d10  unit: Ogre::VRbxSky::?$SharedPtr  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00473d10
//
// 00473d10  55                   push ebp
// 00473d11  8bec                 mov ebp, esp
// 00473d13  6aff                 push -1
// 00473d15  68b13e8500           push 0x853eb1
// 00473d1a  64a100000000         mov eax, dword ptr fs:[0]
// 00473d20  50                   push eax
// 00473d21  64892500000000       mov dword ptr fs:[0], esp
// 00473d28  83ec0c               sub esp, 0xc
// 00473d2b  53                   push ebx
// 00473d2c  56                   push esi
// 00473d2d  57                   push edi
// 00473d2e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00473d31  6a30                 push 0x30
// 00473d33  e8004d2a00           call 0x718a38
// 00473d38  8bf0                 mov esi, eax
// 00473d3a  83c404               add esp, 4
// 00473d3d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00473d40  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00473d47  8975e8               mov dword ptr [ebp - 0x18], esi
// 00473d4a  c645fc01             mov byte ptr [ebp - 4], 1
// 00473d4e  85f6                 test esi, esi
// 00473d50  7430                 je 0x473d82
// 00473d52  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00473d55  8b4508               mov eax, dword ptr [ebp + 8]
// 00473d58  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00473d5b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 00473d5e  894e04               mov dword ptr [esi + 4], ecx
// 00473d61  8d7e0c               lea edi, [esi + 0xc]
// 00473d64  53                   push ebx
// 00473d65  8bcf                 mov ecx, edi
// 00473d67  8906                 mov dword ptr [esi], eax
// 00473d69  895608               mov dword ptr [esi + 8], edx
// 00473d6c  ff15b8e48900         call dword ptr [0x89e4b8]
// 00473d72  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 00473d75  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00473d78  89471c               mov dword ptr [edi + 0x1c], eax
// 00473d7b  884e2c               mov byte ptr [esi + 0x2c], cl
// 00473d7e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 00473d82  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00473d85  5f                   pop edi
// 00473d86  8bc6                 mov eax, esi
// 00473d88  5e                   pop esi
// 00473d89  64890d00000000       mov dword ptr fs:[0], ecx
// 00473d90  5b                   pop ebx
// 00473d91  8be5                 mov esp, ebp
// 00473d93  5d                   pop ebp
// 00473d94  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
