// from server: 100% by auto
// roc 2010-06 006228e0  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006228e0
//
// 006228e0  55                   push ebp
// 006228e1  8bec                 mov ebp, esp
// 006228e3  6aff                 push -1
// 006228e5  6881af9900           push 0x99af81
// 006228ea  64a100000000         mov eax, dword ptr fs:[0]
// 006228f0  50                   push eax
// 006228f1  64892500000000       mov dword ptr fs:[0], esp
// 006228f8  83ec0c               sub esp, 0xc
// 006228fb  53                   push ebx
// 006228fc  56                   push esi
// 006228fd  57                   push edi
// 006228fe  8965f0               mov dword ptr [ebp - 0x10], esp
// 00622901  6a38                 push 0x38
// 00622903  e898501800           call 0x7a79a0
// 00622908  8bf0                 mov esi, eax
// 0062290a  83c404               add esp, 4
// 0062290d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00622910  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00622917  8975e8               mov dword ptr [ebp - 0x18], esi
// 0062291a  c645fc01             mov byte ptr [ebp - 4], 1
// 0062291e  85f6                 test esi, esi
// 00622920  741b                 je 0x62293d
// 00622922  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00622925  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00622928  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0062292b  50                   push eax
// 0062292c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0062292f  51                   push ecx
// 00622930  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00622933  52                   push edx
// 00622934  50                   push eax
// 00622935  51                   push ecx
// 00622936  8bce                 mov ecx, esi
// 00622938  e823f8ffff           call 0x622160
// 0062293d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00622940  5f                   pop edi
// 00622941  8bc6                 mov eax, esi
// 00622943  5e                   pop esi
// 00622944  64890d00000000       mov dword ptr fs:[0], ecx
// 0062294b  5b                   pop ebx
// 0062294c  8be5                 mov esp, ebp
// 0062294e  5d                   pop ebp
// 0062294f  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
