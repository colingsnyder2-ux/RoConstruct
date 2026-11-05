// from server: 100% by auto
// roc 2007-08 0056ad20  unit: ArchiveBinder  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056ad20
//
// 0056ad20  55                   push ebp
// 0056ad21  8bec                 mov ebp, esp
// 0056ad23  6aff                 push -1
// 0056ad25  68e1457500           push 0x7545e1
// 0056ad2a  64a100000000         mov eax, dword ptr fs:[0]
// 0056ad30  50                   push eax
// 0056ad31  64892500000000       mov dword ptr fs:[0], esp
// 0056ad38  83ec0c               sub esp, 0xc
// 0056ad3b  53                   push ebx
// 0056ad3c  56                   push esi
// 0056ad3d  57                   push edi
// 0056ad3e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0056ad41  6a34                 push 0x34
// 0056ad43  e8ae510c00           call 0x62fef6
// 0056ad48  8bf0                 mov esi, eax
// 0056ad4a  83c404               add esp, 4
// 0056ad4d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0056ad50  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0056ad57  8975e8               mov dword ptr [ebp - 0x18], esi
// 0056ad5a  85f6                 test esi, esi
// 0056ad5c  c645fc01             mov byte ptr [ebp - 4], 1
// 0056ad60  741b                 je 0x56ad7d
// 0056ad62  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0056ad65  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0056ad68  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0056ad6b  50                   push eax
// 0056ad6c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0056ad6f  51                   push ecx
// 0056ad70  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0056ad73  52                   push edx
// 0056ad74  50                   push eax
// 0056ad75  51                   push ecx
// 0056ad76  8bce                 mov ecx, esi
// 0056ad78  e843ffffff           call 0x56acc0
// 0056ad7d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0056ad80  5f                   pop edi
// 0056ad81  8bc6                 mov eax, esi
// 0056ad83  5e                   pop esi
// 0056ad84  64890d00000000       mov dword ptr fs:[0], ecx
// 0056ad8b  5b                   pop ebx
// 0056ad8c  8be5                 mov esp, ebp
// 0056ad8e  5d                   pop ebp
// 0056ad8f  c21400               ret 0x14
// standard library map_str<podc6> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<podc6>
struct E { char v[6]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
