// from server: 100% by auto
// roc 2011-06 00929de0  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00929de0
//
// 00929de0  55                   push ebp
// 00929de1  8bec                 mov ebp, esp
// 00929de3  6aff                 push -1
// 00929de5  68d106a100           push 0xa106d1
// 00929dea  64a100000000         mov eax, dword ptr fs:[0]
// 00929df0  50                   push eax
// 00929df1  64892500000000       mov dword ptr fs:[0], esp
// 00929df8  83ec0c               sub esp, 0xc
// 00929dfb  53                   push ebx
// 00929dfc  56                   push esi
// 00929dfd  57                   push edi
// 00929dfe  8965f0               mov dword ptr [ebp - 0x10], esp
// 00929e01  6a40                 push 0x40
// 00929e03  e85602eeff           call 0x80a05e
// 00929e08  8bf0                 mov esi, eax
// 00929e0a  83c404               add esp, 4
// 00929e0d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00929e10  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00929e17  8975e8               mov dword ptr [ebp - 0x18], esi
// 00929e1a  c645fc01             mov byte ptr [ebp - 4], 1
// 00929e1e  85f6                 test esi, esi
// 00929e20  7436                 je 0x929e58
// 00929e22  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00929e25  8b4508               mov eax, dword ptr [ebp + 8]
// 00929e28  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00929e2b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 00929e2e  894e04               mov dword ptr [esi + 4], ecx
// 00929e31  8d7e10               lea edi, [esi + 0x10]
// 00929e34  53                   push ebx
// 00929e35  8bcf                 mov ecx, edi
// 00929e37  8906                 mov dword ptr [esi], eax
// 00929e39  895608               mov dword ptr [esi + 8], edx
// 00929e3c  ff15c804a400         call dword ptr [0xa404c8]
// 00929e42  8b4320               mov eax, dword ptr [ebx + 0x20]
// 00929e45  8a5518               mov dl, byte ptr [ebp + 0x18]
// 00929e48  894720               mov dword ptr [edi + 0x20], eax
// 00929e4b  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 00929e4e  894f24               mov dword ptr [edi + 0x24], ecx
// 00929e51  885638               mov byte ptr [esi + 0x38], dl
// 00929e54  c6463900             mov byte ptr [esi + 0x39], 0
// 00929e58  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00929e5b  5f                   pop edi
// 00929e5c  8bc6                 mov eax, esi
// 00929e5e  5e                   pop esi
// 00929e5f  64890d00000000       mov dword ptr fs:[0], ecx
// 00929e66  5b                   pop ebx
// 00929e67  8be5                 mov esp, ebp
// 00929e69  5d                   pop ebp
// 00929e6a  c21400               ret 0x14
// standard library map_str<i64> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_JU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_J@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_JU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_J@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_J@2@D@Z)

// stl: map_str<i64>
typedef __int64 E;
#include <map>
#include <string>
template class std::map<std::string, E>;
