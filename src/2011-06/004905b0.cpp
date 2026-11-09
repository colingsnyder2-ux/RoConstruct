// from server: 100% by auto
// roc 2011-06 004905b0  unit: CRobloxScriptReviewPaneView  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004905b0
//
// 004905b0  55                   push ebp
// 004905b1  8bec                 mov ebp, esp
// 004905b3  6aff                 push -1
// 004905b5  6841629d00           push 0x9d6241
// 004905ba  64a100000000         mov eax, dword ptr fs:[0]
// 004905c0  50                   push eax
// 004905c1  64892500000000       mov dword ptr fs:[0], esp
// 004905c8  83ec0c               sub esp, 0xc
// 004905cb  53                   push ebx
// 004905cc  56                   push esi
// 004905cd  57                   push edi
// 004905ce  8965f0               mov dword ptr [ebp - 0x10], esp
// 004905d1  6a34                 push 0x34
// 004905d3  e8869a3700           call 0x80a05e
// 004905d8  8bf0                 mov esi, eax
// 004905da  83c404               add esp, 4
// 004905dd  8975ec               mov dword ptr [ebp - 0x14], esi
// 004905e0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004905e7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004905ea  c645fc01             mov byte ptr [ebp - 4], 1
// 004905ee  85f6                 test esi, esi
// 004905f0  7436                 je 0x490628
// 004905f2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004905f5  8b4508               mov eax, dword ptr [ebp + 8]
// 004905f8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004905fb  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004905fe  894e04               mov dword ptr [esi + 4], ecx
// 00490601  8d7e0c               lea edi, [esi + 0xc]
// 00490604  53                   push ebx
// 00490605  8bcf                 mov ecx, edi
// 00490607  8906                 mov dword ptr [esi], eax
// 00490609  895608               mov dword ptr [esi + 8], edx
// 0049060c  ff15c804a400         call dword ptr [0xa404c8]
// 00490612  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 00490615  8a5518               mov dl, byte ptr [ebp + 0x18]
// 00490618  89471c               mov dword ptr [edi + 0x1c], eax
// 0049061b  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 0049061e  894f20               mov dword ptr [edi + 0x20], ecx
// 00490621  885630               mov byte ptr [esi + 0x30], dl
// 00490624  c6463100             mov byte ptr [esi + 0x31], 0
// 00490628  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049062b  5f                   pop edi
// 0049062c  8bc6                 mov eax, esi
// 0049062e  5e                   pop esi
// 0049062f  64890d00000000       mov dword ptr fs:[0], ecx
// 00490636  5b                   pop ebx
// 00490637  8be5                 mov esp, ebp
// 00490639  5d                   pop ebp
// 0049063a  c21400               ret 0x14
// standard library map_str<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
