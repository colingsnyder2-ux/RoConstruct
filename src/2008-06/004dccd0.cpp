// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 004dccd0  unit: RBX::ViewNew::ViewG3D  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dccd0
//
// 004dccd0  55                   push ebp
// 004dccd1  8bec                 mov ebp, esp
// 004dccd3  6aff                 push -1
// 004dccd5  6881a27c00           push 0x7ca281
// 004dccda  64a100000000         mov eax, dword ptr fs:[0]
// 004dcce0  50                   push eax
// 004dcce1  64892500000000       mov dword ptr fs:[0], esp
// 004dcce8  83ec0c               sub esp, 0xc
// 004dcceb  53                   push ebx
// 004dccec  56                   push esi
// 004dcced  57                   push edi
// 004dccee  8965f0               mov dword ptr [ebp - 0x10], esp
// 004dccf1  6a38                 push 0x38
// 004dccf3  e8283c1c00           call 0x6a0920
// 004dccf8  8bf0                 mov esi, eax
// 004dccfa  83c404               add esp, 4
// 004dccfd  8975ec               mov dword ptr [ebp - 0x14], esi
// 004dcd00  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004dcd07  8975e8               mov dword ptr [ebp - 0x18], esi
// 004dcd0a  c645fc01             mov byte ptr [ebp - 4], 1
// 004dcd0e  85f6                 test esi, esi
// 004dcd10  741b                 je 0x4dcd2d
// 004dcd12  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004dcd15  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004dcd18  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004dcd1b  50                   push eax
// 004dcd1c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004dcd1f  51                   push ecx
// 004dcd20  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004dcd23  52                   push edx
// 004dcd24  50                   push eax
// 004dcd25  51                   push ecx
// 004dcd26  8bce                 mov ecx, esi
// 004dcd28  e883fcffff           call 0x4dc9b0
// 004dcd2d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004dcd30  5f                   pop edi
// 004dcd31  8bc6                 mov eax, esi
// 004dcd33  5e                   pop esi
// 004dcd34  64890d00000000       mov dword ptr fs:[0], ecx
// 004dcd3b  5b                   pop ebx
// 004dcd3c  8be5                 mov esp, ebp
// 004dcd3e  5d                   pop ebp
// 004dcd3f  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
