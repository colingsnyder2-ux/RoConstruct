// from server: 100% by auto
// roc 2010-06 0065bf20  unit: RBX::VInstance::?$NonFactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065bf20
//
// 0065bf20  53                   push ebx
// 0065bf21  56                   push esi
// 0065bf22  57                   push edi
// 0065bf23  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065bf27  807f3100             cmp byte ptr [edi + 0x31], 0
// 0065bf2b  8bd9                 mov ebx, ecx
// 0065bf2d  8bf7                 mov esi, edi
// 0065bf2f  7527                 jne 0x65bf58
// 0065bf31  8b4608               mov eax, dword ptr [esi + 8]
// 0065bf34  50                   push eax
// 0065bf35  8bcb                 mov ecx, ebx
// 0065bf37  e8e4ffffff           call 0x65bf20
// 0065bf3c  8b36                 mov esi, dword ptr [esi]
// 0065bf3e  8d4f0c               lea ecx, [edi + 0xc]
// 0065bf41  ff1500a49e00         call dword ptr [0x9ea400]
// 0065bf47  57                   push edi
// 0065bf48  e84dba1400           call 0x7a799a
// 0065bf4d  83c404               add esp, 4
// 0065bf50  807e3100             cmp byte ptr [esi + 0x31], 0
// 0065bf54  8bfe                 mov edi, esi
// 0065bf56  74d9                 je 0x65bf31
// 0065bf58  5f                   pop edi
// 0065bf59  5e                   pop esi
// 0065bf5a  5b                   pop ebx
// 0065bf5b  c20400               ret 4
// standard library map_str<pod8> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
