// from server: 100% by auto
// roc 2011-06 00490d90  unit: CPropGrid::UpdateItemsJob  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00490d90
//
// 00490d90  53                   push ebx
// 00490d91  56                   push esi
// 00490d92  57                   push edi
// 00490d93  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00490d97  807f3100             cmp byte ptr [edi + 0x31], 0
// 00490d9b  8bd9                 mov ebx, ecx
// 00490d9d  8bf7                 mov esi, edi
// 00490d9f  7527                 jne 0x490dc8
// 00490da1  8b4608               mov eax, dword ptr [esi + 8]
// 00490da4  50                   push eax
// 00490da5  8bcb                 mov ecx, ebx
// 00490da7  e8e4ffffff           call 0x490d90
// 00490dac  8b36                 mov esi, dword ptr [esi]
// 00490dae  8d4f0c               lea ecx, [edi + 0xc]
// 00490db1  ff15d004a400         call dword ptr [0xa404d0]
// 00490db7  57                   push edi
// 00490db8  e89b923700           call 0x80a058
// 00490dbd  83c404               add esp, 4
// 00490dc0  807e3100             cmp byte ptr [esi + 0x31], 0
// 00490dc4  8bfe                 mov edi, esi
// 00490dc6  74d9                 je 0x490da1
// 00490dc8  5f                   pop edi
// 00490dc9  5e                   pop esi
// 00490dca  5b                   pop ebx
// 00490dcb  c20400               ret 4
// standard library map_str<pod8> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
