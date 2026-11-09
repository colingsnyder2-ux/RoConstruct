// from server: 100% by auto
// roc 2011-06 007cc6e0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007cc6e0
//
// 007cc6e0  55                   push ebp
// 007cc6e1  8bec                 mov ebp, esp
// 007cc6e3  6aff                 push -1
// 007cc6e5  68f1fb9f00           push 0x9ffbf1
// 007cc6ea  64a100000000         mov eax, dword ptr fs:[0]
// 007cc6f0  50                   push eax
// 007cc6f1  64892500000000       mov dword ptr fs:[0], esp
// 007cc6f8  83ec0c               sub esp, 0xc
// 007cc6fb  53                   push ebx
// 007cc6fc  56                   push esi
// 007cc6fd  57                   push edi
// 007cc6fe  8965f0               mov dword ptr [ebp - 0x10], esp
// 007cc701  6a40                 push 0x40
// 007cc703  e856d90300           call 0x80a05e
// 007cc708  8bf0                 mov esi, eax
// 007cc70a  83c404               add esp, 4
// 007cc70d  8975ec               mov dword ptr [ebp - 0x14], esi
// 007cc710  c745fc00000000       mov dword ptr [ebp - 4], 0
// 007cc717  8975e8               mov dword ptr [ebp - 0x18], esi
// 007cc71a  c645fc01             mov byte ptr [ebp - 4], 1
// 007cc71e  85f6                 test esi, esi
// 007cc720  741b                 je 0x7cc73d
// 007cc722  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007cc725  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 007cc728  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007cc72b  50                   push eax
// 007cc72c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007cc72f  51                   push ecx
// 007cc730  8b4d08               mov ecx, dword ptr [ebp + 8]
// 007cc733  52                   push edx
// 007cc734  50                   push eax
// 007cc735  51                   push ecx
// 007cc736  8bce                 mov ecx, esi
// 007cc738  e813feffff           call 0x7cc550
// 007cc73d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 007cc740  5f                   pop edi
// 007cc741  8bc6                 mov eax, esi
// 007cc743  5e                   pop esi
// 007cc744  64890d00000000       mov dword ptr fs:[0], ecx
// 007cc74b  5b                   pop ebx
// 007cc74c  8be5                 mov esp, ebp
// 007cc74e  5d                   pop ebp
// 007cc74f  c21400               ret 0x14
// standard library map_str<pod20> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
