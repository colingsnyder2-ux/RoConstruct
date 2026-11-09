// from server: 100% by auto
// roc 2009-12 00768a50  unit: RBX::VInstance::?$NonFactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00768a50
//
// 00768a50  53                   push ebx
// 00768a51  56                   push esi
// 00768a52  57                   push edi
// 00768a53  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00768a57  807f3100             cmp byte ptr [edi + 0x31], 0
// 00768a5b  8bd9                 mov ebx, ecx
// 00768a5d  8bf7                 mov esi, edi
// 00768a5f  7527                 jne 0x768a88
// 00768a61  8b4608               mov eax, dword ptr [esi + 8]
// 00768a64  50                   push eax
// 00768a65  8bcb                 mov ecx, ebx
// 00768a67  e8e4ffffff           call 0x768a50
// 00768a6c  8b36                 mov esi, dword ptr [esi]
// 00768a6e  8d4f0c               lea ecx, [edi + 0xc]
// 00768a71  ff15e4b69800         call dword ptr [0x98b6e4]
// 00768a77  57                   push edi
// 00768a78  e8ddad0800           call 0x7f385a
// 00768a7d  83c404               add esp, 4
// 00768a80  807e3100             cmp byte ptr [esi + 0x31], 0
// 00768a84  8bfe                 mov edi, esi
// 00768a86  74d9                 je 0x768a61
// 00768a88  5f                   pop edi
// 00768a89  5e                   pop esi
// 00768a8a  5b                   pop ebx
// 00768a8b  c20400               ret 4
// standard library map_str<pod8> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
