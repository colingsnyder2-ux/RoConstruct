// from server: 100% by auto
// roc 2012-06 005cb1d0  unit: Ogre::istreamDataStream  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005cb1d0
//
// 005cb1d0  55                   push ebp
// 005cb1d1  8bec                 mov ebp, esp
// 005cb1d3  6aff                 push -1
// 005cb1d5  683130ab00           push 0xab3031
// 005cb1da  64a100000000         mov eax, dword ptr fs:[0]
// 005cb1e0  50                   push eax
// 005cb1e1  64892500000000       mov dword ptr fs:[0], esp
// 005cb1e8  83ec0c               sub esp, 0xc
// 005cb1eb  53                   push ebx
// 005cb1ec  56                   push esi
// 005cb1ed  57                   push edi
// 005cb1ee  8965f0               mov dword ptr [ebp - 0x10], esp
// 005cb1f1  6a30                 push 0x30
// 005cb1f3  e8226f3b00           call 0x98211a
// 005cb1f8  8bf0                 mov esi, eax
// 005cb1fa  83c404               add esp, 4
// 005cb1fd  8975ec               mov dword ptr [ebp - 0x14], esi
// 005cb200  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005cb207  8975e8               mov dword ptr [ebp - 0x18], esi
// 005cb20a  c645fc01             mov byte ptr [ebp - 4], 1
// 005cb20e  85f6                 test esi, esi
// 005cb210  7430                 je 0x5cb242
// 005cb212  8b4508               mov eax, dword ptr [ebp + 8]
// 005cb215  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005cb218  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005cb21b  8906                 mov dword ptr [esi], eax
// 005cb21d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005cb220  894e04               mov dword ptr [esi + 4], ecx
// 005cb223  895608               mov dword ptr [esi + 8], edx
// 005cb226  8b08                 mov ecx, dword ptr [eax]
// 005cb228  83c004               add eax, 4
// 005cb22b  894e0c               mov dword ptr [esi + 0xc], ecx
// 005cb22e  50                   push eax
// 005cb22f  8d4e10               lea ecx, [esi + 0x10]
// 005cb232  ff154426b200         call dword ptr [0xb22644]
// 005cb238  8a5518               mov dl, byte ptr [ebp + 0x18]
// 005cb23b  88562c               mov byte ptr [esi + 0x2c], dl
// 005cb23e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 005cb242  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005cb245  5f                   pop edi
// 005cb246  8bc6                 mov eax, esi
// 005cb248  5e                   pop esi
// 005cb249  64890d00000000       mov dword ptr fs:[0], ecx
// 005cb250  5b                   pop ebx
// 005cb251  8be5                 mov esp, ebp
// 005cb253  5d                   pop ebp
// 005cb254  c21400               ret 0x14
// standard library map_int<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@D@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
