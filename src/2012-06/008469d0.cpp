// from server: 100% by auto
// roc 2012-06 008469d0  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008469d0
//
// 008469d0  55                   push ebp
// 008469d1  8bec                 mov ebp, esp
// 008469d3  6aff                 push -1
// 008469d5  68f1d4ac00           push 0xacd4f1
// 008469da  64a100000000         mov eax, dword ptr fs:[0]
// 008469e0  50                   push eax
// 008469e1  64892500000000       mov dword ptr fs:[0], esp
// 008469e8  83ec0c               sub esp, 0xc
// 008469eb  53                   push ebx
// 008469ec  56                   push esi
// 008469ed  57                   push edi
// 008469ee  8965f0               mov dword ptr [ebp - 0x10], esp
// 008469f1  6a34                 push 0x34
// 008469f3  e822b71300           call 0x98211a
// 008469f8  8bf0                 mov esi, eax
// 008469fa  83c404               add esp, 4
// 008469fd  8975ec               mov dword ptr [ebp - 0x14], esi
// 00846a00  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00846a07  8975e8               mov dword ptr [ebp - 0x18], esi
// 00846a0a  c645fc01             mov byte ptr [ebp - 4], 1
// 00846a0e  85f6                 test esi, esi
// 00846a10  741b                 je 0x846a2d
// 00846a12  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00846a15  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00846a18  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00846a1b  50                   push eax
// 00846a1c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00846a1f  51                   push ecx
// 00846a20  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00846a23  52                   push edx
// 00846a24  50                   push eax
// 00846a25  51                   push ecx
// 00846a26  8bce                 mov ecx, esi
// 00846a28  e8634fefff           call 0x73b990
// 00846a2d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00846a30  5f                   pop edi
// 00846a31  8bc6                 mov eax, esi
// 00846a33  5e                   pop esi
// 00846a34  64890d00000000       mov dword ptr fs:[0], ecx
// 00846a3b  5b                   pop ebx
// 00846a3c  8be5                 mov esp, ebp
// 00846a3e  5d                   pop ebp
// 00846a3f  c21400               ret 0x14
// standard library map_str<podc6> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<podc6>
struct E { char v[6]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
