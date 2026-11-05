// from server: 100% by auto
// roc 2012-06 0086a200  unit: RBX::VDataModel::?$BoundFuncDesc  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0086a200
//
// 0086a200  55                   push ebp
// 0086a201  8bec                 mov ebp, esp
// 0086a203  6aff                 push -1
// 0086a205  68c1f2ac00           push 0xacf2c1
// 0086a20a  64a100000000         mov eax, dword ptr fs:[0]
// 0086a210  50                   push eax
// 0086a211  64892500000000       mov dword ptr fs:[0], esp
// 0086a218  83ec0c               sub esp, 0xc
// 0086a21b  53                   push ebx
// 0086a21c  56                   push esi
// 0086a21d  57                   push edi
// 0086a21e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0086a221  6a34                 push 0x34
// 0086a223  e8f27e1100           call 0x98211a
// 0086a228  8bf0                 mov esi, eax
// 0086a22a  83c404               add esp, 4
// 0086a22d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0086a230  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0086a237  8975e8               mov dword ptr [ebp - 0x18], esi
// 0086a23a  c645fc01             mov byte ptr [ebp - 4], 1
// 0086a23e  85f6                 test esi, esi
// 0086a240  7436                 je 0x86a278
// 0086a242  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0086a245  8b4508               mov eax, dword ptr [ebp + 8]
// 0086a248  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0086a24b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 0086a24e  894e04               mov dword ptr [esi + 4], ecx
// 0086a251  8d7e0c               lea edi, [esi + 0xc]
// 0086a254  53                   push ebx
// 0086a255  8bcf                 mov ecx, edi
// 0086a257  8906                 mov dword ptr [esi], eax
// 0086a259  895608               mov dword ptr [esi + 8], edx
// 0086a25c  ff154426b200         call dword ptr [0xb22644]
// 0086a262  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 0086a265  8a5518               mov dl, byte ptr [ebp + 0x18]
// 0086a268  89471c               mov dword ptr [edi + 0x1c], eax
// 0086a26b  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 0086a26e  894f20               mov dword ptr [edi + 0x20], ecx
// 0086a271  885630               mov byte ptr [esi + 0x30], dl
// 0086a274  c6463100             mov byte ptr [esi + 0x31], 0
// 0086a278  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0086a27b  5f                   pop edi
// 0086a27c  8bc6                 mov eax, esi
// 0086a27e  5e                   pop esi
// 0086a27f  64890d00000000       mov dword ptr fs:[0], ecx
// 0086a286  5b                   pop ebx
// 0086a287  8be5                 mov esp, ebp
// 0086a289  5d                   pop ebp
// 0086a28a  c21400               ret 0x14
// standard library map_str<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
