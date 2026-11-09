// from server: 100% by auto
// roc 2008-06 005b2f80  unit: RBX::VHat::?$FactoryProduct  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b2f80
//
// 005b2f80  55                   push ebp
// 005b2f81  8bec                 mov ebp, esp
// 005b2f83  6aff                 push -1
// 005b2f85  6871387d00           push 0x7d3871
// 005b2f8a  64a100000000         mov eax, dword ptr fs:[0]
// 005b2f90  50                   push eax
// 005b2f91  64892500000000       mov dword ptr fs:[0], esp
// 005b2f98  83ec0c               sub esp, 0xc
// 005b2f9b  53                   push ebx
// 005b2f9c  56                   push esi
// 005b2f9d  57                   push edi
// 005b2f9e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005b2fa1  6a30                 push 0x30
// 005b2fa3  e878d90e00           call 0x6a0920
// 005b2fa8  8bf0                 mov esi, eax
// 005b2faa  83c404               add esp, 4
// 005b2fad  8975ec               mov dword ptr [ebp - 0x14], esi
// 005b2fb0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005b2fb7  8975e8               mov dword ptr [ebp - 0x18], esi
// 005b2fba  c645fc01             mov byte ptr [ebp - 4], 1
// 005b2fbe  85f6                 test esi, esi
// 005b2fc0  7430                 je 0x5b2ff2
// 005b2fc2  8b4508               mov eax, dword ptr [ebp + 8]
// 005b2fc5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005b2fc8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005b2fcb  8906                 mov dword ptr [esi], eax
// 005b2fcd  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005b2fd0  894e04               mov dword ptr [esi + 4], ecx
// 005b2fd3  895608               mov dword ptr [esi + 8], edx
// 005b2fd6  8b08                 mov ecx, dword ptr [eax]
// 005b2fd8  83c004               add eax, 4
// 005b2fdb  894e0c               mov dword ptr [esi + 0xc], ecx
// 005b2fde  50                   push eax
// 005b2fdf  8d4e10               lea ecx, [esi + 0x10]
// 005b2fe2  ff155c248000         call dword ptr [0x80245c]
// 005b2fe8  8a5518               mov dl, byte ptr [ebp + 0x18]
// 005b2feb  88562c               mov byte ptr [esi + 0x2c], dl
// 005b2fee  c6462d00             mov byte ptr [esi + 0x2d], 0
// 005b2ff2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005b2ff5  5f                   pop edi
// 005b2ff6  8bc6                 mov eax, esi
// 005b2ff8  5e                   pop esi
// 005b2ff9  64890d00000000       mov dword ptr fs:[0], ecx
// 005b3000  5b                   pop ebx
// 005b3001  8be5                 mov esp, ebp
// 005b3003  5d                   pop ebp
// 005b3004  c21400               ret 0x14
// standard library map_int<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@D@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
