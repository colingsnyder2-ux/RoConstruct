// from server: 100% by auto
// roc 2011-06 0064bb10  unit: RBX::GameBasicSettings  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0064bb10
//
// 0064bb10  55                   push ebp
// 0064bb11  8bec                 mov ebp, esp
// 0064bb13  6aff                 push -1
// 0064bb15  6821c49e00           push 0x9ec421
// 0064bb1a  64a100000000         mov eax, dword ptr fs:[0]
// 0064bb20  50                   push eax
// 0064bb21  64892500000000       mov dword ptr fs:[0], esp
// 0064bb28  83ec0c               sub esp, 0xc
// 0064bb2b  53                   push ebx
// 0064bb2c  56                   push esi
// 0064bb2d  57                   push edi
// 0064bb2e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0064bb31  6a30                 push 0x30
// 0064bb33  e826e51b00           call 0x80a05e
// 0064bb38  8bf0                 mov esi, eax
// 0064bb3a  83c404               add esp, 4
// 0064bb3d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0064bb40  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0064bb47  8975e8               mov dword ptr [ebp - 0x18], esi
// 0064bb4a  c645fc01             mov byte ptr [ebp - 4], 1
// 0064bb4e  85f6                 test esi, esi
// 0064bb50  7430                 je 0x64bb82
// 0064bb52  8b4508               mov eax, dword ptr [ebp + 8]
// 0064bb55  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0064bb58  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0064bb5b  8906                 mov dword ptr [esi], eax
// 0064bb5d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0064bb60  894e04               mov dword ptr [esi + 4], ecx
// 0064bb63  895608               mov dword ptr [esi + 8], edx
// 0064bb66  8b08                 mov ecx, dword ptr [eax]
// 0064bb68  83c004               add eax, 4
// 0064bb6b  894e0c               mov dword ptr [esi + 0xc], ecx
// 0064bb6e  50                   push eax
// 0064bb6f  8d4e10               lea ecx, [esi + 0x10]
// 0064bb72  ff15c804a400         call dword ptr [0xa404c8]
// 0064bb78  8a5518               mov dl, byte ptr [ebp + 0x18]
// 0064bb7b  88562c               mov byte ptr [esi + 0x2c], dl
// 0064bb7e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 0064bb82  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0064bb85  5f                   pop edi
// 0064bb86  8bc6                 mov eax, esi
// 0064bb88  5e                   pop esi
// 0064bb89  64890d00000000       mov dword ptr fs:[0], ecx
// 0064bb90  5b                   pop ebx
// 0064bb91  8be5                 mov esp, ebp
// 0064bb93  5d                   pop ebp
// 0064bb94  c21400               ret 0x14
// standard library map_int<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@D@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
