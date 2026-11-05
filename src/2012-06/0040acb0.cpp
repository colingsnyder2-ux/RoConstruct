// from server: 100% by auto
// roc 2012-06 0040acb0  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040acb0
//
// 0040acb0  55                   push ebp
// 0040acb1  8bec                 mov ebp, esp
// 0040acb3  6aff                 push -1
// 0040acb5  6861a4a900           push 0xa9a461
// 0040acba  64a100000000         mov eax, dword ptr fs:[0]
// 0040acc0  50                   push eax
// 0040acc1  64892500000000       mov dword ptr fs:[0], esp
// 0040acc8  83ec0c               sub esp, 0xc
// 0040accb  53                   push ebx
// 0040accc  56                   push esi
// 0040accd  57                   push edi
// 0040acce  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040acd1  6a48                 push 0x48
// 0040acd3  e842745700           call 0x98211a
// 0040acd8  8bf0                 mov esi, eax
// 0040acda  83c404               add esp, 4
// 0040acdd  8975ec               mov dword ptr [ebp - 0x14], esi
// 0040ace0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040ace7  8975e8               mov dword ptr [ebp - 0x18], esi
// 0040acea  c645fc01             mov byte ptr [ebp - 4], 1
// 0040acee  85f6                 test esi, esi
// 0040acf0  7427                 je 0x40ad19
// 0040acf2  8b4508               mov eax, dword ptr [ebp + 8]
// 0040acf5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0040acf8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0040acfb  8906                 mov dword ptr [esi], eax
// 0040acfd  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0040ad00  894e04               mov dword ptr [esi + 4], ecx
// 0040ad03  50                   push eax
// 0040ad04  8d4e0c               lea ecx, [esi + 0xc]
// 0040ad07  895608               mov dword ptr [esi + 8], edx
// 0040ad0a  e851e62100           call 0x629360
// 0040ad0f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 0040ad12  884e44               mov byte ptr [esi + 0x44], cl
// 0040ad15  c6464500             mov byte ptr [esi + 0x45], 0
// 0040ad19  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040ad1c  5f                   pop edi
// 0040ad1d  8bc6                 mov eax, esi
// 0040ad1f  5e                   pop esi
// 0040ad20  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ad27  5b                   pop ebx
// 0040ad28  8be5                 mov esp, ebp
// 0040ad2a  5d                   pop ebp
// 0040ad2b  c21400               ret 0x14
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@D@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
