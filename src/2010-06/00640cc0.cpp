// from server: 100% by auto
// roc 2010-06 00640cc0  unit: RBX::VInstance::?$NonFactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00640cc0
//
// 00640cc0  53                   push ebx
// 00640cc1  56                   push esi
// 00640cc2  57                   push edi
// 00640cc3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00640cc7  807f3500             cmp byte ptr [edi + 0x35], 0
// 00640ccb  8bd9                 mov ebx, ecx
// 00640ccd  8bf7                 mov esi, edi
// 00640ccf  7527                 jne 0x640cf8
// 00640cd1  8b4608               mov eax, dword ptr [esi + 8]
// 00640cd4  50                   push eax
// 00640cd5  8bcb                 mov ecx, ebx
// 00640cd7  e8e4ffffff           call 0x640cc0
// 00640cdc  8b36                 mov esi, dword ptr [esi]
// 00640cde  8d4f0c               lea ecx, [edi + 0xc]
// 00640ce1  ff1500a49e00         call dword ptr [0x9ea400]
// 00640ce7  57                   push edi
// 00640ce8  e8ad6c1600           call 0x7a799a
// 00640ced  83c404               add esp, 4
// 00640cf0  807e3500             cmp byte ptr [esi + 0x35], 0
// 00640cf4  8bfe                 mov edi, esi
// 00640cf6  74d9                 je 0x640cd1
// 00640cf8  5f                   pop edi
// 00640cf9  5e                   pop esi
// 00640cfa  5b                   pop ebx
// 00640cfb  c20400               ret 4
// standard library map_str<pod12> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
