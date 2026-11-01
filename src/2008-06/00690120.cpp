// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00690120  unit: Ogre::RbxSceneManagerFactory  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00690120
//
// 00690120  55                   push ebp
// 00690121  8bec                 mov ebp, esp
// 00690123  6aff                 push -1
// 00690125  6811e37d00           push 0x7de311
// 0069012a  64a100000000         mov eax, dword ptr fs:[0]
// 00690130  50                   push eax
// 00690131  64892500000000       mov dword ptr fs:[0], esp
// 00690138  83ec0c               sub esp, 0xc
// 0069013b  53                   push ebx
// 0069013c  56                   push esi
// 0069013d  57                   push edi
// 0069013e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00690141  6a3c                 push 0x3c
// 00690143  e8d8070100           call 0x6a0920
// 00690148  8bf0                 mov esi, eax
// 0069014a  83c404               add esp, 4
// 0069014d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00690150  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00690157  8975e8               mov dword ptr [ebp - 0x18], esi
// 0069015a  c645fc01             mov byte ptr [ebp - 4], 1
// 0069015e  85f6                 test esi, esi
// 00690160  741b                 je 0x69017d
// 00690162  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00690165  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00690168  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0069016b  50                   push eax
// 0069016c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0069016f  51                   push ecx
// 00690170  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00690173  52                   push edx
// 00690174  50                   push eax
// 00690175  51                   push ecx
// 00690176  8bce                 mov ecx, esi
// 00690178  e893deffff           call 0x68e010
// 0069017d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00690180  5f                   pop edi
// 00690181  8bc6                 mov eax, esi
// 00690183  5e                   pop esi
// 00690184  64890d00000000       mov dword ptr fs:[0], ecx
// 0069018b  5b                   pop ebx
// 0069018c  8be5                 mov esp, ebp
// 0069018e  5d                   pop ebp
// 0069018f  c21400               ret 0x14
// standard library map_str<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
