// from server: 100% by auto
// roc 2012-06 004aaec0  unit: DxUserInput  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004aaec0
//
// 004aaec0  53                   push ebx
// 004aaec1  56                   push esi
// 004aaec2  57                   push edi
// 004aaec3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004aaec7  807f3100             cmp byte ptr [edi + 0x31], 0
// 004aaecb  8bd9                 mov ebx, ecx
// 004aaecd  8bf7                 mov esi, edi
// 004aaecf  7527                 jne 0x4aaef8
// 004aaed1  8b4608               mov eax, dword ptr [esi + 8]
// 004aaed4  50                   push eax
// 004aaed5  8bcb                 mov ecx, ebx
// 004aaed7  e8e4ffffff           call 0x4aaec0
// 004aaedc  8b36                 mov esi, dword ptr [esi]
// 004aaede  8d4f0c               lea ecx, [edi + 0xc]
// 004aaee1  ff153c26b200         call dword ptr [0xb2263c]
// 004aaee7  57                   push edi
// 004aaee8  e827724d00           call 0x982114
// 004aaeed  83c404               add esp, 4
// 004aaef0  807e3100             cmp byte ptr [esi + 0x31], 0
// 004aaef4  8bfe                 mov edi, esi
// 004aaef6  74d9                 je 0x4aaed1
// 004aaef8  5f                   pop edi
// 004aaef9  5e                   pop esi
// 004aaefa  5b                   pop ebx
// 004aaefb  c20400               ret 4
// standard library map_str<pod8> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
