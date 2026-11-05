// from server: 100% by auto
// roc 2007-08 00469780  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00469780
//
// 00469780  53                   push ebx
// 00469781  56                   push esi
// 00469782  57                   push edi
// 00469783  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00469787  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0046978b  8bd9                 mov ebx, ecx
// 0046978d  8bf7                 mov esi, edi
// 0046978f  7527                 jne 0x4697b8
// 00469791  8b4608               mov eax, dword ptr [esi + 8]
// 00469794  50                   push eax
// 00469795  8bcb                 mov ecx, ebx
// 00469797  e8e4ffffff           call 0x469780
// 0046979c  8b36                 mov esi, dword ptr [esi]
// 0046979e  8d4f0c               lea ecx, [edi + 0xc]
// 004697a1  ff15ace67700         call dword ptr [0x77e6ac]
// 004697a7  57                   push edi
// 004697a8  e8b5641c00           call 0x62fc62
// 004697ad  83c404               add esp, 4
// 004697b0  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004697b4  8bfe                 mov edi, esi
// 004697b6  74d9                 je 0x469791
// 004697b8  5f                   pop edi
// 004697b9  5e                   pop esi
// 004697ba  5b                   pop ebx
// 004697bb  c20400               ret 4
// standard library map_str<ptr> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
